#include <gtest/gtest.h>

#include <algorithm>
#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <string>
#include <system_error>
#include <vector>

extern "C" {
#define HAVE_STDARG_H
#include <86box/86box.h>
#include <86box/hdd.h>
#include <86box/path.h>
#include <86box/plat.h>
}

namespace {

// Exercise the production image loader and real file I/O. Only platform
// services are adapted; the image sizing and writes are not mocked.
class HddImage : public ::testing::Test {
protected:
    static constexpr size_t cylinder_bytes = 4 * 17 * 512;
    std::filesystem::path directory;
    std::filesystem::path image_path;

    void SetUp() override
    {
        std::memset(hdd, 0, sizeof(hdd));
        hdd_image_init();
        std::error_code error;
        const auto root = std::filesystem::temp_directory_path(error);
        ASSERT_FALSE(error) << error.message();
        for (unsigned i = 0; i < 1024; ++i) {
            const auto candidate = root / ("86box-hdd-image-test-" + std::to_string(i));
            if (std::filesystem::create_directory(candidate, error)) {
                directory = candidate;
                break;
            }
            ASSERT_TRUE(!error || error == std::errc::file_exists) << error.message();
        }
        ASSERT_FALSE(directory.empty()) << "No available HDD image test directory";
        image_path = directory / "disk.img";
        const auto filename = image_path.string();
        ASSERT_LT(filename.size(), sizeof(hdd[0].fn));
        std::memcpy(hdd[0].fn, filename.c_str(), filename.size() + 1);
        hdd[0].spt = 17;
        hdd[0].hpc = 4;
        hdd[0].tracks = 4;
    }

    void TearDown() override
    {
        hdd_image_close(0);
        if (!directory.empty()) {
            std::error_code error;
            std::filesystem::remove_all(directory, error);
            EXPECT_FALSE(error) << error.message();
        }
    }

    static std::vector<uint8_t> pattern(size_t size)
    {
        std::vector<uint8_t> data(size);
        for (size_t i = 0; i < size; ++i)
            data[i] = static_cast<uint8_t>(1 + (i + i / 512) % 251);
        return data;
    }

    void write_image(const std::vector<uint8_t> &data)
    {
        std::ofstream file(image_path, std::ios::binary | std::ios::trunc);
        ASSERT_TRUE(file.is_open());
        file.write(reinterpret_cast<const char *>(data.data()),
                   static_cast<std::streamsize>(data.size()));
        file.close();
        ASSERT_TRUE(file.good());
    }

    std::vector<uint8_t> read_image()
    {
        std::ifstream file(image_path, std::ios::binary);
        if (!file.is_open()) {
            ADD_FAILURE() << "Cannot reopen backing image";
            return {};
        }
        std::vector<uint8_t> data { std::istreambuf_iterator<char>(file),
                                    std::istreambuf_iterator<char>() };
        EXPECT_FALSE(file.bad());
        return data;
    }
};

TEST_F(HddImage, NewRawImageHasConfiguredCapacityAndZeroFilledContents)
{
    ASSERT_EQ(hdd_image_load(0), 1);
    EXPECT_EQ(hdd_image_get_last_sector(0), 4 * 4 * 17 - 1u);
    hdd_image_close(0);

    const auto actual = read_image();
    ASSERT_EQ(actual.size(), 4 * cylinder_bytes);
    EXPECT_TRUE(std::all_of(actual.begin(), actual.end(), [](uint8_t b) { return b == 0; }));
}

TEST_F(HddImage, ExistingRawImageMatchingGeometryKeepsAllContents)
{
    const auto original = pattern(4 * cylinder_bytes);
    ASSERT_NO_FATAL_FAILURE(write_image(original));
    ASSERT_EQ(hdd_image_load(0), 1);
    hdd_image_close(0);

    EXPECT_EQ(read_image(), original);
}

TEST_F(HddImage, IncreasingRawImageGeometryPreservesDataAndZeroFillsAddedCapacity)
{
    // A user adds an existing raw image and increases Cylinders from 3 to 4
    // in the hard disk dialog. Loading it must extend the file without losing
    // the original partition/filesystem bytes, including the final sector.
    const auto original = pattern(3 * cylinder_bytes);
    ASSERT_NO_FATAL_FAILURE(write_image(original));
    ASSERT_EQ(hdd_image_load(0), 1);
    hdd_image_close(0);

    const auto actual = read_image();
    EXPECT_EQ(actual.size(), 4 * cylinder_bytes) << "Configured image capacity";
    ASSERT_GE(actual.size(), original.size()) << "Loading erased existing image bytes";
    EXPECT_TRUE(std::equal(original.begin(), original.end(), actual.begin()))
        << "Existing disk contents changed";
    EXPECT_TRUE(std::all_of(actual.begin() + original.size(), actual.end(),
                           [](uint8_t b) { return b == 0; }))
        << "Added capacity must contain zero-filled sectors";
}

TEST_F(HddImage, SharedFolderReadsAndWritesHostFileThroughFatDisk)
{
    const auto hostfile = directory / "HELLO.TXT";
    auto original = pattern(512);
    {
        std::ofstream out(hostfile, std::ios::binary);
        out.write(reinterpret_cast<const char *>(original.data()), original.size());
    }
    const auto folder = directory.string();
    std::strcpy(hdd[0].fn, folder.c_str());
    hdd[0].shared_fake_size_mb = 64;
    hdd[0].shared_fs_type = 16;
    hdd[0].shared_layout = 2;
    ASSERT_EQ(hdd_image_load(0), 1);
    uint8_t boot[512], root[512], data[512];
    ASSERT_EQ(hdd_image_read(0, 0, 1, boot), 0);
    EXPECT_EQ(boot[510], 0x55);
    EXPECT_EQ(boot[511], 0xaa);
    auto le16 = [](const uint8_t *p) { return unsigned(p[0]) | (unsigned(p[1]) << 8); };
    const unsigned root_lba = le16(boot + 14) + boot[16] * le16(boot + 22);
    const unsigned root_sectors = (le16(boot + 17) * 32 + 511) / 512;
    ASSERT_EQ(hdd_image_read(0, root_lba, 1, root), 0);
    unsigned cluster = 0;
    for (unsigned off = 0; off < 512; off += 32)
        if (std::memcmp(root + off, "HELLO   TXT", 11) == 0)
            cluster = le16(root + off + 26);
    ASSERT_GE(cluster, 2u);
    const unsigned lba = root_lba + root_sectors + (cluster - 2) * boot[13];
    ASSERT_EQ(hdd_image_read(0, lba, 1, data), 0);
    EXPECT_TRUE(std::equal(original.begin(), original.end(), data));
    std::fill(std::begin(data), std::end(data), 0x5a);
    ASSERT_EQ(hdd_image_write(0, lba, 1, data), 0);
    hdd_image_close(0);
    std::ifstream in(hostfile, std::ios::binary);
    std::vector<uint8_t> written{std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>()};
    ASSERT_EQ(written.size(), 512u);
    EXPECT_TRUE(std::all_of(written.begin(), written.end(), [](uint8_t b) { return b == 0x5a; }));
}

} // namespace

extern "C" {
hard_disk_t hdd[HDD_SLOTS];

FILE *
plat_fopen(const char *path, const char *mode)
{
    return std::fopen(path, mode);
}

char *
path_get_extension(char *path)
{
    char *dot = std::strrchr(path, '.');
    return dot ? dot + 1 : path + std::strlen(path);
}

const char *path_get_slash(char *) { return "/"; }
int plat_dir_create(char *path) { return std::filesystem::create_directory(path) ? 0 : -1; }
void path_normalize(char *) {}
int plat_is_block_device(const char *) { return 0; }
int64_t plat_get_block_device_size(const char *) { return -1; }
plat_device_vol_locked_t *plat_lock_volumes(FILE *) { return nullptr; }
void plat_unlock_volumes(plat_device_vol_locked_t *) {}
void pclog(const char *, ...) {}
void pclog_toggle_suppr(void) {}

void
fatal(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    std::vfprintf(stderr, format, args);
    va_end(args);
    std::abort();
}
}

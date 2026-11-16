#include <gtest/gtest.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
extern "C" {
#include <86box/86box.h>
#include <86box/timer.h>
#include <86box/fdd.h>
#include <86box/sound.h>
#include <86box/fdd_sfx.h>
#include <86box/path.h>
#include <86box/plat.h>
}
namespace {
void (*mixer)(int32_t *, uint16_t, void *);
int registrations;
std::vector<int32_t> mix()
{
    std::vector<int32_t> samples(8192);
    mixer(samples.data(), 4096, nullptr);
    return samples;
}
bool audible(const std::vector<int32_t> &samples)
{
    return std::any_of(samples.begin(), samples.end(), [](int32_t x) { return x != 0; });
}
TEST(FloppySfx, MotorAndSeekUseBundledSamples)
{
    fdd_sfx_init();
    ASSERT_NE(mixer, nullptr);
    fdd_sfx_enable(1);
    fdd_sfx_motor(0, 1);
    fdd_sfx_step(0);
    EXPECT_TRUE(audible(mix()));
    fdd_sfx_motor(0, 0);
}
TEST(FloppySfx, DisablingStopsActivePlayback)
{
    fdd_sfx_init();
    fdd_sfx_enable(1);
    fdd_sfx_motor(0, 1);
    ASSERT_TRUE(audible(mix()));
    fdd_sfx_enable(0);
    EXPECT_FALSE(audible(mix()));
}
TEST(FloppySfx, ResetRegistersMixerAgainAndClearsOldMotorState)
{
    fdd_sfx_init();
    const int before = registrations;
    fdd_sfx_enable(1);
    fdd_sfx_motor(0, 1);
    fdd_sfx_init();
    EXPECT_EQ(registrations, before + 1);
    EXPECT_FALSE(audible(mix()));
    fdd_sfx_motor(0, 1);
    EXPECT_TRUE(audible(mix()));
}
TEST(FloppySfx, HandlesNewUpstreamEighthDrive)
{
    fdd_sfx_init();
    fdd_sfx_enable(1);
    fdd_sfx_motor(FDD_NUM - 1, 1);
    fdd_sfx_step(FDD_NUM - 1);
    EXPECT_TRUE(audible(mix()));
    fdd_sfx_motor(FDD_NUM - 1, 0);
}
}
extern "C" {
fdd_drive_t drives[FDD_NUM];
int fdd_getrpm(void *) { return 300; }
void sound_add_handler(void (*fn)(int32_t *, uint16_t, void *), void *) { mixer = fn; ++registrations; }
void plat_get_exe_name(char *s, int size) { std::snprintf(s, size, "%s/test", FORK_SOURCE_DIR); }
void path_get_dirname(char *dest, const char *path) {
    std::string directory(path);
    directory.resize(directory.find_last_of('/'));
    std::strcpy(dest, directory.c_str());
}
void path_slash(char *path) { std::strcat(path, "/"); }
}

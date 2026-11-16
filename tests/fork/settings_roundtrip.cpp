/* Ad-hoc integration harness: compile with qt_main.cpp's normal flags, then
   link in front of libplat.a using the application's normal link command.
   Runs entirely in Qt's offscreen platform, without desktop automation. */
#define main emulator_main
#include "../../src/qt/qt_main.cpp"
#undef main
#include "../../src/qt/qt_settingshostfs.hpp"
#include "../../src/qt/qt_settingsharddisks.hpp"
#include <QLineEdit>
#include <QTableView>
extern "C" {
#include <86box/hdd.h>
}

static bool smoke_passed;

static int folder_slot(const QByteArray &folder)
{
    for (int i = 0; i < HDD_NUM; ++i)
        if (QByteArray(hdd[i].fn) == folder)
            return i;
    return -1;
}

static void check(bool okay, const char *message)
{
    if (!okay) {
        fprintf(stderr, "SETTINGS ROUNDTRIP FAILED: %s\n", message);
        std::abort();
    }
}

static void run_settings_test()
{
    auto *settings = qobject_cast<Settings *>(QApplication::activeModalWidget());
    check(settings != nullptr, "settings dialog exists");
    const QByteArray folder = qgetenv("FORK_TEST_FOLDER");
    const QByteArray disk = qgetenv("FORK_TEST_DISK");
    check(!folder.isEmpty() && !disk.isEmpty(), "fixture paths supplied");

    settings->save(0); // Builds every lazily-created page and saves unchanged state.
    auto *shared = settings->findChild<SettingsHostFS *>();
    auto *regular = settings->findChild<SettingsHarddisks *>();
    check(shared && regular, "both disk pages exist");
    check(shared->driveCount() == 1 && regular->driveCount() == 1, "disk pages are independent");
    int slot = folder_slot(folder);
    check(slot >= 0 && hdd[slot].shared_fake_size_mb == 64, "unchanged shared configuration survives");
    check(folder_slot(disk) >= 0, "ordinary image survives");

    auto *table = shared->findChild<QTableView *>("tableView");
    auto *capacity = shared->findChild<QLineEdit *>("lineEditCapacity");
    auto *model_name = shared->findChild<QLineEdit *>("lineEditDevName");
    check(table && capacity && model_name, "shared controls exist");
    table->setCurrentIndex(table->model()->index(0, 0));
    capacity->setText("96");
    model_name->setText("FORK TEST DISK");
    check(hdd[slot].shared_fake_size_mb == 64, "edits do not mutate the running configuration");
    check(shared->changed() != 0, "shared edits require a save");
    settings->save(0);
    slot = folder_slot(folder);
    check(slot >= 0 && hdd[slot].shared_fake_size_mb == 96, "shared capacity is saved");
    check(hdd[slot].override_model && !strcmp(hdd[slot].override_model, "FORK TEST DISK"), "shared identity is saved");
    check(folder_slot(disk) >= 0, "shared save preserves ordinary image");
    settings->save(0);
    check(folder_slot(folder) >= 0 && folder_slot(disk) >= 0, "repeated saves retain both disks");
    config_save();
    config_load();
    slot = folder_slot(folder);
    check(slot >= 0 && hdd[slot].shared_fake_size_mb == 96, "shared capacity survives INI reload");
    check(hdd[slot].override_model && !strcmp(hdd[slot].override_model, "FORK TEST DISK"), "shared identity survives INI reload");
    check(folder_slot(disk) >= 0, "ordinary image survives INI reload");
    smoke_passed = true;
    fprintf(stderr, "PASS: independent disk pages, deferred edits, capacity/identity and repeated saves\n");
    QMetaObject::invokeMethod(settings, "reject", Qt::DirectConnection);
}

static void schedule_settings_test()
{
    QTimer::singleShot(0, run_settings_test);
}
Q_COREAPP_STARTUP_FUNCTION(schedule_settings_test)

int main(int argc, char **argv)
{
    int ret = emulator_main(argc, argv);
    return ret ? ret : smoke_passed ? 0 : 1;
}

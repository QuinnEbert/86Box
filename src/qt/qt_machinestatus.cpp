/*
 * 86Box    A hypervisor and IBM PC system emulator that specializes in
 *          running old operating systems and software designed for IBM
 *          PC systems and compatibles from 1981 through fairly recent
 *          system designs based on the PCI bus.
 *
 *          This file is part of the 86Box distribution.
 *
 *          Joystick configuration UI module.
 *
 *
 *
 * Authors: Joakim L. Gilje <jgilje@jgilje.net>
 *          Cacodemon345
 *
 *          Copyright 2021 Joakim L. Gilje
 *          Copyright 2021-2022 Cacodemon345
 */
#include "qt_machinestatus.hpp"

extern "C" {
#include <86box/hdd.h>
#include <86box/timer.h>
#include <86box/86box.h>
#include <86box/device.h>
#include <86box/video.h>
#include <86box/cartridge.h>
#include <86box/cassette.h>
#include <86box/cdrom.h>
#include <86box/cdrom_interface.h>
#include <86box/fdd.h>
#include <86box/fdc_ext.h>
#include <86box/hdc.h>
#include <86box/scsi.h>
#include <86box/scsi_device.h>
#include <86box/sound.h>
#include <86box/zip.h>
#include <86box/mo.h>
#include <86box/plat.h>
#include <86box/machine.h>
#include <86box/thread.h>
#include <86box/network.h>
#include <86box/ui.h>
#include <86box/machine_status.h>
#include <86box/config.h>

extern volatile int fdcinited;
};

#include <QIcon>
#include <QPicture>
#include <QLabel>
#include <QTimer>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QFileInfo>
#include <QMenu>
#include <QScreen>
#include <QString>
#include <QStringList>

#include "qt_mediamenu.hpp"
#include "qt_mainwindow.hpp"
#include "qt_soundgain.hpp"
#include "qt_progsettings.hpp"
#include "qt_iconindicators.hpp"
#include "qt_deviceconfig.hpp"

extern "C" {
#include "../cpu/cpu.h"
}

#include <array>

extern MainWindow *main_window;

static bool sbar_initialized = false;

namespace {
struct PixmapSetActive {
    QPixmap normal;
    QPixmap active;
    QPixmap write_active;
    QPixmap read_write_active;
    void    load(const QIcon &icon);
};
struct PixmapSetDisabled {
    QPixmap normal;
    QPixmap disabled;
    void    load(const QIcon &icon);
};
struct PixmapSetEmpty {
    QPixmap normal;
    QPixmap empty;
    void    load(const QIcon &icon);
};
struct PixmapSetEmptyActive {
    QPixmap normal;
    QPixmap active;
    QPixmap empty;
    QPixmap empty_active;
    QPixmap write_active;
    QPixmap read_write_active;
    QPixmap empty_write_active;
    QPixmap empty_read_write_active;
    void    load(const QIcon &icon);
};
struct Pixmaps {
    PixmapSetEmpty       cartridge;
    PixmapSetEmptyActive cassette;
    PixmapSetEmptyActive floppy_disabled;
    PixmapSetEmptyActive floppy_525;
    PixmapSetEmptyActive floppy_35;
    PixmapSetEmptyActive cdrom;
    PixmapSetEmptyActive zip;
    PixmapSetEmptyActive mo;
    PixmapSetActive      hd;
    PixmapSetEmptyActive net;
    PixmapSetDisabled    sound;
};

struct StateActive {
    std::unique_ptr<QLabel> label;
    PixmapSetActive        *pixmaps = nullptr;
    bool                    active  = false;
    bool                    write_active  = false;

    void setActive(bool b)
    {
        if (!label || b == active)
            return;
        active = b;

        refresh();
    }

    void setWriteActive(bool b)
    {
        if (!label || b == write_active)
            return;

        write_active = b;
        refresh();
    }

    void refresh()
    {
        if (!label)
            return;
        if (active && write_active)
            label->setPixmap(pixmaps->read_write_active);
        else
            label->setPixmap(write_active ? pixmaps->write_active : (active ? pixmaps->active : pixmaps->normal));
    }
};
struct StateEmpty {
    std::unique_ptr<QLabel> label;
    PixmapSetEmpty         *pixmaps = nullptr;
    bool                    empty   = false;

    void setEmpty(bool e)
    {
        if (!label || e == empty)
            return;
        empty = e;

        refresh();
    }

    void refresh()
    {
        if (!label)
            return;
        label->setPixmap(empty ? pixmaps->empty : pixmaps->normal);
    }
};
struct StateEmptyActive {
    std::unique_ptr<QLabel> label;
    PixmapSetEmptyActive   *pixmaps       = nullptr;
    bool                    empty         = false;
    bool                    active        = false;
    bool                    write_active  = false;

    void setActive(bool b)
    {
        if (!label || b == active)
            return;

        active = b;
        refresh();
    }
    void setWriteActive(bool b)
    {
        if (!label || b == write_active)
            return;

        write_active = b;
        refresh();
    }
    void setEmpty(bool b)
    {
        if (!label || b == empty)
            return;

        empty = b;
        refresh();
    }
    void refresh()
    {
        if (!label)
            return;
        if (empty) {
            if (active && write_active)
                label->setPixmap(pixmaps->empty_read_write_active);
            else
                label->setPixmap(write_active ? pixmaps->empty_write_active : (active ? pixmaps->empty_active : pixmaps->empty));
        } else {
            if (active && write_active)
                label->setPixmap(pixmaps->read_write_active);
            else
                label->setPixmap(write_active ? pixmaps->write_active : (active ? pixmaps->active : pixmaps->normal));
        }
    }
};

static QSize         pixmap_size(16, 16);

void
PixmapSetEmpty::load(const QIcon &icon)
{
    normal = getIconWithIndicator(icon, pixmap_size, QIcon::Normal, None);
    empty  = getIconWithIndicator(icon, pixmap_size, QIcon::Disabled, None);
}

void
PixmapSetActive::load(const QIcon &icon)
{
    normal = getIconWithIndicator(icon, pixmap_size, QIcon::Normal, None);
    active = getIconWithIndicator(icon, pixmap_size, QIcon::Normal, Active);
    
    write_active = getIconWithIndicator(icon, pixmap_size, QIcon::Normal, WriteActive);
    read_write_active = getIconWithIndicator(icon, pixmap_size, QIcon::Normal, ReadWriteActive);
}

void
PixmapSetDisabled::load(const QIcon &icon)
{
    normal   = getIconWithIndicator(icon, pixmap_size, QIcon::Normal, None);
    disabled = getIconWithIndicator(icon, pixmap_size, QIcon::Disabled, Disabled);
}

void
PixmapSetEmptyActive::load(const QIcon &icon)
{
    normal                  = getIconWithIndicator(icon, pixmap_size, QIcon::Normal, None);
    active                  = getIconWithIndicator(icon, pixmap_size, QIcon::Normal, Active);
    write_active            = getIconWithIndicator(icon, pixmap_size, QIcon::Normal, WriteActive);
    read_write_active       = getIconWithIndicator(icon, pixmap_size, QIcon::Normal, ReadWriteActive);
    empty                   = getIconWithIndicator(icon, pixmap_size, QIcon::Disabled, None);
    empty_active            = getIconWithIndicator(icon, pixmap_size, QIcon::Disabled, Active);
    empty_write_active      = getIconWithIndicator(icon, pixmap_size, QIcon::Disabled, WriteActive);
    empty_read_write_active = getIconWithIndicator(icon, pixmap_size, QIcon::Disabled, ReadWriteActive);
}
}

struct MachineStatus::States {
    Pixmaps pixmaps;

    States(QObject *parent)
    {
        pixmaps.cartridge.load(QIcon(":/settings/qt/icons/cartridge.ico"));
        pixmaps.cassette.load(QIcon(":/settings/qt/icons/cassette.ico"));
        pixmaps.floppy_disabled.normal                  = QIcon(":/settings/qt/icons/floppy_disabled.ico").pixmap(pixmap_size);
        pixmaps.floppy_disabled.active                  = pixmaps.floppy_disabled.normal;
        pixmaps.floppy_disabled.read_write_active       = pixmaps.floppy_disabled.normal;
        pixmaps.floppy_disabled.empty                   = pixmaps.floppy_disabled.normal;
        pixmaps.floppy_disabled.empty_active            = pixmaps.floppy_disabled.normal;
        pixmaps.floppy_disabled.empty_write_active      = pixmaps.floppy_disabled.normal;
        pixmaps.floppy_disabled.empty_read_write_active = pixmaps.floppy_disabled.normal;
        pixmaps.floppy_525.load(QIcon(":/settings/qt/icons/floppy_525.ico"));
        pixmaps.floppy_35.load(QIcon(":/settings/qt/icons/floppy_35.ico"));
        pixmaps.cdrom.load(QIcon(":/settings/qt/icons/cdrom.ico"));
        pixmaps.zip.load(QIcon(":/settings/qt/icons/zip.ico"));
        pixmaps.mo.load(QIcon(":/settings/qt/icons/mo.ico"));
        pixmaps.hd.load(QIcon(":/settings/qt/icons/hard_disk.ico"));
        pixmaps.net.load(QIcon(":/settings/qt/icons/network.ico"));
        pixmaps.sound.load(QIcon(":/settings/qt/icons/sound.ico"));

        cartridge[0].pixmaps = &pixmaps.cartridge;
        cartridge[1].pixmaps = &pixmaps.cartridge;
        cassette.pixmaps     = &pixmaps.cassette;
        for (auto &f : fdd) {
            f.pixmaps = &pixmaps.floppy_disabled;
        }
        for (auto &c : cdrom) {
            c.pixmaps = &pixmaps.cdrom;
        }
        for (auto &z : zip) {
            z.pixmaps = &pixmaps.zip;
        }
        for (auto &m : mo) {
            m.pixmaps = &pixmaps.mo;
        }
        for (auto &h : hdds) {
            h.pixmaps = &pixmaps.hd;
        }
        for (auto &n : net) {
            n.pixmaps = &pixmaps.net;
        }

        hardware        = nullptr;
        storage         = nullptr;
        attachments     = nullptr;
        hardwareWidget  = nullptr;
    }

    std::array<StateEmpty, 2>                  cartridge;
    StateEmptyActive                           cassette;
    std::array<StateEmptyActive, FDD_NUM>      fdd;
    std::array<StateEmptyActive, CDROM_NUM>    cdrom;
    std::array<StateEmptyActive, ZIP_NUM>      zip;
    std::array<StateEmptyActive, MO_NUM>       mo;
    std::array<StateActive, HDD_BUS_USB>       hdds;
    std::array<StateEmptyActive, NET_CARD_MAX> net;
    std::unique_ptr<ClickableLabel>            sound;
    std::unique_ptr<QLabel>                    speed;
    std::unique_ptr<QLabel>                    ram;
    std::unique_ptr<QWidget>                   hardwareWidget;
    QLabel*                                   hardware;
    QLabel*                                   storage;
    QLabel*                                   attachments;
    std::unique_ptr<QLabel>                    text;
};

MachineStatus::MachineStatus(QObject *parent)
    : QObject(parent)
    , refreshTimer(new QTimer(this))
{
    d = std::make_unique<MachineStatus::States>(this);
    soundMenu = nullptr;
    connect(refreshTimer, &QTimer::timeout, this, &MachineStatus::refreshIcons);
    refreshTimer->start(75);
}

MachineStatus::~MachineStatus() = default;

void
MachineStatus::setSoundMenu(QMenu* menu)
{
    soundMenu = menu;
}

bool
MachineStatus::hasCassette()
{
    return cassette_enable > 0 ? true : false;
}

bool
MachineStatus::hasIDE()
{
    return (machine_has_flags(machine, MACHINE_IDE_QUAD) > 0) || other_ide_present;
}

bool
MachineStatus::hasSCSI()
{
    return (machine_has_flags(machine, MACHINE_SCSI) > 0) || other_scsi_present;
}

void
MachineStatus::iterateFDD(const std::function<void(int)> &cb)
{
    if (!fdcinited)
        return;

    for (int i = 0; i < FDD_NUM; ++i) {
        if (fdd_get_type(i) != 0) {
            cb(i);
        }
    }
}

void
MachineStatus::iterateCDROM(const std::function<void(int)> &cb)
{
    auto hdc_name = QString(hdc_get_internal_name(hdc_current[0]));
    for (size_t i = 0; i < CDROM_NUM; i++) {
        /* Could be Internal or External IDE.. */
        if ((cdrom[i].bus_type == CDROM_BUS_ATAPI) && !hasIDE() &&
            (hdc_name.left(3) != QStringLiteral("ide")) &&
            (hdc_name.left(5) != QStringLiteral("xtide")) &&
            (hdc_name.left(5) != QStringLiteral("mcide")))
            continue;
        if ((cdrom[i].bus_type == CDROM_BUS_SCSI) && !hasSCSI() &&
            (scsi_card_current[0] == 0) && (scsi_card_current[1] == 0) &&
            (scsi_card_current[2] == 0) && (scsi_card_current[3] == 0))
            continue;
        if ((cdrom[i].bus_type == CDROM_BUS_MITSUMI) && (cdrom_interface_current == 0))
            continue;
        if (cdrom[i].bus_type != 0) {
            cb(i);
        }
    }
}

void
MachineStatus::iterateZIP(const std::function<void(int)> &cb)
{
    auto hdc_name = QString(hdc_get_internal_name(hdc_current[0]));
    for (size_t i = 0; i < ZIP_NUM; i++) {
        /* Could be Internal or External IDE.. */
        if ((zip_drives[i].bus_type == ZIP_BUS_ATAPI) && !hasIDE() &&
            (hdc_name.left(3) != QStringLiteral("ide")) &&
            (hdc_name.left(5) != QStringLiteral("xtide")) &&
            (hdc_name.left(5) != QStringLiteral("mcide")))
            continue;
        if ((zip_drives[i].bus_type == ZIP_BUS_SCSI) && !hasSCSI() &&
            (scsi_card_current[0] == 0) && (scsi_card_current[1] == 0) &&
            (scsi_card_current[2] == 0) && (scsi_card_current[3] == 0))
            continue;
        if (zip_drives[i].bus_type != 0) {
            cb(i);
        }
    }
}

void
MachineStatus::iterateMO(const std::function<void(int)> &cb)
{
    auto hdc_name = QString(hdc_get_internal_name(hdc_current[0]));
    for (size_t i = 0; i < MO_NUM; i++) {
        /* Could be Internal or External IDE.. */
        if ((mo_drives[i].bus_type == MO_BUS_ATAPI) && !hasIDE() &&
            (hdc_name.left(3) != QStringLiteral("ide")) &&
            (hdc_name.left(5) != QStringLiteral("xtide")) &&
            (hdc_name.left(5) != QStringLiteral("mcide")))
            continue;
        if ((mo_drives[i].bus_type == MO_BUS_SCSI) && !hasSCSI() &&
            (scsi_card_current[0] == 0) && (scsi_card_current[1] == 0) &&
            (scsi_card_current[2] == 0) && (scsi_card_current[3] == 0))
            continue;
        if (mo_drives[i].bus_type != 0) {
            cb(i);
        }
    }
}

void
MachineStatus::iterateNIC(const std::function<void(int)> &cb)
{
    for (int i = 0; i < NET_CARD_MAX; i++) {
        if (network_dev_available(i)) {
            cb(i);
        }
    }
}

static int
hdd_count(const int bus_type)
{
    int c = 0;

    for (uint8_t i = 0; i < HDD_NUM; i++) {
        if (hdd[i].bus_type == bus_type) {
            c++;
        }
    }

    return c;
}

void
MachineStatus::refreshEmptyIcons()
{
    /* Check if icons are initialized. */
    if (!sbar_initialized)
        return;

    for (size_t i = 0; i < FDD_NUM; ++i)
        d->fdd[i].setEmpty(machine_status.fdd[i].empty);
    for (size_t i = 0; i < CDROM_NUM; ++i)
        d->cdrom[i].setEmpty(machine_status.cdrom[i].empty);
    for (size_t i = 0; i < ZIP_NUM; i++)
        d->zip[i].setEmpty(machine_status.zip[i].empty);
    for (size_t i = 0; i < MO_NUM; i++)
        d->mo[i].setEmpty(machine_status.mo[i].empty);

    d->cassette.setEmpty(machine_status.cassette.empty);

    for (size_t i = 0; i < NET_CARD_MAX; i++)
        d->net[i].setEmpty(machine_status.net[i].empty);

    for (int i = 0; i < 2; ++i)
        d->cartridge[i].setEmpty(machine_status.cartridge[i].empty);
}

void
MachineStatus::refreshIcons()
{
    /* Check if icons should show activity. */
    if (!update_icons)
        return;

    for (size_t i = 0; i < FDD_NUM; ++i) {
        d->fdd[i].setActive(machine_status.fdd[i].active);
        d->fdd[i].setWriteActive(machine_status.fdd[i].write_active);
    }
    for (size_t i = 0; i < CDROM_NUM; ++i) {
        d->cdrom[i].setActive(machine_status.cdrom[i].active);
        d->cdrom[i].setWriteActive(machine_status.cdrom[i].write_active);
        if (machine_status.cdrom[i].active) {
            ui_sb_update_icon(SB_CDROM | i, 0);
        }
        if (machine_status.cdrom[i].write_active) {
            ui_sb_update_icon_write(SB_CDROM | i, 0);
        }
    }
    for (size_t i = 0; i < ZIP_NUM; i++) {
        d->zip[i].setActive(machine_status.zip[i].active);
        d->zip[i].setWriteActive(machine_status.zip[i].write_active);
        if (machine_status.zip[i].active)
            ui_sb_update_icon(SB_ZIP | i, 0);
        if (machine_status.zip[i].write_active)
            ui_sb_update_icon_write(SB_ZIP | i, 0);
    }
    for (size_t i = 0; i < MO_NUM; i++) {
        d->mo[i].setActive(machine_status.mo[i].active);
        d->mo[i].setWriteActive(machine_status.mo[i].write_active);
        if (machine_status.mo[i].active)
            ui_sb_update_icon(SB_MO | i, 0);
        if (machine_status.mo[i].write_active)
            ui_sb_update_icon_write(SB_MO | i, 0);
    }

    for (size_t i = 0; i < HDD_BUS_USB; i++) {
        d->hdds[i].setActive(machine_status.hdd[i].active);
        d->hdds[i].setWriteActive(machine_status.hdd[i].write_active);
        if (machine_status.hdd[i].active)
            ui_sb_update_icon(SB_HDD | i, 0);
        if (machine_status.hdd[i].write_active)
            ui_sb_update_icon_write(SB_HDD | i, 0);
    }

    for (size_t i = 0; i < NET_CARD_MAX; i++) {
        d->net[i].setActive(machine_status.net[i].active);
        d->net[i].setWriteActive(machine_status.net[i].write_active);
    }
}

void
MachineStatus::clearActivity()
{
    for (auto &fdd : d->fdd) {
        fdd.setActive(false);
        fdd.setWriteActive(false);
    }
    for (auto &cdrom : d->cdrom) {
        cdrom.setActive(false);
        cdrom.setWriteActive(false);
    }
    for (auto &zip : d->zip) {
        zip.setActive(false);
        zip.setWriteActive(false);
    }
    for (auto &mo : d->mo) {
        mo.setActive(false);
        mo.setWriteActive(false);
    }
    for (auto &hdd : d->hdds) {
        hdd.setActive(false);
        hdd.setWriteActive(false);
    }
    for (auto &net : d->net) {
        net.setActive(false);
        net.setWriteActive(false);
    }
}

void
MachineStatus::refresh(QStatusBar *sbar)
{
    bool has_mfm  = machine_has_flags(machine, MACHINE_MFM) > 0;
    bool has_xta  = machine_has_flags(machine, MACHINE_XTA) > 0;
    bool has_esdi = machine_has_flags(machine, MACHINE_ESDI) > 0;

    int c_mfm   = hdd_count(HDD_BUS_MFM);
    int c_esdi  = hdd_count(HDD_BUS_ESDI);
    int c_xta   = hdd_count(HDD_BUS_XTA);
    int c_ide   = hdd_count(HDD_BUS_IDE);
    int c_atapi = hdd_count(HDD_BUS_ATAPI);
    int c_scsi  = hdd_count(HDD_BUS_SCSI);

    sbar->removeWidget(d->cassette.label.get());
    for (int i = 0; i < 2; ++i) {
        sbar->removeWidget(d->cartridge[i].label.get());
    }
    for (size_t i = 0; i < FDD_NUM; ++i) {
        sbar->removeWidget(d->fdd[i].label.get());
    }
    for (size_t i = 0; i < CDROM_NUM; i++) {
        sbar->removeWidget(d->cdrom[i].label.get());
    }
    for (size_t i = 0; i < ZIP_NUM; i++) {
        sbar->removeWidget(d->zip[i].label.get());
    }
    for (size_t i = 0; i < MO_NUM; i++) {
        sbar->removeWidget(d->mo[i].label.get());
    }
    for (size_t i = 0; i < HDD_BUS_USB; i++) {
        sbar->removeWidget(d->hdds[i].label.get());
    }
    for (size_t i = 0; i < NET_CARD_MAX; i++) {
        sbar->removeWidget(d->net[i].label.get());
    }
    sbar->removeWidget(d->sound.get());
    sbar->removeWidget(d->text.get());
    sbar->removeWidget(d->speed.get());
    sbar->removeWidget(d->ram.get());

    if (cassette_enable) {
        d->cassette.label = std::make_unique<ClickableLabel>();
        d->cassette.setEmpty(QString(cassette_fname).isEmpty());
        d->cassette.refresh();
        connect((ClickableLabel *) d->cassette.label.get(), &ClickableLabel::clicked, [](QPoint pos) {
            MediaMenu::ptr->cassetteMenu->popup(pos - QPoint(0, MediaMenu::ptr->cassetteMenu->sizeHint().height()));
        });
        connect((ClickableLabel *) d->cassette.label.get(), &ClickableLabel::dropped, [](QString str) {
            MediaMenu::ptr->cassetteMount(str, false);
        });
        d->cassette.label->setToolTip(MediaMenu::ptr->cassetteMenu->title());
        d->cassette.label->setAcceptDrops(true);
        sbar->addWidget(d->cassette.label.get());
    }

    if (machine_has_cartridge(machine)) {
        for (int i = 0; i < 2; ++i) {
            d->cartridge[i].label = std::make_unique<ClickableLabel>();
            d->cartridge[i].setEmpty(QString(cart_fns[i]).isEmpty());
            d->cartridge[i].refresh();
            connect((ClickableLabel *) d->cartridge[i].label.get(), &ClickableLabel::clicked, [i](QPoint pos) {
                MediaMenu::ptr->cartridgeMenus[i]->popup(pos - QPoint(0, MediaMenu::ptr->cartridgeMenus[i]->sizeHint().height()));
            });
            connect((ClickableLabel *) d->cartridge[i].label.get(), &ClickableLabel::dropped, [i](QString str) {
                MediaMenu::ptr->cartridgeMount(i, str);
            });
            d->cartridge[i].label->setToolTip(MediaMenu::ptr->cartridgeMenus[i]->title());
            d->cartridge[i].label->setAcceptDrops(true);
            sbar->addWidget(d->cartridge[i].label.get());
        }
    }

    iterateFDD([this, sbar](int i) {
        int t = fdd_get_type(i);
        if (t == 0) {
            d->fdd[i].pixmaps = &d->pixmaps.floppy_disabled;
        } else if (t >= 1 && t <= 6) {
            d->fdd[i].pixmaps = &d->pixmaps.floppy_525;
        } else {
            d->fdd[i].pixmaps = &d->pixmaps.floppy_35;
        }
        d->fdd[i].label = std::make_unique<ClickableLabel>();
        d->fdd[i].setEmpty(QString(floppyfns[i]).isEmpty());
        d->fdd[i].setActive(false);
        d->fdd[i].setWriteActive(false);
        d->fdd[i].refresh();
        connect((ClickableLabel *) d->fdd[i].label.get(), &ClickableLabel::clicked, [i](QPoint pos) {
            MediaMenu::ptr->floppyMenus[i]->popup(pos - QPoint(0, MediaMenu::ptr->floppyMenus[i]->sizeHint().height()));
        });
        connect((ClickableLabel *) d->fdd[i].label.get(), &ClickableLabel::dropped, [i](QString str) {
            MediaMenu::ptr->floppyMount(i, str, false);
        });
        d->fdd[i].label->setToolTip(MediaMenu::ptr->floppyMenus[i]->title());
        d->fdd[i].label->setAcceptDrops(true);
        sbar->addWidget(d->fdd[i].label.get());
    });

    iterateCDROM([this, sbar](int i) {
        d->cdrom[i].label = std::make_unique<ClickableLabel>();
        d->cdrom[i].setEmpty(QString(cdrom[i].image_path).isEmpty());
        d->cdrom[i].setActive(false);
        d->cdrom[i].setWriteActive(false);
        d->cdrom[i].refresh();
        connect((ClickableLabel *) d->cdrom[i].label.get(), &ClickableLabel::clicked, [i](QPoint pos) {
            MediaMenu::ptr->cdromMenus[i]->popup(pos - QPoint(0, MediaMenu::ptr->cdromMenus[i]->sizeHint().height()));
        });
        connect((ClickableLabel *) d->cdrom[i].label.get(), &ClickableLabel::dropped, [i](QString str) {
            MediaMenu::ptr->cdromMount(i, str);
        });
        d->cdrom[i].label->setToolTip(MediaMenu::ptr->cdromMenus[i]->title());
        d->cdrom[i].label->setAcceptDrops(true);
        sbar->addWidget(d->cdrom[i].label.get());
    });

    iterateZIP([this, sbar](int i) {
        d->zip[i].label = std::make_unique<ClickableLabel>();
        d->zip[i].setEmpty(QString(zip_drives[i].image_path).isEmpty());
        d->zip[i].setActive(false);
        d->zip[i].setWriteActive(false);
        d->zip[i].refresh();
        connect((ClickableLabel *) d->zip[i].label.get(), &ClickableLabel::clicked, [i](QPoint pos) {
            MediaMenu::ptr->zipMenus[i]->popup(pos - QPoint(0, MediaMenu::ptr->zipMenus[i]->sizeHint().height()));
        });
        connect((ClickableLabel *) d->zip[i].label.get(), &ClickableLabel::dropped, [i](QString str) {
            MediaMenu::ptr->zipMount(i, str, false);
        });
        d->zip[i].label->setToolTip(MediaMenu::ptr->zipMenus[i]->title());
        d->zip[i].label->setAcceptDrops(true);
        sbar->addWidget(d->zip[i].label.get());
    });

    iterateMO([this, sbar](int i) {
        d->mo[i].label = std::make_unique<ClickableLabel>();
        d->mo[i].setEmpty(QString(mo_drives[i].image_path).isEmpty());
        d->mo[i].setActive(false);
        d->mo[i].setWriteActive(false);
        d->mo[i].refresh();
        connect((ClickableLabel *) d->mo[i].label.get(), &ClickableLabel::clicked, [i](QPoint pos) {
            MediaMenu::ptr->moMenus[i]->popup(pos - QPoint(0, MediaMenu::ptr->moMenus[i]->sizeHint().height()));
        });
        connect((ClickableLabel *) d->mo[i].label.get(), &ClickableLabel::dropped, [i](QString str) {
            MediaMenu::ptr->moMount(i, str, false);
        });
        d->mo[i].label->setToolTip(MediaMenu::ptr->moMenus[i]->title());
        d->mo[i].label->setAcceptDrops(true);
        sbar->addWidget(d->mo[i].label.get());
    });

    iterateNIC([this, sbar](int i) {
        d->net[i].label = std::make_unique<ClickableLabel>();
        d->net[i].setEmpty(!network_is_connected(i));
        d->net[i].setActive(false);
        d->net[i].setWriteActive(false);
        d->net[i].refresh();
        d->net[i].label->setToolTip(MediaMenu::ptr->netMenus[i]->title());
        connect((ClickableLabel *) d->net[i].label.get(), &ClickableLabel::clicked, [i](QPoint pos) {
            MediaMenu::ptr->netMenus[i]->popup(pos - QPoint(0, MediaMenu::ptr->netMenus[i]->sizeHint().height()));
        });
        sbar->addWidget(d->net[i].label.get());
    });

    auto hdc_name = QString(hdc_get_internal_name(hdc_current[0]));
    if ((has_mfm || (hdc_name.left(5) == QStringLiteral("st506"))) && (c_mfm > 0)) {
        d->hdds[HDD_BUS_MFM].label = std::make_unique<QLabel>();
        d->hdds[HDD_BUS_MFM].setActive(false);
        d->hdds[HDD_BUS_MFM].setWriteActive(false);
        d->hdds[HDD_BUS_MFM].refresh();
        d->hdds[HDD_BUS_MFM].label->setToolTip(tr("Hard disk (%1)").arg("MFM/RLL"));
        auto tooltip = d->hdds[HDD_BUS_MFM].label->toolTip();
        tooltip.append("\n");
        for (int i = 0; i < HDD_NUM; i++) {
            if (hdd[i].bus_type == HDD_BUS_MFM && hdd[i].fn[0] != 0) {
                tooltip.append(QString("\n%5:%6: %1 (C:H:S = %2:%3:%4, %7 %8)").arg(QString::fromUtf8(hdd[i].fn), QString::number(hdd[i].tracks), QString::number(hdd[i].hpc), QString::number(hdd[i].spt), QString::number(hdd[i].channel >> 1), QString::number(hdd[i].channel & 1), QString::number((((qulonglong)hdd[i].hpc * (qulonglong)hdd[i].spt * (qulonglong)hdd[i].tracks) * 512ull) / 1048576ull), tr("MB")));
            }
        }
        d->hdds[HDD_BUS_MFM].label->setToolTip(tooltip);
        sbar->addWidget(d->hdds[HDD_BUS_MFM].label.get());
    }
    if ((has_esdi || (hdc_name.left(4) == QStringLiteral("esdi"))) && (c_esdi > 0)) {
        d->hdds[HDD_BUS_ESDI].label = std::make_unique<QLabel>();
        d->hdds[HDD_BUS_ESDI].setActive(false);
        d->hdds[HDD_BUS_ESDI].setWriteActive(false);
        d->hdds[HDD_BUS_ESDI].refresh();
        d->hdds[HDD_BUS_ESDI].label->setToolTip(tr("Hard disk (%1)").arg("ESDI"));
        auto tooltip = d->hdds[HDD_BUS_ESDI].label->toolTip();
        tooltip.append("\n");
        for (int i = 0; i < HDD_NUM; i++) {
            if (hdd[i].bus_type == HDD_BUS_ESDI && hdd[i].fn[0] != 0) {
                tooltip.append(QString("\n%5:%6: %1 (C:H:S = %2:%3:%4, %7 %8)").arg(QString::fromUtf8(hdd[i].fn), QString::number(hdd[i].tracks), QString::number(hdd[i].hpc), QString::number(hdd[i].spt), QString::number(hdd[i].channel >> 1), QString::number(hdd[i].channel & 1), QString::number((((qulonglong)hdd[i].hpc * (qulonglong)hdd[i].spt * (qulonglong)hdd[i].tracks) * 512ull) / 1048576ull), tr("MB")));
            }
        }
        d->hdds[HDD_BUS_ESDI].label->setToolTip(tooltip);
        sbar->addWidget(d->hdds[HDD_BUS_ESDI].label.get());
    }
    if ((has_xta || (hdc_name.left(3) == QStringLiteral("xta"))) && (c_xta > 0)) {
        d->hdds[HDD_BUS_XTA].label = std::make_unique<QLabel>();
        d->hdds[HDD_BUS_XTA].setActive(false);
        d->hdds[HDD_BUS_XTA].setWriteActive(false);
        d->hdds[HDD_BUS_XTA].refresh();
        d->hdds[HDD_BUS_XTA].label->setToolTip(tr("Hard disk (%1)").arg("XTA"));
        auto tooltip = d->hdds[HDD_BUS_XTA].label->toolTip();
        tooltip.append("\n");
        for (int i = 0; i < HDD_NUM; i++) {
            if (hdd[i].bus_type == HDD_BUS_XTA && hdd[i].fn[0] != 0) {
                tooltip.append(QString("\n%5:%6: %1 (C:H:S = %2:%3:%4, %7 %8)").arg(QString::fromUtf8(hdd[i].fn), QString::number(hdd[i].tracks), QString::number(hdd[i].hpc), QString::number(hdd[i].spt), QString::number(hdd[i].channel >> 1), QString::number(hdd[i].channel & 1), QString::number((((qulonglong)hdd[i].hpc * (qulonglong)hdd[i].spt * (qulonglong)hdd[i].tracks) * 512ull) / 1048576ull), tr("MB")));
            }
        }
        d->hdds[HDD_BUS_XTA].label->setToolTip(tooltip);
        sbar->addWidget(d->hdds[HDD_BUS_XTA].label.get());
    }
    if (hasIDE() || (hdc_name.left(5) == QStringLiteral("xtide")) ||
        (hdc_name.left(5) == QStringLiteral("mcide")) ||
        (hdc_name.left(3) == QStringLiteral("ide"))) {
        if (c_ide > 0) {
            d->hdds[HDD_BUS_IDE].label = std::make_unique<QLabel>();
            d->hdds[HDD_BUS_IDE].setActive(false);
            d->hdds[HDD_BUS_IDE].setWriteActive(false);
            d->hdds[HDD_BUS_IDE].refresh();
            d->hdds[HDD_BUS_IDE].label->setToolTip(tr("Hard disk (%1)").arg("IDE"));
            auto tooltip = d->hdds[HDD_BUS_IDE].label->toolTip();
            tooltip.append("\n");
            for (int i = 0; i < HDD_NUM; i++) {
                if (hdd[i].bus_type == HDD_BUS_IDE && hdd[i].fn[0] != 0) {
                    tooltip.append(QString("\n%5:%6: %1 (C:H:S = %2:%3:%4, %7 %8)").arg(QString::fromUtf8(hdd[i].fn), QString::number(hdd[i].tracks), QString::number(hdd[i].hpc), QString::number(hdd[i].spt), QString::number(hdd[i].channel >> 1), QString::number(hdd[i].channel & 1), QString::number((((qulonglong)hdd[i].hpc * (qulonglong)hdd[i].spt * (qulonglong)hdd[i].tracks) * 512ull) / 1048576ull), tr("MB")));
                }
            }
            d->hdds[HDD_BUS_IDE].label->setToolTip(tooltip);
            sbar->addWidget(d->hdds[HDD_BUS_IDE].label.get());
        }
        if (c_atapi > 0) {
            d->hdds[HDD_BUS_ATAPI].label = std::make_unique<QLabel>();
            d->hdds[HDD_BUS_ATAPI].setActive(false);
            d->hdds[HDD_BUS_ATAPI].setWriteActive(false);
            d->hdds[HDD_BUS_ATAPI].refresh();
            d->hdds[HDD_BUS_ATAPI].label->setToolTip(tr("Hard disk (%1)").arg("ATAPI"));
            auto tooltip = d->hdds[HDD_BUS_ATAPI].label->toolTip();
            tooltip.append("\n");
            for (int i = 0; i < HDD_NUM; i++) {
                if (hdd[i].bus_type == HDD_BUS_ATAPI && hdd[i].fn[0] != 0) {
                    tooltip.append(QString("\n%5:%6: %1 (C:H:S = %2:%3:%4, %7 %8)").arg(QString::fromUtf8(hdd[i].fn), QString::number(hdd[i].tracks), QString::number(hdd[i].hpc), QString::number(hdd[i].spt), QString::number(hdd[i].channel >> 1), QString::number(hdd[i].channel & 1), QString::number((((qulonglong)hdd[i].hpc * (qulonglong)hdd[i].spt * (qulonglong)hdd[i].tracks) * 512ull) / 1048576ull), tr("MB")));
                }
            }
            d->hdds[HDD_BUS_ATAPI].label->setToolTip(tooltip);
            sbar->addWidget(d->hdds[HDD_BUS_ATAPI].label.get());
        }
    }
    if ((hasSCSI() ||
        (scsi_card_current[0] != 0) || (scsi_card_current[1] != 0) ||
        (scsi_card_current[2] != 0) || (scsi_card_current[3] != 0)) &&
        (c_scsi > 0)) {
        d->hdds[HDD_BUS_SCSI].label = std::make_unique<QLabel>();
        d->hdds[HDD_BUS_SCSI].setActive(false);
        d->hdds[HDD_BUS_SCSI].setWriteActive(false);
        d->hdds[HDD_BUS_SCSI].refresh();
        d->hdds[HDD_BUS_SCSI].label->setToolTip(tr("Hard disk (%1)").arg("SCSI"));
        auto tooltip = d->hdds[HDD_BUS_SCSI].label->toolTip();
        tooltip.append("\n");
        for (int i = 0; i < HDD_NUM; i++) {
            if (hdd[i].bus_type == HDD_BUS_SCSI && hdd[i].fn[0] != 0) {
                tooltip.append(QString("\n%5:%6: %1 (C:H:S = %2:%3:%4, %7 %8)").arg(QString::fromUtf8(hdd[i].fn), QString::number(hdd[i].tracks), QString::number(hdd[i].hpc), QString::number(hdd[i].spt), QString::number(hdd[i].channel >> 4), QString::asprintf("%02d", hdd[i].channel & 15), QString::number((((qulonglong)hdd[i].hpc * (qulonglong)hdd[i].spt * (qulonglong)hdd[i].tracks) * 512ull) / 1048576ull), tr("MB")));
            }
        }
        d->hdds[HDD_BUS_SCSI].label->setToolTip(tooltip);
        sbar->addWidget(d->hdds[HDD_BUS_SCSI].label.get());
    }

    d->sound = std::make_unique<ClickableLabel>();
    d->sound->setPixmap(sound_muted ? d->pixmaps.sound.disabled : d->pixmaps.sound.normal);

    connect(d->sound.get(), &ClickableLabel::clicked, this, [this](QPoint pos) {
        this->soundMenu->popup(pos - QPoint(0, this->soundMenu->sizeHint().height()));
    });

    d->sound->setToolTip(tr("Sound"));
    sbar->addWidget(d->sound.get());

    d->speed = std::make_unique<QLabel>();
    double mhz = static_cast<double>(cpu_s->rspeed) / 1000000.0;
    d->speed->setText(QString::number(mhz, 'f', 2) + QLatin1String(" MHz"));
    sbar->addWidget(d->speed.get());

    d->ram = std::make_unique<QLabel>();
    if (mem_size < 1536) {
        d->ram->setText(QString::number(mem_size) + QLatin1String(" KB"));
    } else {
        d->ram->setText(QString::number(mem_size / 1024) + QLatin1String(" MB"));
    }
    sbar->addWidget(d->ram.get());

    d->hardwareWidget = std::make_unique<QWidget>();
    auto vlayout       = new QVBoxLayout(d->hardwareWidget.get());
    vlayout->setSpacing(0);
    vlayout->setContentsMargins(0, 0, 0, 0);

    d->hardware    = new QLabel(d->hardwareWidget.get());
    d->storage     = new QLabel(d->hardwareWidget.get());
    d->attachments = new QLabel(d->hardwareWidget.get());
    vlayout->addWidget(d->hardware);
    vlayout->addWidget(d->storage);
    vlayout->addWidget(d->attachments);

    d->hardware->setText(buildHardwareSummary());
    d->storage->setText(buildStorageSummary());
    d->attachments->setText(buildAttachmentSummary());
    sbar->addWidget(d->hardwareWidget.get());

    d->text = std::make_unique<QLabel>();
    sbar->addWidget(d->text.get());

    sbar_initialized = true;

    refreshEmptyIcons();
}

void
MachineStatus::updateSoundIcon()
{
    if (d->sound)
        d->sound->setPixmap(sound_muted ? d->pixmaps.sound.disabled : d->pixmaps.sound.normal);
}

void
MachineStatus::message(const QString &msg)
{
    d->text->setText(msg);
}

QString
MachineStatus::getMessage()
{
    return d->text->text();
}

void
MachineStatus::updateTip(int tag)
{
    int category = tag & 0xfffffff0;
    int item     = tag & 0xf;
    if (!MediaMenu::ptr)
        return;
    switch (category) {
        case SB_CASSETTE:
            if (d->cassette.label && MediaMenu::ptr->cassetteMenu)
                d->cassette.label->setToolTip(MediaMenu::ptr->cassetteMenu->title());
            break;
        case SB_CARTRIDGE:
            if (d->cartridge[item].label && MediaMenu::ptr->cartridgeMenus[item])
                d->cartridge[item].label->setToolTip(MediaMenu::ptr->cartridgeMenus[item]->title());
            break;
        case SB_FLOPPY:
            if (d->fdd[item].label && MediaMenu::ptr->floppyMenus[item])
                d->fdd[item].label->setToolTip(MediaMenu::ptr->floppyMenus[item]->title());
            break;
        case SB_CDROM:
            if (d->cdrom[item].label && MediaMenu::ptr->cdromMenus[item])
                d->cdrom[item].label->setToolTip(MediaMenu::ptr->cdromMenus[item]->title());
            break;
        case SB_ZIP:
            if (d->zip[item].label && MediaMenu::ptr->zipMenus[item])
                d->zip[item].label->setToolTip(MediaMenu::ptr->zipMenus[item]->title());
            break;
        case SB_MO:
            if (d->mo[item].label && MediaMenu::ptr->moMenus[item])
                d->mo[item].label->setToolTip(MediaMenu::ptr->moMenus[item]->title());
            break;
        case SB_HDD:
            break;
        case SB_NETWORK:
            break;
        case SB_SOUND:
            break;
        case SB_TEXT:
            break;
    }

    refreshEmptyIcons();
}

QString
MachineStatus::buildHardwareSummary()
{
    QStringList sections;

    QStringList videos;
    for (int i = 0; i < GFXCARD_MAX; ++i) {
        if (gfxcard[i] != VID_NONE) {
            const device_t *dev = video_card_getdevice(gfxcard[i]);
            videos << DeviceConfig::DeviceName(dev, video_get_internal_name(gfxcard[i]), 1);
        }
    }
    if (!videos.isEmpty())
        sections << tr("Video: %1").arg(videos.join(QLatin1String(", ")));

    QStringList sounds;
    for (int i = 0; i < SOUND_CARD_MAX; ++i) {
        if (sound_card_current[i] != SOUND_NONE) {
            const device_t *dev = sound_card_getdevice(sound_card_current[i]);
            sounds << DeviceConfig::DeviceName(dev, sound_card_get_internal_name(sound_card_current[i]), 1);
        }
    }
    if (!sounds.isEmpty())
        sections << tr("Sound: %1").arg(sounds.join(QLatin1String(", ")));


    QStringList disks;
    auto shortSize = [](qulonglong mb) {
        if (mb >= 1024ull * 1024ull)
            return QString::number(mb / (1024ull * 1024ull)) + QLatin1String("T");
        if (mb >= 1024ull)
            return QString::number(mb / 1024ull) + QLatin1String("G");
        return QString::number(mb) + QLatin1String("M");
    };
    for (int i = 0; i < HDD_NUM; ++i) {
        if (hdd[i].fn[0] != 0) {
            qulonglong mb = ((qulonglong)hdd[i].hpc * (qulonglong)hdd[i].spt * (qulonglong)hdd[i].tracks * 512ull) / 1048576ull;
            disks << QStringLiteral("HD%1:%2").arg(i).arg(shortSize(mb));
        }
    }
    if (!disks.isEmpty())
        sections << tr("Disks: %1").arg(disks.join(QLatin1String(" ")));

    return sections.join(QLatin1String(" | "));
}

QString
MachineStatus::buildStorageSummary()
{
    QStringList sections;

    QStringList storage;
    for (int i = 0; i < FDC_MAX; ++i) {
        if (fdc_current[i] != FDC_NONE)
            storage << DeviceConfig::DeviceName(fdc_card_getdevice(fdc_current[i]), fdc_card_get_internal_name(fdc_current[i]), 1);
    }
    for (int i = 0; i < HDC_MAX; ++i) {
        if (hdc_current[i] != HDC_NONE)
            storage << DeviceConfig::DeviceName(hdc_get_device(hdc_current[i]), hdc_get_internal_name(hdc_current[i]), 1);
    }
    for (int i = 0; i < SCSI_CARD_MAX; ++i) {
        if (scsi_card_current[i] != 0)
            storage << DeviceConfig::DeviceName(scsi_card_getdevice(scsi_card_current[i]), scsi_card_get_internal_name(scsi_card_current[i]), 1);
    }
    if (!storage.isEmpty())
        sections << tr("Storage: %1").arg(storage.join(QLatin1String(", ")));

    return sections.join(QLatin1String(" | "));
}

QString
MachineStatus::buildAttachmentSummary()
{
    QStringList sections;

    QStringList floppies;
    for (int i = 0; i < FDD_NUM; ++i) {
        if (floppyfns[i][0] != 0)
            floppies << QFileInfo(QString::fromUtf8(floppyfns[i])).fileName();
    }
    if (!floppies.isEmpty())
        sections << tr("Floppy: %1").arg(floppies.join(QLatin1String(", ")));

    QStringList disks;
    for (int i = 0; i < HDD_NUM; ++i) {
        if (hdd[i].fn[0] != 0)
            disks << QFileInfo(QString::fromUtf8(hdd[i].fn)).fileName();
    }
    if (!disks.isEmpty())
        sections << tr("Disk: %1").arg(disks.join(QLatin1String(", ")));

    QStringList cds;
    for (int i = 0; i < CDROM_NUM; ++i) {
        if (cdrom[i].image_path[0] != 0)
            cds << QFileInfo(QString::fromUtf8(cdrom[i].image_path)).fileName();
    }
    if (!cds.isEmpty())
        sections << tr("CD-ROM: %1").arg(cds.join(QLatin1String(", ")));

    return sections.join(QLatin1String(" | "));
}

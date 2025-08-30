/*
 * 86Box - Host shared folder settings page
 */
#include "qt_settingshostfs.hpp"
#include "ui_qt_settingshostfs.h"

extern "C" {
#include <86box/86box.h>
#include <86box/hdd.h>
}

#include <QFileInfo>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QIntValidator>
#include <QHeaderView>
#include <QMessageBox>
#include <cstdlib>

#include "qt_harddrive_common.hpp"
#include "qt_settings_bus_tracking.hpp"

SettingsHostFS::SettingsHostFS(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SettingsHostFS)
{
    ui->setupUi(this);

    // Setup table model
    auto *model = new QStandardItemModel(0, 3, this);
    model->setHeaderData(ColumnIndex, Qt::Horizontal, tr("Disk"));
    model->setHeaderData(ColumnFolder, Qt::Horizontal, tr("Folder"));
    model->setHeaderData(ColumnMiB, Qt::Horizontal, tr("MiB"));
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    // Populate combos
    auto *fsModel = ui->comboBoxFs->model();
    fsModel->insertRows(0, 4);
    fsModel->setData(fsModel->index(0, 0), tr("Auto")); fsModel->setData(fsModel->index(0, 0), 0, Qt::UserRole);
    fsModel->setData(fsModel->index(1, 0), tr("FAT12")); fsModel->setData(fsModel->index(1, 0), 12, Qt::UserRole);
    fsModel->setData(fsModel->index(2, 0), tr("FAT16")); fsModel->setData(fsModel->index(2, 0), 16, Qt::UserRole);
    fsModel->setData(fsModel->index(3, 0), tr("FAT32")); fsModel->setData(fsModel->index(3, 0), 32, Qt::UserRole);

    auto *osModel = ui->comboBoxOs->model();
    osModel->insertRows(0, 5);
    osModel->setData(osModel->index(0, 0), tr("Auto")); osModel->setData(osModel->index(0, 0), 0, Qt::UserRole);
    osModel->setData(osModel->index(1, 0), tr("MS-DOS 1–2.x")); osModel->setData(osModel->index(1, 0), 4, Qt::UserRole);
    osModel->setData(osModel->index(2, 0), tr("MS-DOS 3–6.x")); osModel->setData(osModel->index(2, 0), 1, Qt::UserRole);
    osModel->setData(osModel->index(3, 0), tr("Windows 95/98/ME")); osModel->setData(osModel->index(3, 0), 2, Qt::UserRole);
    osModel->setData(osModel->index(4, 0), tr("Windows NT/2000+")); osModel->setData(osModel->index(4, 0), 3, Qt::UserRole);

    auto *layoutModel = ui->comboBoxLayout->model();
    layoutModel->insertRows(0, 3);
    layoutModel->setData(layoutModel->index(0, 0), tr("Auto")); layoutModel->setData(layoutModel->index(0, 0), 0, Qt::UserRole);
    layoutModel->setData(layoutModel->index(1, 0), tr("Partitioned (MBR)")); layoutModel->setData(layoutModel->index(1, 0), 1, Qt::UserRole);
    layoutModel->setData(layoutModel->index(2, 0), tr("Superfloppy")); layoutModel->setData(layoutModel->index(2, 0), 2, Qt::UserRole);

    // Capacity field validation
    ui->lineEditCapacity->setValidator(new QIntValidator(1, 1920, this));

    // Populate Hard Disk Type combo
    populateHddTypeCombo();

    populate();

    connect(ui->tableView->selectionModel(), &QItemSelectionModel::currentRowChanged, this, &SettingsHostFS::onTableRowChanged);
    connect(ui->comboBoxFs, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsHostFS::on_fs_currentIndexChanged);
    connect(ui->comboBoxOs, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsHostFS::on_os_currentIndexChanged);
    connect(ui->comboBoxLayout, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsHostFS::on_layout_currentIndexChanged);
    connect(ui->lineEditCapacity, &QLineEdit::textChanged, this, &SettingsHostFS::on_capacity_textChanged);
    connect(ui->lineEditDevName,  &QLineEdit::textChanged, this, &SettingsHostFS::on_devname_textChanged);

    // Bus/channel selectors
    Harddrives::populateBuses(ui->comboBoxBus->model());
    // Default-select IDE if present and pre-populate channels so the dropdown isn't empty
    {
        auto *bm = ui->comboBoxBus->model();
        auto m   = bm->match(bm->index(0, 0), Qt::UserRole, (int)HDD_BUS_IDE);
        ui->comboBoxBus->setCurrentIndex(m.isEmpty() ? 0 : m.first().row());
        int busRole = ui->comboBoxBus->currentData().toInt();
        Harddrives::populateBusChannels(ui->comboBoxChannel->model(), busRole, Harddrives::busTrackClass);
    }
    connect(ui->comboBoxBus, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsHostFS::on_comboBoxBus_currentIndexChanged);
    connect(ui->comboBoxChannel, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsHostFS::on_comboBoxChannel_currentIndexChanged);
    connect(ui->comboBoxHddType, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsHostFS::on_hddtype_currentIndexChanged);

    // Toolbar buttons
    connect(ui->buttonBrowse, &QPushButton::clicked, this, &SettingsHostFS::on_buttonBrowse_clicked);
    connect(ui->buttonAdd, &QPushButton::clicked, this, &SettingsHostFS::on_buttonAdd_clicked);
    connect(ui->buttonRemove, &QPushButton::clicked, this, &SettingsHostFS::on_buttonRemove_clicked);
}

SettingsHostFS::~SettingsHostFS()
{
    delete ui;
}

void SettingsHostFS::populate()
{
    auto *model = qobject_cast<QStandardItemModel *>(ui->tableView->model());
    model->removeRows(0, model->rowCount());
    int row = 0;
    for (int i = 0; i < HDD_NUM; ++i) {
        if (hdd[i].bus_type == HDD_BUS_DISABLED) continue;
        QString fileName = QString::fromUtf8(hdd[i].fn);
        QFileInfo fi(fileName);
        if (!fi.isDir()) continue;

        model->insertRow(row);
        model->setData(model->index(row, ColumnIndex), tr("HDD %1").arg(i + 1));
        model->setData(model->index(row, ColumnFolder), fileName);
        uint32_t size_mb = hdd[i].shared_fake_size_mb ? hdd[i].shared_fake_size_mb : ((hdd[i].tracks * hdd[i].hpc * hdd[i].spt) >> 11);
        if (size_mb == 0) size_mb = 1920;
        if (size_mb > 1920) size_mb = 1920;
        model->setData(model->index(row, ColumnMiB), (int)size_mb);
        // Roles
        model->setData(model->index(row, ColumnIndex), i, DataHddIndex);
        model->setData(model->index(row, ColumnFolder), (int)hdd[i].shared_fs_type, DataFsType);
        model->setData(model->index(row, ColumnFolder), (int)hdd[i].shared_os_level, DataOsLevel);
        model->setData(model->index(row, ColumnFolder), (int)hdd[i].shared_layout, DataLayout);
        // Custom reported device name (override)
        if (hdd[i].override_model && hdd[i].override_model[0])
            model->setData(model->index(row, ColumnFolder), QString::fromUtf8(hdd[i].override_model), DataDevName);
        else
            model->setData(model->index(row, ColumnFolder), QString(), DataDevName);
        // Initial hard disk type from existing CHS, else Auto (-1)
        int typeIdx = -1;
        if (hdd[i].tracks && hdd[i].hpc && hdd[i].spt) {
            for (int t = 0; t < 127; ++t) {
                if (hdd_table[t][0] == hdd[i].tracks && hdd_table[t][1] == hdd[i].hpc && hdd_table[t][2] == hdd[i].spt) { typeIdx = t; break; }
            }
        }
        model->setData(model->index(row, ColumnFolder), typeIdx, DataHdType);
        row++;
    }
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setSectionResizeMode(ColumnFolder, QHeaderView::Stretch);

    // Select first row if any
    if (model->rowCount() > 0) {
        ui->tableView->selectRow(0);
        onTableRowChanged(model->index(0, 0));
    } else {
        ui->lineEditFolder->clear();
        ui->lineEditCapacity->clear();
    }
}

static void setComboByRoleValue(QComboBox *cb, int value)
{
    auto *m = cb->model();
    auto matches = m->match(m->index(0, 0), Qt::UserRole, value);
    cb->setCurrentIndex(matches.isEmpty() ? 0 : matches.first().row());
}

void SettingsHostFS::onTableRowChanged(const QModelIndex &current)
{
    if (!current.isValid()) return;
    auto *model = ui->tableView->model();
    int row = current.row();
    QString folder = model->index(row, ColumnFolder).data().toString();
    ui->lineEditFolder->setText(folder);
    ui->lineEditCapacity->setText(model->index(row, ColumnMiB).data().toString());
    ui->lineEditDevName->setText(model->index(row, ColumnFolder).data(DataDevName).toString());
    updateDevNameCounter();
    setComboByRoleValue(ui->comboBoxFs, model->index(row, ColumnFolder).data(DataFsType).toInt());
    setComboByRoleValue(ui->comboBoxOs, model->index(row, ColumnFolder).data(DataOsLevel).toInt());
    setComboByRoleValue(ui->comboBoxLayout, model->index(row, ColumnFolder).data(DataLayout).toInt());
    // HDD type: model role is -1 for Auto, else direct index; combo has Auto at row 0
    {
        int typeIdx = model->index(row, ColumnFolder).data(DataHdType).toInt();
        int comboRow = (typeIdx < 0) ? 0 : (typeIdx + 1);
        if (comboRow < 0) comboRow = 0;
        ui->comboBoxHddType->setCurrentIndex(comboRow);
        bool partitioned = (ui->comboBoxLayout->currentData(Qt::UserRole).toInt() == 1);
        ui->comboBoxHddType->setEnabled(partitioned);
    }

     int hidx = model->index(row, ColumnIndex).data(DataHddIndex).toInt();
     refreshBusAndChannelCombos(hidx);
}

void SettingsHostFS::on_fs_currentIndexChanged(int)
{
    auto idx = ui->tableView->selectionModel()->currentIndex();
    if (!idx.isValid()) return;
    auto *m = ui->tableView->model();
    m->setData(idx.sibling(idx.row(), ColumnFolder), ui->comboBoxFs->currentData(Qt::UserRole).toInt(), DataFsType);
}

void SettingsHostFS::on_os_currentIndexChanged(int)
{
    auto idx = ui->tableView->selectionModel()->currentIndex();
    if (!idx.isValid()) return;
    auto *m = ui->tableView->model();
    m->setData(idx.sibling(idx.row(), ColumnFolder), ui->comboBoxOs->currentData(Qt::UserRole).toInt(), DataOsLevel);
}

void SettingsHostFS::on_layout_currentIndexChanged(int)
{
    auto idx = ui->tableView->selectionModel()->currentIndex();
    if (!idx.isValid()) return;
    auto *m = ui->tableView->model();
    int layoutRole = ui->comboBoxLayout->currentData(Qt::UserRole).toInt();
    m->setData(idx.sibling(idx.row(), ColumnFolder), layoutRole, DataLayout);
    // Enable/disable HDD Type based on layout
    ui->comboBoxHddType->setEnabled(layoutRole == 1);
}

void SettingsHostFS::on_capacity_textChanged(const QString &text)
{
    auto idx = ui->tableView->selectionModel()->currentIndex();
    if (!idx.isValid()) return;
    bool ok = false; int val = text.toInt(&ok);
    if (ok) {
        ui->tableView->model()->setData(idx.sibling(idx.row(), ColumnMiB), val);
        // Auto-prefer FAT32 at >= 2048 MiB if user hasn't explicitly chosen another FS
        int curFs = ui->comboBoxFs->currentData(Qt::UserRole).toInt();
        if (val >= 2048 && (curFs == 0 || curFs == 16)) {
            // Set to FAT32
            auto *m = ui->comboBoxFs->model();
            auto mm = m->match(m->index(0,0), Qt::UserRole, 32);
            if (!mm.isEmpty()) ui->comboBoxFs->setCurrentIndex(mm.first().row());
        }
    }
}

void SettingsHostFS::on_devname_textChanged(const QString &text)
{
    auto idx = ui->tableView->selectionModel()->currentIndex();
    if (!idx.isValid()) return;
    ui->tableView->model()->setData(idx.sibling(idx.row(), ColumnFolder), text, DataDevName);
    updateDevNameCounter();
}

void SettingsHostFS::save()
{
    auto *model = ui->tableView->model();
    int rows = model->rowCount();
    for (int r = 0; r < rows; ++r) {
        int i = model->index(r, ColumnIndex).data(DataHddIndex).toInt();
        if (i < 0 || i >= HDD_NUM) continue;
        uint32_t cap = (uint32_t)model->index(r, ColumnMiB).data().toUInt();
        hdd[i].shared_fake_size_mb = cap;
        int fs = model->index(r, ColumnFolder).data(DataFsType).toInt();
        if (cap >= 2048 && (fs == 0 || fs == 16)) fs = 32; // prefer FAT32 automatically
        hdd[i].shared_fs_type      = (uint8_t)fs;
        hdd[i].shared_os_level     = (uint8_t)model->index(r, ColumnFolder).data(DataOsLevel).toInt();
        hdd[i].shared_layout       = (uint8_t)model->index(r, ColumnFolder).data(DataLayout).toInt();
        // Apply override device name if provided
        {
            QString dn = model->index(r, ColumnFolder).data(DataDevName).toString();
            if (!dn.isEmpty()) {
                QByteArray ba = dn.toUtf8();
                // Free previous override if any (allocated via strdup/qstrdup)
                if (hdd[i].override_model) free((void*)hdd[i].override_model);
                hdd[i].override_model = qstrdup(ba.constData());
            } else {
                if (hdd[i].override_model) { free((void*)hdd[i].override_model); hdd[i].override_model = NULL; }
            }
        }
        // Apply CHS geometry depending on layout and selected type
        int typeIdx = model->index(r, ColumnFolder).data(DataHdType).toInt();
        if (hdd[i].shared_layout == 1) {
            if (typeIdx >= 0 && typeIdx <= 126) {
                hdd[i].tracks = hdd_table[typeIdx][0];
                hdd[i].hpc    = hdd_table[typeIdx][1];
                hdd[i].spt    = hdd_table[typeIdx][2];
            } else {
                uint32_t c=0,h=0,s=0; hdd_image_calc_chs(&c,&h,&s, cap);
                hdd[i].tracks = c; hdd[i].hpc = h; hdd[i].spt = s;
            }
        } else {
            uint32_t c=0,h=0,s=0; hdd_image_calc_chs(&c,&h,&s, cap);
            hdd[i].tracks = c; hdd[i].hpc = h; hdd[i].spt = s;
        }
    }
}

void SettingsHostFS::on_buttonBrowse_clicked()
{
    auto idx = ui->tableView->selectionModel()->currentIndex();
    if (!idx.isValid()) return;
    QString dir = QFileDialog::getExistingDirectory(this, tr("Choose shared folder"));
    if (dir.isEmpty()) return;
    ui->lineEditFolder->setText(dir);
    // Write into HDD and model
    int hidx = ui->tableView->model()->index(idx.row(), ColumnIndex).data(DataHddIndex).toInt();
    if (hidx >= 0 && hidx < HDD_NUM) {
        strncpy(hdd[hidx].fn, dir.toUtf8().constData(), sizeof(hdd[hidx].fn) - 1);
    }
    ui->tableView->model()->setData(idx.siblingAtColumn(ColumnFolder), dir);
}

int SettingsHostFS::findFreeHddSlot() const
{
    for (int i = 0; i < HDD_NUM; ++i) {
        if (hdd[i].bus_type == HDD_BUS_DISABLED || hdd[i].fn[0] == '\0') {
            return i;
        }
    }
    return -1;
}

void SettingsHostFS::on_buttonAdd_clicked()
{
    // Select folder first
    QString dir = QFileDialog::getExistingDirectory(this, tr("Choose shared folder"));
    if (dir.isEmpty()) return;

    int slot = findFreeHddSlot();
    if (slot < 0) {
        QMessageBox::warning(this, tr("No free HDD slots"), tr("All hard disk slots are in use."));
        return;
    }

    // Default to IDE and next free channel
    uint8_t bus_ui = BUS_IDE;        // bus enum for UI tracking helper
    uint8_t bus_hw = HDD_BUS_IDE;    // actual hardware bus enum
    uint8_t channel = Harddrives::busTrackClass ? Harddrives::busTrackClass->next_free_ide_channel() : 0;
    if (channel == CHANNEL_NONE) channel = 0;

    memset(&hdd[slot], 0, sizeof(hard_disk_t));
    hdd[slot].bus_type = bus_hw;
    hdd[slot].channel  = channel;
    strncpy(hdd[slot].fn, dir.toUtf8().constData(), sizeof(hdd[slot].fn) - 1);
    hdd[slot].shared_fake_size_mb = 1920; // default

    if (Harddrives::busTrackClass) Harddrives::busTrackClass->device_track(TRACK_SET, DEV_HDD, bus_ui, channel);

    // Append to table
    auto *model = qobject_cast<QStandardItemModel *>(ui->tableView->model());
    int row = model->rowCount();
    model->insertRow(row);
    model->setData(model->index(row, ColumnIndex), tr("HDD %1").arg(slot + 1));
    model->setData(model->index(row, ColumnFolder), dir);
    model->setData(model->index(row, ColumnMiB), (int)hdd[slot].shared_fake_size_mb);
    model->setData(model->index(row, ColumnIndex), slot, DataHddIndex);
    model->setData(model->index(row, ColumnFolder), (int)hdd[slot].shared_fs_type, DataFsType);
    model->setData(model->index(row, ColumnFolder), (int)hdd[slot].shared_os_level, DataOsLevel);
    model->setData(model->index(row, ColumnFolder), (int)hdd[slot].shared_layout, DataLayout);
    model->setData(model->index(row, ColumnFolder), -1, DataHdType);

    ui->tableView->selectRow(row);
    onTableRowChanged(model->index(row, 0));
}

void SettingsHostFS::on_buttonRemove_clicked()
{
    auto idx = ui->tableView->selectionModel()->currentIndex();
    if (!idx.isValid()) return;
    int row = idx.row();
    int hidx = ui->tableView->model()->index(row, ColumnIndex).data(DataHddIndex).toInt();
    if (hidx >= 0 && hidx < HDD_NUM) {
        if (Harddrives::busTrackClass) Harddrives::busTrackClass->device_track(TRACK_CLEAR, DEV_HDD, hdd[hidx].bus_type, hdd[hidx].channel);
        memset(&hdd[hidx], 0, sizeof(hard_disk_t));
        hdd[hidx].bus_type = HDD_BUS_DISABLED;
    }
    qobject_cast<QStandardItemModel *>(ui->tableView->model())->removeRow(row);
    if (ui->tableView->model()->rowCount() > 0) ui->tableView->selectRow(0);
}

void SettingsHostFS::refreshBusAndChannelCombos(int hddIndex)
{
    if (hddIndex < 0 || hddIndex >= HDD_NUM) return;
    // Set bus combo
    auto *busModel = ui->comboBoxBus->model();
    // Find row where UserRole equals current bus
    auto matches = busModel->match(busModel->index(0,0), Qt::UserRole, (int)hdd[hddIndex].bus_type);
    if (!matches.isEmpty()) ui->comboBoxBus->setCurrentIndex(matches.first().row());
    // Populate channels for this bus and select
    Harddrives::populateBusChannels(ui->comboBoxChannel->model(), hdd[hddIndex].bus_type, Harddrives::busTrackClass);
    auto *chanModel = ui->comboBoxChannel->model();
    auto cm = chanModel->match(chanModel->index(0,0), Qt::UserRole, (int)hdd[hddIndex].channel);
    if (!cm.isEmpty()) ui->comboBoxChannel->setCurrentIndex(cm.first().row());
}

void SettingsHostFS::on_comboBoxBus_currentIndexChanged(int)
{
    // Always refresh visible channel list for the selected bus so the combo isn't empty
    int visBus = ui->comboBoxBus->currentData().toInt();
    Harddrives::populateBusChannels(ui->comboBoxChannel->model(), visBus, Harddrives::busTrackClass);

    auto idx = ui->tableView->selectionModel()->currentIndex();
    if (!idx.isValid()) return;
    int hidx = ui->tableView->model()->index(idx.row(), ColumnIndex).data(DataHddIndex).toInt();
    if (hidx < 0 || hidx >= HDD_NUM) return;

    // Untrack old
    if (Harddrives::busTrackClass) Harddrives::busTrackClass->device_track(TRACK_CLEAR, DEV_HDD, hdd[hidx].bus_type, hdd[hidx].channel);

    int newBusHw = ui->comboBoxBus->currentData().toInt(); // HDD_BUS_*
    hdd[hidx].bus_type = newBusHw;
    // Repopulate channels for bus and pick next free as default
    Harddrives::populateBusChannels(ui->comboBoxChannel->model(), newBusHw, Harddrives::busTrackClass);
    int defaultChan = 0;
    if (Harddrives::busTrackClass) {
        int busUi = BUS_IDE;
        switch (newBusHw) {
            case HDD_BUS_MFM:   busUi = BUS_MFM;  break;
            case HDD_BUS_ESDI:  busUi = BUS_ESDI; break;
            case HDD_BUS_XTA:   busUi = BUS_XTA;  break;
            case HDD_BUS_SCSI:  busUi = BUS_SCSI; break;
            case HDD_BUS_IDE:
            case HDD_BUS_ATAPI: busUi = BUS_IDE;  break;
            default: break;
        }
        switch (busUi) {
            case BUS_IDE:  defaultChan = Harddrives::busTrackClass->next_free_ide_channel(); break;
            case BUS_SCSI: defaultChan = Harddrives::busTrackClass->next_free_scsi_id(); break;
            case BUS_MFM:  defaultChan = Harddrives::busTrackClass->next_free_mfm_channel(); break;
            case BUS_ESDI: defaultChan = Harddrives::busTrackClass->next_free_esdi_channel(); break;
            case BUS_XTA:  defaultChan = Harddrives::busTrackClass->next_free_xta_channel(); break;
        }
        if (defaultChan == CHANNEL_NONE) defaultChan = 0;
    }
    auto *chanModel = ui->comboBoxChannel->model();
    auto cm = chanModel->match(chanModel->index(0,0), Qt::UserRole, defaultChan);
    ui->comboBoxChannel->setCurrentIndex(cm.isEmpty() ? 0 : cm.first().row());

    // Track new
    hdd[hidx].channel = ui->comboBoxChannel->currentData().toUInt();
    if (Harddrives::busTrackClass) Harddrives::busTrackClass->device_track(TRACK_SET, DEV_HDD, hdd[hidx].bus_type, hdd[hidx].channel);
    updateDevNameCounter();
}

void SettingsHostFS::on_comboBoxChannel_currentIndexChanged(int)
{
    auto idx = ui->tableView->selectionModel()->currentIndex();
    if (!idx.isValid()) return;
    int hidx = ui->tableView->model()->index(idx.row(), ColumnIndex).data(DataHddIndex).toInt();
    if (hidx < 0 || hidx >= HDD_NUM) return;
    // Update tracking: clear old, set new
    if (Harddrives::busTrackClass) Harddrives::busTrackClass->device_track(TRACK_CLEAR, DEV_HDD, hdd[hidx].bus_type, hdd[hidx].channel);
    hdd[hidx].channel = ui->comboBoxChannel->currentData().toUInt();
    if (Harddrives::busTrackClass) Harddrives::busTrackClass->device_track(TRACK_SET, DEV_HDD, hdd[hidx].bus_type, hdd[hidx].channel);
}

void SettingsHostFS::on_hddtype_currentIndexChanged(int)
{
    auto idx = ui->tableView->selectionModel()->currentIndex();
    if (!idx.isValid()) return;
    auto *m = ui->tableView->model();
    int comboIdx = ui->comboBoxHddType->currentIndex();
    int typeIdx = (comboIdx <= 0) ? -1 : (comboIdx - 1);
    m->setData(idx.sibling(idx.row(), ColumnFolder), typeIdx, DataHdType);
    if (typeIdx >= 0 && typeIdx <= 126) {
        uint64_t sectors = (uint64_t)hdd_table[typeIdx][0] * hdd_table[typeIdx][1] * hdd_table[typeIdx][2];
        uint32_t mb = (uint32_t)(sectors >> 11LL);
        ui->lineEditCapacity->setText(QString::number(mb));
    }
}

void SettingsHostFS::updateDevNameCounter()
{
    // Determine max length based on selected bus
    int busHw = ui->comboBoxBus->currentData().toInt();
    int maxLen = (busHw == HDD_BUS_SCSI) ? 16 : 40; // SCSI standard INQUIRY Product is 16 chars; IDE/ATAPI is 40
    ui->lineEditDevName->setMaxLength(maxLen);
    int curLen = ui->lineEditDevName->text().length();
    ui->labelDevNameCount->setText(QString::number(curLen) + "/" + QString::number(maxLen));
}

void SettingsHostFS::populateHddTypeCombo()
{
    auto *model = ui->comboBoxHddType->model();
    model->removeRows(0, model->rowCount());
    // Auto first
    model->insertRow(0);
    model->setData(model->index(0, 0), tr("Auto (based on capacity)"));
    model->setData(model->index(0, 0), -1, Qt::UserRole);
    int row = 1;
    for (int i = 0; i < 127; ++i, ++row) {
        uint64_t size    = ((uint64_t) hdd_table[i][0]) * hdd_table[i][1] * hdd_table[i][2];
        uint32_t size_mb = (uint32_t)(size >> 11LL);
        QString text = tr("%1 MB (CHS: %2, %3, %4)").arg(size_mb).arg(hdd_table[i][0]).arg(hdd_table[i][1]).arg(hdd_table[i][2]);
        model->insertRow(row);
        model->setData(model->index(row, 0), text);
        model->setData(model->index(row, 0), i, Qt::UserRole);
    }
    model->insertRow(row);
    model->setData(model->index(row, 0), tr("Custom..."));
    model->setData(model->index(row, 0), 127, Qt::UserRole);
    ++row;
    model->insertRow(row);
    model->setData(model->index(row, 0), tr("Custom (large)..."));
    model->setData(model->index(row, 0), 128, Qt::UserRole);
}

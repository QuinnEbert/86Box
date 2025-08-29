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
#include <QStandardItemModel>
#include <QIntValidator>
#include <QHeaderView>

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

    populate();

    connect(ui->tableView->selectionModel(), &QItemSelectionModel::currentRowChanged, this, &SettingsHostFS::onTableRowChanged);
    connect(ui->comboBoxFs, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsHostFS::on_fs_currentIndexChanged);
    connect(ui->comboBoxOs, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsHostFS::on_os_currentIndexChanged);
    connect(ui->comboBoxLayout, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SettingsHostFS::on_layout_currentIndexChanged);
    connect(ui->lineEditCapacity, &QLineEdit::textChanged, this, &SettingsHostFS::on_capacity_textChanged);
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
    setComboByRoleValue(ui->comboBoxFs, model->index(row, ColumnFolder).data(DataFsType).toInt());
    setComboByRoleValue(ui->comboBoxOs, model->index(row, ColumnFolder).data(DataOsLevel).toInt());
    setComboByRoleValue(ui->comboBoxLayout, model->index(row, ColumnFolder).data(DataLayout).toInt());
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
    m->setData(idx.sibling(idx.row(), ColumnFolder), ui->comboBoxLayout->currentData(Qt::UserRole).toInt(), DataLayout);
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
    }
}

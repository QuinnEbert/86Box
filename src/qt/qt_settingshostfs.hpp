#ifndef QT_SETTINGSHOSTFS_HPP
#define QT_SETTINGSHOSTFS_HPP

#include <QWidget>
#include <QModelIndex>

namespace Ui { class SettingsHostFS; }

class SettingsHostFS : public QWidget {
    Q_OBJECT

public:
    explicit SettingsHostFS(QWidget *parent = nullptr);
    ~SettingsHostFS();

    void save();

private slots:
    void onTableRowChanged(const QModelIndex &current);
    void on_fs_currentIndexChanged(int index);
    void on_os_currentIndexChanged(int index);
    void on_layout_currentIndexChanged(int index);
    void on_capacity_textChanged(const QString &text);
    void on_buttonBrowse_clicked();
    void on_buttonAdd_clicked();
    void on_buttonRemove_clicked();
    void on_comboBoxBus_currentIndexChanged(int index);
    void on_comboBoxChannel_currentIndexChanged(int index);

private:
    enum Columns { ColumnIndex = 0, ColumnFolder = 1, ColumnMiB = 2 };
    enum Roles { DataHddIndex = Qt::UserRole, DataFsType = Qt::UserRole + 1, DataOsLevel = Qt::UserRole + 2, DataLayout = Qt::UserRole + 3 };

    Ui::SettingsHostFS *ui;
    void populate();
    void refreshBusAndChannelCombos(int hddIndex);
    int  findFreeHddSlot() const;
};

#endif // QT_SETTINGSHOSTFS_HPP

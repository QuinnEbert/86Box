#ifndef QT_HARDDISKDIALOG_HPP
#define QT_HARDDISKDIALOG_HPP

#include <QDialog>
#include <QComboBox>
#include <QLabel>

namespace Ui {
class HarddiskDialog;
}

class HarddiskDialog : public QDialog {
    Q_OBJECT

public:
    explicit HarddiskDialog(bool existing, QWidget *parent = nullptr);
    ~HarddiskDialog();

    uint8_t  bus() const;
    uint8_t  channel() const;
    QString  fileName() const;
    uint32_t cylinders() const { return cylinders_; }
    uint32_t heads() const { return heads_; }
    uint32_t sectors() const { return sectors_; }
    uint32_t speed() const;
    int      fsType() const { return comboBoxFS ? comboBoxFS->currentData().toInt() : 0; }
    int      osLevel() const { return comboBoxOS ? comboBoxOS->currentData().toInt() : 0; }
    int      layoutMode() const { return comboBoxLayout ? comboBoxLayout->currentData().toInt() : 0; }

signals:
    void fileProgress(int i);

public slots:
    void accept() override;

private slots:
    void on_comboBoxType_currentIndexChanged(int index);
    void on_lineEditSectors_textEdited(const QString &arg1);
    void on_lineEditHeads_textEdited(const QString &arg1);
    void on_lineEditCylinders_textEdited(const QString &arg1);
    void on_lineEditSize_textEdited(const QString &arg1);
    void on_comboBoxBus_currentIndexChanged(int index);
    void on_comboBoxFormat_currentIndexChanged(int index);
    void onCreateNewFile();
    void onExistingFileSelected(const QString &fileName, bool precheck);

private:
    Ui::HarddiskDialog *ui;

    uint32_t cylinders_;
    uint32_t heads_;
    uint32_t sectors_;

    uint32_t max_sectors   = 0;
    uint32_t max_heads     = 0;
    uint32_t max_cylinders = 0;

    bool disallowSizeModifications = false;

    QStringList filters;
    // "Dynamic-size VHD" is number 4 in the `filters` list and the
    // comboBoxFormat model
    const uint8_t DEFAULT_DISK_FORMAT = 4;

    bool checkAndAdjustCylinders();
    bool checkAndAdjustHeads();
    bool checkAndAdjustSectors();
    void recalcSize();
    void recalcSelection();

    // For host folder VFS
    QComboBox *comboBoxFS = nullptr; // Filesystem: Auto/FAT16/FAT32
    QLabel    *labelFS    = nullptr;
    QComboBox *comboBoxOS = nullptr; // OS Level selector
    QLabel    *labelOS    = nullptr;
    QComboBox *comboBoxLayout = nullptr; // Layout selector
    QLabel    *labelLayout    = nullptr;
};

typedef struct _86BoxGeom {
    uint32_t cyl;
    uint32_t heads;
    uint32_t spt;
} _86BoxGeom;

#endif // QT_HARDDISKDIALOG_HPP

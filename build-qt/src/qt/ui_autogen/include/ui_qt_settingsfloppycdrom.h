/********************************************************************************
** Form generated from reading UI file 'qt_settingsfloppycdrom.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SETTINGSFLOPPYCDROM_H
#define UI_QT_SETTINGSFLOPPYCDROM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsFloppyCDROM
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelFloppy;
    QTableView *tableViewFloppy;
    QWidget *floppyControls;
    QHBoxLayout *horizontalLayout;
    QLabel *labelFloppyType;
    QComboBox *comboBoxFloppyType;
    QCheckBox *checkBoxTurboTimings;
    QCheckBox *checkBoxCheckBPB;
    QLabel *labelCDROM;
    QTableView *tableViewCDROM;
    QWidget *cdControls;
    QGridLayout *gridLayout;
    QLabel *labelBus;
    QComboBox *comboBoxBus;
    QLabel *labelChannel;
    QComboBox *comboBoxChannel;
    QLabel *labelSpeed;
    QComboBox *comboBoxSpeed;
    QLabel *labelCDROMType;
    QComboBox *comboBoxCDROMType;

    void setupUi(QWidget *SettingsFloppyCDROM)
    {
        if (SettingsFloppyCDROM->objectName().isEmpty())
            SettingsFloppyCDROM->setObjectName("SettingsFloppyCDROM");
        SettingsFloppyCDROM->resize(544, 363);
        verticalLayout = new QVBoxLayout(SettingsFloppyCDROM);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelFloppy = new QLabel(SettingsFloppyCDROM);
        labelFloppy->setObjectName("labelFloppy");

        verticalLayout->addWidget(labelFloppy);

        tableViewFloppy = new QTableView(SettingsFloppyCDROM);
        tableViewFloppy->setObjectName("tableViewFloppy");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableViewFloppy->sizePolicy().hasHeightForWidth());
        tableViewFloppy->setSizePolicy(sizePolicy);
        tableViewFloppy->setMaximumSize(QSize(16777215, 150));
        tableViewFloppy->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableViewFloppy->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewFloppy->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewFloppy->setShowGrid(false);
        tableViewFloppy->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableViewFloppy);

        floppyControls = new QWidget(SettingsFloppyCDROM);
        floppyControls->setObjectName("floppyControls");
        horizontalLayout = new QHBoxLayout(floppyControls);
        horizontalLayout->setObjectName("horizontalLayout");
        labelFloppyType = new QLabel(floppyControls);
        labelFloppyType->setObjectName("labelFloppyType");

        horizontalLayout->addWidget(labelFloppyType);

        comboBoxFloppyType = new QComboBox(floppyControls);
        comboBoxFloppyType->setObjectName("comboBoxFloppyType");
        comboBoxFloppyType->setMaxVisibleItems(30);

        horizontalLayout->addWidget(comboBoxFloppyType);

        checkBoxTurboTimings = new QCheckBox(floppyControls);
        checkBoxTurboTimings->setObjectName("checkBoxTurboTimings");

        horizontalLayout->addWidget(checkBoxTurboTimings);

        checkBoxCheckBPB = new QCheckBox(floppyControls);
        checkBoxCheckBPB->setObjectName("checkBoxCheckBPB");

        horizontalLayout->addWidget(checkBoxCheckBPB);


        verticalLayout->addWidget(floppyControls);

        labelCDROM = new QLabel(SettingsFloppyCDROM);
        labelCDROM->setObjectName("labelCDROM");

        verticalLayout->addWidget(labelCDROM);

        tableViewCDROM = new QTableView(SettingsFloppyCDROM);
        tableViewCDROM->setObjectName("tableViewCDROM");
        sizePolicy.setHeightForWidth(tableViewCDROM->sizePolicy().hasHeightForWidth());
        tableViewCDROM->setSizePolicy(sizePolicy);
        tableViewCDROM->setMaximumSize(QSize(16777215, 150));
        tableViewCDROM->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableViewCDROM->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewCDROM->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewCDROM->setShowGrid(false);
        tableViewCDROM->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableViewCDROM);

        cdControls = new QWidget(SettingsFloppyCDROM);
        cdControls->setObjectName("cdControls");
        gridLayout = new QGridLayout(cdControls);
        gridLayout->setObjectName("gridLayout");
        labelBus = new QLabel(cdControls);
        labelBus->setObjectName("labelBus");

        gridLayout->addWidget(labelBus, 0, 0, 1, 1);

        comboBoxBus = new QComboBox(cdControls);
        comboBoxBus->setObjectName("comboBoxBus");
        comboBoxBus->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxBus, 0, 1, 1, 1);

        labelChannel = new QLabel(cdControls);
        labelChannel->setObjectName("labelChannel");

        gridLayout->addWidget(labelChannel, 0, 2, 1, 1);

        comboBoxChannel = new QComboBox(cdControls);
        comboBoxChannel->setObjectName("comboBoxChannel");
        comboBoxChannel->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxChannel, 0, 3, 1, 1);

        labelSpeed = new QLabel(cdControls);
        labelSpeed->setObjectName("labelSpeed");

        gridLayout->addWidget(labelSpeed, 1, 0, 1, 1);

        comboBoxSpeed = new QComboBox(cdControls);
        comboBoxSpeed->setObjectName("comboBoxSpeed");
        comboBoxSpeed->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxSpeed, 1, 1, 1, 1);

        labelCDROMType = new QLabel(cdControls);
        labelCDROMType->setObjectName("labelCDROMType");

        gridLayout->addWidget(labelCDROMType, 2, 0, 1, 1);

        comboBoxCDROMType = new QComboBox(cdControls);
        comboBoxCDROMType->setObjectName("comboBoxCDROMType");
        comboBoxCDROMType->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxCDROMType, 2, 1, 1, 3);


        verticalLayout->addWidget(cdControls);

        QWidget::setTabOrder(tableViewFloppy, comboBoxFloppyType);
        QWidget::setTabOrder(comboBoxFloppyType, checkBoxTurboTimings);
        QWidget::setTabOrder(checkBoxTurboTimings, checkBoxCheckBPB);
        QWidget::setTabOrder(checkBoxCheckBPB, tableViewCDROM);
        QWidget::setTabOrder(tableViewCDROM, comboBoxBus);
        QWidget::setTabOrder(comboBoxBus, comboBoxChannel);
        QWidget::setTabOrder(comboBoxChannel, comboBoxSpeed);
        QWidget::setTabOrder(comboBoxSpeed, comboBoxCDROMType);

        retranslateUi(SettingsFloppyCDROM);

        QMetaObject::connectSlotsByName(SettingsFloppyCDROM);
    } // setupUi

    void retranslateUi(QWidget *SettingsFloppyCDROM)
    {
        SettingsFloppyCDROM->setWindowTitle(QCoreApplication::translate("SettingsFloppyCDROM", "Form", nullptr));
        labelFloppy->setText(QCoreApplication::translate("SettingsFloppyCDROM", "Floppy drives:", nullptr));
        labelFloppyType->setText(QCoreApplication::translate("SettingsFloppyCDROM", "Type:", nullptr));
        checkBoxTurboTimings->setText(QCoreApplication::translate("SettingsFloppyCDROM", "Turbo timings", nullptr));
        checkBoxCheckBPB->setText(QCoreApplication::translate("SettingsFloppyCDROM", "Check BPB", nullptr));
        labelCDROM->setText(QCoreApplication::translate("SettingsFloppyCDROM", "CD-ROM drives:", nullptr));
        labelBus->setText(QCoreApplication::translate("SettingsFloppyCDROM", "Bus:", nullptr));
        labelChannel->setText(QCoreApplication::translate("SettingsFloppyCDROM", "Channel:", nullptr));
        labelSpeed->setText(QCoreApplication::translate("SettingsFloppyCDROM", "Speed:", nullptr));
        labelCDROMType->setText(QCoreApplication::translate("SettingsFloppyCDROM", "Type:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsFloppyCDROM: public Ui_SettingsFloppyCDROM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SETTINGSFLOPPYCDROM_H

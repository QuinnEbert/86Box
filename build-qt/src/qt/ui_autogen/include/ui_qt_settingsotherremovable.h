/********************************************************************************
** Form generated from reading UI file 'qt_settingsotherremovable.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SETTINGSOTHERREMOVABLE_H
#define UI_QT_SETTINGSOTHERREMOVABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsOtherRemovable
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelMO;
    QTableView *tableViewMO;
    QWidget *moControls;
    QGridLayout *gridLayout;
    QLabel *labelMOBus;
    QComboBox *comboBoxMOBus;
    QLabel *labelMOChannel;
    QComboBox *comboBoxMOChannel;
    QLabel *labelMOType;
    QComboBox *comboBoxMOType;
    QLabel *labelRDisk;
    QTableView *tableViewRDisk;
    QWidget *rdiskControls;
    QGridLayout *gridLayout_2;
    QLabel *labelRDiskBus;
    QComboBox *comboBoxRDiskBus;
    QLabel *labelRDiskChannel;
    QComboBox *comboBoxRDiskChannel;
    QLabel *labelRDiskType;
    QComboBox *comboBoxRDiskType;

    void setupUi(QWidget *SettingsOtherRemovable)
    {
        if (SettingsOtherRemovable->objectName().isEmpty())
            SettingsOtherRemovable->setObjectName("SettingsOtherRemovable");
        SettingsOtherRemovable->resize(418, 368);
        verticalLayout = new QVBoxLayout(SettingsOtherRemovable);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelMO = new QLabel(SettingsOtherRemovable);
        labelMO->setObjectName("labelMO");

        verticalLayout->addWidget(labelMO);

        tableViewMO = new QTableView(SettingsOtherRemovable);
        tableViewMO->setObjectName("tableViewMO");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableViewMO->sizePolicy().hasHeightForWidth());
        tableViewMO->setSizePolicy(sizePolicy);
        tableViewMO->setMaximumSize(QSize(16777215, 150));
        tableViewMO->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableViewMO->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewMO->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewMO->setShowGrid(false);
        tableViewMO->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableViewMO);

        moControls = new QWidget(SettingsOtherRemovable);
        moControls->setObjectName("moControls");
        gridLayout = new QGridLayout(moControls);
        gridLayout->setObjectName("gridLayout");
        labelMOBus = new QLabel(moControls);
        labelMOBus->setObjectName("labelMOBus");

        gridLayout->addWidget(labelMOBus, 0, 0, 1, 1);

        comboBoxMOBus = new QComboBox(moControls);
        comboBoxMOBus->setObjectName("comboBoxMOBus");
        comboBoxMOBus->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxMOBus, 0, 1, 1, 1);

        labelMOChannel = new QLabel(moControls);
        labelMOChannel->setObjectName("labelMOChannel");

        gridLayout->addWidget(labelMOChannel, 0, 2, 1, 1);

        comboBoxMOChannel = new QComboBox(moControls);
        comboBoxMOChannel->setObjectName("comboBoxMOChannel");
        comboBoxMOChannel->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxMOChannel, 0, 3, 1, 1);

        labelMOType = new QLabel(moControls);
        labelMOType->setObjectName("labelMOType");

        gridLayout->addWidget(labelMOType, 1, 0, 1, 1);

        comboBoxMOType = new QComboBox(moControls);
        comboBoxMOType->setObjectName("comboBoxMOType");
        comboBoxMOType->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxMOType, 1, 1, 1, 3);


        verticalLayout->addWidget(moControls);

        labelRDisk = new QLabel(SettingsOtherRemovable);
        labelRDisk->setObjectName("labelRDisk");

        verticalLayout->addWidget(labelRDisk);

        tableViewRDisk = new QTableView(SettingsOtherRemovable);
        tableViewRDisk->setObjectName("tableViewRDisk");
        sizePolicy.setHeightForWidth(tableViewRDisk->sizePolicy().hasHeightForWidth());
        tableViewRDisk->setSizePolicy(sizePolicy);
        tableViewRDisk->setMaximumSize(QSize(16777215, 150));
        tableViewRDisk->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableViewRDisk->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewRDisk->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewRDisk->setShowGrid(false);
        tableViewRDisk->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableViewRDisk);

        rdiskControls = new QWidget(SettingsOtherRemovable);
        rdiskControls->setObjectName("rdiskControls");
        gridLayout_2 = new QGridLayout(rdiskControls);
        gridLayout_2->setObjectName("gridLayout_2");
        labelRDiskBus = new QLabel(rdiskControls);
        labelRDiskBus->setObjectName("labelRDiskBus");

        gridLayout_2->addWidget(labelRDiskBus, 0, 0, 1, 1);

        comboBoxRDiskBus = new QComboBox(rdiskControls);
        comboBoxRDiskBus->setObjectName("comboBoxRDiskBus");
        comboBoxRDiskBus->setMaxVisibleItems(30);

        gridLayout_2->addWidget(comboBoxRDiskBus, 0, 1, 1, 1);

        labelRDiskChannel = new QLabel(rdiskControls);
        labelRDiskChannel->setObjectName("labelRDiskChannel");

        gridLayout_2->addWidget(labelRDiskChannel, 0, 2, 1, 1);

        comboBoxRDiskChannel = new QComboBox(rdiskControls);
        comboBoxRDiskChannel->setObjectName("comboBoxRDiskChannel");
        comboBoxRDiskChannel->setMaxVisibleItems(30);

        gridLayout_2->addWidget(comboBoxRDiskChannel, 0, 3, 1, 1);

        labelRDiskType = new QLabel(rdiskControls);
        labelRDiskType->setObjectName("labelRDiskType");

        gridLayout_2->addWidget(labelRDiskType, 1, 0, 1, 1);

        comboBoxRDiskType = new QComboBox(rdiskControls);
        comboBoxRDiskType->setObjectName("comboBoxRDiskType");
        comboBoxRDiskType->setMaxVisibleItems(30);

        gridLayout_2->addWidget(comboBoxRDiskType, 1, 1, 1, 3);


        verticalLayout->addWidget(rdiskControls);

        QWidget::setTabOrder(tableViewMO, comboBoxMOBus);
        QWidget::setTabOrder(comboBoxMOBus, comboBoxMOChannel);
        QWidget::setTabOrder(comboBoxMOChannel, comboBoxMOType);
        QWidget::setTabOrder(comboBoxMOType, tableViewRDisk);
        QWidget::setTabOrder(tableViewRDisk, comboBoxRDiskBus);
        QWidget::setTabOrder(comboBoxRDiskBus, comboBoxRDiskChannel);
        QWidget::setTabOrder(comboBoxRDiskChannel, comboBoxRDiskType);

        retranslateUi(SettingsOtherRemovable);

        QMetaObject::connectSlotsByName(SettingsOtherRemovable);
    } // setupUi

    void retranslateUi(QWidget *SettingsOtherRemovable)
    {
        SettingsOtherRemovable->setWindowTitle(QCoreApplication::translate("SettingsOtherRemovable", "Form", nullptr));
        labelMO->setText(QCoreApplication::translate("SettingsOtherRemovable", "MO drives:", nullptr));
        labelMOBus->setText(QCoreApplication::translate("SettingsOtherRemovable", "Bus:", nullptr));
        labelMOChannel->setText(QCoreApplication::translate("SettingsOtherRemovable", "Channel:", nullptr));
        labelMOType->setText(QCoreApplication::translate("SettingsOtherRemovable", "Type:", nullptr));
        labelRDisk->setText(QCoreApplication::translate("SettingsOtherRemovable", "Removable disk drives:", nullptr));
        labelRDiskBus->setText(QCoreApplication::translate("SettingsOtherRemovable", "Bus:", nullptr));
        labelRDiskChannel->setText(QCoreApplication::translate("SettingsOtherRemovable", "Channel:", nullptr));
        labelRDiskType->setText(QCoreApplication::translate("SettingsOtherRemovable", "Type:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsOtherRemovable: public Ui_SettingsOtherRemovable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SETTINGSOTHERREMOVABLE_H

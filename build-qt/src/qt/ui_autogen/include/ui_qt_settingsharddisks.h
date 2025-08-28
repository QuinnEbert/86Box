/********************************************************************************
** Form generated from reading UI file 'qt_settingsharddisks.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SETTINGSHARDDISKS_H
#define UI_QT_SETTINGSHARDDISKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsHarddisks
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QWidget *hdControls;
    QGridLayout *gridLayout;
    QLabel *labelBus;
    QComboBox *comboBoxBus;
    QLabel *labelChannel;
    QComboBox *comboBoxChannel;
    QLabel *labelSpeed;
    QComboBox *comboBoxSpeed;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonNew;
    QPushButton *pushButtonExisting;
    QPushButton *pushButtonRemove;

    void setupUi(QWidget *SettingsHarddisks)
    {
        if (SettingsHarddisks->objectName().isEmpty())
            SettingsHarddisks->setObjectName("SettingsHarddisks");
        SettingsHarddisks->resize(400, 300);
        verticalLayout = new QVBoxLayout(SettingsHarddisks);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(SettingsHarddisks);
        tableView->setObjectName("tableView");
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setShowGrid(false);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);

        hdControls = new QWidget(SettingsHarddisks);
        hdControls->setObjectName("hdControls");
        gridLayout = new QGridLayout(hdControls);
        gridLayout->setObjectName("gridLayout");
        labelBus = new QLabel(hdControls);
        labelBus->setObjectName("labelBus");

        gridLayout->addWidget(labelBus, 0, 0, 1, 1);

        comboBoxBus = new QComboBox(hdControls);
        comboBoxBus->setObjectName("comboBoxBus");
        comboBoxBus->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxBus, 0, 1, 1, 1);

        labelChannel = new QLabel(hdControls);
        labelChannel->setObjectName("labelChannel");

        gridLayout->addWidget(labelChannel, 0, 2, 1, 1);

        comboBoxChannel = new QComboBox(hdControls);
        comboBoxChannel->setObjectName("comboBoxChannel");
        comboBoxChannel->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxChannel, 0, 3, 1, 1);

        labelSpeed = new QLabel(hdControls);
        labelSpeed->setObjectName("labelSpeed");

        gridLayout->addWidget(labelSpeed, 1, 0, 1, 1);

        comboBoxSpeed = new QComboBox(hdControls);
        comboBoxSpeed->setObjectName("comboBoxSpeed");
        comboBoxSpeed->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxSpeed, 1, 1, 1, 1);


        verticalLayout->addWidget(hdControls);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonNew = new QPushButton(SettingsHarddisks);
        pushButtonNew->setObjectName("pushButtonNew");

        horizontalLayout->addWidget(pushButtonNew);

        pushButtonExisting = new QPushButton(SettingsHarddisks);
        pushButtonExisting->setObjectName("pushButtonExisting");

        horizontalLayout->addWidget(pushButtonExisting);

        pushButtonRemove = new QPushButton(SettingsHarddisks);
        pushButtonRemove->setObjectName("pushButtonRemove");

        horizontalLayout->addWidget(pushButtonRemove);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SettingsHarddisks);

        QMetaObject::connectSlotsByName(SettingsHarddisks);
    } // setupUi

    void retranslateUi(QWidget *SettingsHarddisks)
    {
        SettingsHarddisks->setWindowTitle(QCoreApplication::translate("SettingsHarddisks", "Form", nullptr));
        labelBus->setText(QCoreApplication::translate("SettingsHarddisks", "Bus:", nullptr));
        labelChannel->setText(QCoreApplication::translate("SettingsHarddisks", "Channel:", nullptr));
        labelSpeed->setText(QCoreApplication::translate("SettingsHarddisks", "Model:", nullptr));
        pushButtonNew->setText(QCoreApplication::translate("SettingsHarddisks", "&New...", nullptr));
        pushButtonExisting->setText(QCoreApplication::translate("SettingsHarddisks", "&Existing...", nullptr));
        pushButtonRemove->setText(QCoreApplication::translate("SettingsHarddisks", "&Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsHarddisks: public Ui_SettingsHarddisks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SETTINGSHARDDISKS_H

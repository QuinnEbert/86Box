/********************************************************************************
** Form generated from reading UI file 'qt_settingsports.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SETTINGSPORTS_H
#define UI_QT_SETTINGSPORTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsPorts
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayoutLptECPDMA;
    QLabel *labelLptECPDMA;
    QComboBox *comboBoxLptECPDMA;
    QLabel *labelLpt1;
    QComboBox *comboBoxLpt1;
    QPushButton *pushButtonConfigureLpt1;
    QLabel *labelLpt2;
    QComboBox *comboBoxLpt2;
    QPushButton *pushButtonConfigureLpt2;
    QLabel *labelLpt3;
    QComboBox *comboBoxLpt3;
    QPushButton *pushButtonConfigureLpt3;
    QLabel *labelLpt4;
    QComboBox *comboBoxLpt4;
    QPushButton *pushButtonConfigureLpt4;
    QGridLayout *gridLayout;
    QCheckBox *checkBoxSerial1;
    QCheckBox *checkBoxParallel1;
    QCheckBox *checkBoxSerial2;
    QCheckBox *checkBoxParallel2;
    QCheckBox *checkBoxSerial3;
    QCheckBox *checkBoxParallel3;
    QCheckBox *checkBoxSerial4;
    QCheckBox *checkBoxParallel4;
    QGridLayout *gridLayoutPassThru;
    QCheckBox *checkBoxSerialPassThru1;
    QPushButton *pushButtonSerialPassThru1;
    QCheckBox *checkBoxSerialPassThru2;
    QPushButton *pushButtonSerialPassThru2;
    QCheckBox *checkBoxSerialPassThru3;
    QPushButton *pushButtonSerialPassThru3;
    QCheckBox *checkBoxSerialPassThru4;
    QPushButton *pushButtonSerialPassThru4;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SettingsPorts)
    {
        if (SettingsPorts->objectName().isEmpty())
            SettingsPorts->setObjectName("SettingsPorts");
        SettingsPorts->resize(398, 341);
        verticalLayout = new QVBoxLayout(SettingsPorts);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutLptECPDMA = new QGridLayout();
        gridLayoutLptECPDMA->setObjectName("gridLayoutLptECPDMA");
        labelLptECPDMA = new QLabel(SettingsPorts);
        labelLptECPDMA->setObjectName("labelLptECPDMA");

        gridLayoutLptECPDMA->addWidget(labelLptECPDMA, 0, 0, 1, 1);

        comboBoxLptECPDMA = new QComboBox(SettingsPorts);
        comboBoxLptECPDMA->setObjectName("comboBoxLptECPDMA");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxLptECPDMA->sizePolicy().hasHeightForWidth());
        comboBoxLptECPDMA->setSizePolicy(sizePolicy);
        comboBoxLptECPDMA->setMaxVisibleItems(30);

        gridLayoutLptECPDMA->addWidget(comboBoxLptECPDMA, 0, 2, 1, 1);

        labelLpt1 = new QLabel(SettingsPorts);
        labelLpt1->setObjectName("labelLpt1");

        gridLayoutLptECPDMA->addWidget(labelLpt1, 1, 0, 1, 1);

        comboBoxLpt1 = new QComboBox(SettingsPorts);
        comboBoxLpt1->setObjectName("comboBoxLpt1");
        sizePolicy.setHeightForWidth(comboBoxLpt1->sizePolicy().hasHeightForWidth());
        comboBoxLpt1->setSizePolicy(sizePolicy);
        comboBoxLpt1->setMaxVisibleItems(30);

        gridLayoutLptECPDMA->addWidget(comboBoxLpt1, 1, 2, 1, 1);

        pushButtonConfigureLpt1 = new QPushButton(SettingsPorts);
        pushButtonConfigureLpt1->setObjectName("pushButtonConfigureLpt1");

        gridLayoutLptECPDMA->addWidget(pushButtonConfigureLpt1, 1, 3, 1, 1);

        labelLpt2 = new QLabel(SettingsPorts);
        labelLpt2->setObjectName("labelLpt2");

        gridLayoutLptECPDMA->addWidget(labelLpt2, 2, 0, 1, 1);

        comboBoxLpt2 = new QComboBox(SettingsPorts);
        comboBoxLpt2->setObjectName("comboBoxLpt2");
        sizePolicy.setHeightForWidth(comboBoxLpt2->sizePolicy().hasHeightForWidth());
        comboBoxLpt2->setSizePolicy(sizePolicy);
        comboBoxLpt2->setMaxVisibleItems(30);

        gridLayoutLptECPDMA->addWidget(comboBoxLpt2, 2, 2, 1, 1);

        pushButtonConfigureLpt2 = new QPushButton(SettingsPorts);
        pushButtonConfigureLpt2->setObjectName("pushButtonConfigureLpt2");

        gridLayoutLptECPDMA->addWidget(pushButtonConfigureLpt2, 2, 3, 1, 1);

        labelLpt3 = new QLabel(SettingsPorts);
        labelLpt3->setObjectName("labelLpt3");

        gridLayoutLptECPDMA->addWidget(labelLpt3, 3, 0, 1, 1);

        comboBoxLpt3 = new QComboBox(SettingsPorts);
        comboBoxLpt3->setObjectName("comboBoxLpt3");
        sizePolicy.setHeightForWidth(comboBoxLpt3->sizePolicy().hasHeightForWidth());
        comboBoxLpt3->setSizePolicy(sizePolicy);
        comboBoxLpt3->setMaxVisibleItems(30);

        gridLayoutLptECPDMA->addWidget(comboBoxLpt3, 3, 2, 1, 1);

        pushButtonConfigureLpt3 = new QPushButton(SettingsPorts);
        pushButtonConfigureLpt3->setObjectName("pushButtonConfigureLpt3");

        gridLayoutLptECPDMA->addWidget(pushButtonConfigureLpt3, 3, 3, 1, 1);

        labelLpt4 = new QLabel(SettingsPorts);
        labelLpt4->setObjectName("labelLpt4");

        gridLayoutLptECPDMA->addWidget(labelLpt4, 4, 0, 1, 1);

        comboBoxLpt4 = new QComboBox(SettingsPorts);
        comboBoxLpt4->setObjectName("comboBoxLpt4");
        sizePolicy.setHeightForWidth(comboBoxLpt4->sizePolicy().hasHeightForWidth());
        comboBoxLpt4->setSizePolicy(sizePolicy);
        comboBoxLpt4->setMaxVisibleItems(30);

        gridLayoutLptECPDMA->addWidget(comboBoxLpt4, 4, 2, 1, 1);

        pushButtonConfigureLpt4 = new QPushButton(SettingsPorts);
        pushButtonConfigureLpt4->setObjectName("pushButtonConfigureLpt4");

        gridLayoutLptECPDMA->addWidget(pushButtonConfigureLpt4, 4, 3, 1, 1);


        verticalLayout->addLayout(gridLayoutLptECPDMA);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        checkBoxSerial1 = new QCheckBox(SettingsPorts);
        checkBoxSerial1->setObjectName("checkBoxSerial1");

        gridLayout->addWidget(checkBoxSerial1, 0, 0, 1, 1);

        checkBoxParallel1 = new QCheckBox(SettingsPorts);
        checkBoxParallel1->setObjectName("checkBoxParallel1");

        gridLayout->addWidget(checkBoxParallel1, 0, 1, 1, 1);

        checkBoxSerial2 = new QCheckBox(SettingsPorts);
        checkBoxSerial2->setObjectName("checkBoxSerial2");

        gridLayout->addWidget(checkBoxSerial2, 1, 0, 1, 1);

        checkBoxParallel2 = new QCheckBox(SettingsPorts);
        checkBoxParallel2->setObjectName("checkBoxParallel2");

        gridLayout->addWidget(checkBoxParallel2, 1, 1, 1, 1);

        checkBoxSerial3 = new QCheckBox(SettingsPorts);
        checkBoxSerial3->setObjectName("checkBoxSerial3");

        gridLayout->addWidget(checkBoxSerial3, 2, 0, 1, 1);

        checkBoxParallel3 = new QCheckBox(SettingsPorts);
        checkBoxParallel3->setObjectName("checkBoxParallel3");

        gridLayout->addWidget(checkBoxParallel3, 2, 1, 1, 1);

        checkBoxSerial4 = new QCheckBox(SettingsPorts);
        checkBoxSerial4->setObjectName("checkBoxSerial4");

        gridLayout->addWidget(checkBoxSerial4, 3, 0, 1, 1);

        checkBoxParallel4 = new QCheckBox(SettingsPorts);
        checkBoxParallel4->setObjectName("checkBoxParallel4");

        gridLayout->addWidget(checkBoxParallel4, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayoutPassThru = new QGridLayout();
        gridLayoutPassThru->setObjectName("gridLayoutPassThru");
        gridLayoutPassThru->setSizeConstraint(QLayout::SetDefaultConstraint);
        checkBoxSerialPassThru1 = new QCheckBox(SettingsPorts);
        checkBoxSerialPassThru1->setObjectName("checkBoxSerialPassThru1");

        gridLayoutPassThru->addWidget(checkBoxSerialPassThru1, 0, 0, 1, 1);

        pushButtonSerialPassThru1 = new QPushButton(SettingsPorts);
        pushButtonSerialPassThru1->setObjectName("pushButtonSerialPassThru1");

        gridLayoutPassThru->addWidget(pushButtonSerialPassThru1, 0, 1, 1, 1);

        checkBoxSerialPassThru2 = new QCheckBox(SettingsPorts);
        checkBoxSerialPassThru2->setObjectName("checkBoxSerialPassThru2");

        gridLayoutPassThru->addWidget(checkBoxSerialPassThru2, 1, 0, 1, 1);

        pushButtonSerialPassThru2 = new QPushButton(SettingsPorts);
        pushButtonSerialPassThru2->setObjectName("pushButtonSerialPassThru2");

        gridLayoutPassThru->addWidget(pushButtonSerialPassThru2, 1, 1, 1, 1);

        checkBoxSerialPassThru3 = new QCheckBox(SettingsPorts);
        checkBoxSerialPassThru3->setObjectName("checkBoxSerialPassThru3");

        gridLayoutPassThru->addWidget(checkBoxSerialPassThru3, 2, 0, 1, 1);

        pushButtonSerialPassThru3 = new QPushButton(SettingsPorts);
        pushButtonSerialPassThru3->setObjectName("pushButtonSerialPassThru3");

        gridLayoutPassThru->addWidget(pushButtonSerialPassThru3, 2, 1, 1, 1);

        checkBoxSerialPassThru4 = new QCheckBox(SettingsPorts);
        checkBoxSerialPassThru4->setObjectName("checkBoxSerialPassThru4");

        gridLayoutPassThru->addWidget(checkBoxSerialPassThru4, 3, 0, 1, 1);

        pushButtonSerialPassThru4 = new QPushButton(SettingsPorts);
        pushButtonSerialPassThru4->setObjectName("pushButtonSerialPassThru4");

        gridLayoutPassThru->addWidget(pushButtonSerialPassThru4, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayoutPassThru->addItem(horizontalSpacer, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayoutPassThru->addItem(verticalSpacer, 5, 0, 1, 2);


        verticalLayout->addLayout(gridLayoutPassThru);


        retranslateUi(SettingsPorts);

        QMetaObject::connectSlotsByName(SettingsPorts);
    } // setupUi

    void retranslateUi(QWidget *SettingsPorts)
    {
        SettingsPorts->setWindowTitle(QCoreApplication::translate("SettingsPorts", "Form", nullptr));
        labelLptECPDMA->setText(QCoreApplication::translate("SettingsPorts", "Internal LPT ECP DMA:", nullptr));
        labelLpt1->setText(QCoreApplication::translate("SettingsPorts", "LPT1 Device:", nullptr));
        pushButtonConfigureLpt1->setText(QCoreApplication::translate("SettingsPorts", "Configure", nullptr));
        labelLpt2->setText(QCoreApplication::translate("SettingsPorts", "LPT2 Device:", nullptr));
        pushButtonConfigureLpt2->setText(QCoreApplication::translate("SettingsPorts", "Configure", nullptr));
        labelLpt3->setText(QCoreApplication::translate("SettingsPorts", "LPT3 Device:", nullptr));
        pushButtonConfigureLpt3->setText(QCoreApplication::translate("SettingsPorts", "Configure", nullptr));
        labelLpt4->setText(QCoreApplication::translate("SettingsPorts", "LPT4 Device:", nullptr));
        pushButtonConfigureLpt4->setText(QCoreApplication::translate("SettingsPorts", "Configure", nullptr));
        checkBoxSerial1->setText(QCoreApplication::translate("SettingsPorts", "Serial port 1", nullptr));
        checkBoxParallel1->setText(QCoreApplication::translate("SettingsPorts", "Parallel port 1", nullptr));
        checkBoxSerial2->setText(QCoreApplication::translate("SettingsPorts", "Serial port 2", nullptr));
        checkBoxParallel2->setText(QCoreApplication::translate("SettingsPorts", "Parallel port 2", nullptr));
        checkBoxSerial3->setText(QCoreApplication::translate("SettingsPorts", "Serial port 3", nullptr));
        checkBoxParallel3->setText(QCoreApplication::translate("SettingsPorts", "Parallel port 3", nullptr));
        checkBoxSerial4->setText(QCoreApplication::translate("SettingsPorts", "Serial port 4", nullptr));
        checkBoxParallel4->setText(QCoreApplication::translate("SettingsPorts", "Parallel port 4", nullptr));
        checkBoxSerialPassThru1->setText(QCoreApplication::translate("SettingsPorts", "Serial port passthrough 1", nullptr));
        pushButtonSerialPassThru1->setText(QCoreApplication::translate("SettingsPorts", "Configure", nullptr));
        checkBoxSerialPassThru2->setText(QCoreApplication::translate("SettingsPorts", "Serial port passthrough 2", nullptr));
        pushButtonSerialPassThru2->setText(QCoreApplication::translate("SettingsPorts", "Configure", nullptr));
        checkBoxSerialPassThru3->setText(QCoreApplication::translate("SettingsPorts", "Serial port passthrough 3", nullptr));
        pushButtonSerialPassThru3->setText(QCoreApplication::translate("SettingsPorts", "Configure", nullptr));
        checkBoxSerialPassThru4->setText(QCoreApplication::translate("SettingsPorts", "Serial port passthrough 4", nullptr));
        pushButtonSerialPassThru4->setText(QCoreApplication::translate("SettingsPorts", "Configure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsPorts: public Ui_SettingsPorts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SETTINGSPORTS_H

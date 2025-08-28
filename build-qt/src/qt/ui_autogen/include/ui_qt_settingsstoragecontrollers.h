/********************************************************************************
** Form generated from reading UI file 'qt_settingsstoragecontrollers.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SETTINGSSTORAGECONTROLLERS_H
#define UI_QT_SETTINGSSTORAGECONTROLLERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsStorageControllers
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelFD;
    QComboBox *comboBoxFD;
    QPushButton *pushButtonFD;
    QLabel *labelCDInterface;
    QComboBox *comboBoxCDInterface;
    QPushButton *pushButtonCDInterface;
    QGroupBox *groupBoxHD;
    QGridLayout *gridLayoutHD;
    QLabel *labelHD1;
    QComboBox *comboBoxHD1;
    QPushButton *pushButtonHD1;
    QLabel *labelHD2;
    QComboBox *comboBoxHD2;
    QPushButton *pushButtonHD2;
    QLabel *labelHD3;
    QComboBox *comboBoxHD3;
    QPushButton *pushButtonHD3;
    QLabel *labelHD4;
    QComboBox *comboBoxHD4;
    QPushButton *pushButtonHD4;
    QGroupBox *groupBoxSCSI;
    QGridLayout *gridLayoutSCSI;
    QLabel *labelSCSI1;
    QComboBox *comboBoxSCSI1;
    QPushButton *pushButtonSCSI1;
    QLabel *labelSCSI2;
    QComboBox *comboBoxSCSI2;
    QPushButton *pushButtonSCSI2;
    QLabel *labelSCSI3;
    QComboBox *comboBoxSCSI3;
    QPushButton *pushButtonSCSI3;
    QLabel *labelSCSI4;
    QComboBox *comboBoxSCSI4;
    QPushButton *pushButtonSCSI4;
    QCheckBox *checkBoxCassette;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SettingsStorageControllers)
    {
        if (SettingsStorageControllers->objectName().isEmpty())
            SettingsStorageControllers->setObjectName("SettingsStorageControllers");
        SettingsStorageControllers->resize(496, 449);
        verticalLayout = new QVBoxLayout(SettingsStorageControllers);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        labelFD = new QLabel(SettingsStorageControllers);
        labelFD->setObjectName("labelFD");

        gridLayout->addWidget(labelFD, 0, 0, 1, 1);

        comboBoxFD = new QComboBox(SettingsStorageControllers);
        comboBoxFD->setObjectName("comboBoxFD");
        comboBoxFD->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxFD, 0, 1, 1, 1);

        pushButtonFD = new QPushButton(SettingsStorageControllers);
        pushButtonFD->setObjectName("pushButtonFD");

        gridLayout->addWidget(pushButtonFD, 0, 2, 1, 1);

        labelCDInterface = new QLabel(SettingsStorageControllers);
        labelCDInterface->setObjectName("labelCDInterface");

        gridLayout->addWidget(labelCDInterface, 1, 0, 1, 1);

        comboBoxCDInterface = new QComboBox(SettingsStorageControllers);
        comboBoxCDInterface->setObjectName("comboBoxCDInterface");
        comboBoxCDInterface->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxCDInterface, 1, 1, 1, 1);

        pushButtonCDInterface = new QPushButton(SettingsStorageControllers);
        pushButtonCDInterface->setObjectName("pushButtonCDInterface");

        gridLayout->addWidget(pushButtonCDInterface, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        groupBoxHD = new QGroupBox(SettingsStorageControllers);
        groupBoxHD->setObjectName("groupBoxHD");
        gridLayoutHD = new QGridLayout(groupBoxHD);
        gridLayoutHD->setObjectName("gridLayoutHD");
        labelHD1 = new QLabel(groupBoxHD);
        labelHD1->setObjectName("labelHD1");

        gridLayoutHD->addWidget(labelHD1, 0, 0, 1, 1);

        comboBoxHD1 = new QComboBox(groupBoxHD);
        comboBoxHD1->setObjectName("comboBoxHD1");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxHD1->sizePolicy().hasHeightForWidth());
        comboBoxHD1->setSizePolicy(sizePolicy);
        comboBoxHD1->setMaxVisibleItems(30);

        gridLayoutHD->addWidget(comboBoxHD1, 0, 2, 1, 1);

        pushButtonHD1 = new QPushButton(groupBoxHD);
        pushButtonHD1->setObjectName("pushButtonHD1");

        gridLayoutHD->addWidget(pushButtonHD1, 0, 3, 1, 1);

        labelHD2 = new QLabel(groupBoxHD);
        labelHD2->setObjectName("labelHD2");

        gridLayoutHD->addWidget(labelHD2, 1, 0, 1, 1);

        comboBoxHD2 = new QComboBox(groupBoxHD);
        comboBoxHD2->setObjectName("comboBoxHD2");
        sizePolicy.setHeightForWidth(comboBoxHD2->sizePolicy().hasHeightForWidth());
        comboBoxHD2->setSizePolicy(sizePolicy);
        comboBoxHD2->setMaxVisibleItems(30);

        gridLayoutHD->addWidget(comboBoxHD2, 1, 2, 1, 1);

        pushButtonHD2 = new QPushButton(groupBoxHD);
        pushButtonHD2->setObjectName("pushButtonHD2");

        gridLayoutHD->addWidget(pushButtonHD2, 1, 3, 1, 1);

        labelHD3 = new QLabel(groupBoxHD);
        labelHD3->setObjectName("labelHD3");

        gridLayoutHD->addWidget(labelHD3, 2, 0, 1, 1);

        comboBoxHD3 = new QComboBox(groupBoxHD);
        comboBoxHD3->setObjectName("comboBoxHD3");
        sizePolicy.setHeightForWidth(comboBoxHD3->sizePolicy().hasHeightForWidth());
        comboBoxHD3->setSizePolicy(sizePolicy);
        comboBoxHD3->setMaxVisibleItems(30);

        gridLayoutHD->addWidget(comboBoxHD3, 2, 2, 1, 1);

        pushButtonHD3 = new QPushButton(groupBoxHD);
        pushButtonHD3->setObjectName("pushButtonHD3");

        gridLayoutHD->addWidget(pushButtonHD3, 2, 3, 1, 1);

        labelHD4 = new QLabel(groupBoxHD);
        labelHD4->setObjectName("labelHD4");

        gridLayoutHD->addWidget(labelHD4, 3, 0, 1, 1);

        comboBoxHD4 = new QComboBox(groupBoxHD);
        comboBoxHD4->setObjectName("comboBoxHD4");
        sizePolicy.setHeightForWidth(comboBoxHD4->sizePolicy().hasHeightForWidth());
        comboBoxHD4->setSizePolicy(sizePolicy);
        comboBoxHD4->setMaxVisibleItems(30);

        gridLayoutHD->addWidget(comboBoxHD4, 3, 2, 1, 1);

        pushButtonHD4 = new QPushButton(groupBoxHD);
        pushButtonHD4->setObjectName("pushButtonHD4");

        gridLayoutHD->addWidget(pushButtonHD4, 3, 3, 1, 1);


        verticalLayout->addWidget(groupBoxHD);

        groupBoxSCSI = new QGroupBox(SettingsStorageControllers);
        groupBoxSCSI->setObjectName("groupBoxSCSI");
        gridLayoutSCSI = new QGridLayout(groupBoxSCSI);
        gridLayoutSCSI->setObjectName("gridLayoutSCSI");
        labelSCSI1 = new QLabel(groupBoxSCSI);
        labelSCSI1->setObjectName("labelSCSI1");

        gridLayoutSCSI->addWidget(labelSCSI1, 0, 0, 1, 1);

        comboBoxSCSI1 = new QComboBox(groupBoxSCSI);
        comboBoxSCSI1->setObjectName("comboBoxSCSI1");
        sizePolicy.setHeightForWidth(comboBoxSCSI1->sizePolicy().hasHeightForWidth());
        comboBoxSCSI1->setSizePolicy(sizePolicy);
        comboBoxSCSI1->setMaxVisibleItems(30);

        gridLayoutSCSI->addWidget(comboBoxSCSI1, 0, 2, 1, 1);

        pushButtonSCSI1 = new QPushButton(groupBoxSCSI);
        pushButtonSCSI1->setObjectName("pushButtonSCSI1");

        gridLayoutSCSI->addWidget(pushButtonSCSI1, 0, 3, 1, 1);

        labelSCSI2 = new QLabel(groupBoxSCSI);
        labelSCSI2->setObjectName("labelSCSI2");

        gridLayoutSCSI->addWidget(labelSCSI2, 1, 0, 1, 1);

        comboBoxSCSI2 = new QComboBox(groupBoxSCSI);
        comboBoxSCSI2->setObjectName("comboBoxSCSI2");
        sizePolicy.setHeightForWidth(comboBoxSCSI2->sizePolicy().hasHeightForWidth());
        comboBoxSCSI2->setSizePolicy(sizePolicy);
        comboBoxSCSI2->setMaxVisibleItems(30);

        gridLayoutSCSI->addWidget(comboBoxSCSI2, 1, 2, 1, 1);

        pushButtonSCSI2 = new QPushButton(groupBoxSCSI);
        pushButtonSCSI2->setObjectName("pushButtonSCSI2");

        gridLayoutSCSI->addWidget(pushButtonSCSI2, 1, 3, 1, 1);

        labelSCSI3 = new QLabel(groupBoxSCSI);
        labelSCSI3->setObjectName("labelSCSI3");

        gridLayoutSCSI->addWidget(labelSCSI3, 2, 0, 1, 1);

        comboBoxSCSI3 = new QComboBox(groupBoxSCSI);
        comboBoxSCSI3->setObjectName("comboBoxSCSI3");
        sizePolicy.setHeightForWidth(comboBoxSCSI3->sizePolicy().hasHeightForWidth());
        comboBoxSCSI3->setSizePolicy(sizePolicy);
        comboBoxSCSI3->setMaxVisibleItems(30);

        gridLayoutSCSI->addWidget(comboBoxSCSI3, 2, 2, 1, 1);

        pushButtonSCSI3 = new QPushButton(groupBoxSCSI);
        pushButtonSCSI3->setObjectName("pushButtonSCSI3");

        gridLayoutSCSI->addWidget(pushButtonSCSI3, 2, 3, 1, 1);

        labelSCSI4 = new QLabel(groupBoxSCSI);
        labelSCSI4->setObjectName("labelSCSI4");

        gridLayoutSCSI->addWidget(labelSCSI4, 3, 0, 1, 1);

        comboBoxSCSI4 = new QComboBox(groupBoxSCSI);
        comboBoxSCSI4->setObjectName("comboBoxSCSI4");
        sizePolicy.setHeightForWidth(comboBoxSCSI4->sizePolicy().hasHeightForWidth());
        comboBoxSCSI4->setSizePolicy(sizePolicy);
        comboBoxSCSI4->setMaxVisibleItems(30);

        gridLayoutSCSI->addWidget(comboBoxSCSI4, 3, 2, 1, 1);

        pushButtonSCSI4 = new QPushButton(groupBoxSCSI);
        pushButtonSCSI4->setObjectName("pushButtonSCSI4");

        gridLayoutSCSI->addWidget(pushButtonSCSI4, 3, 3, 1, 1);


        verticalLayout->addWidget(groupBoxSCSI);

        checkBoxCassette = new QCheckBox(SettingsStorageControllers);
        checkBoxCassette->setObjectName("checkBoxCassette");

        verticalLayout->addWidget(checkBoxCassette);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        QWidget::setTabOrder(comboBoxFD, pushButtonFD);
        QWidget::setTabOrder(pushButtonFD, comboBoxCDInterface);
        QWidget::setTabOrder(comboBoxCDInterface, pushButtonCDInterface);
        QWidget::setTabOrder(pushButtonCDInterface, comboBoxHD1);
        QWidget::setTabOrder(comboBoxHD1, pushButtonHD1);
        QWidget::setTabOrder(pushButtonHD1, comboBoxHD2);
        QWidget::setTabOrder(comboBoxHD2, pushButtonHD2);
        QWidget::setTabOrder(pushButtonHD2, comboBoxHD3);
        QWidget::setTabOrder(comboBoxHD3, pushButtonHD3);
        QWidget::setTabOrder(pushButtonHD3, comboBoxHD4);
        QWidget::setTabOrder(comboBoxHD4, pushButtonHD4);
        QWidget::setTabOrder(pushButtonHD4, comboBoxSCSI1);
        QWidget::setTabOrder(comboBoxSCSI1, pushButtonSCSI1);
        QWidget::setTabOrder(pushButtonSCSI1, comboBoxSCSI2);
        QWidget::setTabOrder(comboBoxSCSI2, pushButtonSCSI2);
        QWidget::setTabOrder(pushButtonSCSI2, comboBoxSCSI3);
        QWidget::setTabOrder(comboBoxSCSI3, pushButtonSCSI3);
        QWidget::setTabOrder(pushButtonSCSI3, comboBoxSCSI4);
        QWidget::setTabOrder(comboBoxSCSI4, pushButtonSCSI4);
        QWidget::setTabOrder(pushButtonSCSI4, checkBoxCassette);

        retranslateUi(SettingsStorageControllers);

        QMetaObject::connectSlotsByName(SettingsStorageControllers);
    } // setupUi

    void retranslateUi(QWidget *SettingsStorageControllers)
    {
        SettingsStorageControllers->setWindowTitle(QCoreApplication::translate("SettingsStorageControllers", "Form", nullptr));
        labelFD->setText(QCoreApplication::translate("SettingsStorageControllers", "FD Controller:", nullptr));
        pushButtonFD->setText(QCoreApplication::translate("SettingsStorageControllers", "Configure", nullptr));
        labelCDInterface->setText(QCoreApplication::translate("SettingsStorageControllers", "CD-ROM Controller:", nullptr));
        pushButtonCDInterface->setText(QCoreApplication::translate("SettingsStorageControllers", "Configure", nullptr));
        groupBoxHD->setTitle(QCoreApplication::translate("SettingsStorageControllers", "Hard disk", nullptr));
        labelHD1->setText(QCoreApplication::translate("SettingsStorageControllers", "Controller 1:", nullptr));
        pushButtonHD1->setText(QCoreApplication::translate("SettingsStorageControllers", "Configure", nullptr));
        labelHD2->setText(QCoreApplication::translate("SettingsStorageControllers", "Controller 2:", nullptr));
        pushButtonHD2->setText(QCoreApplication::translate("SettingsStorageControllers", "Configure", nullptr));
        labelHD3->setText(QCoreApplication::translate("SettingsStorageControllers", "Controller 3:", nullptr));
        pushButtonHD3->setText(QCoreApplication::translate("SettingsStorageControllers", "Configure", nullptr));
        labelHD4->setText(QCoreApplication::translate("SettingsStorageControllers", "Controller 4:", nullptr));
        pushButtonHD4->setText(QCoreApplication::translate("SettingsStorageControllers", "Configure", nullptr));
        groupBoxSCSI->setTitle(QCoreApplication::translate("SettingsStorageControllers", "SCSI", nullptr));
        labelSCSI1->setText(QCoreApplication::translate("SettingsStorageControllers", "Controller 1:", nullptr));
        pushButtonSCSI1->setText(QCoreApplication::translate("SettingsStorageControllers", "Configure", nullptr));
        labelSCSI2->setText(QCoreApplication::translate("SettingsStorageControllers", "Controller 2:", nullptr));
        pushButtonSCSI2->setText(QCoreApplication::translate("SettingsStorageControllers", "Configure", nullptr));
        labelSCSI3->setText(QCoreApplication::translate("SettingsStorageControllers", "Controller 3:", nullptr));
        pushButtonSCSI3->setText(QCoreApplication::translate("SettingsStorageControllers", "Configure", nullptr));
        labelSCSI4->setText(QCoreApplication::translate("SettingsStorageControllers", "Controller 4:", nullptr));
        pushButtonSCSI4->setText(QCoreApplication::translate("SettingsStorageControllers", "Configure", nullptr));
        checkBoxCassette->setText(QCoreApplication::translate("SettingsStorageControllers", "Cassette", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsStorageControllers: public Ui_SettingsStorageControllers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SETTINGSSTORAGECONTROLLERS_H

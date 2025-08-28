/********************************************************************************
** Form generated from reading UI file 'qt_settingsmachine.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SETTINGSMACHINE_H
#define UI_QT_SETTINGSMACHINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsMachine
{
public:
    QVBoxLayout *vboxLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBoxMachineType;
    QLabel *label_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBoxMachine;
    QPushButton *pushButtonConfigure;
    QLabel *label_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBoxCPU;
    QLabel *label_7;
    QComboBox *comboBoxSpeed;
    QLabel *label_4;
    QComboBox *comboBoxFPU;
    QLabel *label_5;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBoxWaitStates;
    QLabel *label_8;
    QComboBox *comboBoxPitMode;
    QLabel *label_6;
    QSpinBox *spinBoxRAM;
    QHBoxLayout *dynamicRecompilerLayout;
    QCheckBox *checkBoxDynamicRecompiler;
    QHBoxLayout *softFloatLayout;
    QCheckBox *checkBoxFPUSoftfloat;
    QLabel *softFloatWarningIcon;
    QLabel *softFloatWarningText;
    QSpacerItem *softFloatHorizontalSpacer;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonLargerFrames;
    QRadioButton *radioButtonSmallerFrames;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonDisabled;
    QRadioButton *radioButtonLocalTime;
    QRadioButton *radioButtonUTC;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SettingsMachine)
    {
        if (SettingsMachine->objectName().isEmpty())
            SettingsMachine->setObjectName("SettingsMachine");
        SettingsMachine->resize(458, 459);
        vboxLayout = new QVBoxLayout(SettingsMachine);
        vboxLayout->setObjectName("vboxLayout");
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SettingsMachine);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBoxMachineType = new QComboBox(widget);
        comboBoxMachineType->setObjectName("comboBoxMachineType");
        comboBoxMachineType->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxMachineType, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBoxMachine = new QComboBox(widget_3);
        comboBoxMachine->setObjectName("comboBoxMachine");
        comboBoxMachine->setMaxVisibleItems(30);

        horizontalLayout_2->addWidget(comboBoxMachine);

        pushButtonConfigure = new QPushButton(widget_3);
        pushButtonConfigure->setObjectName("pushButtonConfigure");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonConfigure->sizePolicy().hasHeightForWidth());
        pushButtonConfigure->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButtonConfigure);


        gridLayout->addWidget(widget_3, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        comboBoxCPU = new QComboBox(widget_2);
        comboBoxCPU->setObjectName("comboBoxCPU");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxCPU->sizePolicy().hasHeightForWidth());
        comboBoxCPU->setSizePolicy(sizePolicy1);
        comboBoxCPU->setMaxVisibleItems(30);

        horizontalLayout->addWidget(comboBoxCPU);

        label_7 = new QLabel(widget_2);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_7);

        comboBoxSpeed = new QComboBox(widget_2);
        comboBoxSpeed->setObjectName("comboBoxSpeed");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBoxSpeed->sizePolicy().hasHeightForWidth());
        comboBoxSpeed->setSizePolicy(sizePolicy2);
        comboBoxSpeed->setMaxVisibleItems(30);

        horizontalLayout->addWidget(comboBoxSpeed);


        gridLayout->addWidget(widget_2, 2, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        comboBoxFPU = new QComboBox(widget);
        comboBoxFPU->setObjectName("comboBoxFPU");
        comboBoxFPU->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxFPU, 3, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName("widget_4");
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        comboBoxWaitStates = new QComboBox(widget_4);
        comboBoxWaitStates->setObjectName("comboBoxWaitStates");
        sizePolicy1.setHeightForWidth(comboBoxWaitStates->sizePolicy().hasHeightForWidth());
        comboBoxWaitStates->setSizePolicy(sizePolicy1);
        comboBoxWaitStates->setMaxVisibleItems(30);

        horizontalLayout_3->addWidget(comboBoxWaitStates);

        label_8 = new QLabel(widget_4);
        label_8->setObjectName("label_8");

        horizontalLayout_3->addWidget(label_8);

        comboBoxPitMode = new QComboBox(widget_4);
        comboBoxPitMode->setObjectName("comboBoxPitMode");
        sizePolicy2.setHeightForWidth(comboBoxPitMode->sizePolicy().hasHeightForWidth());
        comboBoxPitMode->setSizePolicy(sizePolicy2);
        comboBoxPitMode->setMaxVisibleItems(30);

        horizontalLayout_3->addWidget(comboBoxPitMode);


        gridLayout->addWidget(widget_4, 4, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        spinBoxRAM = new QSpinBox(widget);
        spinBoxRAM->setObjectName("spinBoxRAM");
        sizePolicy.setHeightForWidth(spinBoxRAM->sizePolicy().hasHeightForWidth());
        spinBoxRAM->setSizePolicy(sizePolicy);

        gridLayout->addWidget(spinBoxRAM, 5, 1, 1, 1);


        vboxLayout->addWidget(widget);

        dynamicRecompilerLayout = new QHBoxLayout();
        dynamicRecompilerLayout->setObjectName("dynamicRecompilerLayout");
        checkBoxDynamicRecompiler = new QCheckBox(SettingsMachine);
        checkBoxDynamicRecompiler->setObjectName("checkBoxDynamicRecompiler");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(2);
        sizePolicy3.setVerticalStretch(2);
        sizePolicy3.setHeightForWidth(checkBoxDynamicRecompiler->sizePolicy().hasHeightForWidth());
        checkBoxDynamicRecompiler->setSizePolicy(sizePolicy3);

        dynamicRecompilerLayout->addWidget(checkBoxDynamicRecompiler);


        vboxLayout->addLayout(dynamicRecompilerLayout);

        softFloatLayout = new QHBoxLayout();
        softFloatLayout->setObjectName("softFloatLayout");
        checkBoxFPUSoftfloat = new QCheckBox(SettingsMachine);
        checkBoxFPUSoftfloat->setObjectName("checkBoxFPUSoftfloat");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(3);
        sizePolicy4.setVerticalStretch(3);
        sizePolicy4.setHeightForWidth(checkBoxFPUSoftfloat->sizePolicy().hasHeightForWidth());
        checkBoxFPUSoftfloat->setSizePolicy(sizePolicy4);

        softFloatLayout->addWidget(checkBoxFPUSoftfloat);

        softFloatWarningIcon = new QLabel(SettingsMachine);
        softFloatWarningIcon->setObjectName("softFloatWarningIcon");

        softFloatLayout->addWidget(softFloatWarningIcon);

        softFloatWarningText = new QLabel(SettingsMachine);
        softFloatWarningText->setObjectName("softFloatWarningText");

        softFloatLayout->addWidget(softFloatWarningText);

        softFloatHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        softFloatLayout->addItem(softFloatHorizontalSpacer);


        vboxLayout->addLayout(softFloatLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox_2 = new QGroupBox(SettingsMachine);
        groupBox_2->setObjectName("groupBox_2");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy5);
        groupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        radioButtonLargerFrames = new QRadioButton(groupBox_2);
        radioButtonLargerFrames->setObjectName("radioButtonLargerFrames");

        verticalLayout_2->addWidget(radioButtonLargerFrames);

        radioButtonSmallerFrames = new QRadioButton(groupBox_2);
        radioButtonSmallerFrames->setObjectName("radioButtonSmallerFrames");

        verticalLayout_2->addWidget(radioButtonSmallerFrames);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        groupBox = new QGroupBox(SettingsMachine);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy6);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        radioButtonDisabled = new QRadioButton(groupBox);
        radioButtonDisabled->setObjectName("radioButtonDisabled");

        verticalLayout->addWidget(radioButtonDisabled);

        radioButtonLocalTime = new QRadioButton(groupBox);
        radioButtonLocalTime->setObjectName("radioButtonLocalTime");

        verticalLayout->addWidget(radioButtonLocalTime);

        radioButtonUTC = new QRadioButton(groupBox);
        radioButtonUTC->setObjectName("radioButtonUTC");

        verticalLayout->addWidget(radioButtonUTC);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 1, 1, 1);


        vboxLayout->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout->addItem(verticalSpacer);

        QWidget::setTabOrder(comboBoxMachineType, comboBoxMachine);
        QWidget::setTabOrder(comboBoxMachine, pushButtonConfigure);
        QWidget::setTabOrder(pushButtonConfigure, comboBoxCPU);
        QWidget::setTabOrder(comboBoxCPU, comboBoxSpeed);
        QWidget::setTabOrder(comboBoxSpeed, comboBoxFPU);
        QWidget::setTabOrder(comboBoxFPU, comboBoxWaitStates);
        QWidget::setTabOrder(comboBoxWaitStates, comboBoxPitMode);
        QWidget::setTabOrder(comboBoxPitMode, spinBoxRAM);
        QWidget::setTabOrder(spinBoxRAM, checkBoxDynamicRecompiler);
        QWidget::setTabOrder(checkBoxDynamicRecompiler, checkBoxFPUSoftfloat);
        QWidget::setTabOrder(checkBoxFPUSoftfloat, radioButtonDisabled);
        QWidget::setTabOrder(radioButtonDisabled, radioButtonLocalTime);
        QWidget::setTabOrder(radioButtonLocalTime, radioButtonUTC);
        QWidget::setTabOrder(radioButtonUTC, radioButtonLargerFrames);
        QWidget::setTabOrder(radioButtonLargerFrames, radioButtonSmallerFrames);

        retranslateUi(SettingsMachine);

        QMetaObject::connectSlotsByName(SettingsMachine);
    } // setupUi

    void retranslateUi(QWidget *SettingsMachine)
    {
        SettingsMachine->setWindowTitle(QCoreApplication::translate("SettingsMachine", "Form", nullptr));
        label->setText(QCoreApplication::translate("SettingsMachine", "Machine type:", nullptr));
        label_2->setText(QCoreApplication::translate("SettingsMachine", "Machine:", nullptr));
        pushButtonConfigure->setText(QCoreApplication::translate("SettingsMachine", "Configure", nullptr));
        label_3->setText(QCoreApplication::translate("SettingsMachine", "CPU type:", nullptr));
        label_7->setText(QCoreApplication::translate("SettingsMachine", "Frequency:", nullptr));
        label_4->setText(QCoreApplication::translate("SettingsMachine", "FPU:", nullptr));
        label_5->setText(QCoreApplication::translate("SettingsMachine", "Wait states:", nullptr));
        label_8->setText(QCoreApplication::translate("SettingsMachine", "PIT mode:", nullptr));
        label_6->setText(QCoreApplication::translate("SettingsMachine", "Memory:", nullptr));
        checkBoxDynamicRecompiler->setText(QCoreApplication::translate("SettingsMachine", "Dynamic Recompiler", nullptr));
        checkBoxFPUSoftfloat->setText(QCoreApplication::translate("SettingsMachine", "Softfloat FPU", nullptr));
        softFloatWarningIcon->setText(QString());
        softFloatWarningText->setText(QCoreApplication::translate("SettingsMachine", "High performance impact", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SettingsMachine", "CPU frame size", nullptr));
        radioButtonLargerFrames->setText(QCoreApplication::translate("SettingsMachine", "Larger frames (less smooth)", nullptr));
        radioButtonSmallerFrames->setText(QCoreApplication::translate("SettingsMachine", "Smaller frames (smoother)", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SettingsMachine", "Time synchronization", nullptr));
        radioButtonDisabled->setText(QCoreApplication::translate("SettingsMachine", "Disabled", nullptr));
        radioButtonLocalTime->setText(QCoreApplication::translate("SettingsMachine", "Enabled (local time)", nullptr));
        radioButtonUTC->setText(QCoreApplication::translate("SettingsMachine", "Enabled (UTC)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsMachine: public Ui_SettingsMachine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SETTINGSMACHINE_H

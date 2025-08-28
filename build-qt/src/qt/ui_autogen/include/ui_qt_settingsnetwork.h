/********************************************************************************
** Form generated from reading UI file 'qt_settingsnetwork.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SETTINGSNETWORK_H
#define UI_QT_SETTINGSNETWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsNetwork
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidgetNet;
    QWidget *tabNet1;
    QGridLayout *gridLayoutNet1;
    QLabel *labelMode1;
    QComboBox *comboBoxNet1;
    QLabel *labelAdapter1;
    QComboBox *comboBoxNIC1;
    QPushButton *pushButtonConf1;
    QLabel *labelOptionList1;
    QFrame *lineOptionList1;
    QLabel *labelIntf1;
    QComboBox *comboBoxIntf1;
    QLabel *labelSocketVDENIC1;
    QLineEdit *socketVDENIC1;
    QLabel *labelBridgeTAPNIC1;
    QLineEdit *bridgeTAPNIC1;
    QLabel *labelSwitch1;
    QHBoxLayout *HLayoutSwitch1;
    QSpinBox *spinnerSwitch1;
    QSpacerItem *horizontalSpacerSwitch1;
    QLabel *labelPromisc1;
    QCheckBox *boxPromisc1;
    QLabel *labelHostname1;
    QLineEdit *hostnameSwitch1;
    QSpacerItem *verticalSpacerNIC1;
    QWidget *tabNet2;
    QGridLayout *gridLayoutNet2;
    QLabel *labelMode2;
    QComboBox *comboBoxNet2;
    QLabel *labelAdapter2;
    QComboBox *comboBoxNIC2;
    QPushButton *pushButtonConf2;
    QLabel *labelOptionList2;
    QFrame *lineOptionList2;
    QLabel *labelIntf2;
    QComboBox *comboBoxIntf2;
    QLabel *labelSocketVDENIC2;
    QLineEdit *socketVDENIC2;
    QLabel *labelBridgeTAPNIC2;
    QLineEdit *bridgeTAPNIC2;
    QLabel *labelSwitch2;
    QHBoxLayout *HLayoutSwitch2;
    QSpinBox *spinnerSwitch2;
    QSpacerItem *horizontalSpacerSwitch2;
    QLabel *labelPromisc2;
    QCheckBox *boxPromisc2;
    QLabel *labelHostname2;
    QLineEdit *hostnameSwitch2;
    QSpacerItem *verticalSpacerNIC2;
    QWidget *tabNet3;
    QGridLayout *gridLayoutNet3;
    QLabel *labelMode3;
    QComboBox *comboBoxNet3;
    QLabel *labelAdapter3;
    QComboBox *comboBoxNIC3;
    QPushButton *pushButtonConf3;
    QLabel *labelOptionList3;
    QFrame *lineOptionList3;
    QLabel *labelIntf3;
    QComboBox *comboBoxIntf3;
    QLabel *labelSocketVDENIC3;
    QLineEdit *socketVDENIC3;
    QLabel *labelBridgeTAPNIC3;
    QLineEdit *bridgeTAPNIC3;
    QLabel *labelSwitch3;
    QHBoxLayout *HLayoutSwitch3;
    QSpinBox *spinnerSwitch3;
    QSpacerItem *horizontalSpacerSwitch3;
    QLabel *labelPromisc3;
    QCheckBox *boxPromisc3;
    QLabel *labelHostname3;
    QLineEdit *hostnameSwitch3;
    QSpacerItem *verticalSpacerNIC3;
    QWidget *tabNet4;
    QGridLayout *gridLayoutNet4;
    QLabel *labelMode4;
    QComboBox *comboBoxNet4;
    QLabel *labelAdapter4;
    QComboBox *comboBoxNIC4;
    QPushButton *pushButtonConf4;
    QLabel *labelOptionList4;
    QFrame *lineOptionList4;
    QLabel *labelIntf4;
    QComboBox *comboBoxIntf4;
    QLabel *labelSocketVDENIC4;
    QLineEdit *socketVDENIC4;
    QLabel *labelBridgeTAPNIC4;
    QLineEdit *bridgeTAPNIC4;
    QLabel *labelSwitch4;
    QHBoxLayout *HLayoutSwitch4;
    QSpinBox *spinnerSwitch4;
    QSpacerItem *horizontalSpacerSwitch4;
    QLabel *labelPromisc4;
    QCheckBox *boxPromisc4;
    QLabel *labelHostname4;
    QLineEdit *hostnameSwitch4;
    QSpacerItem *verticalSpacerNIC4;

    void setupUi(QWidget *SettingsNetwork)
    {
        if (SettingsNetwork->objectName().isEmpty())
            SettingsNetwork->setObjectName("SettingsNetwork");
        SettingsNetwork->resize(548, 488);
        verticalLayout = new QVBoxLayout(SettingsNetwork);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidgetNet = new QTabWidget(SettingsNetwork);
        tabWidgetNet->setObjectName("tabWidgetNet");
        tabNet1 = new QWidget();
        tabNet1->setObjectName("tabNet1");
        gridLayoutNet1 = new QGridLayout(tabNet1);
        gridLayoutNet1->setObjectName("gridLayoutNet1");
        labelMode1 = new QLabel(tabNet1);
        labelMode1->setObjectName("labelMode1");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelMode1->sizePolicy().hasHeightForWidth());
        labelMode1->setSizePolicy(sizePolicy);

        gridLayoutNet1->addWidget(labelMode1, 0, 0, 1, 1);

        comboBoxNet1 = new QComboBox(tabNet1);
        comboBoxNet1->setObjectName("comboBoxNet1");
        comboBoxNet1->setMaxVisibleItems(30);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxNet1->sizePolicy().hasHeightForWidth());
        comboBoxNet1->setSizePolicy(sizePolicy1);

        gridLayoutNet1->addWidget(comboBoxNet1, 0, 1, 1, 1);

        labelAdapter1 = new QLabel(tabNet1);
        labelAdapter1->setObjectName("labelAdapter1");
        sizePolicy.setHeightForWidth(labelAdapter1->sizePolicy().hasHeightForWidth());
        labelAdapter1->setSizePolicy(sizePolicy);

        gridLayoutNet1->addWidget(labelAdapter1, 1, 0, 1, 1);

        comboBoxNIC1 = new QComboBox(tabNet1);
        comboBoxNIC1->setObjectName("comboBoxNIC1");
        sizePolicy1.setHeightForWidth(comboBoxNIC1->sizePolicy().hasHeightForWidth());
        comboBoxNIC1->setSizePolicy(sizePolicy1);
        comboBoxNIC1->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBoxNIC1->setMaxVisibleItems(30);

        gridLayoutNet1->addWidget(comboBoxNIC1, 1, 1, 1, 1);

        pushButtonConf1 = new QPushButton(tabNet1);
        pushButtonConf1->setObjectName("pushButtonConf1");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonConf1->sizePolicy().hasHeightForWidth());
        pushButtonConf1->setSizePolicy(sizePolicy2);

        gridLayoutNet1->addWidget(pushButtonConf1, 1, 2, 1, 1);

        labelOptionList1 = new QLabel(tabNet1);
        labelOptionList1->setObjectName("labelOptionList1");

        gridLayoutNet1->addWidget(labelOptionList1, 2, 0, 1, 1);

        lineOptionList1 = new QFrame(tabNet1);
        lineOptionList1->setObjectName("lineOptionList1");
        lineOptionList1->setFrameShape(QFrame::Shape::HLine);
        lineOptionList1->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayoutNet1->addWidget(lineOptionList1, 2, 1, 1, 2);

        labelIntf1 = new QLabel(tabNet1);
        labelIntf1->setObjectName("labelIntf1");
        sizePolicy.setHeightForWidth(labelIntf1->sizePolicy().hasHeightForWidth());
        labelIntf1->setSizePolicy(sizePolicy);

        gridLayoutNet1->addWidget(labelIntf1, 3, 0, 1, 1);

        comboBoxIntf1 = new QComboBox(tabNet1);
        comboBoxIntf1->setObjectName("comboBoxIntf1");
        sizePolicy1.setHeightForWidth(comboBoxIntf1->sizePolicy().hasHeightForWidth());
        comboBoxIntf1->setSizePolicy(sizePolicy1);

        gridLayoutNet1->addWidget(comboBoxIntf1, 3, 1, 1, 1);

        labelSocketVDENIC1 = new QLabel(tabNet1);
        labelSocketVDENIC1->setObjectName("labelSocketVDENIC1");

        gridLayoutNet1->addWidget(labelSocketVDENIC1, 5, 0, 1, 1);

        socketVDENIC1 = new QLineEdit(tabNet1);
        socketVDENIC1->setObjectName("socketVDENIC1");
        socketVDENIC1->setMaxLength(127);

        gridLayoutNet1->addWidget(socketVDENIC1, 5, 1, 1, 1);

        labelBridgeTAPNIC1 = new QLabel(tabNet1);
        labelBridgeTAPNIC1->setObjectName("labelBridgeTAPNIC1");

        gridLayoutNet1->addWidget(labelBridgeTAPNIC1, 6, 0, 1, 1);

        bridgeTAPNIC1 = new QLineEdit(tabNet1);
        bridgeTAPNIC1->setObjectName("bridgeTAPNIC1");
        bridgeTAPNIC1->setMaxLength(127);

        gridLayoutNet1->addWidget(bridgeTAPNIC1, 6, 1, 1, 2);

        labelSwitch1 = new QLabel(tabNet1);
        labelSwitch1->setObjectName("labelSwitch1");

        gridLayoutNet1->addWidget(labelSwitch1, 7, 0, 1, 1);

        HLayoutSwitch1 = new QHBoxLayout();
        HLayoutSwitch1->setObjectName("HLayoutSwitch1");
        spinnerSwitch1 = new QSpinBox(tabNet1);
        spinnerSwitch1->setObjectName("spinnerSwitch1");
        spinnerSwitch1->setMinimum(1);
        spinnerSwitch1->setMaximum(10);

        HLayoutSwitch1->addWidget(spinnerSwitch1);

        horizontalSpacerSwitch1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        HLayoutSwitch1->addItem(horizontalSpacerSwitch1);


        gridLayoutNet1->addLayout(HLayoutSwitch1, 7, 1, 1, 1);

        labelPromisc1 = new QLabel(tabNet1);
        labelPromisc1->setObjectName("labelPromisc1");

        gridLayoutNet1->addWidget(labelPromisc1, 8, 0, 1, 1);

        boxPromisc1 = new QCheckBox(tabNet1);
        boxPromisc1->setObjectName("boxPromisc1");

        gridLayoutNet1->addWidget(boxPromisc1, 8, 1, 1, 1);

        labelHostname1 = new QLabel(tabNet1);
        labelHostname1->setObjectName("labelHostname1");

        gridLayoutNet1->addWidget(labelHostname1, 9, 0, 1, 1);

        hostnameSwitch1 = new QLineEdit(tabNet1);
        hostnameSwitch1->setObjectName("hostnameSwitch1");
        hostnameSwitch1->setMaxLength(128);

        gridLayoutNet1->addWidget(hostnameSwitch1, 9, 1, 1, 1);

        verticalSpacerNIC1 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayoutNet1->addItem(verticalSpacerNIC1, 10, 1, 1, 1);

        tabWidgetNet->addTab(tabNet1, QString());
        tabNet2 = new QWidget();
        tabNet2->setObjectName("tabNet2");
        gridLayoutNet2 = new QGridLayout(tabNet2);
        gridLayoutNet2->setObjectName("gridLayoutNet2");
        labelMode2 = new QLabel(tabNet2);
        labelMode2->setObjectName("labelMode2");
        sizePolicy.setHeightForWidth(labelMode2->sizePolicy().hasHeightForWidth());
        labelMode2->setSizePolicy(sizePolicy);

        gridLayoutNet2->addWidget(labelMode2, 0, 0, 1, 1);

        comboBoxNet2 = new QComboBox(tabNet2);
        comboBoxNet2->setObjectName("comboBoxNet2");
        comboBoxNet2->setMaxVisibleItems(30);
        sizePolicy1.setHeightForWidth(comboBoxNet2->sizePolicy().hasHeightForWidth());
        comboBoxNet2->setSizePolicy(sizePolicy1);

        gridLayoutNet2->addWidget(comboBoxNet2, 0, 1, 1, 1);

        labelAdapter2 = new QLabel(tabNet2);
        labelAdapter2->setObjectName("labelAdapter2");
        sizePolicy.setHeightForWidth(labelAdapter2->sizePolicy().hasHeightForWidth());
        labelAdapter2->setSizePolicy(sizePolicy);

        gridLayoutNet2->addWidget(labelAdapter2, 1, 0, 1, 1);

        comboBoxNIC2 = new QComboBox(tabNet2);
        comboBoxNIC2->setObjectName("comboBoxNIC2");
        sizePolicy1.setHeightForWidth(comboBoxNIC2->sizePolicy().hasHeightForWidth());
        comboBoxNIC2->setSizePolicy(sizePolicy1);
        comboBoxNIC2->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBoxNIC2->setMaxVisibleItems(30);

        gridLayoutNet2->addWidget(comboBoxNIC2, 1, 1, 1, 1);

        pushButtonConf2 = new QPushButton(tabNet2);
        pushButtonConf2->setObjectName("pushButtonConf2");
        sizePolicy2.setHeightForWidth(pushButtonConf2->sizePolicy().hasHeightForWidth());
        pushButtonConf2->setSizePolicy(sizePolicy2);

        gridLayoutNet2->addWidget(pushButtonConf2, 1, 2, 1, 1);

        labelOptionList2 = new QLabel(tabNet2);
        labelOptionList2->setObjectName("labelOptionList2");

        gridLayoutNet2->addWidget(labelOptionList2, 2, 0, 1, 1);

        lineOptionList2 = new QFrame(tabNet2);
        lineOptionList2->setObjectName("lineOptionList2");
        lineOptionList2->setFrameShape(QFrame::Shape::HLine);
        lineOptionList2->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayoutNet2->addWidget(lineOptionList2, 2, 1, 1, 2);

        labelIntf2 = new QLabel(tabNet2);
        labelIntf2->setObjectName("labelIntf2");
        sizePolicy.setHeightForWidth(labelIntf2->sizePolicy().hasHeightForWidth());
        labelIntf2->setSizePolicy(sizePolicy);

        gridLayoutNet2->addWidget(labelIntf2, 3, 0, 1, 1);

        comboBoxIntf2 = new QComboBox(tabNet2);
        comboBoxIntf2->setObjectName("comboBoxIntf2");
        sizePolicy1.setHeightForWidth(comboBoxIntf2->sizePolicy().hasHeightForWidth());
        comboBoxIntf2->setSizePolicy(sizePolicy1);

        gridLayoutNet2->addWidget(comboBoxIntf2, 3, 1, 1, 1);

        labelSocketVDENIC2 = new QLabel(tabNet2);
        labelSocketVDENIC2->setObjectName("labelSocketVDENIC2");

        gridLayoutNet2->addWidget(labelSocketVDENIC2, 5, 0, 1, 1);

        socketVDENIC2 = new QLineEdit(tabNet2);
        socketVDENIC2->setObjectName("socketVDENIC2");
        socketVDENIC2->setMaxLength(127);

        gridLayoutNet2->addWidget(socketVDENIC2, 5, 1, 1, 1);

        labelBridgeTAPNIC2 = new QLabel(tabNet2);
        labelBridgeTAPNIC2->setObjectName("labelBridgeTAPNIC2");

        gridLayoutNet2->addWidget(labelBridgeTAPNIC2, 6, 0, 1, 1);

        bridgeTAPNIC2 = new QLineEdit(tabNet2);
        bridgeTAPNIC2->setObjectName("bridgeTAPNIC2");
        bridgeTAPNIC2->setMaxLength(127);

        gridLayoutNet2->addWidget(bridgeTAPNIC2, 6, 1, 1, 2);

        labelSwitch2 = new QLabel(tabNet2);
        labelSwitch2->setObjectName("labelSwitch2");

        gridLayoutNet2->addWidget(labelSwitch2, 7, 0, 1, 1);

        HLayoutSwitch2 = new QHBoxLayout();
        HLayoutSwitch2->setObjectName("HLayoutSwitch2");
        spinnerSwitch2 = new QSpinBox(tabNet2);
        spinnerSwitch2->setObjectName("spinnerSwitch2");
        spinnerSwitch2->setMinimum(1);
        spinnerSwitch2->setMaximum(10);

        HLayoutSwitch2->addWidget(spinnerSwitch2);

        horizontalSpacerSwitch2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        HLayoutSwitch2->addItem(horizontalSpacerSwitch2);


        gridLayoutNet2->addLayout(HLayoutSwitch2, 7, 1, 1, 1);

        labelPromisc2 = new QLabel(tabNet2);
        labelPromisc2->setObjectName("labelPromisc2");

        gridLayoutNet2->addWidget(labelPromisc2, 8, 0, 1, 1);

        boxPromisc2 = new QCheckBox(tabNet2);
        boxPromisc2->setObjectName("boxPromisc2");

        gridLayoutNet2->addWidget(boxPromisc2, 8, 1, 1, 1);

        labelHostname2 = new QLabel(tabNet2);
        labelHostname2->setObjectName("labelHostname2");

        gridLayoutNet2->addWidget(labelHostname2, 9, 0, 1, 1);

        hostnameSwitch2 = new QLineEdit(tabNet2);
        hostnameSwitch2->setObjectName("hostnameSwitch2");
        hostnameSwitch2->setMaxLength(128);

        gridLayoutNet2->addWidget(hostnameSwitch2, 9, 1, 1, 1);

        verticalSpacerNIC2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayoutNet2->addItem(verticalSpacerNIC2, 10, 1, 1, 1);

        tabWidgetNet->addTab(tabNet2, QString());
        tabNet3 = new QWidget();
        tabNet3->setObjectName("tabNet3");
        gridLayoutNet3 = new QGridLayout(tabNet3);
        gridLayoutNet3->setObjectName("gridLayoutNet3");
        labelMode3 = new QLabel(tabNet3);
        labelMode3->setObjectName("labelMode3");
        sizePolicy.setHeightForWidth(labelMode3->sizePolicy().hasHeightForWidth());
        labelMode3->setSizePolicy(sizePolicy);

        gridLayoutNet3->addWidget(labelMode3, 0, 0, 1, 1);

        comboBoxNet3 = new QComboBox(tabNet3);
        comboBoxNet3->setObjectName("comboBoxNet3");
        comboBoxNet3->setMaxVisibleItems(30);
        sizePolicy1.setHeightForWidth(comboBoxNet3->sizePolicy().hasHeightForWidth());
        comboBoxNet3->setSizePolicy(sizePolicy1);

        gridLayoutNet3->addWidget(comboBoxNet3, 0, 1, 1, 1);

        labelAdapter3 = new QLabel(tabNet3);
        labelAdapter3->setObjectName("labelAdapter3");
        sizePolicy.setHeightForWidth(labelAdapter3->sizePolicy().hasHeightForWidth());
        labelAdapter3->setSizePolicy(sizePolicy);

        gridLayoutNet3->addWidget(labelAdapter3, 1, 0, 1, 1);

        comboBoxNIC3 = new QComboBox(tabNet3);
        comboBoxNIC3->setObjectName("comboBoxNIC3");
        sizePolicy1.setHeightForWidth(comboBoxNIC3->sizePolicy().hasHeightForWidth());
        comboBoxNIC3->setSizePolicy(sizePolicy1);
        comboBoxNIC3->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBoxNIC3->setMaxVisibleItems(30);

        gridLayoutNet3->addWidget(comboBoxNIC3, 1, 1, 1, 1);

        pushButtonConf3 = new QPushButton(tabNet3);
        pushButtonConf3->setObjectName("pushButtonConf3");
        sizePolicy2.setHeightForWidth(pushButtonConf3->sizePolicy().hasHeightForWidth());
        pushButtonConf3->setSizePolicy(sizePolicy2);

        gridLayoutNet3->addWidget(pushButtonConf3, 1, 2, 1, 1);

        labelOptionList3 = new QLabel(tabNet3);
        labelOptionList3->setObjectName("labelOptionList3");

        gridLayoutNet3->addWidget(labelOptionList3, 2, 0, 1, 1);

        lineOptionList3 = new QFrame(tabNet3);
        lineOptionList3->setObjectName("lineOptionList3");
        lineOptionList3->setFrameShape(QFrame::Shape::HLine);
        lineOptionList3->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayoutNet3->addWidget(lineOptionList3, 2, 1, 1, 2);

        labelIntf3 = new QLabel(tabNet3);
        labelIntf3->setObjectName("labelIntf3");
        sizePolicy.setHeightForWidth(labelIntf3->sizePolicy().hasHeightForWidth());
        labelIntf3->setSizePolicy(sizePolicy);

        gridLayoutNet3->addWidget(labelIntf3, 3, 0, 1, 1);

        comboBoxIntf3 = new QComboBox(tabNet3);
        comboBoxIntf3->setObjectName("comboBoxIntf3");
        sizePolicy1.setHeightForWidth(comboBoxIntf3->sizePolicy().hasHeightForWidth());
        comboBoxIntf3->setSizePolicy(sizePolicy1);

        gridLayoutNet3->addWidget(comboBoxIntf3, 3, 1, 1, 1);

        labelSocketVDENIC3 = new QLabel(tabNet3);
        labelSocketVDENIC3->setObjectName("labelSocketVDENIC3");

        gridLayoutNet3->addWidget(labelSocketVDENIC3, 5, 0, 1, 1);

        socketVDENIC3 = new QLineEdit(tabNet3);
        socketVDENIC3->setObjectName("socketVDENIC3");
        socketVDENIC3->setMaxLength(127);

        gridLayoutNet3->addWidget(socketVDENIC3, 5, 1, 1, 1);

        labelBridgeTAPNIC3 = new QLabel(tabNet3);
        labelBridgeTAPNIC3->setObjectName("labelBridgeTAPNIC3");

        gridLayoutNet3->addWidget(labelBridgeTAPNIC3, 6, 0, 1, 1);

        bridgeTAPNIC3 = new QLineEdit(tabNet3);
        bridgeTAPNIC3->setObjectName("bridgeTAPNIC3");
        bridgeTAPNIC3->setMaxLength(127);

        gridLayoutNet3->addWidget(bridgeTAPNIC3, 6, 1, 1, 2);

        labelSwitch3 = new QLabel(tabNet3);
        labelSwitch3->setObjectName("labelSwitch3");

        gridLayoutNet3->addWidget(labelSwitch3, 7, 0, 1, 1);

        HLayoutSwitch3 = new QHBoxLayout();
        HLayoutSwitch3->setObjectName("HLayoutSwitch3");
        spinnerSwitch3 = new QSpinBox(tabNet3);
        spinnerSwitch3->setObjectName("spinnerSwitch3");
        spinnerSwitch3->setMinimum(1);
        spinnerSwitch3->setMaximum(10);

        HLayoutSwitch3->addWidget(spinnerSwitch3);

        horizontalSpacerSwitch3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        HLayoutSwitch3->addItem(horizontalSpacerSwitch3);


        gridLayoutNet3->addLayout(HLayoutSwitch3, 7, 1, 1, 1);

        labelPromisc3 = new QLabel(tabNet3);
        labelPromisc3->setObjectName("labelPromisc3");

        gridLayoutNet3->addWidget(labelPromisc3, 8, 0, 1, 1);

        boxPromisc3 = new QCheckBox(tabNet3);
        boxPromisc3->setObjectName("boxPromisc3");

        gridLayoutNet3->addWidget(boxPromisc3, 8, 1, 1, 1);

        labelHostname3 = new QLabel(tabNet3);
        labelHostname3->setObjectName("labelHostname3");

        gridLayoutNet3->addWidget(labelHostname3, 9, 0, 1, 1);

        hostnameSwitch3 = new QLineEdit(tabNet3);
        hostnameSwitch3->setObjectName("hostnameSwitch3");
        hostnameSwitch3->setMaxLength(128);

        gridLayoutNet3->addWidget(hostnameSwitch3, 9, 1, 1, 1);

        verticalSpacerNIC3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayoutNet3->addItem(verticalSpacerNIC3, 10, 1, 1, 1);

        tabWidgetNet->addTab(tabNet3, QString());
        tabNet4 = new QWidget();
        tabNet4->setObjectName("tabNet4");
        gridLayoutNet4 = new QGridLayout(tabNet4);
        gridLayoutNet4->setObjectName("gridLayoutNet4");
        labelMode4 = new QLabel(tabNet4);
        labelMode4->setObjectName("labelMode4");
        sizePolicy.setHeightForWidth(labelMode4->sizePolicy().hasHeightForWidth());
        labelMode4->setSizePolicy(sizePolicy);

        gridLayoutNet4->addWidget(labelMode4, 0, 0, 1, 1);

        comboBoxNet4 = new QComboBox(tabNet4);
        comboBoxNet4->setObjectName("comboBoxNet4");
        comboBoxNet4->setMaxVisibleItems(30);
        sizePolicy1.setHeightForWidth(comboBoxNet4->sizePolicy().hasHeightForWidth());
        comboBoxNet4->setSizePolicy(sizePolicy1);

        gridLayoutNet4->addWidget(comboBoxNet4, 0, 1, 1, 1);

        labelAdapter4 = new QLabel(tabNet4);
        labelAdapter4->setObjectName("labelAdapter4");
        sizePolicy.setHeightForWidth(labelAdapter4->sizePolicy().hasHeightForWidth());
        labelAdapter4->setSizePolicy(sizePolicy);

        gridLayoutNet4->addWidget(labelAdapter4, 1, 0, 1, 1);

        comboBoxNIC4 = new QComboBox(tabNet4);
        comboBoxNIC4->setObjectName("comboBoxNIC4");
        sizePolicy1.setHeightForWidth(comboBoxNIC4->sizePolicy().hasHeightForWidth());
        comboBoxNIC4->setSizePolicy(sizePolicy1);
        comboBoxNIC4->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBoxNIC4->setMaxVisibleItems(30);

        gridLayoutNet4->addWidget(comboBoxNIC4, 1, 1, 1, 1);

        pushButtonConf4 = new QPushButton(tabNet4);
        pushButtonConf4->setObjectName("pushButtonConf4");
        sizePolicy2.setHeightForWidth(pushButtonConf4->sizePolicy().hasHeightForWidth());
        pushButtonConf4->setSizePolicy(sizePolicy2);

        gridLayoutNet4->addWidget(pushButtonConf4, 1, 2, 1, 1);

        labelOptionList4 = new QLabel(tabNet4);
        labelOptionList4->setObjectName("labelOptionList4");

        gridLayoutNet4->addWidget(labelOptionList4, 2, 0, 1, 1);

        lineOptionList4 = new QFrame(tabNet4);
        lineOptionList4->setObjectName("lineOptionList4");
        lineOptionList4->setFrameShape(QFrame::Shape::HLine);
        lineOptionList4->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayoutNet4->addWidget(lineOptionList4, 2, 1, 1, 2);

        labelIntf4 = new QLabel(tabNet4);
        labelIntf4->setObjectName("labelIntf4");
        sizePolicy.setHeightForWidth(labelIntf4->sizePolicy().hasHeightForWidth());
        labelIntf4->setSizePolicy(sizePolicy);

        gridLayoutNet4->addWidget(labelIntf4, 3, 0, 1, 1);

        comboBoxIntf4 = new QComboBox(tabNet4);
        comboBoxIntf4->setObjectName("comboBoxIntf4");
        sizePolicy1.setHeightForWidth(comboBoxIntf4->sizePolicy().hasHeightForWidth());
        comboBoxIntf4->setSizePolicy(sizePolicy1);

        gridLayoutNet4->addWidget(comboBoxIntf4, 3, 1, 1, 1);

        labelSocketVDENIC4 = new QLabel(tabNet4);
        labelSocketVDENIC4->setObjectName("labelSocketVDENIC4");

        gridLayoutNet4->addWidget(labelSocketVDENIC4, 5, 0, 1, 1);

        socketVDENIC4 = new QLineEdit(tabNet4);
        socketVDENIC4->setObjectName("socketVDENIC4");
        socketVDENIC4->setMaxLength(127);

        gridLayoutNet4->addWidget(socketVDENIC4, 5, 1, 1, 1);

        labelBridgeTAPNIC4 = new QLabel(tabNet4);
        labelBridgeTAPNIC4->setObjectName("labelBridgeTAPNIC4");

        gridLayoutNet4->addWidget(labelBridgeTAPNIC4, 6, 0, 1, 1);

        bridgeTAPNIC4 = new QLineEdit(tabNet4);
        bridgeTAPNIC4->setObjectName("bridgeTAPNIC4");
        bridgeTAPNIC4->setMaxLength(127);

        gridLayoutNet4->addWidget(bridgeTAPNIC4, 6, 1, 1, 2);

        labelSwitch4 = new QLabel(tabNet4);
        labelSwitch4->setObjectName("labelSwitch4");

        gridLayoutNet4->addWidget(labelSwitch4, 7, 0, 1, 1);

        HLayoutSwitch4 = new QHBoxLayout();
        HLayoutSwitch4->setObjectName("HLayoutSwitch4");
        spinnerSwitch4 = new QSpinBox(tabNet4);
        spinnerSwitch4->setObjectName("spinnerSwitch4");
        spinnerSwitch4->setMinimum(1);
        spinnerSwitch4->setMaximum(10);

        HLayoutSwitch4->addWidget(spinnerSwitch4);

        horizontalSpacerSwitch4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        HLayoutSwitch4->addItem(horizontalSpacerSwitch4);


        gridLayoutNet4->addLayout(HLayoutSwitch4, 7, 1, 1, 1);

        labelPromisc4 = new QLabel(tabNet4);
        labelPromisc4->setObjectName("labelPromisc4");

        gridLayoutNet4->addWidget(labelPromisc4, 8, 0, 1, 1);

        boxPromisc4 = new QCheckBox(tabNet4);
        boxPromisc4->setObjectName("boxPromisc4");

        gridLayoutNet4->addWidget(boxPromisc4, 8, 1, 1, 1);

        labelHostname4 = new QLabel(tabNet4);
        labelHostname4->setObjectName("labelHostname4");

        gridLayoutNet4->addWidget(labelHostname4, 9, 0, 1, 1);

        hostnameSwitch4 = new QLineEdit(tabNet4);
        hostnameSwitch4->setObjectName("hostnameSwitch4");
        hostnameSwitch4->setMaxLength(128);

        gridLayoutNet4->addWidget(hostnameSwitch4, 9, 1, 1, 1);

        verticalSpacerNIC4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayoutNet4->addItem(verticalSpacerNIC4, 10, 1, 1, 1);

        tabWidgetNet->addTab(tabNet4, QString());

        verticalLayout->addWidget(tabWidgetNet);


        retranslateUi(SettingsNetwork);

        tabWidgetNet->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingsNetwork);
    } // setupUi

    void retranslateUi(QWidget *SettingsNetwork)
    {
        SettingsNetwork->setWindowTitle(QCoreApplication::translate("SettingsNetwork", "Form", nullptr));
        labelMode1->setText(QCoreApplication::translate("SettingsNetwork", "Mode:", nullptr));
        labelAdapter1->setText(QCoreApplication::translate("SettingsNetwork", "Adapter:", nullptr));
        pushButtonConf1->setText(QCoreApplication::translate("SettingsNetwork", "Configure", nullptr));
        labelOptionList1->setText(QCoreApplication::translate("SettingsNetwork", "Options", nullptr));
        labelIntf1->setText(QCoreApplication::translate("SettingsNetwork", "Interface:", nullptr));
        labelSocketVDENIC1->setText(QCoreApplication::translate("SettingsNetwork", "VDE Socket:", nullptr));
        labelBridgeTAPNIC1->setText(QCoreApplication::translate("SettingsNetwork", "TAP Bridge Device", nullptr));
        labelSwitch1->setText(QCoreApplication::translate("SettingsNetwork", "Switch:", nullptr));
        labelPromisc1->setText(QCoreApplication::translate("SettingsNetwork", "Hub Mode", nullptr));
        boxPromisc1->setText(QString());
        labelHostname1->setText(QCoreApplication::translate("SettingsNetwork", "Hostname:", nullptr));
        tabWidgetNet->setTabText(tabWidgetNet->indexOf(tabNet1), QCoreApplication::translate("SettingsNetwork", "Network Card #1", nullptr));
        labelMode2->setText(QCoreApplication::translate("SettingsNetwork", "Mode:", nullptr));
        labelAdapter2->setText(QCoreApplication::translate("SettingsNetwork", "Adapter:", nullptr));
        pushButtonConf2->setText(QCoreApplication::translate("SettingsNetwork", "Configure", nullptr));
        labelOptionList2->setText(QCoreApplication::translate("SettingsNetwork", "Options", nullptr));
        labelIntf2->setText(QCoreApplication::translate("SettingsNetwork", "Interface:", nullptr));
        labelSocketVDENIC2->setText(QCoreApplication::translate("SettingsNetwork", "VDE Socket:", nullptr));
        labelBridgeTAPNIC2->setText(QCoreApplication::translate("SettingsNetwork", "TAP Bridge Device", nullptr));
        labelSwitch2->setText(QCoreApplication::translate("SettingsNetwork", "Switch:", nullptr));
        labelPromisc2->setText(QCoreApplication::translate("SettingsNetwork", "Hub Mode", nullptr));
        boxPromisc2->setText(QString());
        labelHostname2->setText(QCoreApplication::translate("SettingsNetwork", "Hostname:", nullptr));
        tabWidgetNet->setTabText(tabWidgetNet->indexOf(tabNet2), QCoreApplication::translate("SettingsNetwork", "Network Card #2", nullptr));
        labelMode3->setText(QCoreApplication::translate("SettingsNetwork", "Mode:", nullptr));
        labelAdapter3->setText(QCoreApplication::translate("SettingsNetwork", "Adapter:", nullptr));
        pushButtonConf3->setText(QCoreApplication::translate("SettingsNetwork", "Configure", nullptr));
        labelOptionList3->setText(QCoreApplication::translate("SettingsNetwork", "Options", nullptr));
        labelIntf3->setText(QCoreApplication::translate("SettingsNetwork", "Interface:", nullptr));
        labelSocketVDENIC3->setText(QCoreApplication::translate("SettingsNetwork", "VDE Socket:", nullptr));
        labelBridgeTAPNIC3->setText(QCoreApplication::translate("SettingsNetwork", "TAP Bridge Device", nullptr));
        labelSwitch3->setText(QCoreApplication::translate("SettingsNetwork", "Switch:", nullptr));
        labelPromisc3->setText(QCoreApplication::translate("SettingsNetwork", "Hub Mode", nullptr));
        boxPromisc3->setText(QString());
        labelHostname3->setText(QCoreApplication::translate("SettingsNetwork", "Hostname:", nullptr));
        tabWidgetNet->setTabText(tabWidgetNet->indexOf(tabNet3), QCoreApplication::translate("SettingsNetwork", "Network Card #3", nullptr));
        labelMode4->setText(QCoreApplication::translate("SettingsNetwork", "Mode:", nullptr));
        labelAdapter4->setText(QCoreApplication::translate("SettingsNetwork", "Adapter:", nullptr));
        pushButtonConf4->setText(QCoreApplication::translate("SettingsNetwork", "Configure", nullptr));
        labelOptionList4->setText(QCoreApplication::translate("SettingsNetwork", "Options", nullptr));
        labelIntf4->setText(QCoreApplication::translate("SettingsNetwork", "Interface:", nullptr));
        labelSocketVDENIC4->setText(QCoreApplication::translate("SettingsNetwork", "VDE Socket:", nullptr));
        labelBridgeTAPNIC4->setText(QCoreApplication::translate("SettingsNetwork", "TAP Bridge Device", nullptr));
        labelSwitch4->setText(QCoreApplication::translate("SettingsNetwork", "Switch:", nullptr));
        labelPromisc4->setText(QCoreApplication::translate("SettingsNetwork", "Hub Mode", nullptr));
        boxPromisc4->setText(QString());
        labelHostname4->setText(QCoreApplication::translate("SettingsNetwork", "Hostname:", nullptr));
        tabWidgetNet->setTabText(tabWidgetNet->indexOf(tabNet4), QCoreApplication::translate("SettingsNetwork", "Network Card #4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsNetwork: public Ui_SettingsNetwork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SETTINGSNETWORK_H

/********************************************************************************
** Form generated from reading UI file 'qt_settingsotherperipherals.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SETTINGSOTHERPERIPHERALS_H
#define UI_QT_SETTINGSOTHERPERIPHERALS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsOtherPeripherals
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayoutRtc;
    QLabel *labelRtc;
    QComboBox *comboBoxRTC;
    QPushButton *pushButtonConfigureRTC;
    QGroupBox *groupBoxMem;
    QGridLayout *gridLayoutMem;
    QLabel *labelIsaMemCard1;
    QComboBox *comboBoxIsaMemCard1;
    QPushButton *pushButtonConfigureIsaMemCard1;
    QLabel *labelIsaMemCard2;
    QComboBox *comboBoxIsaMemCard2;
    QPushButton *pushButtonConfigureIsaMemCard2;
    QLabel *labelIsaMemCard3;
    QComboBox *comboBoxIsaMemCard3;
    QPushButton *pushButtonConfigureIsaMemCard3;
    QLabel *labelIsaMemCard4;
    QComboBox *comboBoxIsaMemCard4;
    QPushButton *pushButtonConfigureIsaMemCard4;
    QGroupBox *groupBoxRom;
    QGridLayout *gridLayoutRom;
    QLabel *labelIsaRomCard1;
    QComboBox *comboBoxIsaRomCard1;
    QPushButton *pushButtonConfigureIsaRomCard1;
    QLabel *labelIsaRomCard2;
    QComboBox *comboBoxIsaRomCard2;
    QPushButton *pushButtonConfigureIsaRomCard2;
    QLabel *labelIsaRomCard3;
    QComboBox *comboBoxIsaRomCard3;
    QPushButton *pushButtonConfigureIsaRomCard3;
    QLabel *labelIsaRomCard4;
    QComboBox *comboBoxIsaRomCard4;
    QPushButton *pushButtonConfigureIsaRomCard4;
    QHBoxLayout *horizontalLayoutIBPC;
    QCheckBox *checkBoxISABugger;
    QCheckBox *checkBoxPOSTCard;
    QHBoxLayout *horizontalLayoutUT;
    QCheckBox *checkBoxUnitTester;
    QPushButton *pushButtonConfigureUT;
    QHBoxLayout *horizontalLayoutKeyCard;
    QCheckBox *checkBoxKeyCard;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonConfigureKeyCard;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SettingsOtherPeripherals)
    {
        if (SettingsOtherPeripherals->objectName().isEmpty())
            SettingsOtherPeripherals->setObjectName("SettingsOtherPeripherals");
        SettingsOtherPeripherals->resize(421, 458);
        verticalLayout = new QVBoxLayout(SettingsOtherPeripherals);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutRtc = new QHBoxLayout();
        horizontalLayoutRtc->setObjectName("horizontalLayoutRtc");
        labelRtc = new QLabel(SettingsOtherPeripherals);
        labelRtc->setObjectName("labelRtc");

        horizontalLayoutRtc->addWidget(labelRtc);

        comboBoxRTC = new QComboBox(SettingsOtherPeripherals);
        comboBoxRTC->setObjectName("comboBoxRTC");
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxRTC->sizePolicy().hasHeightForWidth());
        comboBoxRTC->setSizePolicy(sizePolicy);
        comboBoxRTC->setMaxVisibleItems(30);

        horizontalLayoutRtc->addWidget(comboBoxRTC);

        pushButtonConfigureRTC = new QPushButton(SettingsOtherPeripherals);
        pushButtonConfigureRTC->setObjectName("pushButtonConfigureRTC");

        horizontalLayoutRtc->addWidget(pushButtonConfigureRTC);


        verticalLayout->addLayout(horizontalLayoutRtc);

        groupBoxMem = new QGroupBox(SettingsOtherPeripherals);
        groupBoxMem->setObjectName("groupBoxMem");
        gridLayoutMem = new QGridLayout(groupBoxMem);
        gridLayoutMem->setObjectName("gridLayoutMem");
        labelIsaMemCard1 = new QLabel(groupBoxMem);
        labelIsaMemCard1->setObjectName("labelIsaMemCard1");

        gridLayoutMem->addWidget(labelIsaMemCard1, 0, 0, 1, 1);

        comboBoxIsaMemCard1 = new QComboBox(groupBoxMem);
        comboBoxIsaMemCard1->setObjectName("comboBoxIsaMemCard1");
        sizePolicy.setHeightForWidth(comboBoxIsaMemCard1->sizePolicy().hasHeightForWidth());
        comboBoxIsaMemCard1->setSizePolicy(sizePolicy);
        comboBoxIsaMemCard1->setMaxVisibleItems(30);

        gridLayoutMem->addWidget(comboBoxIsaMemCard1, 0, 1, 1, 1);

        pushButtonConfigureIsaMemCard1 = new QPushButton(groupBoxMem);
        pushButtonConfigureIsaMemCard1->setObjectName("pushButtonConfigureIsaMemCard1");

        gridLayoutMem->addWidget(pushButtonConfigureIsaMemCard1, 0, 2, 1, 1);

        labelIsaMemCard2 = new QLabel(groupBoxMem);
        labelIsaMemCard2->setObjectName("labelIsaMemCard2");

        gridLayoutMem->addWidget(labelIsaMemCard2, 1, 0, 1, 1);

        comboBoxIsaMemCard2 = new QComboBox(groupBoxMem);
        comboBoxIsaMemCard2->setObjectName("comboBoxIsaMemCard2");
        sizePolicy.setHeightForWidth(comboBoxIsaMemCard2->sizePolicy().hasHeightForWidth());
        comboBoxIsaMemCard2->setSizePolicy(sizePolicy);
        comboBoxIsaMemCard2->setMaxVisibleItems(30);

        gridLayoutMem->addWidget(comboBoxIsaMemCard2, 1, 1, 1, 1);

        pushButtonConfigureIsaMemCard2 = new QPushButton(groupBoxMem);
        pushButtonConfigureIsaMemCard2->setObjectName("pushButtonConfigureIsaMemCard2");

        gridLayoutMem->addWidget(pushButtonConfigureIsaMemCard2, 1, 2, 1, 1);

        labelIsaMemCard3 = new QLabel(groupBoxMem);
        labelIsaMemCard3->setObjectName("labelIsaMemCard3");

        gridLayoutMem->addWidget(labelIsaMemCard3, 2, 0, 1, 1);

        comboBoxIsaMemCard3 = new QComboBox(groupBoxMem);
        comboBoxIsaMemCard3->setObjectName("comboBoxIsaMemCard3");
        sizePolicy.setHeightForWidth(comboBoxIsaMemCard3->sizePolicy().hasHeightForWidth());
        comboBoxIsaMemCard3->setSizePolicy(sizePolicy);
        comboBoxIsaMemCard3->setMaxVisibleItems(30);

        gridLayoutMem->addWidget(comboBoxIsaMemCard3, 2, 1, 1, 1);

        pushButtonConfigureIsaMemCard3 = new QPushButton(groupBoxMem);
        pushButtonConfigureIsaMemCard3->setObjectName("pushButtonConfigureIsaMemCard3");

        gridLayoutMem->addWidget(pushButtonConfigureIsaMemCard3, 2, 2, 1, 1);

        labelIsaMemCard4 = new QLabel(groupBoxMem);
        labelIsaMemCard4->setObjectName("labelIsaMemCard4");

        gridLayoutMem->addWidget(labelIsaMemCard4, 3, 0, 1, 1);

        comboBoxIsaMemCard4 = new QComboBox(groupBoxMem);
        comboBoxIsaMemCard4->setObjectName("comboBoxIsaMemCard4");
        sizePolicy.setHeightForWidth(comboBoxIsaMemCard4->sizePolicy().hasHeightForWidth());
        comboBoxIsaMemCard4->setSizePolicy(sizePolicy);
        comboBoxIsaMemCard4->setMaxVisibleItems(30);

        gridLayoutMem->addWidget(comboBoxIsaMemCard4, 3, 1, 1, 1);

        pushButtonConfigureIsaMemCard4 = new QPushButton(groupBoxMem);
        pushButtonConfigureIsaMemCard4->setObjectName("pushButtonConfigureIsaMemCard4");

        gridLayoutMem->addWidget(pushButtonConfigureIsaMemCard4, 3, 2, 1, 1);


        verticalLayout->addWidget(groupBoxMem);

        groupBoxRom = new QGroupBox(SettingsOtherPeripherals);
        groupBoxRom->setObjectName("groupBoxRom");
        gridLayoutRom = new QGridLayout(groupBoxRom);
        gridLayoutRom->setObjectName("gridLayoutRom");
        labelIsaRomCard1 = new QLabel(groupBoxRom);
        labelIsaRomCard1->setObjectName("labelIsaRomCard1");

        gridLayoutRom->addWidget(labelIsaRomCard1, 0, 0, 1, 1);

        comboBoxIsaRomCard1 = new QComboBox(groupBoxRom);
        comboBoxIsaRomCard1->setObjectName("comboBoxIsaRomCard1");
        sizePolicy.setHeightForWidth(comboBoxIsaRomCard1->sizePolicy().hasHeightForWidth());
        comboBoxIsaRomCard1->setSizePolicy(sizePolicy);
        comboBoxIsaRomCard1->setMaxVisibleItems(30);

        gridLayoutRom->addWidget(comboBoxIsaRomCard1, 0, 1, 1, 1);

        pushButtonConfigureIsaRomCard1 = new QPushButton(groupBoxRom);
        pushButtonConfigureIsaRomCard1->setObjectName("pushButtonConfigureIsaRomCard1");

        gridLayoutRom->addWidget(pushButtonConfigureIsaRomCard1, 0, 2, 1, 1);

        labelIsaRomCard2 = new QLabel(groupBoxRom);
        labelIsaRomCard2->setObjectName("labelIsaRomCard2");

        gridLayoutRom->addWidget(labelIsaRomCard2, 1, 0, 1, 1);

        comboBoxIsaRomCard2 = new QComboBox(groupBoxRom);
        comboBoxIsaRomCard2->setObjectName("comboBoxIsaRomCard2");
        sizePolicy.setHeightForWidth(comboBoxIsaRomCard2->sizePolicy().hasHeightForWidth());
        comboBoxIsaRomCard2->setSizePolicy(sizePolicy);
        comboBoxIsaRomCard2->setMaxVisibleItems(30);

        gridLayoutRom->addWidget(comboBoxIsaRomCard2, 1, 1, 1, 1);

        pushButtonConfigureIsaRomCard2 = new QPushButton(groupBoxRom);
        pushButtonConfigureIsaRomCard2->setObjectName("pushButtonConfigureIsaRomCard2");

        gridLayoutRom->addWidget(pushButtonConfigureIsaRomCard2, 1, 2, 1, 1);

        labelIsaRomCard3 = new QLabel(groupBoxRom);
        labelIsaRomCard3->setObjectName("labelIsaRomCard3");

        gridLayoutRom->addWidget(labelIsaRomCard3, 2, 0, 1, 1);

        comboBoxIsaRomCard3 = new QComboBox(groupBoxRom);
        comboBoxIsaRomCard3->setObjectName("comboBoxIsaRomCard3");
        sizePolicy.setHeightForWidth(comboBoxIsaRomCard3->sizePolicy().hasHeightForWidth());
        comboBoxIsaRomCard3->setSizePolicy(sizePolicy);
        comboBoxIsaRomCard3->setMaxVisibleItems(30);

        gridLayoutRom->addWidget(comboBoxIsaRomCard3, 2, 1, 1, 1);

        pushButtonConfigureIsaRomCard3 = new QPushButton(groupBoxRom);
        pushButtonConfigureIsaRomCard3->setObjectName("pushButtonConfigureIsaRomCard3");

        gridLayoutRom->addWidget(pushButtonConfigureIsaRomCard3, 2, 2, 1, 1);

        labelIsaRomCard4 = new QLabel(groupBoxRom);
        labelIsaRomCard4->setObjectName("labelIsaRomCard4");

        gridLayoutRom->addWidget(labelIsaRomCard4, 3, 0, 1, 1);

        comboBoxIsaRomCard4 = new QComboBox(groupBoxRom);
        comboBoxIsaRomCard4->setObjectName("comboBoxIsaRomCard4");
        sizePolicy.setHeightForWidth(comboBoxIsaRomCard4->sizePolicy().hasHeightForWidth());
        comboBoxIsaRomCard4->setSizePolicy(sizePolicy);
        comboBoxIsaRomCard4->setMaxVisibleItems(30);

        gridLayoutRom->addWidget(comboBoxIsaRomCard4, 3, 1, 1, 1);

        pushButtonConfigureIsaRomCard4 = new QPushButton(groupBoxRom);
        pushButtonConfigureIsaRomCard4->setObjectName("pushButtonConfigureIsaRomCard4");

        gridLayoutRom->addWidget(pushButtonConfigureIsaRomCard4, 3, 2, 1, 1);


        verticalLayout->addWidget(groupBoxRom);

        horizontalLayoutIBPC = new QHBoxLayout();
        horizontalLayoutIBPC->setObjectName("horizontalLayoutIBPC");
        checkBoxISABugger = new QCheckBox(SettingsOtherPeripherals);
        checkBoxISABugger->setObjectName("checkBoxISABugger");

        horizontalLayoutIBPC->addWidget(checkBoxISABugger);

        checkBoxPOSTCard = new QCheckBox(SettingsOtherPeripherals);
        checkBoxPOSTCard->setObjectName("checkBoxPOSTCard");

        horizontalLayoutIBPC->addWidget(checkBoxPOSTCard);


        verticalLayout->addLayout(horizontalLayoutIBPC);

        horizontalLayoutUT = new QHBoxLayout();
        horizontalLayoutUT->setObjectName("horizontalLayoutUT");
        checkBoxUnitTester = new QCheckBox(SettingsOtherPeripherals);
        checkBoxUnitTester->setObjectName("checkBoxUnitTester");
        sizePolicy.setHeightForWidth(checkBoxUnitTester->sizePolicy().hasHeightForWidth());
        checkBoxUnitTester->setSizePolicy(sizePolicy);

        horizontalLayoutUT->addWidget(checkBoxUnitTester);

        pushButtonConfigureUT = new QPushButton(SettingsOtherPeripherals);
        pushButtonConfigureUT->setObjectName("pushButtonConfigureUT");

        horizontalLayoutUT->addWidget(pushButtonConfigureUT);


        verticalLayout->addLayout(horizontalLayoutUT);

        horizontalLayoutKeyCard = new QHBoxLayout();
        horizontalLayoutKeyCard->setObjectName("horizontalLayoutKeyCard");
        horizontalLayoutKeyCard->setContentsMargins(-1, 0, -1, -1);
        checkBoxKeyCard = new QCheckBox(SettingsOtherPeripherals);
        checkBoxKeyCard->setObjectName("checkBoxKeyCard");

        horizontalLayoutKeyCard->addWidget(checkBoxKeyCard);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutKeyCard->addItem(horizontalSpacer);

        pushButtonConfigureKeyCard = new QPushButton(SettingsOtherPeripherals);
        pushButtonConfigureKeyCard->setObjectName("pushButtonConfigureKeyCard");

        horizontalLayoutKeyCard->addWidget(pushButtonConfigureKeyCard);


        verticalLayout->addLayout(horizontalLayoutKeyCard);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        QWidget::setTabOrder(comboBoxRTC, pushButtonConfigureRTC);
        QWidget::setTabOrder(pushButtonConfigureRTC, comboBoxIsaMemCard1);
        QWidget::setTabOrder(comboBoxIsaMemCard1, pushButtonConfigureIsaMemCard1);
        QWidget::setTabOrder(pushButtonConfigureIsaMemCard1, comboBoxIsaMemCard2);
        QWidget::setTabOrder(comboBoxIsaMemCard2, pushButtonConfigureIsaMemCard2);
        QWidget::setTabOrder(pushButtonConfigureIsaMemCard2, comboBoxIsaMemCard3);
        QWidget::setTabOrder(comboBoxIsaMemCard3, pushButtonConfigureIsaMemCard3);
        QWidget::setTabOrder(pushButtonConfigureIsaMemCard3, comboBoxIsaMemCard4);
        QWidget::setTabOrder(comboBoxIsaMemCard4, pushButtonConfigureIsaMemCard4);
        QWidget::setTabOrder(pushButtonConfigureIsaMemCard4, comboBoxIsaRomCard1);
        QWidget::setTabOrder(comboBoxIsaRomCard1, pushButtonConfigureIsaRomCard1);
        QWidget::setTabOrder(pushButtonConfigureIsaRomCard1, comboBoxIsaRomCard2);
        QWidget::setTabOrder(comboBoxIsaRomCard2, pushButtonConfigureIsaRomCard2);
        QWidget::setTabOrder(pushButtonConfigureIsaRomCard2, comboBoxIsaRomCard3);
        QWidget::setTabOrder(comboBoxIsaRomCard3, pushButtonConfigureIsaRomCard3);
        QWidget::setTabOrder(pushButtonConfigureIsaRomCard3, comboBoxIsaRomCard4);
        QWidget::setTabOrder(comboBoxIsaRomCard4, pushButtonConfigureIsaRomCard4);
        QWidget::setTabOrder(pushButtonConfigureIsaRomCard4, checkBoxISABugger);
        QWidget::setTabOrder(checkBoxISABugger, checkBoxPOSTCard);
        QWidget::setTabOrder(checkBoxPOSTCard, checkBoxUnitTester);
        QWidget::setTabOrder(checkBoxUnitTester, pushButtonConfigureUT);
        QWidget::setTabOrder(pushButtonConfigureUT, checkBoxKeyCard);
        QWidget::setTabOrder(checkBoxKeyCard, pushButtonConfigureKeyCard);

        retranslateUi(SettingsOtherPeripherals);

        QMetaObject::connectSlotsByName(SettingsOtherPeripherals);
    } // setupUi

    void retranslateUi(QWidget *SettingsOtherPeripherals)
    {
        SettingsOtherPeripherals->setWindowTitle(QCoreApplication::translate("SettingsOtherPeripherals", "Form", nullptr));
        labelRtc->setText(QCoreApplication::translate("SettingsOtherPeripherals", "ISA RTC:", nullptr));
        pushButtonConfigureRTC->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Configure", nullptr));
        groupBoxMem->setTitle(QCoreApplication::translate("SettingsOtherPeripherals", "ISA Memory Expansion", nullptr));
        labelIsaMemCard1->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Card 1:", nullptr));
        pushButtonConfigureIsaMemCard1->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Configure", nullptr));
        labelIsaMemCard2->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Card 2:", nullptr));
        pushButtonConfigureIsaMemCard2->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Configure", nullptr));
        labelIsaMemCard3->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Card 3:", nullptr));
        pushButtonConfigureIsaMemCard3->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Configure", nullptr));
        labelIsaMemCard4->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Card 4:", nullptr));
        pushButtonConfigureIsaMemCard4->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Configure", nullptr));
        groupBoxRom->setTitle(QCoreApplication::translate("SettingsOtherPeripherals", "ISA ROM Cards", nullptr));
        labelIsaRomCard1->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Card 1:", nullptr));
        pushButtonConfigureIsaRomCard1->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Configure", nullptr));
        labelIsaRomCard2->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Card 2:", nullptr));
        pushButtonConfigureIsaRomCard2->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Configure", nullptr));
        labelIsaRomCard3->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Card 3:", nullptr));
        pushButtonConfigureIsaRomCard3->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Configure", nullptr));
        labelIsaRomCard4->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Card 4:", nullptr));
        pushButtonConfigureIsaRomCard4->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Configure", nullptr));
        checkBoxISABugger->setText(QCoreApplication::translate("SettingsOtherPeripherals", "ISABugger device", nullptr));
        checkBoxPOSTCard->setText(QCoreApplication::translate("SettingsOtherPeripherals", "POST card", nullptr));
        checkBoxUnitTester->setText(QCoreApplication::translate("SettingsOtherPeripherals", "86Box Unit Tester", nullptr));
        pushButtonConfigureUT->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Configure", nullptr));
        checkBoxKeyCard->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Novell NetWare 2.x Key Card", nullptr));
        pushButtonConfigureKeyCard->setText(QCoreApplication::translate("SettingsOtherPeripherals", "Configure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsOtherPeripherals: public Ui_SettingsOtherPeripherals {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SETTINGSOTHERPERIPHERALS_H

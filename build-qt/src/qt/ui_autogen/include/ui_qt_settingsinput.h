/********************************************************************************
** Form generated from reading UI file 'qt_settingsinput.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SETTINGSINPUT_H
#define UI_QT_SETTINGSINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsInput
{
public:
    QGridLayout *gridLayout;
    QLabel *labelKeyboard;
    QComboBox *comboBoxKeyboard;
    QPushButton *pushButtonConfigureKeyboard;
    QLabel *labelMouse;
    QComboBox *comboBoxMouse;
    QPushButton *pushButtonConfigureMouse;
    QLabel *labelJoystick0;
    QComboBox *comboBoxJoystick0;
    QPushButton *pushButtonJoystick01;
    QPushButton *pushButtonJoystick02;
    QPushButton *pushButtonJoystick03;
    QPushButton *pushButtonJoystick04;
    QLabel *labelKeys;
    QTableWidget *tableKeys;
    QPushButton *pushButtonClearBind;
    QPushButton *pushButtonBind;

    void setupUi(QWidget *SettingsInput)
    {
        if (SettingsInput->objectName().isEmpty())
            SettingsInput->setObjectName("SettingsInput");
        SettingsInput->resize(400, 300);
        gridLayout = new QGridLayout(SettingsInput);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, -1);
        labelKeyboard = new QLabel(SettingsInput);
        labelKeyboard->setObjectName("labelKeyboard");

        gridLayout->addWidget(labelKeyboard, 0, 0, 1, 1);

        comboBoxKeyboard = new QComboBox(SettingsInput);
        comboBoxKeyboard->setObjectName("comboBoxKeyboard");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxKeyboard->sizePolicy().hasHeightForWidth());
        comboBoxKeyboard->setSizePolicy(sizePolicy);
        comboBoxKeyboard->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxKeyboard, 0, 1, 1, 2);

        pushButtonConfigureKeyboard = new QPushButton(SettingsInput);
        pushButtonConfigureKeyboard->setObjectName("pushButtonConfigureKeyboard");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonConfigureKeyboard->sizePolicy().hasHeightForWidth());
        pushButtonConfigureKeyboard->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButtonConfigureKeyboard, 0, 3, 1, 1);

        labelMouse = new QLabel(SettingsInput);
        labelMouse->setObjectName("labelMouse");

        gridLayout->addWidget(labelMouse, 1, 0, 1, 1);

        comboBoxMouse = new QComboBox(SettingsInput);
        comboBoxMouse->setObjectName("comboBoxMouse");
        sizePolicy.setHeightForWidth(comboBoxMouse->sizePolicy().hasHeightForWidth());
        comboBoxMouse->setSizePolicy(sizePolicy);
        comboBoxMouse->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxMouse, 1, 1, 1, 2);

        pushButtonConfigureMouse = new QPushButton(SettingsInput);
        pushButtonConfigureMouse->setObjectName("pushButtonConfigureMouse");
        sizePolicy1.setHeightForWidth(pushButtonConfigureMouse->sizePolicy().hasHeightForWidth());
        pushButtonConfigureMouse->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButtonConfigureMouse, 1, 3, 1, 1);

        labelJoystick0 = new QLabel(SettingsInput);
        labelJoystick0->setObjectName("labelJoystick0");

        gridLayout->addWidget(labelJoystick0, 2, 0, 1, 1);

        comboBoxJoystick0 = new QComboBox(SettingsInput);
        comboBoxJoystick0->setObjectName("comboBoxJoystick0");
        comboBoxJoystick0->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxJoystick0, 2, 1, 1, 2);

        pushButtonJoystick01 = new QPushButton(SettingsInput);
        pushButtonJoystick01->setObjectName("pushButtonJoystick01");

        gridLayout->addWidget(pushButtonJoystick01, 3, 0, 1, 1);

        pushButtonJoystick02 = new QPushButton(SettingsInput);
        pushButtonJoystick02->setObjectName("pushButtonJoystick02");

        gridLayout->addWidget(pushButtonJoystick02, 3, 1, 1, 1);

        pushButtonJoystick03 = new QPushButton(SettingsInput);
        pushButtonJoystick03->setObjectName("pushButtonJoystick03");

        gridLayout->addWidget(pushButtonJoystick03, 3, 2, 1, 1);

        pushButtonJoystick04 = new QPushButton(SettingsInput);
        pushButtonJoystick04->setObjectName("pushButtonJoystick04");

        gridLayout->addWidget(pushButtonJoystick04, 3, 3, 1, 1);

        labelKeys = new QLabel(SettingsInput);
        labelKeys->setObjectName("labelKeys");

        gridLayout->addWidget(labelKeys, 4, 0, 1, 1);

        tableKeys = new QTableWidget(SettingsInput);
        tableKeys->setObjectName("tableKeys");
        tableKeys->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableKeys->setTabKeyNavigation(false);
        tableKeys->setProperty("showDropIndicator", QVariant(false));
        tableKeys->setAlternatingRowColors(true);
        tableKeys->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout->addWidget(tableKeys, 5, 0, 1, 4);

        pushButtonClearBind = new QPushButton(SettingsInput);
        pushButtonClearBind->setObjectName("pushButtonClearBind");
        pushButtonClearBind->setEnabled(false);

        gridLayout->addWidget(pushButtonClearBind, 6, 2, 1, 1);

        pushButtonBind = new QPushButton(SettingsInput);
        pushButtonBind->setObjectName("pushButtonBind");
        pushButtonBind->setEnabled(false);

        gridLayout->addWidget(pushButtonBind, 6, 3, 1, 1);


        retranslateUi(SettingsInput);

        QMetaObject::connectSlotsByName(SettingsInput);
    } // setupUi

    void retranslateUi(QWidget *SettingsInput)
    {
        SettingsInput->setWindowTitle(QCoreApplication::translate("SettingsInput", "Form", nullptr));
        labelKeyboard->setText(QCoreApplication::translate("SettingsInput", "Keyboard:", nullptr));
        pushButtonConfigureKeyboard->setText(QCoreApplication::translate("SettingsInput", "Configure", nullptr));
        labelMouse->setText(QCoreApplication::translate("SettingsInput", "Mouse:", nullptr));
        pushButtonConfigureMouse->setText(QCoreApplication::translate("SettingsInput", "Configure", nullptr));
        labelJoystick0->setText(QCoreApplication::translate("SettingsInput", "Joystick:", nullptr));
        pushButtonJoystick01->setText(QCoreApplication::translate("SettingsInput", "Joystick 1...", nullptr));
        pushButtonJoystick02->setText(QCoreApplication::translate("SettingsInput", "Joystick 2...", nullptr));
        pushButtonJoystick03->setText(QCoreApplication::translate("SettingsInput", "Joystick 3...", nullptr));
        pushButtonJoystick04->setText(QCoreApplication::translate("SettingsInput", "Joystick 4...", nullptr));
        labelKeys->setText(QCoreApplication::translate("SettingsInput", "Key Bindings:", nullptr));
        pushButtonClearBind->setText(QCoreApplication::translate("SettingsInput", "Clear binding", nullptr));
        pushButtonBind->setText(QCoreApplication::translate("SettingsInput", "Bind", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsInput: public Ui_SettingsInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SETTINGSINPUT_H

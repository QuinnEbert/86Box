/********************************************************************************
** Form generated from reading UI file 'qt_settingsdisplay.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SETTINGSDISPLAY_H
#define UI_QT_SETTINGSDISPLAY_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qt_filefield.hpp"

QT_BEGIN_NAMESPACE

class Ui_SettingsDisplay
{
public:
    QGridLayout *gridLayout;
    QCheckBox *checkBoxVoodoo;
    QPushButton *pushButtonConfigureDa2;
    QCheckBox *checkBox8514;
    QLabel *labelVideoSecondary;
    QPushButton *pushButtonConfigure8514;
    QPushButton *pushButtonConfigureXga;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonDefault;
    QPushButton *pushButtonExportDefault;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonCustom;
    FileField *lineEdit;
    QComboBox *comboBoxVideoSecondary;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonConfigureVoodoo;
    QPushButton *pushButtonConfigureVideo;
    QLabel *labelVideo;
    QPushButton *pushButtonConfigureVideoSecondary;
    QComboBox *comboBoxVideo;
    QCheckBox *checkBoxXga;
    QCheckBox *checkBoxDa2;
    QWidget *widget;

    void setupUi(QWidget *SettingsDisplay)
    {
        if (SettingsDisplay->objectName().isEmpty())
            SettingsDisplay->setObjectName("SettingsDisplay");
        SettingsDisplay->resize(400, 466);
        gridLayout = new QGridLayout(SettingsDisplay);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        checkBoxVoodoo = new QCheckBox(SettingsDisplay);
        checkBoxVoodoo->setObjectName("checkBoxVoodoo");

        gridLayout->addWidget(checkBoxVoodoo, 4, 0, 1, 2);

        pushButtonConfigureDa2 = new QPushButton(SettingsDisplay);
        pushButtonConfigureDa2->setObjectName("pushButtonConfigureDa2");

        gridLayout->addWidget(pushButtonConfigureDa2, 7, 2, 1, 1);

        checkBox8514 = new QCheckBox(SettingsDisplay);
        checkBox8514->setObjectName("checkBox8514");

        gridLayout->addWidget(checkBox8514, 5, 0, 1, 2);

        labelVideoSecondary = new QLabel(SettingsDisplay);
        labelVideoSecondary->setObjectName("labelVideoSecondary");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelVideoSecondary->sizePolicy().hasHeightForWidth());
        labelVideoSecondary->setSizePolicy(sizePolicy);

        gridLayout->addWidget(labelVideoSecondary, 2, 0, 1, 1);

        pushButtonConfigure8514 = new QPushButton(SettingsDisplay);
        pushButtonConfigure8514->setObjectName("pushButtonConfigure8514");

        gridLayout->addWidget(pushButtonConfigure8514, 5, 2, 1, 1);

        pushButtonConfigureXga = new QPushButton(SettingsDisplay);
        pushButtonConfigureXga->setObjectName("pushButtonConfigureXga");

        gridLayout->addWidget(pushButtonConfigureXga, 6, 2, 1, 1);

        groupBox = new QGroupBox(SettingsDisplay);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        radioButtonDefault = new QRadioButton(groupBox);
        radioButtonDefault->setObjectName("radioButtonDefault");

        horizontalLayout->addWidget(radioButtonDefault);

        pushButtonExportDefault = new QPushButton(groupBox);
        pushButtonExportDefault->setObjectName("pushButtonExportDefault");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonExportDefault->sizePolicy().hasHeightForWidth());
        pushButtonExportDefault->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(pushButtonExportDefault);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        radioButtonCustom = new QRadioButton(groupBox);
        radioButtonCustom->setObjectName("radioButtonCustom");

        horizontalLayout_2->addWidget(radioButtonCustom);

        lineEdit = new FileField(groupBox);
        lineEdit->setObjectName("lineEdit");
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addWidget(groupBox, 8, 0, 1, 3);

        comboBoxVideoSecondary = new QComboBox(SettingsDisplay);
        comboBoxVideoSecondary->setObjectName("comboBoxVideoSecondary");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBoxVideoSecondary->sizePolicy().hasHeightForWidth());
        comboBoxVideoSecondary->setSizePolicy(sizePolicy3);
        comboBoxVideoSecondary->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxVideoSecondary, 3, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 10, 0, 1, 3);

        pushButtonConfigureVoodoo = new QPushButton(SettingsDisplay);
        pushButtonConfigureVoodoo->setObjectName("pushButtonConfigureVoodoo");

        gridLayout->addWidget(pushButtonConfigureVoodoo, 4, 2, 1, 1);

        pushButtonConfigureVideo = new QPushButton(SettingsDisplay);
        pushButtonConfigureVideo->setObjectName("pushButtonConfigureVideo");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButtonConfigureVideo->sizePolicy().hasHeightForWidth());
        pushButtonConfigureVideo->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pushButtonConfigureVideo, 1, 2, 1, 1);

        labelVideo = new QLabel(SettingsDisplay);
        labelVideo->setObjectName("labelVideo");
        sizePolicy.setHeightForWidth(labelVideo->sizePolicy().hasHeightForWidth());
        labelVideo->setSizePolicy(sizePolicy);

        gridLayout->addWidget(labelVideo, 0, 0, 1, 1);

        pushButtonConfigureVideoSecondary = new QPushButton(SettingsDisplay);
        pushButtonConfigureVideoSecondary->setObjectName("pushButtonConfigureVideoSecondary");

        gridLayout->addWidget(pushButtonConfigureVideoSecondary, 3, 2, 1, 1);

        comboBoxVideo = new QComboBox(SettingsDisplay);
        comboBoxVideo->setObjectName("comboBoxVideo");
        sizePolicy3.setHeightForWidth(comboBoxVideo->sizePolicy().hasHeightForWidth());
        comboBoxVideo->setSizePolicy(sizePolicy3);
        comboBoxVideo->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxVideo, 1, 0, 1, 2);

        checkBoxXga = new QCheckBox(SettingsDisplay);
        checkBoxXga->setObjectName("checkBoxXga");

        gridLayout->addWidget(checkBoxXga, 6, 0, 1, 2);

        checkBoxDa2 = new QCheckBox(SettingsDisplay);
        checkBoxDa2->setObjectName("checkBoxDa2");

        gridLayout->addWidget(checkBoxDa2, 7, 0, 1, 1);

        widget = new QWidget(SettingsDisplay);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(widget, 9, 0, 1, 3);

        gridLayout->setColumnStretch(0, 2);

        retranslateUi(SettingsDisplay);

        QMetaObject::connectSlotsByName(SettingsDisplay);
    } // setupUi

    void retranslateUi(QWidget *SettingsDisplay)
    {
        SettingsDisplay->setWindowTitle(QCoreApplication::translate("SettingsDisplay", "Form", nullptr));
        checkBoxVoodoo->setText(QCoreApplication::translate("SettingsDisplay", "Voodoo 1 or 2 Graphics", nullptr));
        pushButtonConfigureDa2->setText(QCoreApplication::translate("SettingsDisplay", "Configure", nullptr));
        checkBox8514->setText(QCoreApplication::translate("SettingsDisplay", "IBM 8514/A Graphics", nullptr));
        labelVideoSecondary->setText(QCoreApplication::translate("SettingsDisplay", "Video #2:", nullptr));
        pushButtonConfigure8514->setText(QCoreApplication::translate("SettingsDisplay", "Configure", nullptr));
        pushButtonConfigureXga->setText(QCoreApplication::translate("SettingsDisplay", "Configure", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SettingsDisplay", "Monitor EDID", nullptr));
        radioButtonDefault->setText(QCoreApplication::translate("SettingsDisplay", "Default", nullptr));
        pushButtonExportDefault->setText(QCoreApplication::translate("SettingsDisplay", "Export...", nullptr));
        radioButtonCustom->setText(QCoreApplication::translate("SettingsDisplay", "Custom...", nullptr));
        pushButtonConfigureVoodoo->setText(QCoreApplication::translate("SettingsDisplay", "Configure", nullptr));
        pushButtonConfigureVideo->setText(QCoreApplication::translate("SettingsDisplay", "Configure", nullptr));
        labelVideo->setText(QCoreApplication::translate("SettingsDisplay", "Video:", nullptr));
        pushButtonConfigureVideoSecondary->setText(QCoreApplication::translate("SettingsDisplay", "Configure", nullptr));
        checkBoxXga->setText(QCoreApplication::translate("SettingsDisplay", "XGA Graphics", nullptr));
        checkBoxDa2->setText(QCoreApplication::translate("SettingsDisplay", "IBM PS/55 Display Adapter Graphics", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDisplay: public Ui_SettingsDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SETTINGSDISPLAY_H

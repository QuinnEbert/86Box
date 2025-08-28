/********************************************************************************
** Form generated from reading UI file 'qt_settingssound.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SETTINGSSOUND_H
#define UI_QT_SETTINGSSOUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsSound
{
public:
    QGridLayout *gridLayout;
    QLabel *labelSoundCard1;
    QComboBox *comboBoxSoundCard1;
    QPushButton *pushButtonConfigureSoundCard1;
    QLabel *labelSoundCard2;
    QComboBox *comboBoxSoundCard2;
    QPushButton *pushButtonConfigureSoundCard2;
    QLabel *labelSoundCard3;
    QComboBox *comboBoxSoundCard3;
    QPushButton *pushButtonConfigureSoundCard3;
    QLabel *labelSoundCard4;
    QComboBox *comboBoxSoundCard4;
    QPushButton *pushButtonConfigureSoundCard4;
    QLabel *labelMidiOut;
    QComboBox *comboBoxMidiOut;
    QPushButton *pushButtonConfigureMidiOut;
    QLabel *labelMidiIn;
    QComboBox *comboBoxMidiIn;
    QPushButton *pushButtonConfigureMidiIn;
    QCheckBox *checkBoxMPU401;
    QPushButton *pushButtonConfigureMPU401;
    QCheckBox *checkBoxFloat32;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayoutFM;
    QRadioButton *radioButtonNuked;
    QRadioButton *radioButtonYMFM;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SettingsSound)
    {
        if (SettingsSound->objectName().isEmpty())
            SettingsSound->setObjectName("SettingsSound");
        SettingsSound->resize(387, 332);
        gridLayout = new QGridLayout(SettingsSound);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelSoundCard1 = new QLabel(SettingsSound);
        labelSoundCard1->setObjectName("labelSoundCard1");

        gridLayout->addWidget(labelSoundCard1, 0, 0, 1, 1);

        comboBoxSoundCard1 = new QComboBox(SettingsSound);
        comboBoxSoundCard1->setObjectName("comboBoxSoundCard1");
        comboBoxSoundCard1->setMaxVisibleItems(30);
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxSoundCard1->sizePolicy().hasHeightForWidth());
        comboBoxSoundCard1->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBoxSoundCard1, 0, 1, 1, 1);

        pushButtonConfigureSoundCard1 = new QPushButton(SettingsSound);
        pushButtonConfigureSoundCard1->setObjectName("pushButtonConfigureSoundCard1");

        gridLayout->addWidget(pushButtonConfigureSoundCard1, 0, 3, 1, 1);

        labelSoundCard2 = new QLabel(SettingsSound);
        labelSoundCard2->setObjectName("labelSoundCard2");

        gridLayout->addWidget(labelSoundCard2, 1, 0, 1, 1);

        comboBoxSoundCard2 = new QComboBox(SettingsSound);
        comboBoxSoundCard2->setObjectName("comboBoxSoundCard2");
        comboBoxSoundCard2->setMaxVisibleItems(30);
        sizePolicy.setHeightForWidth(comboBoxSoundCard2->sizePolicy().hasHeightForWidth());
        comboBoxSoundCard2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBoxSoundCard2, 1, 1, 1, 1);

        pushButtonConfigureSoundCard2 = new QPushButton(SettingsSound);
        pushButtonConfigureSoundCard2->setObjectName("pushButtonConfigureSoundCard2");

        gridLayout->addWidget(pushButtonConfigureSoundCard2, 1, 3, 1, 1);

        labelSoundCard3 = new QLabel(SettingsSound);
        labelSoundCard3->setObjectName("labelSoundCard3");

        gridLayout->addWidget(labelSoundCard3, 2, 0, 1, 1);

        comboBoxSoundCard3 = new QComboBox(SettingsSound);
        comboBoxSoundCard3->setObjectName("comboBoxSoundCard3");
        comboBoxSoundCard3->setMaxVisibleItems(30);
        sizePolicy.setHeightForWidth(comboBoxSoundCard3->sizePolicy().hasHeightForWidth());
        comboBoxSoundCard3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBoxSoundCard3, 2, 1, 1, 1);

        pushButtonConfigureSoundCard3 = new QPushButton(SettingsSound);
        pushButtonConfigureSoundCard3->setObjectName("pushButtonConfigureSoundCard3");

        gridLayout->addWidget(pushButtonConfigureSoundCard3, 2, 3, 1, 1);

        labelSoundCard4 = new QLabel(SettingsSound);
        labelSoundCard4->setObjectName("labelSoundCard4");

        gridLayout->addWidget(labelSoundCard4, 3, 0, 1, 1);

        comboBoxSoundCard4 = new QComboBox(SettingsSound);
        comboBoxSoundCard4->setObjectName("comboBoxSoundCard4");
        comboBoxSoundCard4->setMaxVisibleItems(30);
        sizePolicy.setHeightForWidth(comboBoxSoundCard4->sizePolicy().hasHeightForWidth());
        comboBoxSoundCard4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBoxSoundCard4, 3, 1, 1, 1);

        pushButtonConfigureSoundCard4 = new QPushButton(SettingsSound);
        pushButtonConfigureSoundCard4->setObjectName("pushButtonConfigureSoundCard4");

        gridLayout->addWidget(pushButtonConfigureSoundCard4, 3, 3, 1, 1);

        labelMidiOut = new QLabel(SettingsSound);
        labelMidiOut->setObjectName("labelMidiOut");

        gridLayout->addWidget(labelMidiOut, 4, 0, 1, 1);

        comboBoxMidiOut = new QComboBox(SettingsSound);
        comboBoxMidiOut->setObjectName("comboBoxMidiOut");
        comboBoxMidiOut->setMaxVisibleItems(30);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxMidiOut->sizePolicy().hasHeightForWidth());
        comboBoxMidiOut->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBoxMidiOut, 4, 1, 1, 1);

        pushButtonConfigureMidiOut = new QPushButton(SettingsSound);
        pushButtonConfigureMidiOut->setObjectName("pushButtonConfigureMidiOut");

        gridLayout->addWidget(pushButtonConfigureMidiOut, 4, 3, 1, 1);

        labelMidiIn = new QLabel(SettingsSound);
        labelMidiIn->setObjectName("labelMidiIn");

        gridLayout->addWidget(labelMidiIn, 5, 0, 1, 1);

        comboBoxMidiIn = new QComboBox(SettingsSound);
        comboBoxMidiIn->setObjectName("comboBoxMidiIn");
        comboBoxMidiIn->setMaxVisibleItems(30);
        sizePolicy1.setHeightForWidth(comboBoxMidiIn->sizePolicy().hasHeightForWidth());
        comboBoxMidiIn->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBoxMidiIn, 5, 1, 1, 1);

        pushButtonConfigureMidiIn = new QPushButton(SettingsSound);
        pushButtonConfigureMidiIn->setObjectName("pushButtonConfigureMidiIn");

        gridLayout->addWidget(pushButtonConfigureMidiIn, 5, 3, 1, 1);

        checkBoxMPU401 = new QCheckBox(SettingsSound);
        checkBoxMPU401->setObjectName("checkBoxMPU401");

        gridLayout->addWidget(checkBoxMPU401, 6, 0, 1, 1);

        pushButtonConfigureMPU401 = new QPushButton(SettingsSound);
        pushButtonConfigureMPU401->setObjectName("pushButtonConfigureMPU401");

        gridLayout->addWidget(pushButtonConfigureMPU401, 6, 3, 1, 1);

        checkBoxFloat32 = new QCheckBox(SettingsSound);
        checkBoxFloat32->setObjectName("checkBoxFloat32");

        gridLayout->addWidget(checkBoxFloat32, 10, 0, 1, 1);

        groupBox = new QGroupBox(SettingsSound);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        verticalLayoutFM = new QVBoxLayout(groupBox);
        verticalLayoutFM->setObjectName("verticalLayoutFM");
        radioButtonNuked = new QRadioButton(groupBox);
        radioButtonNuked->setObjectName("radioButtonNuked");

        verticalLayoutFM->addWidget(radioButtonNuked);

        radioButtonYMFM = new QRadioButton(groupBox);
        radioButtonYMFM->setObjectName("radioButtonYMFM");

        verticalLayoutFM->addWidget(radioButtonYMFM);


        gridLayout->addWidget(groupBox, 11, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 12, 0, 1, 1);


        retranslateUi(SettingsSound);

        QMetaObject::connectSlotsByName(SettingsSound);
    } // setupUi

    void retranslateUi(QWidget *SettingsSound)
    {
        SettingsSound->setWindowTitle(QCoreApplication::translate("SettingsSound", "Form", nullptr));
        labelSoundCard1->setText(QCoreApplication::translate("SettingsSound", "Sound card #1:", nullptr));
        pushButtonConfigureSoundCard1->setText(QCoreApplication::translate("SettingsSound", "Configure", nullptr));
        labelSoundCard2->setText(QCoreApplication::translate("SettingsSound", "Sound card #2:", nullptr));
        pushButtonConfigureSoundCard2->setText(QCoreApplication::translate("SettingsSound", "Configure", nullptr));
        labelSoundCard3->setText(QCoreApplication::translate("SettingsSound", "Sound card #3:", nullptr));
        pushButtonConfigureSoundCard3->setText(QCoreApplication::translate("SettingsSound", "Configure", nullptr));
        labelSoundCard4->setText(QCoreApplication::translate("SettingsSound", "Sound card #4:", nullptr));
        pushButtonConfigureSoundCard4->setText(QCoreApplication::translate("SettingsSound", "Configure", nullptr));
        labelMidiOut->setText(QCoreApplication::translate("SettingsSound", "MIDI Out Device:", nullptr));
        pushButtonConfigureMidiOut->setText(QCoreApplication::translate("SettingsSound", "Configure", nullptr));
        labelMidiIn->setText(QCoreApplication::translate("SettingsSound", "MIDI In Device:", nullptr));
        pushButtonConfigureMidiIn->setText(QCoreApplication::translate("SettingsSound", "Configure", nullptr));
        checkBoxMPU401->setText(QCoreApplication::translate("SettingsSound", "Standalone MPU-401", nullptr));
        pushButtonConfigureMPU401->setText(QCoreApplication::translate("SettingsSound", "Configure", nullptr));
        checkBoxFloat32->setText(QCoreApplication::translate("SettingsSound", "Use FLOAT32 sound", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SettingsSound", "FM synth driver", nullptr));
        radioButtonNuked->setText(QCoreApplication::translate("SettingsSound", "Nuked (more accurate)", nullptr));
        radioButtonYMFM->setText(QCoreApplication::translate("SettingsSound", "YMFM (faster)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsSound: public Ui_SettingsSound {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SETTINGSSOUND_H

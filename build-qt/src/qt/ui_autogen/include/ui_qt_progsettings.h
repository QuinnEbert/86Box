/********************************************************************************
** Form generated from reading UI file 'qt_progsettings.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_PROGSETTINGS_H
#define UI_QT_PROGSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProgSettings
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *checkBoxMultimediaKeys;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QComboBox *comboBoxLanguage;
    QCheckBox *checkBoxConfirmSave;
    QSlider *horizontalSlider;
    QCheckBox *openDirUsrPath;
    QPushButton *pushButtonLanguage;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBoxConfirmExit;
    QDialogButtonBox *buttonBox;
    QCheckBox *checkBoxConfirmHardReset;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonSystem;
    QRadioButton *radioButtonLight;
    QRadioButton *radioButtonDark;

    void setupUi(QDialog *ProgSettings)
    {
        if (ProgSettings->objectName().isEmpty())
            ProgSettings->setObjectName("ProgSettings");
        ProgSettings->resize(458, 508);
        ProgSettings->setMinimumSize(QSize(0, 0));
        ProgSettings->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(ProgSettings);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        label_2 = new QLabel(ProgSettings);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        checkBoxMultimediaKeys = new QCheckBox(ProgSettings);
        checkBoxMultimediaKeys->setObjectName("checkBoxMultimediaKeys");

        gridLayout->addWidget(checkBoxMultimediaKeys, 7, 0, 1, 1);

        label_3 = new QLabel(ProgSettings);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(ProgSettings);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 5, 1, 1, 1);

        comboBoxLanguage = new QComboBox(ProgSettings);
        comboBoxLanguage->addItem(QString());
        comboBoxLanguage->setObjectName("comboBoxLanguage");
        comboBoxLanguage->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxLanguage, 1, 0, 1, 2);

        checkBoxConfirmSave = new QCheckBox(ProgSettings);
        checkBoxConfirmSave->setObjectName("checkBoxConfirmSave");

        gridLayout->addWidget(checkBoxConfirmSave, 8, 0, 1, 1);

        horizontalSlider = new QSlider(ProgSettings);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setMinimum(10);
        horizontalSlider->setMaximum(200);
        horizontalSlider->setSingleStep(10);
        horizontalSlider->setPageStep(20);
        horizontalSlider->setValue(100);
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        gridLayout->addWidget(horizontalSlider, 4, 0, 1, 3);

        openDirUsrPath = new QCheckBox(ProgSettings);
        openDirUsrPath->setObjectName("openDirUsrPath");

        gridLayout->addWidget(openDirUsrPath, 6, 0, 1, 1);

        pushButtonLanguage = new QPushButton(ProgSettings);
        pushButtonLanguage->setObjectName("pushButtonLanguage");

        gridLayout->addWidget(pushButtonLanguage, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 5, 0, 1, 1);

        checkBoxConfirmExit = new QCheckBox(ProgSettings);
        checkBoxConfirmExit->setObjectName("checkBoxConfirmExit");

        gridLayout->addWidget(checkBoxConfirmExit, 9, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ProgSettings);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        gridLayout->addWidget(buttonBox, 14, 0, 1, 2);

        checkBoxConfirmHardReset = new QCheckBox(ProgSettings);
        checkBoxConfirmHardReset->setObjectName("checkBoxConfirmHardReset");

        gridLayout->addWidget(checkBoxConfirmHardReset, 10, 0, 1, 1);

        groupBox = new QGroupBox(ProgSettings);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        radioButtonSystem = new QRadioButton(groupBox);
        radioButtonSystem->setObjectName("radioButtonSystem");

        verticalLayout->addWidget(radioButtonSystem);

        radioButtonLight = new QRadioButton(groupBox);
        radioButtonLight->setObjectName("radioButtonLight");

        verticalLayout->addWidget(radioButtonLight);

        radioButtonDark = new QRadioButton(groupBox);
        radioButtonDark->setObjectName("radioButtonDark");

        verticalLayout->addWidget(radioButtonDark);


        gridLayout->addWidget(groupBox, 13, 0, 1, 1);


        retranslateUi(ProgSettings);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ProgSettings, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ProgSettings, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ProgSettings);
    } // setupUi

    void retranslateUi(QDialog *ProgSettings)
    {
        ProgSettings->setWindowTitle(QCoreApplication::translate("ProgSettings", "Preferences", nullptr));
        label_2->setText(QCoreApplication::translate("ProgSettings", "Language:", nullptr));
        checkBoxMultimediaKeys->setText(QCoreApplication::translate("ProgSettings", "Inhibit multimedia keys", nullptr));
        label_3->setText(QCoreApplication::translate("ProgSettings", "Mouse sensitivity:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ProgSettings", "Default", nullptr));
        comboBoxLanguage->setItemText(0, QCoreApplication::translate("ProgSettings", "(System Default)", nullptr));

        checkBoxConfirmSave->setText(QCoreApplication::translate("ProgSettings", "Ask for confirmation before saving settings", nullptr));
#if QT_CONFIG(tooltip)
        openDirUsrPath->setToolTip(QCoreApplication::translate("ProgSettings", "<html><head/><body><p>When selecting media images (CD-ROM, floppy, etc.) the open dialog will start in the same directory as the 86Box configuration file. This setting will likely only make a difference on macOS.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        openDirUsrPath->setText(QCoreApplication::translate("ProgSettings", "Select media images from program working directory", nullptr));
        pushButtonLanguage->setText(QCoreApplication::translate("ProgSettings", "Default", nullptr));
        checkBoxConfirmExit->setText(QCoreApplication::translate("ProgSettings", "Ask for confirmation before quitting", nullptr));
        checkBoxConfirmHardReset->setText(QCoreApplication::translate("ProgSettings", "Ask for confirmation before hard resetting", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ProgSettings", "Color scheme", nullptr));
        radioButtonSystem->setText(QCoreApplication::translate("ProgSettings", "System", nullptr));
        radioButtonLight->setText(QCoreApplication::translate("ProgSettings", "Light", nullptr));
        radioButtonDark->setText(QCoreApplication::translate("ProgSettings", "Dark", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgSettings: public Ui_ProgSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_PROGSETTINGS_H

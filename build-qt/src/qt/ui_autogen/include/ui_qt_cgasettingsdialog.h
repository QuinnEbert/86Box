/********************************************************************************
** Form generated from reading UI file 'qt_cgasettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_CGASETTINGSDIALOG_H
#define UI_QT_CGASETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_CGASettingsDialog
{
public:
    QGridLayout *gridLayout_2;
    QSlider *horizontalSliderBrightness;
    QSlider *horizontalSliderSaturation;
    QLabel *label;
    QSlider *horizontalSliderSharpness;
    QDialogButtonBox *buttonBox;
    QSlider *horizontalSliderContrast;
    QLabel *label_4;
    QSlider *horizontalSliderHue;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *CGASettingsDialog)
    {
        if (CGASettingsDialog->objectName().isEmpty())
            CGASettingsDialog->setObjectName("CGASettingsDialog");
        CGASettingsDialog->resize(400, 300);
        gridLayout_2 = new QGridLayout(CGASettingsDialog);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        horizontalSliderBrightness = new QSlider(CGASettingsDialog);
        horizontalSliderBrightness->setObjectName("horizontalSliderBrightness");
        horizontalSliderBrightness->setMinimum(-100);
        horizontalSliderBrightness->setMaximum(100);
        horizontalSliderBrightness->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_2->addWidget(horizontalSliderBrightness, 2, 2, 1, 1);

        horizontalSliderSaturation = new QSlider(CGASettingsDialog);
        horizontalSliderSaturation->setObjectName("horizontalSliderSaturation");
        horizontalSliderSaturation->setMaximum(360);
        horizontalSliderSaturation->setValue(100);
        horizontalSliderSaturation->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_2->addWidget(horizontalSliderSaturation, 1, 2, 1, 1);

        label = new QLabel(CGASettingsDialog);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 2);

        horizontalSliderSharpness = new QSlider(CGASettingsDialog);
        horizontalSliderSharpness->setObjectName("horizontalSliderSharpness");
        horizontalSliderSharpness->setMinimum(-50);
        horizontalSliderSharpness->setMaximum(50);
        horizontalSliderSharpness->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_2->addWidget(horizontalSliderSharpness, 4, 2, 1, 1);

        buttonBox = new QDialogButtonBox(CGASettingsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Apply|QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok|QDialogButtonBox::StandardButton::Reset);

        gridLayout_2->addWidget(buttonBox, 5, 2, 1, 1);

        horizontalSliderContrast = new QSlider(CGASettingsDialog);
        horizontalSliderContrast->setObjectName("horizontalSliderContrast");
        horizontalSliderContrast->setMaximum(360);
        horizontalSliderContrast->setValue(100);
        horizontalSliderContrast->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_2->addWidget(horizontalSliderContrast, 3, 2, 1, 1);

        label_4 = new QLabel(CGASettingsDialog);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        horizontalSliderHue = new QSlider(CGASettingsDialog);
        horizontalSliderHue->setObjectName("horizontalSliderHue");
        horizontalSliderHue->setMinimum(-360);
        horizontalSliderHue->setMaximum(360);
        horizontalSliderHue->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_2->addWidget(horizontalSliderHue, 0, 2, 1, 1);

        label_5 = new QLabel(CGASettingsDialog);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        label_2 = new QLabel(CGASettingsDialog);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 2);

        label_3 = new QLabel(CGASettingsDialog);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);


        retranslateUi(CGASettingsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CGASettingsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CGASettingsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CGASettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *CGASettingsDialog)
    {
        CGASettingsDialog->setWindowTitle(QCoreApplication::translate("CGASettingsDialog", "CGA composite settings", nullptr));
        label->setText(QCoreApplication::translate("CGASettingsDialog", "Hue", nullptr));
        label_4->setText(QCoreApplication::translate("CGASettingsDialog", "Contrast", nullptr));
        label_5->setText(QCoreApplication::translate("CGASettingsDialog", "Sharpness", nullptr));
        label_2->setText(QCoreApplication::translate("CGASettingsDialog", "Saturation", nullptr));
        label_3->setText(QCoreApplication::translate("CGASettingsDialog", "Brightness", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CGASettingsDialog: public Ui_CGASettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_CGASETTINGSDIALOG_H

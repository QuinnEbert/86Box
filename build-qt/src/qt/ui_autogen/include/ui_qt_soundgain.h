/********************************************************************************
** Form generated from reading UI file 'qt_soundgain.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SOUNDGAIN_H
#define UI_QT_SOUNDGAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_SoundGain
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSlider *verticalSlider;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SoundGain)
    {
        if (SoundGain->objectName().isEmpty())
            SoundGain->setObjectName("SoundGain");
        SoundGain->resize(200, 250);
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SoundGain->sizePolicy().hasHeightForWidth());
        SoundGain->setSizePolicy(sizePolicy);
        SoundGain->setMinimumSize(QSize(200, 250));
        SoundGain->setMaximumSize(QSize(200, 250));
        gridLayout = new QGridLayout(SoundGain);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(SoundGain);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalSlider = new QSlider(SoundGain);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setMaximum(18);
        verticalSlider->setSingleStep(2);
        verticalSlider->setPageStep(4);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setInvertedAppearance(false);
        verticalSlider->setTickPosition(QSlider::TicksBothSides);

        gridLayout->addWidget(verticalSlider, 1, 0, 1, 1, Qt::AlignHCenter);

        buttonBox = new QDialogButtonBox(SoundGain);
        buttonBox->setObjectName("buttonBox");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy2);
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 0, 1, 2, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);

        retranslateUi(SoundGain);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SoundGain, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SoundGain, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SoundGain);
    } // setupUi

    void retranslateUi(QDialog *SoundGain)
    {
        SoundGain->setWindowTitle(QCoreApplication::translate("SoundGain", "Sound Gain", nullptr));
        label->setText(QCoreApplication::translate("SoundGain", "Gain", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SoundGain: public Ui_SoundGain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SOUNDGAIN_H

/********************************************************************************
** Form generated from reading UI file 'qt_specifydimensions.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SPECIFYDIMENSIONS_H
#define UI_QT_SPECIFYDIMENSIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SpecifyDimensions
{
public:
    QGridLayout *gridLayout;
    QLabel *labelWidth;
    QSpinBox *spinBoxWidth;
    QLabel *labelHeight;
    QSpinBox *spinBoxHeight;
    QCheckBox *checkBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SpecifyDimensions)
    {
        if (SpecifyDimensions->objectName().isEmpty())
            SpecifyDimensions->setObjectName("SpecifyDimensions");
        SpecifyDimensions->resize(388, 158);
        gridLayout = new QGridLayout(SpecifyDimensions);
        gridLayout->setObjectName("gridLayout");
        labelWidth = new QLabel(SpecifyDimensions);
        labelWidth->setObjectName("labelWidth");

        gridLayout->addWidget(labelWidth, 0, 0, 1, 1);

        spinBoxWidth = new QSpinBox(SpecifyDimensions);
        spinBoxWidth->setObjectName("spinBoxWidth");

        gridLayout->addWidget(spinBoxWidth, 0, 1, 1, 1);

        labelHeight = new QLabel(SpecifyDimensions);
        labelHeight->setObjectName("labelHeight");

        gridLayout->addWidget(labelHeight, 0, 2, 1, 1);

        spinBoxHeight = new QSpinBox(SpecifyDimensions);
        spinBoxHeight->setObjectName("spinBoxHeight");

        gridLayout->addWidget(spinBoxHeight, 0, 3, 1, 1);

        checkBox = new QCheckBox(SpecifyDimensions);
        checkBox->setObjectName("checkBox");

        gridLayout->addWidget(checkBox, 1, 0, 1, 2);

        buttonBox = new QDialogButtonBox(SpecifyDimensions);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 4);


        retranslateUi(SpecifyDimensions);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SpecifyDimensions, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SpecifyDimensions, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SpecifyDimensions);
    } // setupUi

    void retranslateUi(QDialog *SpecifyDimensions)
    {
        SpecifyDimensions->setWindowTitle(QCoreApplication::translate("SpecifyDimensions", "Specify Main Window Dimensions", nullptr));
        labelWidth->setText(QCoreApplication::translate("SpecifyDimensions", "Width:", nullptr));
        labelHeight->setText(QCoreApplication::translate("SpecifyDimensions", "Height:", nullptr));
        checkBox->setText(QCoreApplication::translate("SpecifyDimensions", "Lock to this size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpecifyDimensions: public Ui_SpecifyDimensions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SPECIFYDIMENSIONS_H

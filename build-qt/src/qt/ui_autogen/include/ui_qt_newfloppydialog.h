/********************************************************************************
** Form generated from reading UI file 'qt_newfloppydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_NEWFLOPPYDIALOG_H
#define UI_QT_NEWFLOPPYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include "qt_filefield.hpp"

QT_BEGIN_NAMESPACE

class Ui_NewFloppyDialog
{
public:
    QFormLayout *formLayout;
    QLabel *label_2;
    FileField *fileField;
    QLabel *label;
    QComboBox *comboBoxSize;
    QLabel *labelRpm;
    QComboBox *comboBoxRpm;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewFloppyDialog)
    {
        if (NewFloppyDialog->objectName().isEmpty())
            NewFloppyDialog->setObjectName("NewFloppyDialog");
        NewFloppyDialog->resize(327, 200);
        NewFloppyDialog->setMinimumSize(QSize(327, 200));
        NewFloppyDialog->setMaximumSize(QSize(327, 200));
        formLayout = new QFormLayout(NewFloppyDialog);
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(NewFloppyDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_2);

        fileField = new FileField(NewFloppyDialog);
        fileField->setObjectName("fileField");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fileField->sizePolicy().hasHeightForWidth());
        fileField->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, fileField);

        label = new QLabel(NewFloppyDialog);
        label->setObjectName("label");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label);

        comboBoxSize = new QComboBox(NewFloppyDialog);
        comboBoxSize->setObjectName("comboBoxSize");
        comboBoxSize->setMaxVisibleItems(30);
        sizePolicy.setHeightForWidth(comboBoxSize->sizePolicy().hasHeightForWidth());
        comboBoxSize->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboBoxSize);

        labelRpm = new QLabel(NewFloppyDialog);
        labelRpm->setObjectName("labelRpm");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelRpm);

        comboBoxRpm = new QComboBox(NewFloppyDialog);
        comboBoxRpm->setObjectName("comboBoxRpm");
        comboBoxRpm->setMaxVisibleItems(30);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxRpm->sizePolicy().hasHeightForWidth());
        comboBoxRpm->setSizePolicy(sizePolicy1);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, comboBoxRpm);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(3, QFormLayout::ItemRole::LabelRole, verticalSpacer);

        buttonBox = new QDialogButtonBox(NewFloppyDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(4, QFormLayout::ItemRole::SpanningRole, buttonBox);


        retranslateUi(NewFloppyDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, NewFloppyDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, NewFloppyDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(NewFloppyDialog);
    } // setupUi

    void retranslateUi(QDialog *NewFloppyDialog)
    {
        NewFloppyDialog->setWindowTitle(QCoreApplication::translate("NewFloppyDialog", "New Image", nullptr));
        label_2->setText(QCoreApplication::translate("NewFloppyDialog", "File name:", nullptr));
        label->setText(QCoreApplication::translate("NewFloppyDialog", "Disk size:", nullptr));
        labelRpm->setText(QCoreApplication::translate("NewFloppyDialog", "RPM mode:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewFloppyDialog: public Ui_NewFloppyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_NEWFLOPPYDIALOG_H

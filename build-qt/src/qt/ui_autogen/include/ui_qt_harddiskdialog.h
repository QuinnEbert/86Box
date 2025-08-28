/********************************************************************************
** Form generated from reading UI file 'qt_harddiskdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_HARDDISKDIALOG_H
#define UI_QT_HARDDISKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include "qt_filefield.hpp"

QT_BEGIN_NAMESPACE

class Ui_HarddiskDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    FileField *fileField;
    QLabel *label_2;
    QLineEdit *lineEditCylinders;
    QLabel *label_4;
    QLineEdit *lineEditHeads;
    QLabel *label_5;
    QLineEdit *lineEditSectors;
    QLabel *label_3;
    QLineEdit *lineEditSize;
    QLabel *label_6;
    QComboBox *comboBoxType;
    QLabel *label_8;
    QComboBox *comboBoxBus;
    QLabel *label_7;
    QComboBox *comboBoxChannel;
    QLabel *label_9;
    QComboBox *comboBoxSpeed;
    QLabel *labelFormat;
    QComboBox *comboBoxFormat;
    QLabel *labelBlockSize;
    QComboBox *comboBoxBlockSize;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *HarddiskDialog)
    {
        if (HarddiskDialog->objectName().isEmpty())
            HarddiskDialog->setObjectName("HarddiskDialog");
        HarddiskDialog->resize(421, 269);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HarddiskDialog->sizePolicy().hasHeightForWidth());
        HarddiskDialog->setSizePolicy(sizePolicy);
        HarddiskDialog->setMinimumSize(QSize(421, 269));
        HarddiskDialog->setMaximumSize(QSize(421, 269));
        gridLayout = new QGridLayout(HarddiskDialog);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(HarddiskDialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        fileField = new FileField(HarddiskDialog);
        fileField->setObjectName("fileField");

        gridLayout->addWidget(fileField, 0, 1, 1, 5);

        label_2 = new QLabel(HarddiskDialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditCylinders = new QLineEdit(HarddiskDialog);
        lineEditCylinders->setObjectName("lineEditCylinders");
        sizePolicy.setHeightForWidth(lineEditCylinders->sizePolicy().hasHeightForWidth());
        lineEditCylinders->setSizePolicy(sizePolicy);
        lineEditCylinders->setMaximumSize(QSize(64, 16777215));

        gridLayout->addWidget(lineEditCylinders, 1, 1, 1, 1);

        label_4 = new QLabel(HarddiskDialog);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        lineEditHeads = new QLineEdit(HarddiskDialog);
        lineEditHeads->setObjectName("lineEditHeads");
        sizePolicy.setHeightForWidth(lineEditHeads->sizePolicy().hasHeightForWidth());
        lineEditHeads->setSizePolicy(sizePolicy);
        lineEditHeads->setMaximumSize(QSize(64, 16777215));
        lineEditHeads->setMaxLength(32767);

        gridLayout->addWidget(lineEditHeads, 1, 3, 1, 1);

        label_5 = new QLabel(HarddiskDialog);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 1, 4, 1, 1);

        lineEditSectors = new QLineEdit(HarddiskDialog);
        lineEditSectors->setObjectName("lineEditSectors");
        sizePolicy.setHeightForWidth(lineEditSectors->sizePolicy().hasHeightForWidth());
        lineEditSectors->setSizePolicy(sizePolicy);
        lineEditSectors->setMaximumSize(QSize(64, 16777215));
        lineEditSectors->setMaxLength(32767);

        gridLayout->addWidget(lineEditSectors, 1, 5, 1, 1);

        label_3 = new QLabel(HarddiskDialog);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEditSize = new QLineEdit(HarddiskDialog);
        lineEditSize->setObjectName("lineEditSize");
        sizePolicy.setHeightForWidth(lineEditSize->sizePolicy().hasHeightForWidth());
        lineEditSize->setSizePolicy(sizePolicy);
        lineEditSize->setMaximumSize(QSize(64, 16777215));

        gridLayout->addWidget(lineEditSize, 2, 1, 1, 1);

        label_6 = new QLabel(HarddiskDialog);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        comboBoxType = new QComboBox(HarddiskDialog);
        comboBoxType->setObjectName("comboBoxType");
        comboBoxType->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxType, 2, 3, 1, 3);

        label_8 = new QLabel(HarddiskDialog);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        comboBoxBus = new QComboBox(HarddiskDialog);
        comboBoxBus->setObjectName("comboBoxBus");
        comboBoxBus->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxBus, 3, 1, 1, 3);

        label_7 = new QLabel(HarddiskDialog);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 3, 4, 1, 1);

        comboBoxChannel = new QComboBox(HarddiskDialog);
        comboBoxChannel->setObjectName("comboBoxChannel");
        comboBoxChannel->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxChannel, 3, 5, 1, 1);

        label_9 = new QLabel(HarddiskDialog);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        comboBoxSpeed = new QComboBox(HarddiskDialog);
        comboBoxSpeed->setObjectName("comboBoxSpeed");
        comboBoxSpeed->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxSpeed, 4, 1, 1, 5);

        labelFormat = new QLabel(HarddiskDialog);
        labelFormat->setObjectName("labelFormat");

        gridLayout->addWidget(labelFormat, 5, 0, 1, 1);

        comboBoxFormat = new QComboBox(HarddiskDialog);
        comboBoxFormat->setObjectName("comboBoxFormat");
        comboBoxFormat->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxFormat, 5, 1, 1, 5);

        labelBlockSize = new QLabel(HarddiskDialog);
        labelBlockSize->setObjectName("labelBlockSize");

        gridLayout->addWidget(labelBlockSize, 6, 0, 1, 1);

        comboBoxBlockSize = new QComboBox(HarddiskDialog);
        comboBoxBlockSize->setObjectName("comboBoxBlockSize");
        comboBoxBlockSize->setMaxVisibleItems(30);

        gridLayout->addWidget(comboBoxBlockSize, 6, 1, 1, 5);

        progressBar = new QProgressBar(HarddiskDialog);
        progressBar->setObjectName("progressBar");
        progressBar->setVisible(false);
        progressBar->setValue(0);
        progressBar->setTextVisible(true);

        gridLayout->addWidget(progressBar, 7, 0, 1, 6);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 0, 1, 6);

        buttonBox = new QDialogButtonBox(HarddiskDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 9, 0, 1, 6);


        retranslateUi(HarddiskDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, HarddiskDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, HarddiskDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(HarddiskDialog);
    } // setupUi

    void retranslateUi(QDialog *HarddiskDialog)
    {
        HarddiskDialog->setWindowTitle(QCoreApplication::translate("HarddiskDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("HarddiskDialog", "File name:", nullptr));
        label_2->setText(QCoreApplication::translate("HarddiskDialog", "Cylinders:", nullptr));
        label_4->setText(QCoreApplication::translate("HarddiskDialog", "Heads:", nullptr));
        label_5->setText(QCoreApplication::translate("HarddiskDialog", "Sectors:", nullptr));
        label_3->setText(QCoreApplication::translate("HarddiskDialog", "Size (MB):", nullptr));
        label_6->setText(QCoreApplication::translate("HarddiskDialog", "Type:", nullptr));
        label_8->setText(QCoreApplication::translate("HarddiskDialog", "Bus:", nullptr));
        label_7->setText(QCoreApplication::translate("HarddiskDialog", "Channel:", nullptr));
        label_9->setText(QCoreApplication::translate("HarddiskDialog", "Model:", nullptr));
        labelFormat->setText(QCoreApplication::translate("HarddiskDialog", "Image Format:", nullptr));
        labelBlockSize->setText(QCoreApplication::translate("HarddiskDialog", "Block Size:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HarddiskDialog: public Ui_HarddiskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_HARDDISKDIALOG_H

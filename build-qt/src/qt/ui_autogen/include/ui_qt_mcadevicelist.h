/********************************************************************************
** Form generated from reading UI file 'qt_mcadevicelist.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_MCADEVICELIST_H
#define UI_QT_MCADEVICELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MCADeviceList
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MCADeviceList)
    {
        if (MCADeviceList->objectName().isEmpty())
            MCADeviceList->setObjectName("MCADeviceList");
        MCADeviceList->resize(400, 300);
        verticalLayout = new QVBoxLayout(MCADeviceList);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(MCADeviceList);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(MCADeviceList);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        buttonBox = new QDialogButtonBox(MCADeviceList);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MCADeviceList);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MCADeviceList, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MCADeviceList, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MCADeviceList);
    } // setupUi

    void retranslateUi(QDialog *MCADeviceList)
    {
        MCADeviceList->setWindowTitle(QCoreApplication::translate("MCADeviceList", "MCA devices", nullptr));
        label->setText(QCoreApplication::translate("MCADeviceList", "List of MCA devices:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MCADeviceList: public Ui_MCADeviceList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_MCADEVICELIST_H

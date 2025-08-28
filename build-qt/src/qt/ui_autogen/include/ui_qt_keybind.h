/********************************************************************************
** Form generated from reading UI file 'qt_keybind.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_KEYBIND_H
#define UI_QT_KEYBIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_KeyBinder
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QFrame *line;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *KeyBinder)
    {
        if (KeyBinder->objectName().isEmpty())
            KeyBinder->setObjectName("KeyBinder");
        KeyBinder->resize(400, 103);
        verticalLayout = new QVBoxLayout(KeyBinder);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(KeyBinder);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, label);


        verticalLayout->addLayout(formLayout);

        line = new QFrame(KeyBinder);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line);

        buttonBox = new QDialogButtonBox(KeyBinder);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(KeyBinder);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, KeyBinder, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, KeyBinder, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(KeyBinder);
    } // setupUi

    void retranslateUi(QDialog *KeyBinder)
    {
        KeyBinder->setWindowTitle(QCoreApplication::translate("KeyBinder", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("KeyBinder", "Enter key combo:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KeyBinder: public Ui_KeyBinder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_KEYBIND_H

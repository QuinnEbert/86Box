/********************************************************************************
** Form generated from reading UI file 'qt_openglshaderconfig.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_OPENGLSHADERCONFIG_H
#define UI_QT_OPENGLSHADERCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenGLShaderConfig
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OpenGLShaderConfig)
    {
        if (OpenGLShaderConfig->objectName().isEmpty())
            OpenGLShaderConfig->setObjectName("OpenGLShaderConfig");
        OpenGLShaderConfig->resize(400, 300);
        verticalLayout = new QVBoxLayout(OpenGLShaderConfig);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        scrollArea = new QScrollArea(OpenGLShaderConfig);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 250));
        formLayout_2 = new QFormLayout(scrollAreaWidgetContents);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        buttonBox = new QDialogButtonBox(OpenGLShaderConfig);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::Reset);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(OpenGLShaderConfig);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, OpenGLShaderConfig, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, OpenGLShaderConfig, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(OpenGLShaderConfig);
    } // setupUi

    void retranslateUi(QDialog *OpenGLShaderConfig)
    {
        OpenGLShaderConfig->setWindowTitle(QCoreApplication::translate("OpenGLShaderConfig", "Shader Configuration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenGLShaderConfig: public Ui_OpenGLShaderConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_OPENGLSHADERCONFIG_H

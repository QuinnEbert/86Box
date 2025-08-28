/********************************************************************************
** Form generated from reading UI file 'qt_openglshadermanagerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_OPENGLSHADERMANAGERDIALOG_H
#define UI_QT_OPENGLSHADERMANAGERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OpenGLShaderManagerDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButtonVideoSync;
    QRadioButton *radioButtonTargetFramerate;
    QSlider *horizontalSliderFramerate;
    QSpinBox *targetFrameRate;
    QCheckBox *checkBoxVSync;
    QGroupBox *groupBoxShaders;
    QHBoxLayout *horizontalLayout;
    QListWidget *shaderListWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *buttonAdd;
    QPushButton *buttonRemove;
    QSpacerItem *verticalSpacer;
    QPushButton *buttonConfigure;
    QPushButton *buttonMoveUp;
    QPushButton *buttonMoveDown;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OpenGLShaderManagerDialog)
    {
        if (OpenGLShaderManagerDialog->objectName().isEmpty())
            OpenGLShaderManagerDialog->setObjectName("OpenGLShaderManagerDialog");
        OpenGLShaderManagerDialog->resize(400, 465);
        gridLayout = new QGridLayout(OpenGLShaderManagerDialog);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        groupBox = new QGroupBox(OpenGLShaderManagerDialog);
        groupBox->setObjectName("groupBox");
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        radioButtonVideoSync = new QRadioButton(groupBox);
        radioButtonVideoSync->setObjectName("radioButtonVideoSync");
        radioButtonVideoSync->setChecked(true);

        gridLayout_2->addWidget(radioButtonVideoSync, 0, 0, 1, 1);

        radioButtonTargetFramerate = new QRadioButton(groupBox);
        radioButtonTargetFramerate->setObjectName("radioButtonTargetFramerate");

        gridLayout_2->addWidget(radioButtonTargetFramerate, 1, 0, 1, 1);

        horizontalSliderFramerate = new QSlider(groupBox);
        horizontalSliderFramerate->setObjectName("horizontalSliderFramerate");
        horizontalSliderFramerate->setMinimum(15);
        horizontalSliderFramerate->setMaximum(240);
        horizontalSliderFramerate->setValue(60);
        horizontalSliderFramerate->setOrientation(Qt::Horizontal);
        horizontalSliderFramerate->setInvertedAppearance(false);
        horizontalSliderFramerate->setInvertedControls(false);

        gridLayout_2->addWidget(horizontalSliderFramerate, 2, 0, 1, 1);

        targetFrameRate = new QSpinBox(groupBox);
        targetFrameRate->setObjectName("targetFrameRate");
        targetFrameRate->setMinimum(15);
        targetFrameRate->setMaximum(240);
        targetFrameRate->setValue(60);

        gridLayout_2->addWidget(targetFrameRate, 2, 1, 1, 1);

        checkBoxVSync = new QCheckBox(groupBox);
        checkBoxVSync->setObjectName("checkBoxVSync");

        gridLayout_2->addWidget(checkBoxVSync, 3, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBoxShaders = new QGroupBox(OpenGLShaderManagerDialog);
        groupBoxShaders->setObjectName("groupBoxShaders");
        horizontalLayout = new QHBoxLayout(groupBoxShaders);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        shaderListWidget = new QListWidget(groupBoxShaders);
        shaderListWidget->setObjectName("shaderListWidget");
        shaderListWidget->setDragDropMode(QAbstractItemView::InternalMove);
        shaderListWidget->setSelectionBehavior(QAbstractItemView::SelectItems);

        horizontalLayout->addWidget(shaderListWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        buttonAdd = new QPushButton(groupBoxShaders);
        buttonAdd->setObjectName("buttonAdd");

        verticalLayout->addWidget(buttonAdd);

        buttonRemove = new QPushButton(groupBoxShaders);
        buttonRemove->setObjectName("buttonRemove");

        verticalLayout->addWidget(buttonRemove);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonConfigure = new QPushButton(groupBoxShaders);
        buttonConfigure->setObjectName("buttonConfigure");
        buttonConfigure->setEnabled(true);

        verticalLayout->addWidget(buttonConfigure);

        buttonMoveUp = new QPushButton(groupBoxShaders);
        buttonMoveUp->setObjectName("buttonMoveUp");

        verticalLayout->addWidget(buttonMoveUp);

        buttonMoveDown = new QPushButton(groupBoxShaders);
        buttonMoveDown->setObjectName("buttonMoveDown");

        verticalLayout->addWidget(buttonMoveDown);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        buttonBox = new QDialogButtonBox(groupBoxShaders);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        verticalLayout->addWidget(buttonBox);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addWidget(groupBoxShaders, 1, 0, 1, 1);


        retranslateUi(OpenGLShaderManagerDialog);

        QMetaObject::connectSlotsByName(OpenGLShaderManagerDialog);
    } // setupUi

    void retranslateUi(QDialog *OpenGLShaderManagerDialog)
    {
        OpenGLShaderManagerDialog->setWindowTitle(QCoreApplication::translate("OpenGLShaderManagerDialog", "Shader Manager", nullptr));
        groupBox->setTitle(QCoreApplication::translate("OpenGLShaderManagerDialog", "Render behavior", nullptr));
        radioButtonVideoSync->setText(QCoreApplication::translate("OpenGLShaderManagerDialog", "Synchronize with video", nullptr));
        radioButtonTargetFramerate->setText(QCoreApplication::translate("OpenGLShaderManagerDialog", "Use target framerate:", nullptr));
        targetFrameRate->setSuffix(QCoreApplication::translate("OpenGLShaderManagerDialog", " fps", nullptr));
        checkBoxVSync->setText(QCoreApplication::translate("OpenGLShaderManagerDialog", "VSync", nullptr));
        groupBoxShaders->setTitle(QCoreApplication::translate("OpenGLShaderManagerDialog", "Shaders", nullptr));
        buttonAdd->setText(QCoreApplication::translate("OpenGLShaderManagerDialog", "Add", nullptr));
        buttonRemove->setText(QCoreApplication::translate("OpenGLShaderManagerDialog", "Remove", nullptr));
        buttonConfigure->setText(QCoreApplication::translate("OpenGLShaderManagerDialog", "Configure", nullptr));
        buttonMoveUp->setText(QCoreApplication::translate("OpenGLShaderManagerDialog", "Move up", nullptr));
        buttonMoveDown->setText(QCoreApplication::translate("OpenGLShaderManagerDialog", "Move down", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenGLShaderManagerDialog: public Ui_OpenGLShaderManagerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_OPENGLSHADERMANAGERDIALOG_H

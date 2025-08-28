/********************************************************************************
** Form generated from reading UI file 'qt_vmmanager_preferences.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_VMMANAGER_PREFERENCES_H
#define UI_QT_VMMANAGER_PREFERENCES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VMManagerPreferences
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *systemDirectory;
    QPushButton *dirSelectButton;
    QLabel *labelLanguage;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBoxLanguage;
    QPushButton *pushButtonLanguage;
    QCheckBox *updateCheckBox;
    QCheckBox *regexSearchCheckBox;
    QGroupBox *groupBoxColorScheme;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonSystem;
    QRadioButton *radioButtonLight;
    QRadioButton *radioButtonDark;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *VMManagerPreferences)
    {
        if (VMManagerPreferences->objectName().isEmpty())
            VMManagerPreferences->setObjectName("VMManagerPreferences");
        VMManagerPreferences->resize(400, 475);
        verticalLayout = new QVBoxLayout(VMManagerPreferences);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        label = new QLabel(VMManagerPreferences);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        widget = new QWidget(VMManagerPreferences);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        systemDirectory = new QLabel(widget);
        systemDirectory->setObjectName("systemDirectory");

        horizontalLayout->addWidget(systemDirectory);

        dirSelectButton = new QPushButton(widget);
        dirSelectButton->setObjectName("dirSelectButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dirSelectButton->sizePolicy().hasHeightForWidth());
        dirSelectButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(dirSelectButton);


        verticalLayout->addWidget(widget);

        labelLanguage = new QLabel(VMManagerPreferences);
        labelLanguage->setObjectName("labelLanguage");

        verticalLayout->addWidget(labelLanguage);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        comboBoxLanguage = new QComboBox(VMManagerPreferences);
        comboBoxLanguage->addItem(QString());
        comboBoxLanguage->setObjectName("comboBoxLanguage");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxLanguage->sizePolicy().hasHeightForWidth());
        comboBoxLanguage->setSizePolicy(sizePolicy1);
        comboBoxLanguage->setMaxVisibleItems(30);

        horizontalLayout_2->addWidget(comboBoxLanguage);

        pushButtonLanguage = new QPushButton(VMManagerPreferences);
        pushButtonLanguage->setObjectName("pushButtonLanguage");

        horizontalLayout_2->addWidget(pushButtonLanguage);


        verticalLayout->addLayout(horizontalLayout_2);

        updateCheckBox = new QCheckBox(VMManagerPreferences);
        updateCheckBox->setObjectName("updateCheckBox");

        verticalLayout->addWidget(updateCheckBox);

        regexSearchCheckBox = new QCheckBox(VMManagerPreferences);
        regexSearchCheckBox->setObjectName("regexSearchCheckBox");

        verticalLayout->addWidget(regexSearchCheckBox);

        groupBoxColorScheme = new QGroupBox(VMManagerPreferences);
        groupBoxColorScheme->setObjectName("groupBoxColorScheme");
        verticalLayout_2 = new QVBoxLayout(groupBoxColorScheme);
        verticalLayout_2->setObjectName("verticalLayout_2");
        radioButtonSystem = new QRadioButton(groupBoxColorScheme);
        radioButtonSystem->setObjectName("radioButtonSystem");

        verticalLayout_2->addWidget(radioButtonSystem);

        radioButtonLight = new QRadioButton(groupBoxColorScheme);
        radioButtonLight->setObjectName("radioButtonLight");

        verticalLayout_2->addWidget(radioButtonLight);

        radioButtonDark = new QRadioButton(groupBoxColorScheme);
        radioButtonDark->setObjectName("radioButtonDark");

        verticalLayout_2->addWidget(radioButtonDark);


        verticalLayout->addWidget(groupBoxColorScheme);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(VMManagerPreferences);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(dirSelectButton, comboBoxLanguage);
        QWidget::setTabOrder(comboBoxLanguage, pushButtonLanguage);
        QWidget::setTabOrder(pushButtonLanguage, updateCheckBox);
        QWidget::setTabOrder(updateCheckBox, regexSearchCheckBox);

        retranslateUi(VMManagerPreferences);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, VMManagerPreferences, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, VMManagerPreferences, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(VMManagerPreferences);
    } // setupUi

    void retranslateUi(QDialog *VMManagerPreferences)
    {
        VMManagerPreferences->setWindowTitle(QCoreApplication::translate("VMManagerPreferences", "Preferences", nullptr));
        label->setText(QCoreApplication::translate("VMManagerPreferences", "System Directory:", nullptr));
        systemDirectory->setText(QString());
        dirSelectButton->setText(QString());
        labelLanguage->setText(QCoreApplication::translate("VMManagerPreferences", "Language:", nullptr));
        comboBoxLanguage->setItemText(0, QCoreApplication::translate("VMManagerPreferences", "(System Default)", nullptr));

        pushButtonLanguage->setText(QCoreApplication::translate("VMManagerPreferences", "Default", nullptr));
        updateCheckBox->setText(QCoreApplication::translate("VMManagerPreferences", "Check for updates on startup", nullptr));
        regexSearchCheckBox->setText(QCoreApplication::translate("VMManagerPreferences", "Use regular expressions in search box", nullptr));
        groupBoxColorScheme->setTitle(QCoreApplication::translate("VMManagerPreferences", "Color scheme", nullptr));
        radioButtonSystem->setText(QCoreApplication::translate("VMManagerPreferences", "System", nullptr));
        radioButtonLight->setText(QCoreApplication::translate("VMManagerPreferences", "Light", nullptr));
        radioButtonDark->setText(QCoreApplication::translate("VMManagerPreferences", "Dark", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VMManagerPreferences: public Ui_VMManagerPreferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_VMMANAGER_PREFERENCES_H

/********************************************************************************
** Form generated from reading UI file 'qt_vmmanager_details.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_VMMANAGER_DETAILS_H
#define UI_QT_VMMANAGER_DETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VMManagerDetails
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *systemLabel;
    QWidget *LeftRight;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *leftColumn;
    QVBoxLayout *verticalLayout_4;
    QWidget *rightColumn;
    QVBoxLayout *verticalLayout_3;
    QLabel *screenshot;
    QWidget *screenshotNavButtons;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *screenshotPrevious;
    QWidget *ssNavTBHolder;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *screenshotPreviousTB;
    QToolButton *screenshotNextTB;
    QPushButton *screenshotNext;
    QSpacerItem *horizontalSpacer_2;
    QPlainTextEdit *notesTextEdit;
    QSpacerItem *verticalSpacer_3;
    QWidget *toolButtonHolder;
    QHBoxLayout *horizontalLayout_3;
    QLabel *statusLabel;

    void setupUi(QWidget *VMManagerDetails)
    {
        if (VMManagerDetails->objectName().isEmpty())
            VMManagerDetails->setObjectName("VMManagerDetails");
        VMManagerDetails->resize(497, 444);
        verticalLayout = new QVBoxLayout(VMManagerDetails);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, -1, -1, 0);
        systemLabel = new QLabel(VMManagerDetails);
        systemLabel->setObjectName("systemLabel");
        QFont font;
        font.setPointSize(18);
        systemLabel->setFont(font);
        systemLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(systemLabel);

        LeftRight = new QWidget(VMManagerDetails);
        LeftRight->setObjectName("LeftRight");
        horizontalLayout = new QHBoxLayout(LeftRight);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, -1, -1, 0);
        scrollArea = new QScrollArea(LeftRight);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setWidgetResizable(true);
        leftColumn = new QWidget();
        leftColumn->setObjectName("leftColumn");
        leftColumn->setGeometry(QRect(0, 0, 139, 388));
        verticalLayout_4 = new QVBoxLayout(leftColumn);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(12, 12, 12, 12);
        scrollArea->setWidget(leftColumn);

        horizontalLayout->addWidget(scrollArea);

        rightColumn = new QWidget(LeftRight);
        rightColumn->setObjectName("rightColumn");
        verticalLayout_3 = new QVBoxLayout(rightColumn);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, 0, 0, -1);
        screenshot = new QLabel(rightColumn);
        screenshot->setObjectName("screenshot");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(screenshot->sizePolicy().hasHeightForWidth());
        screenshot->setSizePolicy(sizePolicy);
        screenshot->setMinimumSize(QSize(240, 160));
        screenshot->setMaximumSize(QSize(240, 160));
        screenshot->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(screenshot, 0, Qt::AlignHCenter);

        screenshotNavButtons = new QWidget(rightColumn);
        screenshotNavButtons->setObjectName("screenshotNavButtons");
        horizontalLayout_2 = new QHBoxLayout(screenshotNavButtons);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        screenshotPrevious = new QPushButton(screenshotNavButtons);
        screenshotPrevious->setObjectName("screenshotPrevious");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(screenshotPrevious->sizePolicy().hasHeightForWidth());
        screenshotPrevious->setSizePolicy(sizePolicy1);
        screenshotPrevious->setFlat(false);

        horizontalLayout_2->addWidget(screenshotPrevious);

        ssNavTBHolder = new QWidget(screenshotNavButtons);
        ssNavTBHolder->setObjectName("ssNavTBHolder");
        horizontalLayout_4 = new QHBoxLayout(ssNavTBHolder);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        screenshotPreviousTB = new QToolButton(ssNavTBHolder);
        screenshotPreviousTB->setObjectName("screenshotPreviousTB");

        horizontalLayout_4->addWidget(screenshotPreviousTB);

        screenshotNextTB = new QToolButton(ssNavTBHolder);
        screenshotNextTB->setObjectName("screenshotNextTB");
        screenshotNextTB->setAutoRaise(true);

        horizontalLayout_4->addWidget(screenshotNextTB);


        horizontalLayout_2->addWidget(ssNavTBHolder);

        screenshotNext = new QPushButton(screenshotNavButtons);
        screenshotNext->setObjectName("screenshotNext");
        sizePolicy1.setHeightForWidth(screenshotNext->sizePolicy().hasHeightForWidth());
        screenshotNext->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(screenshotNext);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(screenshotNavButtons);

        notesTextEdit = new QPlainTextEdit(rightColumn);
        notesTextEdit->setObjectName("notesTextEdit");

        verticalLayout_3->addWidget(notesTextEdit);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        toolButtonHolder = new QWidget(rightColumn);
        toolButtonHolder->setObjectName("toolButtonHolder");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolButtonHolder->sizePolicy().hasHeightForWidth());
        toolButtonHolder->setSizePolicy(sizePolicy2);
        horizontalLayout_3 = new QHBoxLayout(toolButtonHolder);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);

        verticalLayout_3->addWidget(toolButtonHolder);

        statusLabel = new QLabel(rightColumn);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(statusLabel);


        horizontalLayout->addWidget(rightColumn, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(LeftRight);


        retranslateUi(VMManagerDetails);

        QMetaObject::connectSlotsByName(VMManagerDetails);
    } // setupUi

    void retranslateUi(QWidget *VMManagerDetails)
    {
        VMManagerDetails->setWindowTitle(QCoreApplication::translate("VMManagerDetails", "VMManagerDetails", nullptr));
        systemLabel->setText(QCoreApplication::translate("VMManagerDetails", "No Machines Found!", nullptr));
        screenshot->setText(QString());
        screenshotPrevious->setText(QString());
        screenshotPreviousTB->setText(QCoreApplication::translate("VMManagerDetails", "...", nullptr));
        screenshotNextTB->setText(QCoreApplication::translate("VMManagerDetails", "...", nullptr));
        screenshotNext->setText(QString());
        notesTextEdit->setPlaceholderText(QCoreApplication::translate("VMManagerDetails", "Type some notes here", nullptr));
        statusLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VMManagerDetails: public Ui_VMManagerDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_VMMANAGER_DETAILS_H

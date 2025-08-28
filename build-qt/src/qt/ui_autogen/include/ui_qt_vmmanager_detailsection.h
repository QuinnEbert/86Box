/********************************************************************************
** Form generated from reading UI file 'qt_vmmanager_detailsection.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_VMMANAGER_DETAILSECTION_H
#define UI_QT_VMMANAGER_DETAILSECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetailSection
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *outerFrame;
    QVBoxLayout *verticalLayout_2;
    QWidget *collapseButtonHolder;
    QHBoxLayout *horizontalLayout;
    QFrame *detailFrame;

    void setupUi(QWidget *DetailSection)
    {
        if (DetailSection->objectName().isEmpty())
            DetailSection->setObjectName("DetailSection");
        DetailSection->resize(348, 151);
        verticalLayout = new QVBoxLayout(DetailSection);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        outerFrame = new QFrame(DetailSection);
        outerFrame->setObjectName("outerFrame");
        outerFrame->setFrameShape(QFrame::NoFrame);
        outerFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(outerFrame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        collapseButtonHolder = new QWidget(outerFrame);
        collapseButtonHolder->setObjectName("collapseButtonHolder");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(collapseButtonHolder->sizePolicy().hasHeightForWidth());
        collapseButtonHolder->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(collapseButtonHolder);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout_2->addWidget(collapseButtonHolder);

        detailFrame = new QFrame(outerFrame);
        detailFrame->setObjectName("detailFrame");
        detailFrame->setFrameShape(QFrame::NoFrame);
        detailFrame->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(detailFrame);


        verticalLayout->addWidget(outerFrame);


        retranslateUi(DetailSection);

        QMetaObject::connectSlotsByName(DetailSection);
    } // setupUi

    void retranslateUi(QWidget *DetailSection)
    {
        DetailSection->setWindowTitle(QCoreApplication::translate("DetailSection", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetailSection: public Ui_DetailSection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_VMMANAGER_DETAILSECTION_H

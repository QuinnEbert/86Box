/********************************************************************************
** Form generated from reading UI file 'qt_vmmanager_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_VMMANAGER_MAINWINDOW_H
#define UI_QT_VMMANAGER_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VMManagerMainWindow
{
public:
    QAction *actionStartPause;
    QAction *actionHard_Reset;
    QAction *actionForce_Shutdown;
    QAction *actionCtrl_Alt_Del;
    QAction *actionSettings;
    QAction *actionNew_Machine;
    QAction *actionRemember_size_and_position;
    QAction *actionPreferences;
    QAction *actionStart;
    QAction *actionCheck_for_updates;
    QAction *actionExit;
    QAction *actionDocumentation;
    QAction *actionAbout_86Box;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuTools;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *VMManagerMainWindow)
    {
        if (VMManagerMainWindow->objectName().isEmpty())
            VMManagerMainWindow->setObjectName("VMManagerMainWindow");
        VMManagerMainWindow->resize(900, 600);
        actionStartPause = new QAction(VMManagerMainWindow);
        actionStartPause->setObjectName("actionStartPause");
        actionStartPause->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/menuicons/qt/icons/run.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionStartPause->setIcon(icon);
        actionStartPause->setIconVisibleInMenu(false);
        actionHard_Reset = new QAction(VMManagerMainWindow);
        actionHard_Reset->setObjectName("actionHard_Reset");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/menuicons/qt/icons/hard_reset.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionHard_Reset->setIcon(icon1);
        actionHard_Reset->setIconVisibleInMenu(false);
        actionForce_Shutdown = new QAction(VMManagerMainWindow);
        actionForce_Shutdown->setObjectName("actionForce_Shutdown");
        actionForce_Shutdown->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/menuicons/qt/icons/acpi_shutdown.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionForce_Shutdown->setIcon(icon2);
        actionForce_Shutdown->setVisible(true);
        actionForce_Shutdown->setIconVisibleInMenu(false);
        actionCtrl_Alt_Del = new QAction(VMManagerMainWindow);
        actionCtrl_Alt_Del->setObjectName("actionCtrl_Alt_Del");
        actionCtrl_Alt_Del->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/menuicons/qt/icons/send_cad.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCtrl_Alt_Del->setIcon(icon3);
        actionCtrl_Alt_Del->setVisible(false);
        actionCtrl_Alt_Del->setIconVisibleInMenu(false);
        actionCtrl_Alt_Del->setShortcutVisibleInContextMenu(false);
        actionSettings = new QAction(VMManagerMainWindow);
        actionSettings->setObjectName("actionSettings");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/menuicons/qt/icons/settings.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSettings->setIcon(icon4);
        actionSettings->setMenuRole(QAction::NoRole);
        actionSettings->setIconVisibleInMenu(false);
        actionNew_Machine = new QAction(VMManagerMainWindow);
        actionNew_Machine->setObjectName("actionNew_Machine");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/settings/qt/icons/86Box-yellow.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNew_Machine->setIcon(icon5);
        actionRemember_size_and_position = new QAction(VMManagerMainWindow);
        actionRemember_size_and_position->setObjectName("actionRemember_size_and_position");
        actionRemember_size_and_position->setCheckable(true);
        actionPreferences = new QAction(VMManagerMainWindow);
        actionPreferences->setObjectName("actionPreferences");
        actionPreferences->setMenuRole(QAction::PreferencesRole);
        actionStart = new QAction(VMManagerMainWindow);
        actionStart->setObjectName("actionStart");
        actionStart->setCheckable(true);
        actionStart->setIcon(icon);
        actionStart->setIconVisibleInMenu(false);
        actionCheck_for_updates = new QAction(VMManagerMainWindow);
        actionCheck_for_updates->setObjectName("actionCheck_for_updates");
        actionExit = new QAction(VMManagerMainWindow);
        actionExit->setObjectName("actionExit");
        actionExit->setMenuRole(QAction::QuitRole);
        actionDocumentation = new QAction(VMManagerMainWindow);
        actionDocumentation->setObjectName("actionDocumentation");
        actionAbout_86Box = new QAction(VMManagerMainWindow);
        actionAbout_86Box->setObjectName("actionAbout_86Box");
        actionAbout_86Box->setMenuRole(QAction::AboutRole);
        actionAbout_Qt = new QAction(VMManagerMainWindow);
        actionAbout_Qt->setObjectName("actionAbout_Qt");
        actionAbout_Qt->setVisible(false);
        actionAbout_Qt->setMenuRole(QAction::AboutQtRole);
        centralwidget = new QWidget(VMManagerMainWindow);
        centralwidget->setObjectName("centralwidget");
        VMManagerMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VMManagerMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 21));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName("menuTools");
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        VMManagerMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(VMManagerMainWindow);
        statusbar->setObjectName("statusbar");
        VMManagerMainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(VMManagerMainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setAutoFillBackground(true);
        toolBar->setMovable(false);
        toolBar->setAllowedAreas(Qt::TopToolBarArea);
        toolBar->setIconSize(QSize(16, 16));
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        VMManagerMainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuTools->addAction(actionPreferences);
        menuTools->addAction(actionRemember_size_and_position);
        menuTools->addAction(actionCheck_for_updates);
        menuFile->addAction(actionNew_Machine);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionDocumentation);
        menuHelp->addAction(actionAbout_86Box);
        menuHelp->addAction(actionAbout_Qt);
        toolBar->addAction(actionNew_Machine);
        toolBar->addSeparator();
        toolBar->addAction(actionStartPause);
        toolBar->addAction(actionHard_Reset);
        toolBar->addAction(actionForce_Shutdown);
        toolBar->addAction(actionCtrl_Alt_Del);
        toolBar->addAction(actionSettings);

        retranslateUi(VMManagerMainWindow);

        QMetaObject::connectSlotsByName(VMManagerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *VMManagerMainWindow)
    {
        VMManagerMainWindow->setWindowTitle(QCoreApplication::translate("VMManagerMainWindow", "86Box VM Manager", nullptr));
        actionStartPause->setText(QCoreApplication::translate("VMManagerMainWindow", "&Start", nullptr));
        actionHard_Reset->setText(QCoreApplication::translate("VMManagerMainWindow", "&Hard Reset...", nullptr));
        actionForce_Shutdown->setText(QCoreApplication::translate("VMManagerMainWindow", "&Force shutdown", nullptr));
#if QT_CONFIG(tooltip)
        actionForce_Shutdown->setToolTip(QCoreApplication::translate("VMManagerMainWindow", "Force shutdown", nullptr));
#endif // QT_CONFIG(tooltip)
        actionCtrl_Alt_Del->setText(QCoreApplication::translate("VMManagerMainWindow", "&Ctrl+Alt+Del", nullptr));
#if QT_CONFIG(tooltip)
        actionCtrl_Alt_Del->setToolTip(QCoreApplication::translate("VMManagerMainWindow", "Ctrl+Alt+Del", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSettings->setText(QCoreApplication::translate("VMManagerMainWindow", "&Settings...", nullptr));
        actionNew_Machine->setText(QCoreApplication::translate("VMManagerMainWindow", "&New machine...", nullptr));
#if QT_CONFIG(tooltip)
        actionNew_Machine->setToolTip(QCoreApplication::translate("VMManagerMainWindow", "New machine...", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRemember_size_and_position->setText(QCoreApplication::translate("VMManagerMainWindow", "R&emember size && position", nullptr));
        actionPreferences->setText(QCoreApplication::translate("VMManagerMainWindow", "&Preferences...", nullptr));
#if QT_CONFIG(tooltip)
        actionPreferences->setToolTip(QCoreApplication::translate("VMManagerMainWindow", "Preferences...", nullptr));
#endif // QT_CONFIG(tooltip)
        actionStart->setText(QCoreApplication::translate("VMManagerMainWindow", "&Start", nullptr));
        actionCheck_for_updates->setText(QCoreApplication::translate("VMManagerMainWindow", "&Check for updates...", nullptr));
        actionExit->setText(QCoreApplication::translate("VMManagerMainWindow", "E&xit", nullptr));
        actionDocumentation->setText(QCoreApplication::translate("VMManagerMainWindow", "&Documentation...", nullptr));
        actionAbout_86Box->setText(QCoreApplication::translate("VMManagerMainWindow", "&About 86Box...", nullptr));
        actionAbout_Qt->setText(QCoreApplication::translate("VMManagerMainWindow", "About &Qt", nullptr));
        menuTools->setTitle(QCoreApplication::translate("VMManagerMainWindow", "&Tools", nullptr));
        menuFile->setTitle(QCoreApplication::translate("VMManagerMainWindow", "&File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("VMManagerMainWindow", "&Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("VMManagerMainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VMManagerMainWindow: public Ui_VMManagerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_VMMANAGER_MAINWINDOW_H

/****************************************************************************
** Meta object code from reading C++ file 'qt_mainwindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qt/qt_mainwindow.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_mainwindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainWindow",
        "paint",
        "",
        "image",
        "resizeContents",
        "w",
        "h",
        "resizeContentsMonitor",
        "monitor_index",
        "statusBarMessage",
        "msg",
        "updateStatusBarPanes",
        "updateStatusBarActivity",
        "tag",
        "active",
        "updateStatusBarEmpty",
        "empty",
        "updateStatusBarTip",
        "updateMenuResizeOptions",
        "updateWindowRememberOption",
        "initRendererMonitor",
        "destroyRendererMonitor",
        "initRendererMonitorForNonQtThread",
        "destroyRendererMonitorForNonQtThread",
        "hardResetCompleted",
        "setTitle",
        "title",
        "setFullscreen",
        "state",
        "setMouseCapture",
        "showMessageForNonQtThread",
        "flags",
        "header",
        "message",
        "richText",
        "std::atomic_bool*",
        "done",
        "getTitleForNonQtThread",
        "wchar_t*",
        "vmmRunningStateChanged",
        "VMManagerProtocol::RunningState",
        "vmmConfigurationChanged",
        "vmmGlobalConfigurationChanged",
        "showSettings",
        "hardReset",
        "togglePause",
        "initRendererMonitorSlot",
        "destroyRendererMonitorSlot",
        "updateStatusEmptyIcons",
        "updateUiPauseState",
        "on_actionFullscreen_triggered",
        "on_actionSettings_triggered",
        "on_actionExit_triggered",
        "on_actionAuto_pause_triggered",
        "on_actionUpdate_mouse_every_CPU_frame_triggered",
        "on_actionPause_triggered",
        "on_actionTurbo_mode_triggered",
        "on_actionSlow_Turbo_Off_triggered",
        "on_actionSlow_Turbo_1_cycle_triggered",
        "on_actionSlow_Turbo_2_cycles_triggered",
        "on_actionSlow_Turbo_3_cycles_triggered",
        "on_actionSlow_Turbo_4_cycles_triggered",
        "on_actionTurbo_Batch_Auto_triggered",
        "on_actionTurbo_Batch_8ms_triggered",
        "on_actionTurbo_Batch_16ms_triggered",
        "on_actionTurbo_Batch_32ms_triggered",
        "on_actionTurbo_Batch_64ms_triggered",
        "on_actionTurbo_Batch_Unlimited_triggered",
        "on_actionVirtualized_CPU_triggered",
        "on_actionCtrl_Alt_Del_triggered",
        "on_actionCtrl_Alt_Esc_triggered",
        "on_actionHard_Reset_triggered",
        "on_actionRight_CTRL_is_left_ALT_triggered",
        "on_actionKeyboard_requires_capture_triggered",
        "on_actionResizable_window_triggered",
        "checked",
        "on_actionInverted_VGA_monitor_triggered",
        "on_action0_5x_triggered",
        "on_action1x_triggered",
        "on_action1_5x_triggered",
        "on_action2x_triggered",
        "on_action3x_triggered",
        "on_action4x_triggered",
        "on_action5x_triggered",
        "on_action6x_triggered",
        "on_action7x_triggered",
        "on_action8x_triggered",
        "on_actionLinear_triggered",
        "on_actionNearest_triggered",
        "on_actionFullScreen_int_triggered",
        "on_actionFullScreen_int43_triggered",
        "on_actionFullScreen_keepRatio_triggered",
        "on_actionFullScreen_43_triggered",
        "on_actionFullScreen_stretch_triggered",
        "on_actionWhite_monitor_triggered",
        "on_actionGreen_monitor_triggered",
        "on_actionAmber_monitor_triggered",
        "on_actionRGB_Grayscale_triggered",
        "on_actionRGB_Color_triggered",
        "on_actionAverage_triggered",
        "on_actionBT709_HDTV_triggered",
        "on_actionBT601_NTSC_PAL_triggered",
        "on_actionDocumentation_triggered",
        "on_actionAbout_86Box_triggered",
        "on_actionAbout_Qt_triggered",
        "on_actionForce_4_3_display_ratio_triggered",
        "on_actionChange_contrast_for_monochrome_display_triggered",
        "on_actionCGA_PCjr_Tandy_EGA_S_VGA_overscan_triggered",
        "on_actionRemember_size_and_position_triggered",
        "on_actionSpecify_dimensions_triggered",
        "on_actionHiDPI_scaling_triggered",
        "on_actionHide_status_bar_triggered",
        "on_actionHide_tool_bar_triggered",
        "on_actionUpdate_status_bar_icons_triggered",
        "on_actionTake_screenshot_triggered",
        "on_actionMute_Unmute_triggered",
        "on_actionSound_gain_triggered",
        "on_actionPreferences_triggered",
        "on_actionEnable_Discord_integration_triggered",
        "on_actionRenderer_options_triggered",
        "refreshMediaMenu",
        "showMessage_",
        "getTitle_",
        "on_actionMCA_devices_triggered",
        "on_actionPen_triggered",
        "on_actionCursor_Puck_triggered",
        "on_actionACPI_Shutdown_triggered",
        "on_actionShow_non_primary_monitors_triggered",
        "on_actionOpen_screenshots_folder_triggered",
        "on_actionOpen_printer_tray_triggered",
        "on_actionApply_fullscreen_stretch_mode_when_maximized_triggered",
        "on_actionCGA_composite_settings_triggered"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'paint'
        QtMocHelpers::SignalData<void(const QImage &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QImage, 3 },
        }}),
        // Signal 'resizeContents'
        QtMocHelpers::SignalData<void(int, int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 }, { QMetaType::Int, 6 },
        }}),
        // Signal 'resizeContentsMonitor'
        QtMocHelpers::SignalData<void(int, int, int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 }, { QMetaType::Int, 6 }, { QMetaType::Int, 8 },
        }}),
        // Signal 'statusBarMessage'
        QtMocHelpers::SignalData<void(const QString &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 },
        }}),
        // Signal 'updateStatusBarPanes'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'updateStatusBarActivity'
        QtMocHelpers::SignalData<void(int, bool)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 13 }, { QMetaType::Bool, 14 },
        }}),
        // Signal 'updateStatusBarEmpty'
        QtMocHelpers::SignalData<void(int, bool)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 13 }, { QMetaType::Bool, 16 },
        }}),
        // Signal 'updateStatusBarTip'
        QtMocHelpers::SignalData<void(int)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 13 },
        }}),
        // Signal 'updateMenuResizeOptions'
        QtMocHelpers::SignalData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'updateWindowRememberOption'
        QtMocHelpers::SignalData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'initRendererMonitor'
        QtMocHelpers::SignalData<void(int)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Signal 'destroyRendererMonitor'
        QtMocHelpers::SignalData<void(int)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Signal 'initRendererMonitorForNonQtThread'
        QtMocHelpers::SignalData<void(int)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Signal 'destroyRendererMonitorForNonQtThread'
        QtMocHelpers::SignalData<void(int)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Signal 'hardResetCompleted'
        QtMocHelpers::SignalData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'setTitle'
        QtMocHelpers::SignalData<void(const QString &)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 26 },
        }}),
        // Signal 'setFullscreen'
        QtMocHelpers::SignalData<void(bool)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 28 },
        }}),
        // Signal 'setMouseCapture'
        QtMocHelpers::SignalData<void(bool)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 28 },
        }}),
        // Signal 'showMessageForNonQtThread'
        QtMocHelpers::SignalData<void(int, const QString &, const QString &, bool, std::atomic_bool *)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 31 }, { QMetaType::QString, 32 }, { QMetaType::QString, 33 }, { QMetaType::Bool, 34 },
            { 0x80000000 | 35, 36 },
        }}),
        // Signal 'getTitleForNonQtThread'
        QtMocHelpers::SignalData<void(wchar_t *)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 38, 26 },
        }}),
        // Signal 'vmmRunningStateChanged'
        QtMocHelpers::SignalData<void(VMManagerProtocol::RunningState)>(39, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 40, 28 },
        }}),
        // Signal 'vmmConfigurationChanged'
        QtMocHelpers::SignalData<void()>(41, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'vmmGlobalConfigurationChanged'
        QtMocHelpers::SignalData<void()>(42, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showSettings'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'hardReset'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'togglePause'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'initRendererMonitorSlot'
        QtMocHelpers::SlotData<void(int)>(46, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Slot 'destroyRendererMonitorSlot'
        QtMocHelpers::SlotData<void(int)>(47, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Slot 'updateStatusEmptyIcons'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updateUiPauseState'
        QtMocHelpers::SlotData<void()>(49, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'on_actionFullscreen_triggered'
        QtMocHelpers::SlotData<void()>(50, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSettings_triggered'
        QtMocHelpers::SlotData<void()>(51, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionExit_triggered'
        QtMocHelpers::SlotData<void()>(52, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionAuto_pause_triggered'
        QtMocHelpers::SlotData<void()>(53, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionUpdate_mouse_every_CPU_frame_triggered'
        QtMocHelpers::SlotData<void()>(54, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionPause_triggered'
        QtMocHelpers::SlotData<void()>(55, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionTurbo_mode_triggered'
        QtMocHelpers::SlotData<void()>(56, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSlow_Turbo_Off_triggered'
        QtMocHelpers::SlotData<void()>(57, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSlow_Turbo_1_cycle_triggered'
        QtMocHelpers::SlotData<void()>(58, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSlow_Turbo_2_cycles_triggered'
        QtMocHelpers::SlotData<void()>(59, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSlow_Turbo_3_cycles_triggered'
        QtMocHelpers::SlotData<void()>(60, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSlow_Turbo_4_cycles_triggered'
        QtMocHelpers::SlotData<void()>(61, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionTurbo_Batch_Auto_triggered'
        QtMocHelpers::SlotData<void()>(62, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionTurbo_Batch_8ms_triggered'
        QtMocHelpers::SlotData<void()>(63, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionTurbo_Batch_16ms_triggered'
        QtMocHelpers::SlotData<void()>(64, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionTurbo_Batch_32ms_triggered'
        QtMocHelpers::SlotData<void()>(65, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionTurbo_Batch_64ms_triggered'
        QtMocHelpers::SlotData<void()>(66, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionTurbo_Batch_Unlimited_triggered'
        QtMocHelpers::SlotData<void()>(67, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionVirtualized_CPU_triggered'
        QtMocHelpers::SlotData<void()>(68, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionCtrl_Alt_Del_triggered'
        QtMocHelpers::SlotData<void()>(69, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionCtrl_Alt_Esc_triggered'
        QtMocHelpers::SlotData<void()>(70, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionHard_Reset_triggered'
        QtMocHelpers::SlotData<void()>(71, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionRight_CTRL_is_left_ALT_triggered'
        QtMocHelpers::SlotData<void()>(72, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionKeyboard_requires_capture_triggered'
        QtMocHelpers::SlotData<void()>(73, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionResizable_window_triggered'
        QtMocHelpers::SlotData<void(bool)>(74, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 75 },
        }}),
        // Slot 'on_actionInverted_VGA_monitor_triggered'
        QtMocHelpers::SlotData<void()>(76, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_action0_5x_triggered'
        QtMocHelpers::SlotData<void()>(77, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_action1x_triggered'
        QtMocHelpers::SlotData<void()>(78, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_action1_5x_triggered'
        QtMocHelpers::SlotData<void()>(79, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_action2x_triggered'
        QtMocHelpers::SlotData<void()>(80, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_action3x_triggered'
        QtMocHelpers::SlotData<void()>(81, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_action4x_triggered'
        QtMocHelpers::SlotData<void()>(82, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_action5x_triggered'
        QtMocHelpers::SlotData<void()>(83, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_action6x_triggered'
        QtMocHelpers::SlotData<void()>(84, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_action7x_triggered'
        QtMocHelpers::SlotData<void()>(85, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_action8x_triggered'
        QtMocHelpers::SlotData<void()>(86, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionLinear_triggered'
        QtMocHelpers::SlotData<void()>(87, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionNearest_triggered'
        QtMocHelpers::SlotData<void()>(88, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionFullScreen_int_triggered'
        QtMocHelpers::SlotData<void()>(89, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionFullScreen_int43_triggered'
        QtMocHelpers::SlotData<void()>(90, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionFullScreen_keepRatio_triggered'
        QtMocHelpers::SlotData<void()>(91, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionFullScreen_43_triggered'
        QtMocHelpers::SlotData<void()>(92, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionFullScreen_stretch_triggered'
        QtMocHelpers::SlotData<void()>(93, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionWhite_monitor_triggered'
        QtMocHelpers::SlotData<void()>(94, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionGreen_monitor_triggered'
        QtMocHelpers::SlotData<void()>(95, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionAmber_monitor_triggered'
        QtMocHelpers::SlotData<void()>(96, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionRGB_Grayscale_triggered'
        QtMocHelpers::SlotData<void()>(97, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionRGB_Color_triggered'
        QtMocHelpers::SlotData<void()>(98, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionAverage_triggered'
        QtMocHelpers::SlotData<void()>(99, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionBT709_HDTV_triggered'
        QtMocHelpers::SlotData<void()>(100, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionBT601_NTSC_PAL_triggered'
        QtMocHelpers::SlotData<void()>(101, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionDocumentation_triggered'
        QtMocHelpers::SlotData<void()>(102, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionAbout_86Box_triggered'
        QtMocHelpers::SlotData<void()>(103, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionAbout_Qt_triggered'
        QtMocHelpers::SlotData<void()>(104, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionForce_4_3_display_ratio_triggered'
        QtMocHelpers::SlotData<void()>(105, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionChange_contrast_for_monochrome_display_triggered'
        QtMocHelpers::SlotData<void()>(106, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionCGA_PCjr_Tandy_EGA_S_VGA_overscan_triggered'
        QtMocHelpers::SlotData<void()>(107, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionRemember_size_and_position_triggered'
        QtMocHelpers::SlotData<void()>(108, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSpecify_dimensions_triggered'
        QtMocHelpers::SlotData<void()>(109, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionHiDPI_scaling_triggered'
        QtMocHelpers::SlotData<void()>(110, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionHide_status_bar_triggered'
        QtMocHelpers::SlotData<void()>(111, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionHide_tool_bar_triggered'
        QtMocHelpers::SlotData<void()>(112, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionUpdate_status_bar_icons_triggered'
        QtMocHelpers::SlotData<void()>(113, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionTake_screenshot_triggered'
        QtMocHelpers::SlotData<void()>(114, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionMute_Unmute_triggered'
        QtMocHelpers::SlotData<void()>(115, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSound_gain_triggered'
        QtMocHelpers::SlotData<void()>(116, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionPreferences_triggered'
        QtMocHelpers::SlotData<void()>(117, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionEnable_Discord_integration_triggered'
        QtMocHelpers::SlotData<void(bool)>(118, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 75 },
        }}),
        // Slot 'on_actionRenderer_options_triggered'
        QtMocHelpers::SlotData<void()>(119, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'refreshMediaMenu'
        QtMocHelpers::SlotData<void()>(120, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'showMessage_'
        QtMocHelpers::SlotData<void(int, const QString &, const QString &, bool, std::atomic_bool *)>(121, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 31 }, { QMetaType::QString, 32 }, { QMetaType::QString, 33 }, { QMetaType::Bool, 34 },
            { 0x80000000 | 35, 36 },
        }}),
        // Slot 'showMessage_'
        QtMocHelpers::SlotData<void(int, const QString &, const QString &, bool)>(121, 2, QMC::AccessPrivate | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::Int, 31 }, { QMetaType::QString, 32 }, { QMetaType::QString, 33 }, { QMetaType::Bool, 34 },
        }}),
        // Slot 'getTitle_'
        QtMocHelpers::SlotData<void(wchar_t *)>(122, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 38, 26 },
        }}),
        // Slot 'on_actionMCA_devices_triggered'
        QtMocHelpers::SlotData<void()>(123, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionPen_triggered'
        QtMocHelpers::SlotData<void()>(124, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionCursor_Puck_triggered'
        QtMocHelpers::SlotData<void()>(125, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionACPI_Shutdown_triggered'
        QtMocHelpers::SlotData<void()>(126, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionShow_non_primary_monitors_triggered'
        QtMocHelpers::SlotData<void()>(127, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionOpen_screenshots_folder_triggered'
        QtMocHelpers::SlotData<void()>(128, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionOpen_printer_tray_triggered'
        QtMocHelpers::SlotData<void()>(129, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionApply_fullscreen_stretch_mode_when_maximized_triggered'
        QtMocHelpers::SlotData<void(bool)>(130, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 75 },
        }}),
        // Slot 'on_actionCGA_composite_settings_triggered'
        QtMocHelpers::SlotData<void()>(131, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10MainWindowE_t>.metaTypes,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->paint((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 1: _t->resizeContents((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->resizeContentsMonitor((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 3: _t->statusBarMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->updateStatusBarPanes(); break;
        case 5: _t->updateStatusBarActivity((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 6: _t->updateStatusBarEmpty((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 7: _t->updateStatusBarTip((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->updateMenuResizeOptions(); break;
        case 9: _t->updateWindowRememberOption(); break;
        case 10: _t->initRendererMonitor((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->destroyRendererMonitor((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->initRendererMonitorForNonQtThread((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->destroyRendererMonitorForNonQtThread((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->hardResetCompleted(); break;
        case 15: _t->setTitle((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->setFullscreen((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->setMouseCapture((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->showMessageForNonQtThread((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<std::atomic_bool*>>(_a[5]))); break;
        case 19: _t->getTitleForNonQtThread((*reinterpret_cast< std::add_pointer_t<wchar_t*>>(_a[1]))); break;
        case 20: _t->vmmRunningStateChanged((*reinterpret_cast< std::add_pointer_t<VMManagerProtocol::RunningState>>(_a[1]))); break;
        case 21: _t->vmmConfigurationChanged(); break;
        case 22: _t->vmmGlobalConfigurationChanged(); break;
        case 23: _t->showSettings(); break;
        case 24: _t->hardReset(); break;
        case 25: _t->togglePause(); break;
        case 26: _t->initRendererMonitorSlot((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->destroyRendererMonitorSlot((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->updateStatusEmptyIcons(); break;
        case 29: _t->updateUiPauseState(); break;
        case 30: _t->on_actionFullscreen_triggered(); break;
        case 31: _t->on_actionSettings_triggered(); break;
        case 32: _t->on_actionExit_triggered(); break;
        case 33: _t->on_actionAuto_pause_triggered(); break;
        case 34: _t->on_actionUpdate_mouse_every_CPU_frame_triggered(); break;
        case 35: _t->on_actionPause_triggered(); break;
        case 36: _t->on_actionTurbo_mode_triggered(); break;
        case 37: _t->on_actionSlow_Turbo_Off_triggered(); break;
        case 38: _t->on_actionSlow_Turbo_1_cycle_triggered(); break;
        case 39: _t->on_actionSlow_Turbo_2_cycles_triggered(); break;
        case 40: _t->on_actionSlow_Turbo_3_cycles_triggered(); break;
        case 41: _t->on_actionSlow_Turbo_4_cycles_triggered(); break;
        case 42: _t->on_actionTurbo_Batch_Auto_triggered(); break;
        case 43: _t->on_actionTurbo_Batch_8ms_triggered(); break;
        case 44: _t->on_actionTurbo_Batch_16ms_triggered(); break;
        case 45: _t->on_actionTurbo_Batch_32ms_triggered(); break;
        case 46: _t->on_actionTurbo_Batch_64ms_triggered(); break;
        case 47: _t->on_actionTurbo_Batch_Unlimited_triggered(); break;
        case 48: _t->on_actionVirtualized_CPU_triggered(); break;
        case 49: _t->on_actionCtrl_Alt_Del_triggered(); break;
        case 50: _t->on_actionCtrl_Alt_Esc_triggered(); break;
        case 51: _t->on_actionHard_Reset_triggered(); break;
        case 52: _t->on_actionRight_CTRL_is_left_ALT_triggered(); break;
        case 53: _t->on_actionKeyboard_requires_capture_triggered(); break;
        case 54: _t->on_actionResizable_window_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 55: _t->on_actionInverted_VGA_monitor_triggered(); break;
        case 56: _t->on_action0_5x_triggered(); break;
        case 57: _t->on_action1x_triggered(); break;
        case 58: _t->on_action1_5x_triggered(); break;
        case 59: _t->on_action2x_triggered(); break;
        case 60: _t->on_action3x_triggered(); break;
        case 61: _t->on_action4x_triggered(); break;
        case 62: _t->on_action5x_triggered(); break;
        case 63: _t->on_action6x_triggered(); break;
        case 64: _t->on_action7x_triggered(); break;
        case 65: _t->on_action8x_triggered(); break;
        case 66: _t->on_actionLinear_triggered(); break;
        case 67: _t->on_actionNearest_triggered(); break;
        case 68: _t->on_actionFullScreen_int_triggered(); break;
        case 69: _t->on_actionFullScreen_int43_triggered(); break;
        case 70: _t->on_actionFullScreen_keepRatio_triggered(); break;
        case 71: _t->on_actionFullScreen_43_triggered(); break;
        case 72: _t->on_actionFullScreen_stretch_triggered(); break;
        case 73: _t->on_actionWhite_monitor_triggered(); break;
        case 74: _t->on_actionGreen_monitor_triggered(); break;
        case 75: _t->on_actionAmber_monitor_triggered(); break;
        case 76: _t->on_actionRGB_Grayscale_triggered(); break;
        case 77: _t->on_actionRGB_Color_triggered(); break;
        case 78: _t->on_actionAverage_triggered(); break;
        case 79: _t->on_actionBT709_HDTV_triggered(); break;
        case 80: _t->on_actionBT601_NTSC_PAL_triggered(); break;
        case 81: _t->on_actionDocumentation_triggered(); break;
        case 82: _t->on_actionAbout_86Box_triggered(); break;
        case 83: _t->on_actionAbout_Qt_triggered(); break;
        case 84: _t->on_actionForce_4_3_display_ratio_triggered(); break;
        case 85: _t->on_actionChange_contrast_for_monochrome_display_triggered(); break;
        case 86: _t->on_actionCGA_PCjr_Tandy_EGA_S_VGA_overscan_triggered(); break;
        case 87: _t->on_actionRemember_size_and_position_triggered(); break;
        case 88: _t->on_actionSpecify_dimensions_triggered(); break;
        case 89: _t->on_actionHiDPI_scaling_triggered(); break;
        case 90: _t->on_actionHide_status_bar_triggered(); break;
        case 91: _t->on_actionHide_tool_bar_triggered(); break;
        case 92: _t->on_actionUpdate_status_bar_icons_triggered(); break;
        case 93: _t->on_actionTake_screenshot_triggered(); break;
        case 94: _t->on_actionMute_Unmute_triggered(); break;
        case 95: _t->on_actionSound_gain_triggered(); break;
        case 96: _t->on_actionPreferences_triggered(); break;
        case 97: _t->on_actionEnable_Discord_integration_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 98: _t->on_actionRenderer_options_triggered(); break;
        case 99: _t->refreshMediaMenu(); break;
        case 100: _t->showMessage_((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<std::atomic_bool*>>(_a[5]))); break;
        case 101: _t->showMessage_((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 102: _t->getTitle_((*reinterpret_cast< std::add_pointer_t<wchar_t*>>(_a[1]))); break;
        case 103: _t->on_actionMCA_devices_triggered(); break;
        case 104: _t->on_actionPen_triggered(); break;
        case 105: _t->on_actionCursor_Puck_triggered(); break;
        case 106: _t->on_actionACPI_Shutdown_triggered(); break;
        case 107: _t->on_actionShow_non_primary_monitors_triggered(); break;
        case 108: _t->on_actionOpen_screenshots_folder_triggered(); break;
        case 109: _t->on_actionOpen_printer_tray_triggered(); break;
        case 110: _t->on_actionApply_fullscreen_stretch_mode_when_maximized_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 111: _t->on_actionCGA_composite_settings_triggered(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(const QImage & )>(_a, &MainWindow::paint, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(int , int )>(_a, &MainWindow::resizeContents, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(int , int , int )>(_a, &MainWindow::resizeContentsMonitor, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(const QString & )>(_a, &MainWindow::statusBarMessage, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::updateStatusBarPanes, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(int , bool )>(_a, &MainWindow::updateStatusBarActivity, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(int , bool )>(_a, &MainWindow::updateStatusBarEmpty, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(int )>(_a, &MainWindow::updateStatusBarTip, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::updateMenuResizeOptions, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::updateWindowRememberOption, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(int )>(_a, &MainWindow::initRendererMonitor, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(int )>(_a, &MainWindow::destroyRendererMonitor, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(int )>(_a, &MainWindow::initRendererMonitorForNonQtThread, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(int )>(_a, &MainWindow::destroyRendererMonitorForNonQtThread, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::hardResetCompleted, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(const QString & )>(_a, &MainWindow::setTitle, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(bool )>(_a, &MainWindow::setFullscreen, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(bool )>(_a, &MainWindow::setMouseCapture, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(int , const QString & , const QString & , bool , std::atomic_bool * )>(_a, &MainWindow::showMessageForNonQtThread, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(wchar_t * )>(_a, &MainWindow::getTitleForNonQtThread, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)(VMManagerProtocol::RunningState )>(_a, &MainWindow::vmmRunningStateChanged, 20))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::vmmConfigurationChanged, 21))
            return;
        if (QtMocHelpers::indexOfMethod<void (MainWindow::*)()>(_a, &MainWindow::vmmGlobalConfigurationChanged, 22))
            return;
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 112)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 112;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 112)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 112;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::paint(const QImage & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void MainWindow::resizeContents(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void MainWindow::resizeContentsMonitor(int _t1, int _t2, int _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2, _t3);
}

// SIGNAL 3
void MainWindow::statusBarMessage(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void MainWindow::updateStatusBarPanes()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::updateStatusBarActivity(int _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2);
}

// SIGNAL 6
void MainWindow::updateStatusBarEmpty(int _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void MainWindow::updateStatusBarTip(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void MainWindow::updateMenuResizeOptions()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void MainWindow::updateWindowRememberOption()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void MainWindow::initRendererMonitor(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void MainWindow::destroyRendererMonitor(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void MainWindow::initRendererMonitorForNonQtThread(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1);
}

// SIGNAL 13
void MainWindow::destroyRendererMonitorForNonQtThread(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1);
}

// SIGNAL 14
void MainWindow::hardResetCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void MainWindow::setTitle(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 15, nullptr, _t1);
}

// SIGNAL 16
void MainWindow::setFullscreen(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 16, nullptr, _t1);
}

// SIGNAL 17
void MainWindow::setMouseCapture(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 17, nullptr, _t1);
}

// SIGNAL 18
void MainWindow::showMessageForNonQtThread(int _t1, const QString & _t2, const QString & _t3, bool _t4, std::atomic_bool * _t5)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 18, nullptr, _t1, _t2, _t3, _t4, _t5);
}

// SIGNAL 19
void MainWindow::getTitleForNonQtThread(wchar_t * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 19, nullptr, _t1);
}

// SIGNAL 20
void MainWindow::vmmRunningStateChanged(VMManagerProtocol::RunningState _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 20, nullptr, _t1);
}

// SIGNAL 21
void MainWindow::vmmConfigurationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void MainWindow::vmmGlobalConfigurationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}
QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'qt_vmmanager_protocol.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qt/qt_vmmanager_protocol.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_vmmanager_protocol.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17VMManagerProtocolE_t {};
} // unnamed namespace

template <> constexpr inline auto VMManagerProtocol::qt_create_metaobjectdata<qt_meta_tag_ZN17VMManagerProtocolE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VMManagerProtocol",
        "Sender",
        "Manager",
        "Client",
        "ManagerMessage",
        "RequestStatus",
        "Pause",
        "CtrlAltDel",
        "ShowSettings",
        "ResetVM",
        "RequestShutdown",
        "ForceShutdown",
        "GlobalConfigurationChanged",
        "UnknownMessage",
        "ClientMessage",
        "Status",
        "WindowBlocked",
        "WindowUnblocked",
        "RunningStateChanged",
        "ConfigurationChanged",
        "WinIdMessage",
        "RunningState",
        "Running",
        "Paused",
        "RunningWaiting",
        "PausedWaiting",
        "Unknown"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Sender'
        QtMocHelpers::EnumData<enum Sender>(1, 1, QMC::EnumIsScoped).add({
            {    2, Sender::Manager },
            {    3, Sender::Client },
        }),
        // enum 'ManagerMessage'
        QtMocHelpers::EnumData<enum ManagerMessage>(4, 4, QMC::EnumIsScoped).add({
            {    5, ManagerMessage::RequestStatus },
            {    6, ManagerMessage::Pause },
            {    7, ManagerMessage::CtrlAltDel },
            {    8, ManagerMessage::ShowSettings },
            {    9, ManagerMessage::ResetVM },
            {   10, ManagerMessage::RequestShutdown },
            {   11, ManagerMessage::ForceShutdown },
            {   12, ManagerMessage::GlobalConfigurationChanged },
            {   13, ManagerMessage::UnknownMessage },
        }),
        // enum 'ClientMessage'
        QtMocHelpers::EnumData<enum ClientMessage>(14, 14, QMC::EnumIsScoped).add({
            {   15, ClientMessage::Status },
            {   16, ClientMessage::WindowBlocked },
            {   17, ClientMessage::WindowUnblocked },
            {   18, ClientMessage::RunningStateChanged },
            {   19, ClientMessage::ConfigurationChanged },
            {   20, ClientMessage::WinIdMessage },
            {   12, ClientMessage::GlobalConfigurationChanged },
            {   13, ClientMessage::UnknownMessage },
        }),
        // enum 'RunningState'
        QtMocHelpers::EnumData<enum RunningState>(21, 21, QMC::EnumIsScoped).add({
            {   22, RunningState::Running },
            {   23, RunningState::Paused },
            {   24, RunningState::RunningWaiting },
            {   25, RunningState::PausedWaiting },
            {   26, RunningState::Unknown },
        }),
    };
    return QtMocHelpers::metaObjectData<VMManagerProtocol, qt_meta_tag_ZN17VMManagerProtocolE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VMManagerProtocol::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17VMManagerProtocolE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17VMManagerProtocolE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17VMManagerProtocolE_t>.metaTypes,
    nullptr
} };

void VMManagerProtocol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VMManagerProtocol *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *VMManagerProtocol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VMManagerProtocol::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17VMManagerProtocolE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VMManagerProtocol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP

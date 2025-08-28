/****************************************************************************
** Meta object code from reading C++ file 'qt_vmmanager_system.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qt/qt_vmmanager_system.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_vmmanager_system.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15VMManagerSystemE_t {};
} // unnamed namespace

template <> constexpr inline auto VMManagerSystem::qt_create_metaobjectdata<qt_meta_tag_ZN15VMManagerSystemE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VMManagerSystem",
        "windowStatusChanged",
        "",
        "itemDataChanged",
        "clientProcessStatusChanged",
        "configurationChanged",
        "uuid",
        "globalConfigurationChanged",
        "launchMainProcess",
        "launchSettings",
        "startButtonPressed",
        "restartButtonPressed",
        "pauseButtonPressed",
        "shutdownRequestButtonPressed",
        "shutdownForceButtonPressed",
        "cadButtonPressed",
        "reloadConfig",
        "sendGlobalConfigurationChanged",
        "ProcessStatus",
        "Stopped",
        "Running",
        "Paused",
        "PausedWaiting",
        "RunningWaiting",
        "Unknown"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'windowStatusChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'itemDataChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'clientProcessStatusChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'configurationChanged'
        QtMocHelpers::SignalData<void(const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Signal 'globalConfigurationChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'launchMainProcess'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'launchSettings'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'startButtonPressed'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'restartButtonPressed'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'pauseButtonPressed'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'shutdownRequestButtonPressed'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'shutdownForceButtonPressed'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'cadButtonPressed'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'reloadConfig'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'sendGlobalConfigurationChanged'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ProcessStatus'
        QtMocHelpers::EnumData<enum ProcessStatus>(18, 18, QMC::EnumIsScoped).add({
            {   19, ProcessStatus::Stopped },
            {   20, ProcessStatus::Running },
            {   21, ProcessStatus::Paused },
            {   22, ProcessStatus::PausedWaiting },
            {   23, ProcessStatus::RunningWaiting },
            {   24, ProcessStatus::Unknown },
        }),
    };
    return QtMocHelpers::metaObjectData<VMManagerSystem, qt_meta_tag_ZN15VMManagerSystemE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VMManagerSystem::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15VMManagerSystemE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15VMManagerSystemE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15VMManagerSystemE_t>.metaTypes,
    nullptr
} };

void VMManagerSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VMManagerSystem *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->windowStatusChanged(); break;
        case 1: _t->itemDataChanged(); break;
        case 2: _t->clientProcessStatusChanged(); break;
        case 3: _t->configurationChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->globalConfigurationChanged(); break;
        case 5: _t->launchMainProcess(); break;
        case 6: _t->launchSettings(); break;
        case 7: _t->startButtonPressed(); break;
        case 8: _t->restartButtonPressed(); break;
        case 9: _t->pauseButtonPressed(); break;
        case 10: _t->shutdownRequestButtonPressed(); break;
        case 11: _t->shutdownForceButtonPressed(); break;
        case 12: _t->cadButtonPressed(); break;
        case 13: _t->reloadConfig(); break;
        case 14: _t->sendGlobalConfigurationChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VMManagerSystem::*)()>(_a, &VMManagerSystem::windowStatusChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerSystem::*)()>(_a, &VMManagerSystem::itemDataChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerSystem::*)()>(_a, &VMManagerSystem::clientProcessStatusChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerSystem::*)(const QString & )>(_a, &VMManagerSystem::configurationChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerSystem::*)()>(_a, &VMManagerSystem::globalConfigurationChanged, 4))
            return;
    }
}

const QMetaObject *VMManagerSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VMManagerSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15VMManagerSystemE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VMManagerSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void VMManagerSystem::windowStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VMManagerSystem::itemDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void VMManagerSystem::clientProcessStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void VMManagerSystem::configurationChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void VMManagerSystem::globalConfigurationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
namespace {
struct qt_meta_tag_ZN9VMManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto VMManager::qt_create_metaobjectdata<qt_meta_tag_ZN9VMManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VMManager"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN9VMManagerE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN9VMManagerE =
    VMManager::qt_create_metaobjectdata<qt_meta_tag_ZN9VMManagerE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN9VMManagerE =
    qt_staticMetaObjectContent_ZN9VMManagerE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN9VMManagerE =
    qt_staticMetaObjectContent_ZN9VMManagerE.relocatingData;

Q_CONSTINIT const QMetaObject VMManager::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN9VMManagerE.stringdata,
    qt_staticMetaObjectStaticContent_ZN9VMManagerE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN9VMManagerE.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN9VMManager7DisplayE_t {};
} // unnamed namespace

template <> constexpr inline auto VMManager::Display::qt_create_metaobjectdata<qt_meta_tag_ZN9VMManager7DisplayE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VMManager::Display",
        "Name",
        "Machine",
        "CPU",
        "Memory",
        "Video",
        "Disks",
        "Floppy",
        "CD",
        "RDisk",
        "MO",
        "SCSIController",
        "StorageController",
        "MidiOut",
        "Joystick",
        "Serial",
        "Parallel",
        "Audio",
        "Voodoo",
        "NIC",
        "Keyboard",
        "Mouse",
        "IsaRtc",
        "IsaMem",
        "IsaRom",
        "Unknown"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Name'
        QtMocHelpers::EnumData<Name>(1, 1, QMC::EnumIsScoped).add({
            {    2, Name::Machine },
            {    3, Name::CPU },
            {    4, Name::Memory },
            {    5, Name::Video },
            {    6, Name::Disks },
            {    7, Name::Floppy },
            {    8, Name::CD },
            {    9, Name::RDisk },
            {   10, Name::MO },
            {   11, Name::SCSIController },
            {   12, Name::StorageController },
            {   13, Name::MidiOut },
            {   14, Name::Joystick },
            {   15, Name::Serial },
            {   16, Name::Parallel },
            {   17, Name::Audio },
            {   18, Name::Voodoo },
            {   19, Name::NIC },
            {   20, Name::Keyboard },
            {   21, Name::Mouse },
            {   22, Name::IsaRtc },
            {   23, Name::IsaMem },
            {   24, Name::IsaRom },
            {   25, Name::Unknown },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN9VMManager7DisplayE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN9VMManager7DisplayE =
    VMManager::Display::qt_create_metaobjectdata<qt_meta_tag_ZN9VMManager7DisplayE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN9VMManager7DisplayE =
    qt_staticMetaObjectContent_ZN9VMManager7DisplayE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN9VMManager7DisplayE =
    qt_staticMetaObjectContent_ZN9VMManager7DisplayE.relocatingData;

Q_CONSTINIT const QMetaObject VMManager::Display::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN9VMManager7DisplayE.stringdata,
    qt_staticMetaObjectStaticContent_ZN9VMManager7DisplayE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN9VMManager7DisplayE.metaTypes,
    nullptr
} };

QT_WARNING_POP

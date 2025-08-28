/****************************************************************************
** Meta object code from reading C++ file 'qt_vmmanager_clientsocket.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qt/qt_vmmanager_clientsocket.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_vmmanager_clientsocket.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN21VMManagerClientSocketE_t {};
} // unnamed namespace

template <> constexpr inline auto VMManagerClientSocket::qt_create_metaobjectdata<qt_meta_tag_ZN21VMManagerClientSocketE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VMManagerClientSocket",
        "pause",
        "",
        "ctrlaltdel",
        "showsettings",
        "resetVM",
        "request_shutdown",
        "force_shutdown",
        "dialogstatus",
        "open",
        "clientRunningStateChanged",
        "VMManagerProtocol::RunningState",
        "state",
        "configurationChanged",
        "globalConfigurationChanged"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'pause'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'ctrlaltdel'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'showsettings'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'resetVM'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'request_shutdown'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'force_shutdown'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'dialogstatus'
        QtMocHelpers::SignalData<void(bool)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'clientRunningStateChanged'
        QtMocHelpers::SlotData<void(VMManagerProtocol::RunningState) const>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Slot 'configurationChanged'
        QtMocHelpers::SlotData<void() const>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'globalConfigurationChanged'
        QtMocHelpers::SlotData<void() const>(14, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VMManagerClientSocket, qt_meta_tag_ZN21VMManagerClientSocketE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VMManagerClientSocket::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21VMManagerClientSocketE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21VMManagerClientSocketE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN21VMManagerClientSocketE_t>.metaTypes,
    nullptr
} };

void VMManagerClientSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VMManagerClientSocket *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->pause(); break;
        case 1: _t->ctrlaltdel(); break;
        case 2: _t->showsettings(); break;
        case 3: _t->resetVM(); break;
        case 4: _t->request_shutdown(); break;
        case 5: _t->force_shutdown(); break;
        case 6: _t->dialogstatus((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->clientRunningStateChanged((*reinterpret_cast< std::add_pointer_t<VMManagerProtocol::RunningState>>(_a[1]))); break;
        case 8: _t->configurationChanged(); break;
        case 9: _t->globalConfigurationChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VMManagerClientSocket::*)()>(_a, &VMManagerClientSocket::pause, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerClientSocket::*)()>(_a, &VMManagerClientSocket::ctrlaltdel, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerClientSocket::*)()>(_a, &VMManagerClientSocket::showsettings, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerClientSocket::*)()>(_a, &VMManagerClientSocket::resetVM, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerClientSocket::*)()>(_a, &VMManagerClientSocket::request_shutdown, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerClientSocket::*)()>(_a, &VMManagerClientSocket::force_shutdown, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerClientSocket::*)(bool )>(_a, &VMManagerClientSocket::dialogstatus, 6))
            return;
    }
}

const QMetaObject *VMManagerClientSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VMManagerClientSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21VMManagerClientSocketE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VMManagerClientSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void VMManagerClientSocket::pause()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VMManagerClientSocket::ctrlaltdel()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void VMManagerClientSocket::showsettings()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void VMManagerClientSocket::resetVM()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void VMManagerClientSocket::request_shutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void VMManagerClientSocket::force_shutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void VMManagerClientSocket::dialogstatus(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}
QT_WARNING_POP

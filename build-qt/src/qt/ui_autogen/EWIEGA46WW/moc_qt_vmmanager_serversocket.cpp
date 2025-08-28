/****************************************************************************
** Meta object code from reading C++ file 'qt_vmmanager_serversocket.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qt/qt_vmmanager_serversocket.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_vmmanager_serversocket.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN21VMManagerServerSocketE_t {};
} // unnamed namespace

template <> constexpr inline auto VMManagerServerSocket::qt_create_metaobjectdata<qt_meta_tag_ZN21VMManagerServerSocketE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VMManagerServerSocket",
        "dataReceived",
        "",
        "windowStatusChanged",
        "status",
        "runningStatusChanged",
        "VMManagerProtocol::RunningState",
        "state",
        "configurationChanged",
        "globalConfigurationChanged",
        "winIdReceived",
        "WId",
        "id",
        "ServerType",
        "Standard",
        "Legacy"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'dataReceived'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'windowStatusChanged'
        QtMocHelpers::SignalData<void(int)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Signal 'runningStatusChanged'
        QtMocHelpers::SignalData<void(VMManagerProtocol::RunningState)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'configurationChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'globalConfigurationChanged'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'winIdReceived'
        QtMocHelpers::SignalData<void(WId)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ServerType'
        QtMocHelpers::EnumData<enum ServerType>(13, 13, QMC::EnumIsScoped).add({
            {   14, ServerType::Standard },
            {   15, ServerType::Legacy },
        }),
    };
    return QtMocHelpers::metaObjectData<VMManagerServerSocket, qt_meta_tag_ZN21VMManagerServerSocketE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VMManagerServerSocket::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21VMManagerServerSocketE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21VMManagerServerSocketE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN21VMManagerServerSocketE_t>.metaTypes,
    nullptr
} };

void VMManagerServerSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VMManagerServerSocket *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dataReceived(); break;
        case 1: _t->windowStatusChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->runningStatusChanged((*reinterpret_cast< std::add_pointer_t<VMManagerProtocol::RunningState>>(_a[1]))); break;
        case 3: _t->configurationChanged(); break;
        case 4: _t->globalConfigurationChanged(); break;
        case 5: _t->winIdReceived((*reinterpret_cast< std::add_pointer_t<WId>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VMManagerServerSocket::*)()>(_a, &VMManagerServerSocket::dataReceived, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerServerSocket::*)(int )>(_a, &VMManagerServerSocket::windowStatusChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerServerSocket::*)(VMManagerProtocol::RunningState )>(_a, &VMManagerServerSocket::runningStatusChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerServerSocket::*)()>(_a, &VMManagerServerSocket::configurationChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerServerSocket::*)()>(_a, &VMManagerServerSocket::globalConfigurationChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerServerSocket::*)(WId )>(_a, &VMManagerServerSocket::winIdReceived, 5))
            return;
    }
}

const QMetaObject *VMManagerServerSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VMManagerServerSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21VMManagerServerSocketE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VMManagerServerSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void VMManagerServerSocket::dataReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VMManagerServerSocket::windowStatusChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void VMManagerServerSocket::runningStatusChanged(VMManagerProtocol::RunningState _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void VMManagerServerSocket::configurationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void VMManagerServerSocket::globalConfigurationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void VMManagerServerSocket::winIdReceived(WId _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP

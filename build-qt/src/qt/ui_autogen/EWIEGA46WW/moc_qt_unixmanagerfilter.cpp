/****************************************************************************
** Meta object code from reading C++ file 'qt_unixmanagerfilter.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qt/qt_unixmanagerfilter.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_unixmanagerfilter.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17UnixManagerSocketE_t {};
} // unnamed namespace

template <> constexpr inline auto UnixManagerSocket::qt_create_metaobjectdata<qt_meta_tag_ZN17UnixManagerSocketE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "UnixManagerSocket",
        "pause",
        "",
        "ctrlaltdel",
        "showsettings",
        "resetVM",
        "request_shutdown",
        "force_shutdown",
        "dialogstatus",
        "open",
        "readyToRead"
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
        // Slot 'readyToRead'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessProtected, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<UnixManagerSocket, qt_meta_tag_ZN17UnixManagerSocketE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject UnixManagerSocket::staticMetaObject = { {
    QMetaObject::SuperData::link<QLocalSocket::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17UnixManagerSocketE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17UnixManagerSocketE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17UnixManagerSocketE_t>.metaTypes,
    nullptr
} };

void UnixManagerSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<UnixManagerSocket *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->pause(); break;
        case 1: _t->ctrlaltdel(); break;
        case 2: _t->showsettings(); break;
        case 3: _t->resetVM(); break;
        case 4: _t->request_shutdown(); break;
        case 5: _t->force_shutdown(); break;
        case 6: _t->dialogstatus((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->readyToRead(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (UnixManagerSocket::*)()>(_a, &UnixManagerSocket::pause, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (UnixManagerSocket::*)()>(_a, &UnixManagerSocket::ctrlaltdel, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (UnixManagerSocket::*)()>(_a, &UnixManagerSocket::showsettings, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (UnixManagerSocket::*)()>(_a, &UnixManagerSocket::resetVM, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (UnixManagerSocket::*)()>(_a, &UnixManagerSocket::request_shutdown, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (UnixManagerSocket::*)()>(_a, &UnixManagerSocket::force_shutdown, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (UnixManagerSocket::*)(bool )>(_a, &UnixManagerSocket::dialogstatus, 6))
            return;
    }
}

const QMetaObject *UnixManagerSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UnixManagerSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17UnixManagerSocketE_t>.strings))
        return static_cast<void*>(this);
    return QLocalSocket::qt_metacast(_clname);
}

int UnixManagerSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLocalSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void UnixManagerSocket::pause()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void UnixManagerSocket::ctrlaltdel()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UnixManagerSocket::showsettings()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void UnixManagerSocket::resetVM()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void UnixManagerSocket::request_shutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void UnixManagerSocket::force_shutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void UnixManagerSocket::dialogstatus(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}
QT_WARNING_POP

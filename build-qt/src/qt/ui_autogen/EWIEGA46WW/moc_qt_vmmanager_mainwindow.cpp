/****************************************************************************
** Meta object code from reading C++ file 'qt_vmmanager_mainwindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qt/qt_vmmanager_mainwindow.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_vmmanager_mainwindow.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19VMManagerMainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto VMManagerMainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN19VMManagerMainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VMManagerMainWindow",
        "preferencesUpdated",
        "",
        "languageUpdated",
        "setStatusLeft",
        "text",
        "setStatusRight",
        "updateLanguage",
        "vmmSelectionChanged",
        "QModelIndex",
        "currentSelection",
        "QProcess::ProcessState",
        "processState",
        "preferencesTriggered",
        "on_actionExit_triggered",
        "on_actionDocumentation_triggered",
        "on_actionAbout_86Box_triggered",
        "on_actionAbout_Qt_triggered"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'preferencesUpdated'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'languageUpdated'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setStatusLeft'
        QtMocHelpers::SlotData<void(const QString &) const>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Slot 'setStatusRight'
        QtMocHelpers::SlotData<void(const QString &) const>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Slot 'updateLanguage'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'vmmSelectionChanged'
        QtMocHelpers::SlotData<void(const QModelIndex &, QProcess::ProcessState) const>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'preferencesTriggered'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionExit_triggered'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionDocumentation_triggered'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionAbout_86Box_triggered'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionAbout_Qt_triggered'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VMManagerMainWindow, qt_meta_tag_ZN19VMManagerMainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VMManagerMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19VMManagerMainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19VMManagerMainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19VMManagerMainWindowE_t>.metaTypes,
    nullptr
} };

void VMManagerMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VMManagerMainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->preferencesUpdated(); break;
        case 1: _t->languageUpdated(); break;
        case 2: _t->setStatusLeft((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->setStatusRight((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->updateLanguage(); break;
        case 5: _t->vmmSelectionChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QProcess::ProcessState>>(_a[2]))); break;
        case 6: _t->preferencesTriggered(); break;
        case 7: _t->on_actionExit_triggered(); break;
        case 8: _t->on_actionDocumentation_triggered(); break;
        case 9: _t->on_actionAbout_86Box_triggered(); break;
        case 10: _t->on_actionAbout_Qt_triggered(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VMManagerMainWindow::*)()>(_a, &VMManagerMainWindow::preferencesUpdated, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerMainWindow::*)()>(_a, &VMManagerMainWindow::languageUpdated, 1))
            return;
    }
}

const QMetaObject *VMManagerMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VMManagerMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19VMManagerMainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int VMManagerMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void VMManagerMainWindow::preferencesUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VMManagerMainWindow::languageUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP

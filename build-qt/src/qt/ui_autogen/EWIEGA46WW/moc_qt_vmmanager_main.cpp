/****************************************************************************
** Meta object code from reading C++ file 'qt_vmmanager_main.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qt/qt_vmmanager_main.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_vmmanager_main.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13VMManagerMainE_t {};
} // unnamed namespace

template <> constexpr inline auto VMManagerMain::qt_create_metaobjectdata<qt_meta_tag_ZN13VMManagerMainE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VMManagerMain",
        "selectionChanged",
        "",
        "QModelIndex",
        "currentSelection",
        "QProcess::ProcessState",
        "processState",
        "updateStatusLeft",
        "text",
        "updateStatusRight",
        "startButtonPressed",
        "settingsButtonPressed",
        "restartButtonPressed",
        "pauseButtonPressed",
        "shutdownRequestButtonPressed",
        "shutdownForceButtonPressed",
        "searchSystems",
        "newMachineWizard",
        "updateGlobalSettings",
        "deleteSystem",
        "VMManagerSystem*",
        "sysconfig",
        "addNewSystem",
        "name",
        "dir",
        "displayName",
        "configFile",
        "getSearchCompletionList",
        "modelDataChange",
        "onPreferencesUpdated",
        "onLanguageUpdated",
        "onConfigUpdated",
        "uuid",
        "getActiveMachineCount"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'selectionChanged'
        QtMocHelpers::SignalData<void(const QModelIndex &, QProcess::ProcessState)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 5, 6 },
        }}),
        // Signal 'updateStatusLeft'
        QtMocHelpers::SignalData<void(const QString &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 },
        }}),
        // Signal 'updateStatusRight'
        QtMocHelpers::SignalData<void(const QString &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 },
        }}),
        // Slot 'startButtonPressed'
        QtMocHelpers::SlotData<void() const>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'settingsButtonPressed'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'restartButtonPressed'
        QtMocHelpers::SlotData<void() const>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'pauseButtonPressed'
        QtMocHelpers::SlotData<void() const>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'shutdownRequestButtonPressed'
        QtMocHelpers::SlotData<void() const>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'shutdownForceButtonPressed'
        QtMocHelpers::SlotData<void() const>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'searchSystems'
        QtMocHelpers::SlotData<void(const QString &) const>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 },
        }}),
        // Slot 'newMachineWizard'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updateGlobalSettings'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'deleteSystem'
        QtMocHelpers::SlotData<void(VMManagerSystem *)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 20, 21 },
        }}),
        // Slot 'addNewSystem'
        QtMocHelpers::SlotData<void(const QString &, const QString &, const QString &, const QString &)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 23 }, { QMetaType::QString, 24 }, { QMetaType::QString, 25 }, { QMetaType::QString, 26 },
        }}),
        // Slot 'addNewSystem'
        QtMocHelpers::SlotData<void(const QString &, const QString &, const QString &)>(22, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 23 }, { QMetaType::QString, 24 }, { QMetaType::QString, 25 },
        }}),
        // Slot 'addNewSystem'
        QtMocHelpers::SlotData<void(const QString &, const QString &)>(22, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 23 }, { QMetaType::QString, 24 },
        }}),
        // Slot 'getSearchCompletionList'
        QtMocHelpers::SlotData<QStringList() const>(27, 2, QMC::AccessPublic, QMetaType::QStringList),
        // Slot 'modelDataChange'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onPreferencesUpdated'
        QtMocHelpers::SlotData<void()>(29, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onLanguageUpdated'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onConfigUpdated'
        QtMocHelpers::SlotData<void(const QString &)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 32 },
        }}),
        // Slot 'getActiveMachineCount'
        QtMocHelpers::SlotData<int()>(33, 2, QMC::AccessPublic, QMetaType::Int),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VMManagerMain, qt_meta_tag_ZN13VMManagerMainE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VMManagerMain::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13VMManagerMainE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13VMManagerMainE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13VMManagerMainE_t>.metaTypes,
    nullptr
} };

void VMManagerMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VMManagerMain *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->selectionChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QProcess::ProcessState>>(_a[2]))); break;
        case 1: _t->updateStatusLeft((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->updateStatusRight((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->startButtonPressed(); break;
        case 4: _t->settingsButtonPressed(); break;
        case 5: _t->restartButtonPressed(); break;
        case 6: _t->pauseButtonPressed(); break;
        case 7: _t->shutdownRequestButtonPressed(); break;
        case 8: _t->shutdownForceButtonPressed(); break;
        case 9: _t->searchSystems((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->newMachineWizard(); break;
        case 11: _t->updateGlobalSettings(); break;
        case 12: _t->deleteSystem((*reinterpret_cast< std::add_pointer_t<VMManagerSystem*>>(_a[1]))); break;
        case 13: _t->addNewSystem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 14: _t->addNewSystem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 15: _t->addNewSystem((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 16: { QStringList _r = _t->getSearchCompletionList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->modelDataChange(); break;
        case 18: _t->onPreferencesUpdated(); break;
        case 19: _t->onLanguageUpdated(); break;
        case 20: _t->onConfigUpdated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: { int _r = _t->getActiveMachineCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< VMManagerSystem* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VMManagerMain::*)(const QModelIndex & , QProcess::ProcessState )>(_a, &VMManagerMain::selectionChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerMain::*)(const QString & )>(_a, &VMManagerMain::updateStatusLeft, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (VMManagerMain::*)(const QString & )>(_a, &VMManagerMain::updateStatusRight, 2))
            return;
    }
}

const QMetaObject *VMManagerMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VMManagerMain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13VMManagerMainE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int VMManagerMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void VMManagerMain::selectionChanged(const QModelIndex & _t1, QProcess::ProcessState _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void VMManagerMain::updateStatusLeft(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void VMManagerMain::updateStatusRight(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN19IconSelectionDialogE_t {};
} // unnamed namespace

template <> constexpr inline auto IconSelectionDialog::qt_create_metaobjectdata<qt_meta_tag_ZN19IconSelectionDialogE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "IconSelectionDialog",
        "getSelectedIconName",
        ""
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'getSelectedIconName'
        QtMocHelpers::SlotData<QString() const>(1, 2, QMC::AccessPublic, QMetaType::QString),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<IconSelectionDialog, qt_meta_tag_ZN19IconSelectionDialogE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject IconSelectionDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19IconSelectionDialogE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19IconSelectionDialogE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19IconSelectionDialogE_t>.metaTypes,
    nullptr
} };

void IconSelectionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IconSelectionDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->getSelectedIconName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *IconSelectionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IconSelectionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19IconSelectionDialogE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int IconSelectionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP

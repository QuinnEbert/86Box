/****************************************************************************
** Meta object code from reading C++ file 'qt_settingsinput.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qt/qt_settingsinput.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_settingsinput.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13SettingsInputE_t {};
} // unnamed namespace

template <> constexpr inline auto SettingsInput::qt_create_metaobjectdata<qt_meta_tag_ZN13SettingsInputE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SettingsInput",
        "onCurrentMachineChanged",
        "",
        "machineId",
        "on_comboBoxKeyboard_currentIndexChanged",
        "index",
        "on_pushButtonConfigureKeyboard_clicked",
        "on_comboBoxMouse_currentIndexChanged",
        "on_pushButtonConfigureMouse_clicked",
        "on_comboBoxJoystick0_currentIndexChanged",
        "on_pushButtonJoystick01_clicked",
        "on_pushButtonJoystick02_clicked",
        "on_pushButtonJoystick03_clicked",
        "on_pushButtonJoystick04_clicked",
        "on_tableKeys_cellDoubleClicked",
        "row",
        "col",
        "on_tableKeys_currentCellChanged",
        "currentRow",
        "currentColumn",
        "previousRow",
        "previousColumn",
        "on_pushButtonClearBind_clicked",
        "on_pushButtonBind_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'onCurrentMachineChanged'
        QtMocHelpers::SlotData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'on_comboBoxKeyboard_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(4, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Slot 'on_pushButtonConfigureKeyboard_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_comboBoxMouse_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Slot 'on_pushButtonConfigureMouse_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_comboBoxJoystick0_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Slot 'on_pushButtonJoystick01_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonJoystick02_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonJoystick03_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonJoystick04_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_tableKeys_cellDoubleClicked'
        QtMocHelpers::SlotData<void(int, int)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 15 }, { QMetaType::Int, 16 },
        }}),
        // Slot 'on_tableKeys_currentCellChanged'
        QtMocHelpers::SlotData<void(int, int, int, int)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 18 }, { QMetaType::Int, 19 }, { QMetaType::Int, 20 }, { QMetaType::Int, 21 },
        }}),
        // Slot 'on_pushButtonClearBind_clicked'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonBind_clicked'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SettingsInput, qt_meta_tag_ZN13SettingsInputE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SettingsInput::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13SettingsInputE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13SettingsInputE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13SettingsInputE_t>.metaTypes,
    nullptr
} };

void SettingsInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SettingsInput *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onCurrentMachineChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_comboBoxKeyboard_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_pushButtonConfigureKeyboard_clicked(); break;
        case 3: _t->on_comboBoxMouse_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_pushButtonConfigureMouse_clicked(); break;
        case 5: _t->on_comboBoxJoystick0_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_pushButtonJoystick01_clicked(); break;
        case 7: _t->on_pushButtonJoystick02_clicked(); break;
        case 8: _t->on_pushButtonJoystick03_clicked(); break;
        case 9: _t->on_pushButtonJoystick04_clicked(); break;
        case 10: _t->on_tableKeys_cellDoubleClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 11: _t->on_tableKeys_currentCellChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 12: _t->on_pushButtonClearBind_clicked(); break;
        case 13: _t->on_pushButtonBind_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *SettingsInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsInput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13SettingsInputE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SettingsInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP

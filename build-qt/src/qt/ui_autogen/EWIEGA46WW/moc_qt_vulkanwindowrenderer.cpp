/****************************************************************************
** Meta object code from reading C++ file 'qt_vulkanwindowrenderer.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qt/qt_vulkanwindowrenderer.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_vulkanwindowrenderer.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN20VulkanWindowRendererE_t {};
} // unnamed namespace

template <> constexpr inline auto VulkanWindowRenderer::qt_create_metaobjectdata<qt_meta_tag_ZN20VulkanWindowRendererE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "VulkanWindowRenderer",
        "rendererInitialized",
        "",
        "errorInitializing",
        "onBlit",
        "buf_idx",
        "x",
        "y",
        "w",
        "h"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'rendererInitialized'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'errorInitializing'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onBlit'
        QtMocHelpers::SlotData<void(int, int, int, int, int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 }, { QMetaType::Int, 6 }, { QMetaType::Int, 7 }, { QMetaType::Int, 8 },
            { QMetaType::Int, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VulkanWindowRenderer, qt_meta_tag_ZN20VulkanWindowRendererE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject VulkanWindowRenderer::staticMetaObject = { {
    QMetaObject::SuperData::link<QVulkanWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20VulkanWindowRendererE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20VulkanWindowRendererE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20VulkanWindowRendererE_t>.metaTypes,
    nullptr
} };

void VulkanWindowRenderer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VulkanWindowRenderer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->rendererInitialized(); break;
        case 1: _t->errorInitializing(); break;
        case 2: _t->onBlit((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VulkanWindowRenderer::*)()>(_a, &VulkanWindowRenderer::rendererInitialized, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VulkanWindowRenderer::*)()>(_a, &VulkanWindowRenderer::errorInitializing, 1))
            return;
    }
}

const QMetaObject *VulkanWindowRenderer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VulkanWindowRenderer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20VulkanWindowRendererE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "RendererCommon"))
        return static_cast< RendererCommon*>(this);
    return QVulkanWindow::qt_metacast(_clname);
}

int VulkanWindowRenderer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVulkanWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void VulkanWindowRenderer::rendererInitialized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VulkanWindowRenderer::errorInitializing()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP

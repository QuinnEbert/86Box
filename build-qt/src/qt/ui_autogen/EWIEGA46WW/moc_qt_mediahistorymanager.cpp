/****************************************************************************
** Meta object code from reading C++ file 'qt_mediahistorymanager.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qt/qt_mediahistorymanager.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt_mediahistorymanager.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2uiE_t {};
} // unnamed namespace

template <> constexpr inline auto ui::qt_create_metaobjectdata<qt_meta_tag_ZN2uiE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ui",
        "MediaType",
        "Floppy",
        "Optical",
        "RDisk",
        "Mo",
        "Cassette",
        "Cartridge"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'MediaType'
        QtMocHelpers::EnumData<MediaType>(1, 1, QMC::EnumIsScoped).add({
            {    2, MediaType::Floppy },
            {    3, MediaType::Optical },
            {    4, MediaType::RDisk },
            {    5, MediaType::Mo },
            {    6, MediaType::Cassette },
            {    7, MediaType::Cartridge },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN2uiE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN2uiE =
    ui::qt_create_metaobjectdata<qt_meta_tag_ZN2uiE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN2uiE =
    qt_staticMetaObjectContent_ZN2uiE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN2uiE =
    qt_staticMetaObjectContent_ZN2uiE.relocatingData;

Q_CONSTINIT const QMetaObject ui::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN2uiE.stringdata,
    qt_staticMetaObjectStaticContent_ZN2uiE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN2uiE.metaTypes,
    nullptr
} };

QT_WARNING_POP

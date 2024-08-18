/****************************************************************************
** Meta object code from reading C++ file 'basicwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../basicwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basicwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSBasicWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSBasicWindowENDCLASS = QtMocHelpers::stringData(
    "BasicWindow",
    "onShowClose",
    "",
    "onShowMin",
    "onShowHide",
    "onShowNormal",
    "onShowQuit",
    "onSignalSkinChanged",
    "color",
    "onButtonMinClicked",
    "onButtonRestoreClicked",
    "onButtonMaxClicked",
    "onButtonCloseClicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSBasicWindowENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[12];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[11];
    char stringdata5[13];
    char stringdata6[11];
    char stringdata7[20];
    char stringdata8[6];
    char stringdata9[19];
    char stringdata10[23];
    char stringdata11[19];
    char stringdata12[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSBasicWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSBasicWindowENDCLASS_t qt_meta_stringdata_CLASSBasicWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "BasicWindow"
        QT_MOC_LITERAL(12, 11),  // "onShowClose"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 9),  // "onShowMin"
        QT_MOC_LITERAL(35, 10),  // "onShowHide"
        QT_MOC_LITERAL(46, 12),  // "onShowNormal"
        QT_MOC_LITERAL(59, 10),  // "onShowQuit"
        QT_MOC_LITERAL(70, 19),  // "onSignalSkinChanged"
        QT_MOC_LITERAL(90, 5),  // "color"
        QT_MOC_LITERAL(96, 18),  // "onButtonMinClicked"
        QT_MOC_LITERAL(115, 22),  // "onButtonRestoreClicked"
        QT_MOC_LITERAL(138, 18),  // "onButtonMaxClicked"
        QT_MOC_LITERAL(157, 20)   // "onButtonCloseClicked"
    },
    "BasicWindow",
    "onShowClose",
    "",
    "onShowMin",
    "onShowHide",
    "onShowNormal",
    "onShowQuit",
    "onSignalSkinChanged",
    "color",
    "onButtonMinClicked",
    "onButtonRestoreClicked",
    "onButtonMaxClicked",
    "onButtonCloseClicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBasicWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x0a,    1 /* Public */,
       3,    1,   77,    2, 0x0a,    3 /* Public */,
       4,    1,   80,    2, 0x0a,    5 /* Public */,
       5,    1,   83,    2, 0x0a,    7 /* Public */,
       6,    1,   86,    2, 0x0a,    9 /* Public */,
       7,    1,   89,    2, 0x0a,   11 /* Public */,
       9,    0,   92,    2, 0x0a,   13 /* Public */,
      10,    0,   93,    2, 0x0a,   14 /* Public */,
      11,    0,   94,    2, 0x0a,   15 /* Public */,
      12,    0,   95,    2, 0x0a,   16 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QColor,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject BasicWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSBasicWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBasicWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBasicWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BasicWindow, std::true_type>,
        // method 'onShowClose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'onShowMin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'onShowHide'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'onShowNormal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'onShowQuit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'onSignalSkinChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'onButtonMinClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonRestoreClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonMaxClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonCloseClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void BasicWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BasicWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onShowClose((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->onShowMin((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->onShowHide((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->onShowNormal((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->onShowQuit((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->onSignalSkinChanged((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 6: _t->onButtonMinClicked(); break;
        case 7: _t->onButtonRestoreClicked(); break;
        case 8: _t->onButtonMaxClicked(); break;
        case 9: _t->onButtonCloseClicked(); break;
        default: ;
        }
    }
}

const QMetaObject *BasicWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BasicWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBasicWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int BasicWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP

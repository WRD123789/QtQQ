/****************************************************************************
** Meta object code from reading C++ file 'talkwindowshell.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../talkwindowshell.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'talkwindowshell.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTalkWindowShellENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSTalkWindowShellENDCLASS = QtMocHelpers::stringData(
    "TalkWindowShell",
    "onEmotionBtnClicked",
    "",
    "updateSendMsg",
    "QString&",
    "msg",
    "int&",
    "msgType",
    "fileName",
    "onTalkWindowItemClicked",
    "QListWidgetItem*",
    "item",
    "onEmotionItemClicked",
    "emotionNum",
    "processPendingData"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTalkWindowShellENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[16];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[5];
    char stringdata7[8];
    char stringdata8[9];
    char stringdata9[24];
    char stringdata10[17];
    char stringdata11[5];
    char stringdata12[21];
    char stringdata13[11];
    char stringdata14[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTalkWindowShellENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTalkWindowShellENDCLASS_t qt_meta_stringdata_CLASSTalkWindowShellENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "TalkWindowShell"
        QT_MOC_LITERAL(16, 19),  // "onEmotionBtnClicked"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 13),  // "updateSendMsg"
        QT_MOC_LITERAL(51, 8),  // "QString&"
        QT_MOC_LITERAL(60, 3),  // "msg"
        QT_MOC_LITERAL(64, 4),  // "int&"
        QT_MOC_LITERAL(69, 7),  // "msgType"
        QT_MOC_LITERAL(77, 8),  // "fileName"
        QT_MOC_LITERAL(86, 23),  // "onTalkWindowItemClicked"
        QT_MOC_LITERAL(110, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(127, 4),  // "item"
        QT_MOC_LITERAL(132, 20),  // "onEmotionItemClicked"
        QT_MOC_LITERAL(153, 10),  // "emotionNum"
        QT_MOC_LITERAL(164, 18)   // "processPendingData"
    },
    "TalkWindowShell",
    "onEmotionBtnClicked",
    "",
    "updateSendMsg",
    "QString&",
    "msg",
    "int&",
    "msgType",
    "fileName",
    "onTalkWindowItemClicked",
    "QListWidgetItem*",
    "item",
    "onEmotionItemClicked",
    "emotionNum",
    "processPendingData"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTalkWindowShellENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x0a,    1 /* Public */,
       3,    3,   53,    2, 0x0a,    3 /* Public */,
       3,    2,   60,    2, 0x2a,    7 /* Public | MethodCloned */,
       9,    1,   65,    2, 0x08,   10 /* Private */,
      12,    1,   68,    2, 0x08,   12 /* Private */,
      14,    0,   71,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6, QMetaType::QString,    5,    7,    8,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TalkWindowShell::staticMetaObject = { {
    QMetaObject::SuperData::link<BasicWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSTalkWindowShellENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTalkWindowShellENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTalkWindowShellENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TalkWindowShell, std::true_type>,
        // method 'onEmotionBtnClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'updateSendMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'updateSendMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int &, std::false_type>,
        // method 'onTalkWindowItemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'onEmotionItemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'processPendingData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TalkWindowShell::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TalkWindowShell *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onEmotionBtnClicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->updateSendMsg((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 2: _t->updateSendMsg((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int&>>(_a[2]))); break;
        case 3: _t->onTalkWindowItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 4: _t->onEmotionItemClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->processPendingData(); break;
        default: ;
        }
    }
}

const QMetaObject *TalkWindowShell::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TalkWindowShell::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTalkWindowShellENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return BasicWindow::qt_metacast(_clname);
}

int TalkWindowShell::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BasicWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP

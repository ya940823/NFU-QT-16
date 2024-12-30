/****************************************************************************
** Meta object code from reading C++ file 'P7S6.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../P7S6.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'P7S6.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
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
struct qt_meta_stringdata_CLASSP7S6ENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSP7S6ENDCLASS = QtMocHelpers::stringData(
    "P7S6",
    "handlePB1Pressed",
    "",
    "handlePB2Pressed",
    "handleolPressed",
    "toggleFR",
    "handlePB3Pressed",
    "handlePB4Pressed",
    "handlePB4Released",
    "handlels1Pressed",
    "handlels1Released",
    "handlels2Pressed",
    "handlels2Released"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSP7S6ENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    0,   87,    2, 0x08,    8 /* Private */,
      10,    0,   88,    2, 0x08,    9 /* Private */,
      11,    0,   89,    2, 0x08,   10 /* Private */,
      12,    0,   90,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject P7S6::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSP7S6ENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSP7S6ENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSP7S6ENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<P7S6, std::true_type>,
        // method 'handlePB1Pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlePB2Pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleolPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleFR'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlePB3Pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlePB4Pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlePB4Released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlels1Pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlels1Released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlels2Pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handlels2Released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void P7S6::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<P7S6 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handlePB1Pressed(); break;
        case 1: _t->handlePB2Pressed(); break;
        case 2: _t->handleolPressed(); break;
        case 3: _t->toggleFR(); break;
        case 4: _t->handlePB3Pressed(); break;
        case 5: _t->handlePB4Pressed(); break;
        case 6: _t->handlePB4Released(); break;
        case 7: _t->handlels1Pressed(); break;
        case 8: _t->handlels1Released(); break;
        case 9: _t->handlels2Pressed(); break;
        case 10: _t->handlels2Released(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *P7S6::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *P7S6::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSP7S6ENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int P7S6::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP

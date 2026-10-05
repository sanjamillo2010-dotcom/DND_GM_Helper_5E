/****************************************************************************
** Meta object code from reading C++ file 'dashbord.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../include/dashbord.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dashbord.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Dashbord_t {
    uint offsetsAndSizes[16];
    char stringdata0[9];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[15];
    char stringdata5[17];
    char stringdata6[4];
    char stringdata7[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Dashbord_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Dashbord_t qt_meta_stringdata_Dashbord = {
    {
        QT_MOC_LITERAL(0, 8),  // "Dashbord"
        QT_MOC_LITERAL(9, 11),  // "Add_Mission"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 14),  // "Remove_Mission"
        QT_MOC_LITERAL(37, 14),  // "Update_Mission"
        QT_MOC_LITERAL(52, 16),  // "Mission_Selected"
        QT_MOC_LITERAL(69, 3),  // "row"
        QT_MOC_LITERAL(73, 12)   // "Open_Mission"
    },
    "Dashbord",
    "Add_Mission",
    "",
    "Remove_Mission",
    "Update_Mission",
    "Mission_Selected",
    "row",
    "Open_Mission"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Dashbord[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    1,   47,    2, 0x08,    4 /* Private */,
       7,    0,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Dashbord::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Dashbord.offsetsAndSizes,
    qt_meta_data_Dashbord,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Dashbord_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Dashbord, std::true_type>,
        // method 'Add_Mission'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Remove_Mission'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Update_Mission'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Mission_Selected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'Open_Mission'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Dashbord::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dashbord *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Add_Mission(); break;
        case 1: _t->Remove_Mission(); break;
        case 2: _t->Update_Mission(); break;
        case 3: _t->Mission_Selected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->Open_Mission(); break;
        default: ;
        }
    }
}

const QMetaObject *Dashbord::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dashbord::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dashbord.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Dashbord::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'npccreatordialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../include/npccreatordialog.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'npccreatordialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_NPCCreatorDialog_t {
    uint offsetsAndSizes[20];
    char stringdata0[17];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[14];
    char stringdata5[11];
    char stringdata6[17];
    char stringdata7[20];
    char stringdata8[18];
    char stringdata9[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_NPCCreatorDialog_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_NPCCreatorDialog_t qt_meta_stringdata_NPCCreatorDialog = {
    {
        QT_MOC_LITERAL(0, 16),  // "NPCCreatorDialog"
        QT_MOC_LITERAL(17, 10),  // "Reroll_All"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 11),  // "Reroll_Race"
        QT_MOC_LITERAL(41, 13),  // "Reroll_Prenom"
        QT_MOC_LITERAL(55, 10),  // "Reroll_Nom"
        QT_MOC_LITERAL(66, 16),  // "Reroll_Apparence"
        QT_MOC_LITERAL(83, 19),  // "Reroll_Personnalite"
        QT_MOC_LITERAL(103, 17),  // "Reroll_Motivation"
        QT_MOC_LITERAL(121, 15)   // "Reroll_Accroche"
    },
    "NPCCreatorDialog",
    "Reroll_All",
    "",
    "Reroll_Race",
    "Reroll_Prenom",
    "Reroll_Nom",
    "Reroll_Apparence",
    "Reroll_Personnalite",
    "Reroll_Motivation",
    "Reroll_Accroche"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_NPCCreatorDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // slots: parameters
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

Q_CONSTINIT const QMetaObject NPCCreatorDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_NPCCreatorDialog.offsetsAndSizes,
    qt_meta_data_NPCCreatorDialog,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_NPCCreatorDialog_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<NPCCreatorDialog, std::true_type>,
        // method 'Reroll_All'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Reroll_Race'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Reroll_Prenom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Reroll_Nom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Reroll_Apparence'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Reroll_Personnalite'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Reroll_Motivation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Reroll_Accroche'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void NPCCreatorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NPCCreatorDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Reroll_All(); break;
        case 1: _t->Reroll_Race(); break;
        case 2: _t->Reroll_Prenom(); break;
        case 3: _t->Reroll_Nom(); break;
        case 4: _t->Reroll_Apparence(); break;
        case 5: _t->Reroll_Personnalite(); break;
        case 6: _t->Reroll_Motivation(); break;
        case 7: _t->Reroll_Accroche(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *NPCCreatorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NPCCreatorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NPCCreatorDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int NPCCreatorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'npccreatordialog.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/npccreatordialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'npccreatordialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.3. It"
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
struct qt_meta_tag_ZN16NPCCreatorDialogE_t {};
} // unnamed namespace

template <> constexpr inline auto NPCCreatorDialog::qt_create_metaobjectdata<qt_meta_tag_ZN16NPCCreatorDialogE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
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

    QtMocHelpers::UintData qt_methods {
        // Slot 'Reroll_All'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'Reroll_Race'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'Reroll_Prenom'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'Reroll_Nom'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'Reroll_Apparence'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'Reroll_Personnalite'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'Reroll_Motivation'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'Reroll_Accroche'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<NPCCreatorDialog, qt_meta_tag_ZN16NPCCreatorDialogE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject NPCCreatorDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16NPCCreatorDialogE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16NPCCreatorDialogE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16NPCCreatorDialogE_t>.metaTypes,
    nullptr
} };

void NPCCreatorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NPCCreatorDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
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
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16NPCCreatorDialogE_t>.strings))
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
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP

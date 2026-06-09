/****************************************************************************
** Meta object code from reading C++ file 'CrudController.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/controllers/CrudController.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CrudController.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
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
struct qt_meta_tag_ZN11Controllers14CrudControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto Controllers::CrudController::qt_create_metaobjectdata<qt_meta_tag_ZN11Controllers14CrudControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Controllers::CrudController",
        "listeAvionsChangee",
        "",
        "listePistesChangee",
        "chargerDonnees",
        "creerAvion",
        "id",
        "x",
        "y",
        "ax",
        "ay",
        "vx",
        "vy",
        "vd",
        "fmax_x",
        "fmax_y",
        "pasfx",
        "pasfy",
        "dPiste",
        "supprimerAvion",
        "creerPiste",
        "longueur",
        "debutX",
        "finX",
        "supprimerPiste",
        "listeAvions",
        "listePistes"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'listeAvionsChangee'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'listePistesChangee'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'chargerDonnees'
        QtMocHelpers::MethodData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'creerAvion'
        QtMocHelpers::MethodData<bool(int, double, double, double, double, double, double, double, double, double, double, double, double)>(5, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 6 }, { QMetaType::Double, 7 }, { QMetaType::Double, 8 }, { QMetaType::Double, 9 },
            { QMetaType::Double, 10 }, { QMetaType::Double, 11 }, { QMetaType::Double, 12 }, { QMetaType::Double, 13 },
            { QMetaType::Double, 14 }, { QMetaType::Double, 15 }, { QMetaType::Double, 16 }, { QMetaType::Double, 17 },
            { QMetaType::Double, 18 },
        }}),
        // Method 'supprimerAvion'
        QtMocHelpers::MethodData<bool(int)>(19, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 6 },
        }}),
        // Method 'creerPiste'
        QtMocHelpers::MethodData<bool(int, double, double, double)>(20, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 6 }, { QMetaType::Double, 21 }, { QMetaType::Double, 22 }, { QMetaType::Double, 23 },
        }}),
        // Method 'supprimerPiste'
        QtMocHelpers::MethodData<bool(int)>(24, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'listeAvions'
        QtMocHelpers::PropertyData<QStringList>(25, QMetaType::QStringList, QMC::DefaultPropertyFlags, 0),
        // property 'listePistes'
        QtMocHelpers::PropertyData<QStringList>(26, QMetaType::QStringList, QMC::DefaultPropertyFlags, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<CrudController, qt_meta_tag_ZN11Controllers14CrudControllerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Controllers::CrudController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11Controllers14CrudControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11Controllers14CrudControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11Controllers14CrudControllerE_t>.metaTypes,
    nullptr
} };

void Controllers::CrudController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<CrudController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->listeAvionsChangee(); break;
        case 1: _t->listePistesChangee(); break;
        case 2: _t->chargerDonnees(); break;
        case 3: { bool _r = _t->creerAvion((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[9])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[10])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[11])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[12])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[13])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->supprimerAvion((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->creerPiste((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->supprimerPiste((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (CrudController::*)()>(_a, &CrudController::listeAvionsChangee, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (CrudController::*)()>(_a, &CrudController::listePistesChangee, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QStringList*>(_v) = _t->getListeAvions(); break;
        case 1: *reinterpret_cast<QStringList*>(_v) = _t->getListePistes(); break;
        default: break;
        }
    }
}

const QMetaObject *Controllers::CrudController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controllers::CrudController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11Controllers14CrudControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controllers::CrudController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Controllers::CrudController::listeAvionsChangee()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Controllers::CrudController::listePistesChangee()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP

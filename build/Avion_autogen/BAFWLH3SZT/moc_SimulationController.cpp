/****************************************************************************
** Meta object code from reading C++ file 'SimulationController.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/controllers/SimulationController.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SimulationController.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11Controllers20SimulationControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto Controllers::SimulationController::qt_create_metaobjectdata<qt_meta_tag_ZN11Controllers20SimulationControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Controllers::SimulationController",
        "positionChangee",
        "",
        "listesSelectionChangees",
        "simulationPrete",
        "mettreAJourPhysique",
        "chargerOptions",
        "selectionnerConfiguration",
        "indexAvion",
        "indexPiste",
        "accelererX",
        "freinerX",
        "accelererY",
        "freinerY",
        "avionX",
        "avionY",
        "vitesseX",
        "vitesseY",
        "accelerationX",
        "accelerationY",
        "distancePiste",
        "vitesseDecrochage",
        "modelesAvions",
        "modelesPistes"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'positionChangee'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'listesSelectionChangees'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'simulationPrete'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'mettreAJourPhysique'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Method 'chargerOptions'
        QtMocHelpers::MethodData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'selectionnerConfiguration'
        QtMocHelpers::MethodData<bool(int, int)>(7, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 8 }, { QMetaType::Int, 9 },
        }}),
        // Method 'accelererX'
        QtMocHelpers::MethodData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'freinerX'
        QtMocHelpers::MethodData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'accelererY'
        QtMocHelpers::MethodData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'freinerY'
        QtMocHelpers::MethodData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'avionX'
        QtMocHelpers::PropertyData<double>(14, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'avionY'
        QtMocHelpers::PropertyData<double>(15, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'vitesseX'
        QtMocHelpers::PropertyData<double>(16, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'vitesseY'
        QtMocHelpers::PropertyData<double>(17, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'accelerationX'
        QtMocHelpers::PropertyData<double>(18, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'accelerationY'
        QtMocHelpers::PropertyData<double>(19, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'distancePiste'
        QtMocHelpers::PropertyData<double>(20, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'vitesseDecrochage'
        QtMocHelpers::PropertyData<double>(21, QMetaType::Double, QMC::DefaultPropertyFlags, 0),
        // property 'modelesAvions'
        QtMocHelpers::PropertyData<QStringList>(22, QMetaType::QStringList, QMC::DefaultPropertyFlags, 1),
        // property 'modelesPistes'
        QtMocHelpers::PropertyData<QStringList>(23, QMetaType::QStringList, QMC::DefaultPropertyFlags, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SimulationController, qt_meta_tag_ZN11Controllers20SimulationControllerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Controllers::SimulationController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11Controllers20SimulationControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11Controllers20SimulationControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11Controllers20SimulationControllerE_t>.metaTypes,
    nullptr
} };

void Controllers::SimulationController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SimulationController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->positionChangee(); break;
        case 1: _t->listesSelectionChangees(); break;
        case 2: _t->simulationPrete(); break;
        case 3: _t->mettreAJourPhysique(); break;
        case 4: _t->chargerOptions(); break;
        case 5: { bool _r = _t->selectionnerConfiguration((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->accelererX(); break;
        case 7: _t->freinerX(); break;
        case 8: _t->accelererY(); break;
        case 9: _t->freinerY(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SimulationController::*)()>(_a, &SimulationController::positionChangee, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SimulationController::*)()>(_a, &SimulationController::listesSelectionChangees, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (SimulationController::*)()>(_a, &SimulationController::simulationPrete, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<double*>(_v) = _t->getAvionX(); break;
        case 1: *reinterpret_cast<double*>(_v) = _t->getAvionY(); break;
        case 2: *reinterpret_cast<double*>(_v) = _t->getVitesseX(); break;
        case 3: *reinterpret_cast<double*>(_v) = _t->getVitesseY(); break;
        case 4: *reinterpret_cast<double*>(_v) = _t->getAccelerationX(); break;
        case 5: *reinterpret_cast<double*>(_v) = _t->getAccelerationY(); break;
        case 6: *reinterpret_cast<double*>(_v) = _t->getDistancePiste(); break;
        case 7: *reinterpret_cast<double*>(_v) = _t->getVitesseDecrochage(); break;
        case 8: *reinterpret_cast<QStringList*>(_v) = _t->getModelesAvions(); break;
        case 9: *reinterpret_cast<QStringList*>(_v) = _t->getModelesPistes(); break;
        default: break;
        }
    }
}

const QMetaObject *Controllers::SimulationController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controllers::SimulationController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11Controllers20SimulationControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controllers::SimulationController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Controllers::SimulationController::positionChangee()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Controllers::SimulationController::listesSelectionChangees()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Controllers::SimulationController::simulationPrete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP

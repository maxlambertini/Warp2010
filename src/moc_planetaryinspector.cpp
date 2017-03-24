/****************************************************************************
** Meta object code from reading C++ file 'planetaryinspector.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/planetaryinspector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'planetaryinspector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PlanetaryInspector[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      39,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      59,   19,   19,   19, 0x0a,
      83,   81,   19,   19, 0x0a,
     114,   81,   19,   19, 0x0a,
     146,   81,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PlanetaryInspector[] = {
    "PlanetaryInspector\0\0planetDataLoaded()\0"
    "planetDataChanged()\0onPlanetNameChanged()\0"
    "d\0onPlanetDensityChanged(double)\0"
    "onPlanetDiameterChanged(double)\0"
    "onDistanceChanged(double)\0"
};

void PlanetaryInspector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PlanetaryInspector *_t = static_cast<PlanetaryInspector *>(_o);
        switch (_id) {
        case 0: _t->planetDataLoaded(); break;
        case 1: _t->planetDataChanged(); break;
        case 2: _t->onPlanetNameChanged(); break;
        case 3: _t->onPlanetDensityChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->onPlanetDiameterChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->onDistanceChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PlanetaryInspector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PlanetaryInspector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlanetaryInspector,
      qt_meta_data_PlanetaryInspector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PlanetaryInspector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PlanetaryInspector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PlanetaryInspector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlanetaryInspector))
        return static_cast<void*>(const_cast< PlanetaryInspector*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlanetaryInspector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PlanetaryInspector::planetDataLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PlanetaryInspector::planetDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE

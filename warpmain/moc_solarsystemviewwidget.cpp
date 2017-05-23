/****************************************************************************
** Meta object code from reading C++ file 'solarsystemviewwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/solarsystemviewwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'solarsystemviewwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SolarSystemViewWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   23,   22,   22, 0x05,
      51,   49,   22,   22, 0x05,
      79,   77,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     101,   23,   22,   22, 0x0a,
     131,   49,   22,   22, 0x0a,
     159,   22,   22,   22, 0x0a,
     181,   49,   22,   22, 0x0a,
     211,   77,   22,   22, 0x0a,
     235,   22,   22,   22, 0x0a,
     248,   22,   22,   22, 0x0a,
     262,   22,   22,   22, 0x0a,
     271,   22,   22,   22, 0x0a,
     285,  281,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SolarSystemViewWidget[] = {
    "SolarSystemViewWidget\0\0p\0"
    "planetSelected(Planet*)\0s\0"
    "starNameChanged(QString&)\0i\0"
    "neighborSelected(int)\0"
    "handlePlanetSelected(Planet*)\0"
    "onStarNameChanged(QString&)\0"
    "onPlanetDataChanged()\0"
    "starFullTypeChanged(QString&)\0"
    "onNeighborSelected(int)\0rotateLeft()\0"
    "rotateRight()\0zoomIn()\0zoomOut()\0val\0"
    "sliderValueChanged(int)\0"
};

void SolarSystemViewWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SolarSystemViewWidget *_t = static_cast<SolarSystemViewWidget *>(_o);
        switch (_id) {
        case 0: _t->planetSelected((*reinterpret_cast< Planet*(*)>(_a[1]))); break;
        case 1: _t->starNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->neighborSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->handlePlanetSelected((*reinterpret_cast< Planet*(*)>(_a[1]))); break;
        case 4: _t->onStarNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->onPlanetDataChanged(); break;
        case 6: _t->starFullTypeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->onNeighborSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->rotateLeft(); break;
        case 9: _t->rotateRight(); break;
        case 10: _t->zoomIn(); break;
        case 11: _t->zoomOut(); break;
        case 12: _t->sliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SolarSystemViewWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SolarSystemViewWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SolarSystemViewWidget,
      qt_meta_data_SolarSystemViewWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SolarSystemViewWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SolarSystemViewWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SolarSystemViewWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SolarSystemViewWidget))
        return static_cast<void*>(const_cast< SolarSystemViewWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SolarSystemViewWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void SolarSystemViewWidget::planetSelected(Planet * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SolarSystemViewWidget::starNameChanged(QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SolarSystemViewWidget::neighborSelected(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

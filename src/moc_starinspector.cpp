/****************************************************************************
** Meta object code from reading C++ file 'starinspector.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/starinspector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'starinspector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StarInspector[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   15,   14,   14, 0x05,
      51,   46,   14,   14, 0x05,
      86,   77,   14,   14, 0x05,
     121,  113,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     143,   14,   14,   14, 0x0a,
     161,   14,   14,   14, 0x0a,
     186,   14,   14,   14, 0x0a,
     221,  217,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_StarInspector[] = {
    "StarInspector\0\0name\0starNameChanged(QString&)\0"
    "type\0starTypeChanged(QString&)\0starName\0"
    "neighborSelected(QString&)\0starIdx\0"
    "neighborSelected(int)\0editingFinished()\0"
    "starTypeEditingChanged()\0"
    "lstNeighborsSelectionChanged()\0qwi\0"
    "lstNeighborsCurrentRowChanged(QListWidgetItem*)\0"
};

void StarInspector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StarInspector *_t = static_cast<StarInspector *>(_o);
        switch (_id) {
        case 0: _t->starNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->starTypeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->neighborSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->neighborSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->editingFinished(); break;
        case 5: _t->starTypeEditingChanged(); break;
        case 6: _t->lstNeighborsSelectionChanged(); break;
        case 7: _t->lstNeighborsCurrentRowChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StarInspector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StarInspector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StarInspector,
      qt_meta_data_StarInspector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StarInspector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StarInspector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StarInspector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StarInspector))
        return static_cast<void*>(const_cast< StarInspector*>(this));
    return QWidget::qt_metacast(_clname);
}

int StarInspector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void StarInspector::starNameChanged(QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StarInspector::starTypeChanged(QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void StarInspector::neighborSelected(QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void StarInspector::neighborSelected(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'diasporaclusterdialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "diasporaclusterdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diasporaclusterdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DiasporaClusterDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x08,
      57,   22,   22,   22, 0x08,
      96,   22,   22,   22, 0x08,
     124,   22,   22,   22, 0x08,
     151,   22,   22,   22, 0x08,
     175,   22,   22,   22, 0x08,
     204,  198,   22,   22, 0x08,
     236,  198,   22,   22, 0x08,
     270,   22,   22,   22, 0x08,
     311,  305,   22,   22, 0x08,
     346,  305,   22,   22, 0x08,
     381,   22,   22,   22, 0x08,
     402,   22,   22,   22, 0x08,
     430,   22,   22,   22, 0x08,
     456,   22,   22,   22, 0x08,
     489,   22,   22,   22, 0x08,
     514,   22,   22,   22, 0x08,
     547,  538,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DiasporaClusterDialog[] = {
    "DiasporaClusterDialog\0\0"
    "on_lblClusterName_returnPressed()\0"
    "on_lblClusterName_textChanged(QString)\0"
    "on_btnRotateRight_clicked()\0"
    "on_btnRotateLeft_clicked()\0"
    "on_btnZoomOut_clicked()\0on_btnZoomIn_clicked()\0"
    "value\0on_sliderZoom_valueChanged(int)\0"
    "on_sliderRotate_valueChanged(int)\0"
    "on_spinNumSolSys_valueChanged(int)\0"
    "index\0on_lstCluster_entered(QModelIndex)\0"
    "on_lstCluster_clicked(QModelIndex)\0"
    "on_btnExit_clicked()\0on_btnSaveCluster_clicked()\0"
    "on_btnAddAspect_clicked()\0"
    "on_btnRandomizeAspects_clicked()\0"
    "on_btnGenerate_clicked()\0"
    "on_clusterItemChanged()\0cli2,idx\0"
    "on_clusterItemClicked(ClusterItem,int)\0"
};

void DiasporaClusterDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DiasporaClusterDialog *_t = static_cast<DiasporaClusterDialog *>(_o);
        switch (_id) {
        case 0: _t->on_lblClusterName_returnPressed(); break;
        case 1: _t->on_lblClusterName_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_btnRotateRight_clicked(); break;
        case 3: _t->on_btnRotateLeft_clicked(); break;
        case 4: _t->on_btnZoomOut_clicked(); break;
        case 5: _t->on_btnZoomIn_clicked(); break;
        case 6: _t->on_sliderZoom_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_sliderRotate_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_spinNumSolSys_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_lstCluster_entered((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_lstCluster_clicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 11: _t->on_btnExit_clicked(); break;
        case 12: _t->on_btnSaveCluster_clicked(); break;
        case 13: _t->on_btnAddAspect_clicked(); break;
        case 14: _t->on_btnRandomizeAspects_clicked(); break;
        case 15: _t->on_btnGenerate_clicked(); break;
        case 16: _t->on_clusterItemChanged(); break;
        case 17: _t->on_clusterItemClicked((*reinterpret_cast< const ClusterItem(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DiasporaClusterDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DiasporaClusterDialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DiasporaClusterDialog,
      qt_meta_data_DiasporaClusterDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DiasporaClusterDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DiasporaClusterDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DiasporaClusterDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DiasporaClusterDialog))
        return static_cast<void*>(const_cast< DiasporaClusterDialog*>(this));
    return QWidget::qt_metacast(_clname);
}

int DiasporaClusterDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

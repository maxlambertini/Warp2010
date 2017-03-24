/****************************************************************************
** Meta object code from reading C++ file 'clusteritemeditor.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "clusteritemeditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clusteritemeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClusterItemEditor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   40,   18,   18, 0x08,
      94,   18,   18,   18, 0x08,
     125,   18,   18,   18, 0x08,
     154,   18,   18,   18, 0x08,
     182,   18,   18,   18, 0x08,
     210,   18,   18,   18, 0x08,
     248,   18,   18,   18, 0x08,
     276,   18,   18,   18, 0x08,
     304,   18,   18,   18, 0x08,
     332,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ClusterItemEditor[] = {
    "ClusterItemEditor\0\0clusterItemChanged()\0"
    "item\0on_lstReachability_itemChanged(QListWidgetItem*)\0"
    "on_btnConfirmEditing_clicked()\0"
    "on_spnTech_valueChanged(int)\0"
    "on_spnRes_valueChanged(int)\0"
    "on_spnEnv_valueChanged(int)\0"
    "on_txtSystemDescription_textChanged()\0"
    "on_txtAspect3_textChanged()\0"
    "on_txtAspect2_textChanged()\0"
    "on_txtAspect1_textChanged()\0"
    "on_txtSystemName_textChanged(QString)\0"
};

void ClusterItemEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ClusterItemEditor *_t = static_cast<ClusterItemEditor *>(_o);
        switch (_id) {
        case 0: _t->clusterItemChanged(); break;
        case 1: _t->on_lstReachability_itemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->on_btnConfirmEditing_clicked(); break;
        case 3: _t->on_spnTech_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_spnRes_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_spnEnv_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_txtSystemDescription_textChanged(); break;
        case 7: _t->on_txtAspect3_textChanged(); break;
        case 8: _t->on_txtAspect2_textChanged(); break;
        case 9: _t->on_txtAspect1_textChanged(); break;
        case 10: _t->on_txtSystemName_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ClusterItemEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ClusterItemEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ClusterItemEditor,
      qt_meta_data_ClusterItemEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClusterItemEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClusterItemEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClusterItemEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClusterItemEditor))
        return static_cast<void*>(const_cast< ClusterItemEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int ClusterItemEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ClusterItemEditor::clusterItemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

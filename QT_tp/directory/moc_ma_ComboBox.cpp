/****************************************************************************
** Meta object code from reading C++ file 'ma_ComboBox.h'
**
** Created: Tue Jan 31 09:07:50 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ma_ComboBox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ma_ComboBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ma_ComboBox[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,   12,   12,   12, 0x0a,
      41,   37,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Ma_ComboBox[] = {
    "Ma_ComboBox\0\0directoryChanged()\0ls()\0"
    "dir\0cd(QString)\0"
};

const QMetaObject Ma_ComboBox::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_Ma_ComboBox,
      qt_meta_data_Ma_ComboBox, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ma_ComboBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ma_ComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ma_ComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ma_ComboBox))
        return static_cast<void*>(const_cast< Ma_ComboBox*>(this));
    return QComboBox::qt_metacast(_clname);
}

int Ma_ComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: directoryChanged(); break;
        case 1: ls(); break;
        case 2: cd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Ma_ComboBox::directoryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

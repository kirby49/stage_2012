/****************************************************************************
** Meta object code from reading C++ file 'calcul.h'
**
** Created: Thu Apr 26 15:20:35 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tp1/calcul.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calcul.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_calcul[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,    8,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_calcul[] = {
    "calcul\0\0int\0x,c,y\0calculer(int,QString,int)\0"
};

const QMetaObject calcul::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_calcul,
      qt_meta_data_calcul, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &calcul::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *calcul::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *calcul::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_calcul))
        return static_cast<void*>(const_cast< calcul*>(this));
    return QWidget::qt_metacast(_clname);
}

int calcul::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = calculer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

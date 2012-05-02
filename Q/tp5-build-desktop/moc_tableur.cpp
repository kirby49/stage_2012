/****************************************************************************
** Meta object code from reading C++ file 'tableur.h'
**
** Created: Wed May 2 10:59:19 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tp5/tableur.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tableur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_tableur[] = {

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
      16,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,    8,    8,    8, 0x0a,
      53,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_tableur[] = {
    "tableur\0\0layout\0changeRes(QGridLayout*)\0"
    "ajoutligne()\0ajoutcol()\0"
};

const QMetaObject tableur::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_tableur,
      qt_meta_data_tableur, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &tableur::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *tableur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *tableur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tableur))
        return static_cast<void*>(const_cast< tableur*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int tableur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: changeRes((*reinterpret_cast< QGridLayout*(*)>(_a[1]))); break;
        case 1: ajoutligne(); break;
        case 2: ajoutcol(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void tableur::changeRes(QGridLayout * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'tableur.h'
**
** Created: Sun Feb 12 15:36:57 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tableur.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tableur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tableur[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,    9,    8,    8, 0x0a,
      45,    9,    8,    8, 0x0a,
      70,    9,    8,    8, 0x0a,
      97,    8,    8,    8, 0x0a,
     110,    8,    8,    8, 0x0a,
     121,    8,    8,    8, 0x0a,
     140,    8,    8,    8, 0x0a,
     150,    8,    8,    8, 0x0a,
     162,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tableur[] = {
    "Tableur\0\0event\0mousePressEvent(QMouseEvent*)\0"
    "paintEvent(QPaintEvent*)\0"
    "resizeEvent(QResizeEvent*)\0clearImage()\0"
    "drawGrid()\0showSelectedCell()\0addLign()\0"
    "addColumn()\0addCell()\0"
};

const QMetaObject Tableur::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tableur,
      qt_meta_data_Tableur, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tableur::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tableur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tableur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tableur))
        return static_cast<void*>(const_cast< Tableur*>(this));
    return QWidget::qt_metacast(_clname);
}

int Tableur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 2: resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 3: clearImage(); break;
        case 4: drawGrid(); break;
        case 5: showSelectedCell(); break;
        case 6: addLign(); break;
        case 7: addColumn(); break;
        case 8: addCell(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

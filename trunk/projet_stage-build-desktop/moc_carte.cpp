/****************************************************************************
** Meta object code from reading C++ file 'carte.h'
**
** Created: Fri May 11 15:03:58 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../projet_stage/carte.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'carte.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_carte[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      21,   19,    6,    6, 0x05,
      40,    6,    6,    6, 0x05,
      53,    6,    6,    6, 0x05,
      68,   19,    6,    6, 0x05,
      97,   19,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     116,    6,    6,    6, 0x0a,
     133,    6,    6,    6, 0x0a,
     149,    6,    6,    6, 0x0a,
     164,    6,    6,    6, 0x0a,
     177,   19,    6,    6, 0x0a,
     200,   19,    6,    6, 0x0a,
     224,   19,    6,    6, 0x0a,
     244,   19,    6,    6, 0x0a,
     270,  264,    6,    6, 0x0a,
     300,  264,    6,    6, 0x0a,
     332,  264,    6,    6, 0x0a,
     357,  264,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_carte[] = {
    "carte\0\0ChangeRes()\0p\0changeRes2(QPoint)\0"
    "ChangeZoom()\0ChangeZoomIn()\0"
    "signalDessinerChemin(QPoint)\0"
    "SignalFlag(QPoint)\0augmenter_zoom()\0"
    "diminuer_zoom()\0fermerProjet()\0"
    "setNbpoint()\0dessinerChemin(QPoint)\0"
    "attributCouleur(QPoint)\0placerFlag1(QPoint)\0"
    "placerFlag2(QPoint)\0event\0"
    "mousePressEvent(QMouseEvent*)\0"
    "mouseReleaseEvent(QMouseEvent*)\0"
    "wheelEvent(QWheelEvent*)\0"
    "paintEvent(QPaintEvent*)\0"
};

const QMetaObject carte::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_carte,
      qt_meta_data_carte, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &carte::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *carte::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *carte::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_carte))
        return static_cast<void*>(const_cast< carte*>(this));
    return QWidget::qt_metacast(_clname);
}

int carte::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: ChangeRes(); break;
        case 1: changeRes2((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 2: ChangeZoom(); break;
        case 3: ChangeZoomIn(); break;
        case 4: signalDessinerChemin((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 5: SignalFlag((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 6: augmenter_zoom(); break;
        case 7: diminuer_zoom(); break;
        case 8: fermerProjet(); break;
        case 9: setNbpoint(); break;
        case 10: dessinerChemin((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 11: attributCouleur((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 12: placerFlag1((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 13: placerFlag2((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 14: mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 15: mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 16: wheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 17: paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void carte::ChangeRes()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void carte::changeRes2(const QPoint & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void carte::ChangeZoom()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void carte::ChangeZoomIn()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void carte::signalDessinerChemin(const QPoint & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void carte::SignalFlag(const QPoint & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE

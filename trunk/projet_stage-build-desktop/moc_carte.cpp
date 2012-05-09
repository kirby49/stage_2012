/****************************************************************************
** Meta object code from reading C++ file 'carte.h'
**
** Created: Wed May 9 10:03:47 2012
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
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      19,    6,    6,    6, 0x05,
      32,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,    6,    6,    6, 0x0a,
      64,    6,    6,    6, 0x0a,
      80,    6,    6,    6, 0x0a,
     101,   95,    6,    6, 0x0a,
     131,   95,    6,    6, 0x0a,
     163,   95,    6,    6, 0x0a,
     188,   95,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_carte[] = {
    "carte\0\0ChangeRes()\0ChangeZoom()\0"
    "ChangeZoomIn()\0augmenter_zoom()\0"
    "diminuer_zoom()\0fermerProjet()\0event\0"
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
        case 1: ChangeZoom(); break;
        case 2: ChangeZoomIn(); break;
        case 3: augmenter_zoom(); break;
        case 4: diminuer_zoom(); break;
        case 5: fermerProjet(); break;
        case 6: mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 8: wheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 9: paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void carte::ChangeRes()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void carte::ChangeZoom()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void carte::ChangeZoomIn()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE

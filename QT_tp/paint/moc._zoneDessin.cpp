/****************************************************************************
** Meta object code from reading C++ file 'zoneDessin.h'
**
** Created: Tue Feb 7 09:35:07 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "zoneDessin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zoneDessin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ZoneDessin[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x0a,
      48,   12,   11,   11, 0x0a,
      80,   12,   11,   11, 0x0a,
     109,   12,   11,   11, 0x0a,
     134,   12,   11,   11, 0x0a,
     161,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ZoneDessin[] = {
    "ZoneDessin\0\0event\0mousePressEvent(QMouseEvent*)\0"
    "mouseReleaseEvent(QMouseEvent*)\0"
    "mouseMoveEvent(QMouseEvent*)\0"
    "paintEvent(QPaintEvent*)\0"
    "resizeEvent(QResizeEvent*)\0clearImage()\0"
};

const QMetaObject ZoneDessin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ZoneDessin,
      qt_meta_data_ZoneDessin, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ZoneDessin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ZoneDessin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ZoneDessin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ZoneDessin))
        return static_cast<void*>(const_cast< ZoneDessin*>(this));
    return QWidget::qt_metacast(_clname);
}

int ZoneDessin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 4: resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 5: clearImage(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

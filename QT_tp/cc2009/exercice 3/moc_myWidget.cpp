/****************************************************************************
** Meta object code from reading C++ file 'myWidget.h'
**
** Created: Thu Feb 16 17:40:09 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   37,    9,    9, 0x0a,
      73,   37,    9,    9, 0x0a,
      98,    9,    9,    9, 0x0a,
     111,   37,    9,    9, 0x0a,
     131,   37,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyWidget[] = {
    "MyWidget\0\0clicked\0stateChanged(bool)\0"
    "event\0mousePressEvent(QMouseEvent*)\0"
    "paintEvent(QPaintEvent*)\0clearImage()\0"
    "enterEvent(QEvent*)\0leaveEvent(QEvent*)\0"
};

const QMetaObject MyWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyWidget,
      qt_meta_data_MyWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyWidget))
        return static_cast<void*>(const_cast< MyWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: stateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 3: clearImage(); break;
        case 4: enterEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 5: leaveEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MyWidget::stateChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

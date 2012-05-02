/****************************************************************************
** Meta object code from reading C++ file 'moteur.h'
**
** Created: Fri Jan 27 11:15:46 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "moteur.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'moteur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Moteur[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      30,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,    7,    7,    7, 0x0a,
      56,    7,    7,    7, 0x0a,
      63,    7,    7,    7, 0x0a,
      70,    7,    7,    7, 0x0a,
      77,    7,    7,    7, 0x0a,
      84,    7,    7,    7, 0x0a,
      91,    7,    7,    7, 0x0a,
      98,    7,    7,    7, 0x0a,
     105,    7,    7,    7, 0x0a,
     112,    7,    7,    7, 0x0a,
     119,    7,    7,    7, 0x0a,
     125,    7,    7,    7, 0x0a,
     132,    7,    7,    7, 0x0a,
     139,    7,    7,    7, 0x0a,
     147,    7,    7,    7, 0x0a,
     156,    7,    7,    7, 0x0a,
     167,    7,    7,    7, 0x0a,
     178,    7,    7,    7, 0x0a,
     187,    7,    7,    7, 0x0a,
     195,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Moteur[] = {
    "Moteur\0\0valueChanged(QString)\0"
    "opChanged(QString)\0add1()\0add2()\0"
    "add3()\0add4()\0add5()\0add6()\0add7()\0"
    "add8()\0add9()\0add0()\0dot()\0plus()\0"
    "less()\0times()\0divide()\0bracketL()\0"
    "bracketR()\0square()\0clear()\0afficheEqu()\0"
};

const QMetaObject Moteur::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Moteur,
      qt_meta_data_Moteur, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Moteur::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Moteur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Moteur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Moteur))
        return static_cast<void*>(const_cast< Moteur*>(this));
    return QObject::qt_metacast(_clname);
}

int Moteur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: opChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: add1(); break;
        case 3: add2(); break;
        case 4: add3(); break;
        case 5: add4(); break;
        case 6: add5(); break;
        case 7: add6(); break;
        case 8: add7(); break;
        case 9: add8(); break;
        case 10: add9(); break;
        case 11: add0(); break;
        case 12: dot(); break;
        case 13: plus(); break;
        case 14: less(); break;
        case 15: times(); break;
        case 16: divide(); break;
        case 17: bracketL(); break;
        case 18: bracketR(); break;
        case 19: square(); break;
        case 20: clear(); break;
        case 21: afficheEqu(); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void Moteur::valueChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Moteur::opChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

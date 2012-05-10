/****************************************************************************
** Meta object code from reading C++ file 'fenetre.h'
**
** Created: Thu May 10 09:09:18 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../projet_stage/fenetre.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_fenetre[] = {

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
       9,    8,    8,    8, 0x0a,
      28,    8,    8,    8, 0x0a,
      41,    8,    8,    8, 0x0a,
      55,    8,    8,    8, 0x0a,
      70,    8,    8,    8, 0x0a,
      78,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_fenetre[] = {
    "fenetre\0\0telechargerImage()\0setCouleur()\0"
    "valider_dec()\0valider_sexa()\0ignor()\0"
    "afficher_dock()\0"
};

const QMetaObject fenetre::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_fenetre,
      qt_meta_data_fenetre, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &fenetre::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *fenetre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *fenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fenetre))
        return static_cast<void*>(const_cast< fenetre*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int fenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: telechargerImage(); break;
        case 1: setCouleur(); break;
        case 2: valider_dec(); break;
        case 3: valider_sexa(); break;
        case 4: ignor(); break;
        case 5: afficher_dock(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

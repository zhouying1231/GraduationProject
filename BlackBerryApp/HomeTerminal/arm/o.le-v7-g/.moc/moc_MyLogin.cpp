/****************************************************************************
** Meta object code from reading C++ file 'MyLogin.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/MyLogin.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyLogin.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyLogin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,

 // methods: signature, parameters, type, tag, flags
      48,   24,    8,    8, 0x02,
      86,   72,    8,    8, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_MyLogin[] = {
    "MyLogin\0\0GetReturnMsg()\0activityindicator,toast\0"
    "Init(QObject*,QObject*)\0name,password\0"
    "SendInfo(QString,QString)\0"
};

void MyLogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyLogin *_t = static_cast<MyLogin *>(_o);
        switch (_id) {
        case 0: _t->GetReturnMsg(); break;
        case 1: _t->Init((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2]))); break;
        case 2: _t->SendInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyLogin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyLogin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyLogin,
      qt_meta_data_MyLogin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyLogin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyLogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyLogin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyLogin))
        return static_cast<void*>(const_cast< MyLogin*>(this));
    return QObject::qt_metacast(_clname);
}

int MyLogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'set_user.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../set_user.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'set_user.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_set_user_t {
    QByteArrayData data[10];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_set_user_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_set_user_t qt_meta_stringdata_set_user = {
    {
QT_MOC_LITERAL(0, 0, 8), // "set_user"
QT_MOC_LITERAL(1, 9, 18), // "SIG_Setuser_Commit"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "conid"
QT_MOC_LITERAL(4, 35, 4), // "name"
QT_MOC_LITERAL(5, 40, 9), // "signature"
QT_MOC_LITERAL(6, 50, 19), // "on_pb_clear_clicked"
QT_MOC_LITERAL(7, 70, 18), // "on_pb_emit_clicked"
QT_MOC_LITERAL(8, 89, 12), // "slot_setInfo"
QT_MOC_LITERAL(9, 102, 6) // "iconid"

    },
    "set_user\0SIG_Setuser_Commit\0\0conid\0"
    "name\0signature\0on_pb_clear_clicked\0"
    "on_pb_emit_clicked\0slot_setInfo\0iconid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_set_user[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   46,    2, 0x0a /* Public */,
       7,    0,   47,    2, 0x0a /* Public */,
       8,    3,   48,    2, 0x0a /* Public */,
       8,    2,   55,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    9,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    9,    4,

       0        // eod
};

void set_user::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        set_user *_t = static_cast<set_user *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_Setuser_Commit((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->on_pb_clear_clicked(); break;
        case 2: _t->on_pb_emit_clicked(); break;
        case 3: _t->slot_setInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->slot_setInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (set_user::*_t)(int , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&set_user::SIG_Setuser_Commit)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject set_user::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_set_user.data,
      qt_meta_data_set_user,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *set_user::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *set_user::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_set_user.stringdata0))
        return static_cast<void*>(const_cast< set_user*>(this));
    return QDialog::qt_metacast(_clname);
}

int set_user::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void set_user::SIG_Setuser_Commit(int _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

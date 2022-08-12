/****************************************************************************
** Meta object code from reading C++ file 'lobby_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../lobby_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lobby_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_lobby_dialog_t {
    QByteArrayData data[12];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lobby_dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lobby_dialog_t qt_meta_stringdata_lobby_dialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "lobby_dialog"
QT_MOC_LITERAL(1, 13, 9), // "SIG_close"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "SIG_showroom"
QT_MOC_LITERAL(4, 37, 12), // "SIG_UserInfo"
QT_MOC_LITERAL(5, 50, 23), // "on_pb_fightmode_clicked"
QT_MOC_LITERAL(6, 74, 18), // "on_pb_icon_clicked"
QT_MOC_LITERAL(7, 93, 16), // "slot_setUserInfo"
QT_MOC_LITERAL(8, 110, 7), // "icon_id"
QT_MOC_LITERAL(9, 118, 7), // "user_id"
QT_MOC_LITERAL(10, 126, 7), // "my_name"
QT_MOC_LITERAL(11, 134, 19) // "on_pb_leave_clicked"

    },
    "lobby_dialog\0SIG_close\0\0SIG_showroom\0"
    "SIG_UserInfo\0on_pb_fightmode_clicked\0"
    "on_pb_icon_clicked\0slot_setUserInfo\0"
    "icon_id\0user_id\0my_name\0on_pb_leave_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lobby_dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    3,   54,    2, 0x0a /* Public */,
      11,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    8,    9,   10,
    QMetaType::Void,

       0        // eod
};

void lobby_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        lobby_dialog *_t = static_cast<lobby_dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_close(); break;
        case 1: _t->SIG_showroom(); break;
        case 2: _t->SIG_UserInfo(); break;
        case 3: _t->on_pb_fightmode_clicked(); break;
        case 4: _t->on_pb_icon_clicked(); break;
        case 5: _t->slot_setUserInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: _t->on_pb_leave_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (lobby_dialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lobby_dialog::SIG_close)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (lobby_dialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lobby_dialog::SIG_showroom)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (lobby_dialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&lobby_dialog::SIG_UserInfo)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject lobby_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_lobby_dialog.data,
      qt_meta_data_lobby_dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *lobby_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lobby_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_lobby_dialog.stringdata0))
        return static_cast<void*>(const_cast< lobby_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int lobby_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void lobby_dialog::SIG_close()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void lobby_dialog::SIG_showroom()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void lobby_dialog::SIG_UserInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

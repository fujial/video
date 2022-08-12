/****************************************************************************
** Meta object code from reading C++ file 'game_control.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../game_control.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_game_Control_t {
    QByteArrayData data[26];
    char stringdata0[307];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_game_Control_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_game_Control_t qt_meta_stringdata_game_Control = {
    {
QT_MOC_LITERAL(0, 0, 12), // "game_Control"
QT_MOC_LITERAL(1, 13, 15), // "SIG_setRoomInfo"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "player_id"
QT_MOC_LITERAL(4, 40, 8), // "enemy_id"
QT_MOC_LITERAL(5, 49, 10), // "playerlife"
QT_MOC_LITERAL(6, 60, 9), // "enemylife"
QT_MOC_LITERAL(7, 70, 7), // "room_id"
QT_MOC_LITERAL(8, 78, 12), // "slot_destroy"
QT_MOC_LITERAL(9, 91, 17), // "slot_login_commit"
QT_MOC_LITERAL(10, 109, 20), // "slot_register_commit"
QT_MOC_LITERAL(11, 130, 13), // "slot_showroom"
QT_MOC_LITERAL(12, 144, 13), // "slot_dealData"
QT_MOC_LITERAL(13, 158, 6), // "socket"
QT_MOC_LITERAL(14, 165, 5), // "char*"
QT_MOC_LITERAL(15, 171, 3), // "buf"
QT_MOC_LITERAL(16, 175, 4), // "nlen"
QT_MOC_LITERAL(17, 180, 15), // "slot_createroom"
QT_MOC_LITERAL(18, 196, 13), // "slot_joinroom"
QT_MOC_LITERAL(19, 210, 12), // "slot_setInfo"
QT_MOC_LITERAL(20, 223, 20), // "slot_userInfo_commit"
QT_MOC_LITERAL(21, 244, 6), // "iconid"
QT_MOC_LITERAL(22, 251, 4), // "name"
QT_MOC_LITERAL(23, 256, 17), // "slot_leaveroom_RQ"
QT_MOC_LITERAL(24, 274, 14), // "slot_leaveroom"
QT_MOC_LITERAL(25, 289, 17) // "slot_return_lobby"

    },
    "game_Control\0SIG_setRoomInfo\0\0player_id\0"
    "enemy_id\0playerlife\0enemylife\0room_id\0"
    "slot_destroy\0slot_login_commit\0"
    "slot_register_commit\0slot_showroom\0"
    "slot_dealData\0socket\0char*\0buf\0nlen\0"
    "slot_createroom\0slot_joinroom\0"
    "slot_setInfo\0slot_userInfo_commit\0"
    "iconid\0name\0slot_leaveroom_RQ\0"
    "slot_leaveroom\0slot_return_lobby"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_game_Control[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   90,    2, 0x0a /* Public */,
       9,    2,   91,    2, 0x0a /* Public */,
      10,    2,   96,    2, 0x0a /* Public */,
      11,    0,  101,    2, 0x0a /* Public */,
      12,    3,  102,    2, 0x0a /* Public */,
      17,    0,  109,    2, 0x0a /* Public */,
      18,    0,  110,    2, 0x0a /* Public */,
      19,    0,  111,    2, 0x0a /* Public */,
      20,    2,  112,    2, 0x0a /* Public */,
      23,    0,  117,    2, 0x0a /* Public */,
      24,    0,  118,    2, 0x0a /* Public */,
      25,    0,  119,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 14, QMetaType::Int,   13,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   21,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void game_Control::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        game_Control *_t = static_cast<game_Control *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_setRoomInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 1: _t->slot_destroy(); break;
        case 2: _t->slot_login_commit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->slot_register_commit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->slot_showroom(); break;
        case 5: _t->slot_dealData((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->slot_createroom(); break;
        case 7: _t->slot_joinroom(); break;
        case 8: _t->slot_setInfo(); break;
        case 9: _t->slot_userInfo_commit((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->slot_leaveroom_RQ(); break;
        case 11: _t->slot_leaveroom(); break;
        case 12: _t->slot_return_lobby(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (game_Control::*_t)(int , int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&game_Control::SIG_setRoomInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject game_Control::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_game_Control.data,
      qt_meta_data_game_Control,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *game_Control::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *game_Control::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_game_Control.stringdata0))
        return static_cast<void*>(const_cast< game_Control*>(this));
    return QObject::qt_metacast(_clname);
}

int game_Control::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void game_Control::SIG_setRoomInfo(int _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

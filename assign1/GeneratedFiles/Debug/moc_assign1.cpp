/****************************************************************************
** Meta object code from reading C++ file 'assign1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../assign1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'assign1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_assign1_t {
    QByteArrayData data[15];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_assign1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_assign1_t qt_meta_stringdata_assign1 = {
    {
QT_MOC_LITERAL(0, 0, 7), // "assign1"
QT_MOC_LITERAL(1, 8, 15), // "lookupIpPressed"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 21), // "lookupHostnamePressed"
QT_MOC_LITERAL(4, 47, 20), // "lookupServicePressed"
QT_MOC_LITERAL(5, 68, 17), // "lookupPortPressed"
QT_MOC_LITERAL(6, 86, 16), // "hostnameReceived"
QT_MOC_LITERAL(7, 103, 8), // "hostname"
QT_MOC_LITERAL(8, 112, 10), // "ipReceived"
QT_MOC_LITERAL(9, 123, 9), // "ipAddress"
QT_MOC_LITERAL(10, 133, 12), // "portReceived"
QT_MOC_LITERAL(11, 146, 10), // "portNumber"
QT_MOC_LITERAL(12, 157, 8), // "protocol"
QT_MOC_LITERAL(13, 166, 15), // "serviceReceived"
QT_MOC_LITERAL(14, 182, 7) // "service"

    },
    "assign1\0lookupIpPressed\0\0lookupHostnamePressed\0"
    "lookupServicePressed\0lookupPortPressed\0"
    "hostnameReceived\0hostname\0ipReceived\0"
    "ipAddress\0portReceived\0portNumber\0"
    "protocol\0serviceReceived\0service"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_assign1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x08 /* Private */,
       8,    1,   61,    2, 0x08 /* Private */,
      10,    2,   64,    2, 0x08 /* Private */,
      13,    2,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   12,

       0        // eod
};

void assign1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        assign1 *_t = static_cast<assign1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lookupIpPressed(); break;
        case 1: _t->lookupHostnamePressed(); break;
        case 2: _t->lookupServicePressed(); break;
        case 3: _t->lookupPortPressed(); break;
        case 4: _t->hostnameReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->ipReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->portReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->serviceReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject assign1::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_assign1.data,
      qt_meta_data_assign1,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *assign1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *assign1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_assign1.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int assign1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

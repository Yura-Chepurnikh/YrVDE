/****************************************************************************
** Meta object code from reading C++ file 'workspace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.15)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../workspace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workspace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.15. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WorkSpace_t {
    QByteArrayData data[16];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkSpace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkSpace_t qt_meta_stringdata_WorkSpace = {
    {
QT_MOC_LITERAL(0, 0, 9), // "WorkSpace"
QT_MOC_LITERAL(1, 10, 9), // "SendPoint"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 5), // "point"
QT_MOC_LITERAL(4, 27, 10), // "SendIsShow"
QT_MOC_LITERAL(5, 38, 6), // "isShow"
QT_MOC_LITERAL(6, 45, 7), // "SendGap"
QT_MOC_LITERAL(7, 53, 3), // "gap"
QT_MOC_LITERAL(8, 57, 9), // "SendScene"
QT_MOC_LITERAL(9, 67, 10), // "WorkSpace*"
QT_MOC_LITERAL(10, 78, 9), // "workSpace"
QT_MOC_LITERAL(11, 88, 14), // "SendInputPoint"
QT_MOC_LITERAL(12, 103, 21), // "QSharedPointer<Input>"
QT_MOC_LITERAL(13, 125, 12), // "GetLogicGate"
QT_MOC_LITERAL(14, 138, 10), // "LogicGate*"
QT_MOC_LITERAL(15, 149, 4) // "gate"

    },
    "WorkSpace\0SendPoint\0\0point\0SendIsShow\0"
    "isShow\0SendGap\0gap\0SendScene\0WorkSpace*\0"
    "workSpace\0SendInputPoint\0QSharedPointer<Input>\0"
    "GetLogicGate\0LogicGate*\0gate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkSpace[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,
       8,    1,   53,    2, 0x06 /* Public */,
      11,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void WorkSpace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WorkSpace *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SendPoint((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->SendIsShow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->SendGap((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->SendScene((*reinterpret_cast< WorkSpace*(*)>(_a[1]))); break;
        case 4: _t->SendInputPoint((*reinterpret_cast< QSharedPointer<Input>(*)>(_a[1]))); break;
        case 5: _t->GetLogicGate((*reinterpret_cast< LogicGate*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WorkSpace* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSharedPointer<Input> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< LogicGate* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WorkSpace::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkSpace::SendPoint)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WorkSpace::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkSpace::SendIsShow)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WorkSpace::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkSpace::SendGap)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WorkSpace::*)(WorkSpace * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkSpace::SendScene)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WorkSpace::*)(QSharedPointer<Input> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkSpace::SendInputPoint)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WorkSpace::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_WorkSpace.data,
    qt_meta_data_WorkSpace,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WorkSpace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkSpace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WorkSpace.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int WorkSpace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void WorkSpace::SendPoint(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WorkSpace::SendIsShow(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WorkSpace::SendGap(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WorkSpace::SendScene(WorkSpace * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WorkSpace::SendInputPoint(QSharedPointer<Input> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

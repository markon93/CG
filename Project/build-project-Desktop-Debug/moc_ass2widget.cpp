/****************************************************************************
** Meta object code from reading C++ file 'ass2widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Part3/ass2widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ass2widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ass2Widget_t {
    QByteArrayData data[30];
    char stringdata0[432];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ass2Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ass2Widget_t qt_meta_stringdata_Ass2Widget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Ass2Widget"
QT_MOC_LITERAL(1, 11, 10), // "changeFile"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "std::string"
QT_MOC_LITERAL(4, 35, 8), // "filename"
QT_MOC_LITERAL(5, 44, 9), // "changeFOV"
QT_MOC_LITERAL(6, 54, 3), // "fov"
QT_MOC_LITERAL(7, 58, 10), // "changePFar"
QT_MOC_LITERAL(8, 69, 1), // "d"
QT_MOC_LITERAL(9, 71, 19), // "changeToPerspective"
QT_MOC_LITERAL(10, 91, 16), // "changeToParallel"
QT_MOC_LITERAL(11, 108, 14), // "changeOblScale"
QT_MOC_LITERAL(12, 123, 5), // "scale"
QT_MOC_LITERAL(13, 129, 14), // "changeOblAngle"
QT_MOC_LITERAL(14, 144, 5), // "angle"
QT_MOC_LITERAL(15, 150, 11), // "changePlTop"
QT_MOC_LITERAL(16, 162, 3), // "top"
QT_MOC_LITERAL(17, 166, 11), // "changePlFar"
QT_MOC_LITERAL(18, 178, 5), // "plFar"
QT_MOC_LITERAL(19, 184, 23), // "on_btn_parallel_clicked"
QT_MOC_LITERAL(20, 208, 26), // "on_btn_perspective_clicked"
QT_MOC_LITERAL(21, 235, 24), // "on_spin_top_valueChanged"
QT_MOC_LITERAL(22, 260, 26), // "on_spin_plfar_valueChanged"
QT_MOC_LITERAL(23, 287, 5), // "plfar"
QT_MOC_LITERAL(24, 293, 29), // "on_spin_oblscale_valueChanged"
QT_MOC_LITERAL(25, 323, 29), // "on_spin_oblangle_valueChanged"
QT_MOC_LITERAL(26, 353, 24), // "on_spin_fov_valueChanged"
QT_MOC_LITERAL(27, 378, 26), // "on_spin_pefar_valueChanged"
QT_MOC_LITERAL(28, 405, 5), // "pefar"
QT_MOC_LITERAL(29, 411, 20) // "on_push_file_clicked"

    },
    "Ass2Widget\0changeFile\0\0std::string\0"
    "filename\0changeFOV\0fov\0changePFar\0d\0"
    "changeToPerspective\0changeToParallel\0"
    "changeOblScale\0scale\0changeOblAngle\0"
    "angle\0changePlTop\0top\0changePlFar\0"
    "plFar\0on_btn_parallel_clicked\0"
    "on_btn_perspective_clicked\0"
    "on_spin_top_valueChanged\0"
    "on_spin_plfar_valueChanged\0plfar\0"
    "on_spin_oblscale_valueChanged\0"
    "on_spin_oblangle_valueChanged\0"
    "on_spin_fov_valueChanged\0"
    "on_spin_pefar_valueChanged\0pefar\0"
    "on_push_file_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ass2Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       5,    1,  107,    2, 0x06 /* Public */,
       7,    1,  110,    2, 0x06 /* Public */,
       9,    0,  113,    2, 0x06 /* Public */,
      10,    0,  114,    2, 0x06 /* Public */,
      11,    1,  115,    2, 0x06 /* Public */,
      13,    1,  118,    2, 0x06 /* Public */,
      15,    1,  121,    2, 0x06 /* Public */,
      17,    1,  124,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    0,  127,    2, 0x0a /* Public */,
      20,    0,  128,    2, 0x0a /* Public */,
      21,    1,  129,    2, 0x0a /* Public */,
      22,    1,  132,    2, 0x0a /* Public */,
      24,    1,  135,    2, 0x0a /* Public */,
      25,    1,  138,    2, 0x0a /* Public */,
      26,    1,  141,    2, 0x0a /* Public */,
      27,    1,  144,    2, 0x0a /* Public */,
      29,    0,  147,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Int,   18,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void,

       0        // eod
};

void Ass2Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ass2Widget *_t = static_cast<Ass2Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeFile((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->changeFOV((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changePFar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changeToPerspective(); break;
        case 4: _t->changeToParallel(); break;
        case 5: _t->changeOblScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->changeOblAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->changePlTop((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->changePlFar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_btn_parallel_clicked(); break;
        case 10: _t->on_btn_perspective_clicked(); break;
        case 11: _t->on_spin_top_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->on_spin_plfar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_spin_oblscale_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->on_spin_oblangle_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->on_spin_fov_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_spin_pefar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_push_file_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Ass2Widget::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass2Widget::changeFile)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Ass2Widget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass2Widget::changeFOV)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Ass2Widget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass2Widget::changePFar)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Ass2Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass2Widget::changeToPerspective)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Ass2Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass2Widget::changeToParallel)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Ass2Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass2Widget::changeOblScale)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Ass2Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass2Widget::changeOblAngle)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Ass2Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass2Widget::changePlTop)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Ass2Widget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass2Widget::changePlFar)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject Ass2Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Ass2Widget.data,
      qt_meta_data_Ass2Widget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Ass2Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ass2Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Ass2Widget.stringdata0))
        return static_cast<void*>(const_cast< Ass2Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Ass2Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void Ass2Widget::changeFile(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Ass2Widget::changeFOV(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Ass2Widget::changePFar(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Ass2Widget::changeToPerspective()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Ass2Widget::changeToParallel()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Ass2Widget::changeOblScale(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Ass2Widget::changeOblAngle(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Ass2Widget::changePlTop(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Ass2Widget::changePlFar(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE

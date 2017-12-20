/****************************************************************************
** Meta object code from reading C++ file 'ass3widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Part3/ass3widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ass3widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ass3Widget_t {
    QByteArrayData data[66];
    char stringdata0[1227];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ass3Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ass3Widget_t qt_meta_stringdata_Ass3Widget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Ass3Widget"
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
QT_MOC_LITERAL(19, 184, 12), // "changeLightX"
QT_MOC_LITERAL(20, 197, 1), // "x"
QT_MOC_LITERAL(21, 199, 12), // "changeLightY"
QT_MOC_LITERAL(22, 212, 1), // "y"
QT_MOC_LITERAL(23, 214, 12), // "changeLightZ"
QT_MOC_LITERAL(24, 227, 1), // "z"
QT_MOC_LITERAL(25, 229, 12), // "changeLightR"
QT_MOC_LITERAL(26, 242, 1), // "r"
QT_MOC_LITERAL(27, 244, 12), // "changeLightG"
QT_MOC_LITERAL(28, 257, 1), // "g"
QT_MOC_LITERAL(29, 259, 12), // "changeLightB"
QT_MOC_LITERAL(30, 272, 1), // "b"
QT_MOC_LITERAL(31, 274, 23), // "on_btn_parallel_clicked"
QT_MOC_LITERAL(32, 298, 26), // "on_btn_perspective_clicked"
QT_MOC_LITERAL(33, 325, 24), // "on_spin_top_valueChanged"
QT_MOC_LITERAL(34, 350, 26), // "on_spin_plfar_valueChanged"
QT_MOC_LITERAL(35, 377, 5), // "plfar"
QT_MOC_LITERAL(36, 383, 29), // "on_spin_oblscale_valueChanged"
QT_MOC_LITERAL(37, 413, 29), // "on_spin_oblangle_valueChanged"
QT_MOC_LITERAL(38, 443, 24), // "on_spin_fov_valueChanged"
QT_MOC_LITERAL(39, 468, 26), // "on_spin_pefar_valueChanged"
QT_MOC_LITERAL(40, 495, 5), // "pefar"
QT_MOC_LITERAL(41, 501, 20), // "on_push_file_clicked"
QT_MOC_LITERAL(42, 522, 26), // "on_sb_light_x_valueChanged"
QT_MOC_LITERAL(43, 549, 26), // "on_sb_light_y_valueChanged"
QT_MOC_LITERAL(44, 576, 26), // "on_sb_light_z_valueChanged"
QT_MOC_LITERAL(45, 603, 32), // "on_sb_light_r_doubleValueChanged"
QT_MOC_LITERAL(46, 636, 1), // "v"
QT_MOC_LITERAL(47, 638, 32), // "on_sb_light_g_doubleValueChanged"
QT_MOC_LITERAL(48, 671, 32), // "on_sb_light_b_doubleValueChanged"
QT_MOC_LITERAL(49, 704, 34), // "on_sb_ambient_r_doubleValueCh..."
QT_MOC_LITERAL(50, 739, 34), // "on_sb_ambient_g_doubleValueCh..."
QT_MOC_LITERAL(51, 774, 34), // "on_sb_ambient_b_doubleValueCh..."
QT_MOC_LITERAL(52, 809, 36), // "on_sb_ambient_c_r_doubleValue..."
QT_MOC_LITERAL(53, 846, 36), // "on_sb_ambient_c_g_doubleValue..."
QT_MOC_LITERAL(54, 883, 36), // "on_sb_ambient_c_b_doubleValue..."
QT_MOC_LITERAL(55, 920, 34), // "on_sb_diffuse_r_doubleValueCh..."
QT_MOC_LITERAL(56, 955, 34), // "on_sb_diffuse_g_doubleValueCh..."
QT_MOC_LITERAL(57, 990, 34), // "on_sb_diffuse_b_doubleValueCh..."
QT_MOC_LITERAL(58, 1025, 35), // "on_sb_specular_r_doubleValueC..."
QT_MOC_LITERAL(59, 1061, 35), // "on_sb_specular_g_doubleValueC..."
QT_MOC_LITERAL(60, 1097, 35), // "on_sb_specular_b_doubleValueC..."
QT_MOC_LITERAL(61, 1133, 24), // "on_sb_phong_valueChanged"
QT_MOC_LITERAL(62, 1158, 5), // "phong"
QT_MOC_LITERAL(63, 1164, 27), // "on_push_texturefile_clicked"
QT_MOC_LITERAL(64, 1192, 26), // "on_cb_show_texture_toggled"
QT_MOC_LITERAL(65, 1219, 7) // "checked"

    },
    "Ass3Widget\0changeFile\0\0std::string\0"
    "filename\0changeFOV\0fov\0changePFar\0d\0"
    "changeToPerspective\0changeToParallel\0"
    "changeOblScale\0scale\0changeOblAngle\0"
    "angle\0changePlTop\0top\0changePlFar\0"
    "plFar\0changeLightX\0x\0changeLightY\0y\0"
    "changeLightZ\0z\0changeLightR\0r\0"
    "changeLightG\0g\0changeLightB\0b\0"
    "on_btn_parallel_clicked\0"
    "on_btn_perspective_clicked\0"
    "on_spin_top_valueChanged\0"
    "on_spin_plfar_valueChanged\0plfar\0"
    "on_spin_oblscale_valueChanged\0"
    "on_spin_oblangle_valueChanged\0"
    "on_spin_fov_valueChanged\0"
    "on_spin_pefar_valueChanged\0pefar\0"
    "on_push_file_clicked\0on_sb_light_x_valueChanged\0"
    "on_sb_light_y_valueChanged\0"
    "on_sb_light_z_valueChanged\0"
    "on_sb_light_r_doubleValueChanged\0v\0"
    "on_sb_light_g_doubleValueChanged\0"
    "on_sb_light_b_doubleValueChanged\0"
    "on_sb_ambient_r_doubleValueChanged\0"
    "on_sb_ambient_g_doubleValueChanged\0"
    "on_sb_ambient_b_doubleValueChanged\0"
    "on_sb_ambient_c_r_doubleValueChanged\0"
    "on_sb_ambient_c_g_doubleValueChanged\0"
    "on_sb_ambient_c_b_doubleValueChanged\0"
    "on_sb_diffuse_r_doubleValueChanged\0"
    "on_sb_diffuse_g_doubleValueChanged\0"
    "on_sb_diffuse_b_doubleValueChanged\0"
    "on_sb_specular_r_doubleValueChanged\0"
    "on_sb_specular_g_doubleValueChanged\0"
    "on_sb_specular_b_doubleValueChanged\0"
    "on_sb_phong_valueChanged\0phong\0"
    "on_push_texturefile_clicked\0"
    "on_cb_show_texture_toggled\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ass3Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      45,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  239,    2, 0x06 /* Public */,
       5,    1,  242,    2, 0x06 /* Public */,
       7,    1,  245,    2, 0x06 /* Public */,
       9,    0,  248,    2, 0x06 /* Public */,
      10,    0,  249,    2, 0x06 /* Public */,
      11,    1,  250,    2, 0x06 /* Public */,
      13,    1,  253,    2, 0x06 /* Public */,
      15,    1,  256,    2, 0x06 /* Public */,
      17,    1,  259,    2, 0x06 /* Public */,
      19,    1,  262,    2, 0x06 /* Public */,
      21,    1,  265,    2, 0x06 /* Public */,
      23,    1,  268,    2, 0x06 /* Public */,
      25,    1,  271,    2, 0x06 /* Public */,
      27,    1,  274,    2, 0x06 /* Public */,
      29,    1,  277,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      31,    0,  280,    2, 0x08 /* Private */,
      32,    0,  281,    2, 0x08 /* Private */,
      33,    1,  282,    2, 0x08 /* Private */,
      34,    1,  285,    2, 0x08 /* Private */,
      36,    1,  288,    2, 0x08 /* Private */,
      37,    1,  291,    2, 0x08 /* Private */,
      38,    1,  294,    2, 0x08 /* Private */,
      39,    1,  297,    2, 0x08 /* Private */,
      41,    0,  300,    2, 0x08 /* Private */,
      42,    1,  301,    2, 0x08 /* Private */,
      43,    1,  304,    2, 0x08 /* Private */,
      44,    1,  307,    2, 0x08 /* Private */,
      45,    1,  310,    2, 0x08 /* Private */,
      47,    1,  313,    2, 0x08 /* Private */,
      48,    1,  316,    2, 0x08 /* Private */,
      49,    1,  319,    2, 0x08 /* Private */,
      50,    1,  322,    2, 0x08 /* Private */,
      51,    1,  325,    2, 0x08 /* Private */,
      52,    1,  328,    2, 0x08 /* Private */,
      53,    1,  331,    2, 0x08 /* Private */,
      54,    1,  334,    2, 0x08 /* Private */,
      55,    1,  337,    2, 0x08 /* Private */,
      56,    1,  340,    2, 0x08 /* Private */,
      57,    1,  343,    2, 0x08 /* Private */,
      58,    1,  346,    2, 0x08 /* Private */,
      59,    1,  349,    2, 0x08 /* Private */,
      60,    1,  352,    2, 0x08 /* Private */,
      61,    1,  355,    2, 0x08 /* Private */,
      63,    0,  358,    2, 0x08 /* Private */,
      64,    1,  359,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Float,   20,
    QMetaType::Void, QMetaType::Float,   22,
    QMetaType::Void, QMetaType::Float,   24,
    QMetaType::Void, QMetaType::Double,   26,
    QMetaType::Void, QMetaType::Double,   28,
    QMetaType::Void, QMetaType::Double,   30,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,   40,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   20,
    QMetaType::Void, QMetaType::Double,   22,
    QMetaType::Void, QMetaType::Double,   24,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Int,   62,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   65,

       0        // eod
};

void Ass3Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ass3Widget *_t = static_cast<Ass3Widget *>(_o);
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
        case 9: _t->changeLightX((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 10: _t->changeLightY((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: _t->changeLightZ((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 12: _t->changeLightR((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->changeLightG((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->changeLightB((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->on_btn_parallel_clicked(); break;
        case 16: _t->on_btn_perspective_clicked(); break;
        case 17: _t->on_spin_top_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->on_spin_plfar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_spin_oblscale_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->on_spin_oblangle_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 21: _t->on_spin_fov_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_spin_pefar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_push_file_clicked(); break;
        case 24: _t->on_sb_light_x_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->on_sb_light_y_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: _t->on_sb_light_z_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 27: _t->on_sb_light_r_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 28: _t->on_sb_light_g_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: _t->on_sb_light_b_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 30: _t->on_sb_ambient_r_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->on_sb_ambient_g_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 32: _t->on_sb_ambient_b_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 33: _t->on_sb_ambient_c_r_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 34: _t->on_sb_ambient_c_g_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 35: _t->on_sb_ambient_c_b_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 36: _t->on_sb_diffuse_r_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 37: _t->on_sb_diffuse_g_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 38: _t->on_sb_diffuse_b_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 39: _t->on_sb_specular_r_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 40: _t->on_sb_specular_g_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 41: _t->on_sb_specular_b_doubleValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 42: _t->on_sb_phong_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->on_push_texturefile_clicked(); break;
        case 44: _t->on_cb_show_texture_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Ass3Widget::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeFile)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeFOV)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changePFar)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeToPerspective)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeToParallel)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeOblScale)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeOblAngle)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changePlTop)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changePlFar)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeLightX)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeLightY)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeLightZ)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeLightR)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeLightG)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (Ass3Widget::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ass3Widget::changeLightB)) {
                *result = 14;
                return;
            }
        }
    }
}

const QMetaObject Ass3Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Ass3Widget.data,
      qt_meta_data_Ass3Widget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Ass3Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ass3Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Ass3Widget.stringdata0))
        return static_cast<void*>(const_cast< Ass3Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Ass3Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 45)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 45;
    }
    return _id;
}

// SIGNAL 0
void Ass3Widget::changeFile(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Ass3Widget::changeFOV(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Ass3Widget::changePFar(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Ass3Widget::changeToPerspective()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Ass3Widget::changeToParallel()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Ass3Widget::changeOblScale(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Ass3Widget::changeOblAngle(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Ass3Widget::changePlTop(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Ass3Widget::changePlFar(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Ass3Widget::changeLightX(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Ass3Widget::changeLightY(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Ass3Widget::changeLightZ(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Ass3Widget::changeLightR(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Ass3Widget::changeLightG(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Ass3Widget::changeLightB(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_END_MOC_NAMESPACE

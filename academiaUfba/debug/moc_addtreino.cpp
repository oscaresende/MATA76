/****************************************************************************
** Meta object code from reading C++ file 'addtreino.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../addtreino.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addtreino.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_addTreino_t {
    QByteArrayData data[7];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addTreino_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addTreino_t qt_meta_stringdata_addTreino = {
    {
QT_MOC_LITERAL(0, 0, 9), // "addTreino"
QT_MOC_LITERAL(1, 10, 8), // "cancelar"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 28), // "carregarTableViewDisponiveis"
QT_MOC_LITERAL(4, 49, 23), // "carregarTableViewUsados"
QT_MOC_LITERAL(5, 73, 19), // "adicionar_exercicio"
QT_MOC_LITERAL(6, 93, 17) // "remover_exercicio"

    },
    "addTreino\0cancelar\0\0carregarTableViewDisponiveis\0"
    "carregarTableViewUsados\0adicionar_exercicio\0"
    "remover_exercicio"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addTreino[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void addTreino::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        addTreino *_t = static_cast<addTreino *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cancelar(); break;
        case 1: _t->carregarTableViewDisponiveis(); break;
        case 2: _t->carregarTableViewUsados(); break;
        case 3: _t->adicionar_exercicio(); break;
        case 4: _t->remover_exercicio(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject addTreino::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_addTreino.data,
      qt_meta_data_addTreino,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *addTreino::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addTreino::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_addTreino.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int addTreino::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

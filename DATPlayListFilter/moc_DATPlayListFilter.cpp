/****************************************************************************
** Meta object code from reading C++ file 'DATPlayListFilter.h'
**
** Created: Mon Jun 15 16:52:22 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "DATPlayListFilter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DATPlayListFilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DATPlayListFilter[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   18,   19,   18, 0x0a,
      50,   18,   19,   18, 0x0a,
      72,   18,   19,   18, 0x0a,
     100,   18,   19,   18, 0x0a,
     127,   18,   19,   18, 0x0a,
     155,   18,   19,   18, 0x0a,
     184,   18,   19,   18, 0x0a,
     212,   18,   19,   18, 0x0a,
     236,   18,   19,   18, 0x0a,
     258,   18,   19,   18, 0x0a,
     282,   18,   19,   18, 0x0a,
     309,   18,   19,   18, 0x0a,
     340,   18,   19,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DATPlayListFilter[] = {
    "DATPlayListFilter\0\0tResult\0"
    "on_btn_login_clicked()\0on_chk_date_clicked()\0"
    "on_chk_eyeq_event_clicked()\0"
    "on_chk_fcm_event_clicked()\0"
    "on_chk_user_event_clicked()\0"
    "on_chk_radar_event_clicked()\0"
    "on_chk_annotation_clicked()\0"
    "on_chk_search_clicked()\0on_dateEdit_changed()\0"
    "on_dateEdit_2_changed()\0"
    "on_btn_change_pw_clicked()\0"
    "on_btn_change_cancel_clicked()\0"
    "on_btn_change_clicked()\0"
};

const QMetaObject DATPlayListFilter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DATPlayListFilter,
      qt_meta_data_DATPlayListFilter, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DATPlayListFilter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DATPlayListFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DATPlayListFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DATPlayListFilter))
        return static_cast<void*>(const_cast< DATPlayListFilter*>(this));
    if (!strcmp(_clname, "cBaseQtFilter"))
        return static_cast< cBaseQtFilter*>(const_cast< DATPlayListFilter*>(this));
    return QObject::qt_metacast(_clname);
}

int DATPlayListFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { tResult _r = on_btn_login_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 1: { tResult _r = on_chk_date_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 2: { tResult _r = on_chk_eyeq_event_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 3: { tResult _r = on_chk_fcm_event_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 4: { tResult _r = on_chk_user_event_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 5: { tResult _r = on_chk_radar_event_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 6: { tResult _r = on_chk_annotation_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 7: { tResult _r = on_chk_search_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 8: { tResult _r = on_dateEdit_changed();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 9: { tResult _r = on_dateEdit_2_changed();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 10: { tResult _r = on_btn_change_pw_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 11: { tResult _r = on_btn_change_cancel_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 12: { tResult _r = on_btn_change_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

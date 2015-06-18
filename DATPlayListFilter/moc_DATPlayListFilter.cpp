/****************************************************************************
** Meta object code from reading C++ file 'DATPlayListFilter.h'
**
** Created: Wed Jun 17 22:39:12 2015
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
      40,   14, // methods
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
     196,  184,   19,   18, 0x0a,
     226,   18,   19,   18, 0x0a,
     254,   18,   19,   18, 0x0a,
     278,   18,   19,   18, 0x0a,
     298,   18,   19,   18, 0x0a,
     320,   18,   19,   18, 0x0a,
     344,   18,   19,   18, 0x0a,
     351,   18,   18,   18, 0x0a,
     376,   18,   19,   18, 0x0a,
     403,   18,   19,   18, 0x0a,
     434,   18,   19,   18, 0x0a,
     456,   18,   19,   18, 0x0a,
     480,   18,   19,   18, 0x0a,
     497,   18,   19,   18, 0x0a,
     516,   18,   19,   18, 0x0a,
     533,   18,   19,   18, 0x0a,
     552,   18,   19,   18, 0x0a,
     565,   18,   19,   18, 0x0a,
     580,   18,   19,   18, 0x0a,
     600,   18,   19,   18, 0x0a,
     618,   18,   19,   18, 0x0a,
     638,   18,   19,   18, 0x0a,
     660,   18,   19,   18, 0x0a,
     684,   18,   19,   18, 0x0a,
     703,   18,   19,   18, 0x0a,
     724,   18,   19,   18, 0x0a,
     746,   18,   19,   18, 0x0a,
     770,   18,   19,   18, 0x0a,
     785,   18,   19,   18, 0x0a,
     802,   18,   19,   18, 0x0a,
     822,   18,   19,   18, 0x0a,
     844,   18,   19,   18, 0x0a,
     856,   18,   19,   18, 0x0a,
     870,   18,   19,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DATPlayListFilter[] = {
    "DATPlayListFilter\0\0tResult\0"
    "on_btn_login_clicked()\0on_chk_date_clicked()\0"
    "on_chk_eyeq_event_clicked()\0"
    "on_chk_fcm_event_clicked()\0"
    "on_chk_user_event_clicked()\0"
    "on_chk_radar_event_clicked()\0search_text\0"
    "on_txt_search_edited(QString)\0"
    "on_chk_annotation_clicked()\0"
    "on_chk_search_clicked()\0on_chk_ai_clicked()\0"
    "on_dateEdit_changed()\0on_dateEdit_2_changed()\0"
    "make()\0initWorkspaceDirectory()\0"
    "on_btn_change_pw_clicked()\0"
    "on_btn_change_cancel_clicked()\0"
    "on_btn_clip_clicked()\0on_btn_change_clicked()\0"
    "project_select()\0project_deselect()\0"
    "feature_select()\0feature_deselect()\0"
    "vin_select()\0vin_deselect()\0"
    "ai_value_deselect()\0day_type_select()\0"
    "day_type_deselect()\0weather_type_select()\0"
    "weather_type_deselect()\0road_type_select()\0"
    "road_type_deselect()\0event_status_select()\0"
    "event_status_deselect()\0event_select()\0"
    "event_deselect()\0annotation_select()\0"
    "annotation_deselect()\0ai_select()\0"
    "ai_deselect()\0ai_value_select()\0"
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
        case 6: { tResult _r = on_txt_search_edited((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 7: { tResult _r = on_chk_annotation_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 8: { tResult _r = on_chk_search_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 9: { tResult _r = on_chk_ai_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 10: { tResult _r = on_dateEdit_changed();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 11: { tResult _r = on_dateEdit_2_changed();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 12: { tResult _r = make();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 13: initWorkspaceDirectory(); break;
        case 14: { tResult _r = on_btn_change_pw_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 15: { tResult _r = on_btn_change_cancel_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 16: { tResult _r = on_btn_clip_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 17: { tResult _r = on_btn_change_clicked();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 18: { tResult _r = project_select();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 19: { tResult _r = project_deselect();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 20: { tResult _r = feature_select();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 21: { tResult _r = feature_deselect();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 22: { tResult _r = vin_select();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 23: { tResult _r = vin_deselect();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 24: { tResult _r = ai_value_deselect();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 25: { tResult _r = day_type_select();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 26: { tResult _r = day_type_deselect();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 27: { tResult _r = weather_type_select();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 28: { tResult _r = weather_type_deselect();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 29: { tResult _r = road_type_select();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 30: { tResult _r = road_type_deselect();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 31: { tResult _r = event_status_select();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 32: { tResult _r = event_status_deselect();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 33: { tResult _r = event_select();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 34: { tResult _r = event_deselect();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 35: { tResult _r = annotation_select();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 36: { tResult _r = annotation_deselect();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 37: { tResult _r = ai_select();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 38: { tResult _r = ai_deselect();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        case 39: { tResult _r = ai_value_select();
            if (_a[0]) *reinterpret_cast< tResult*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 40;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

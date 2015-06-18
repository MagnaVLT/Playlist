/*****************************************************************************
 *     ADTF Template Project Filter (header)
 *****************************************************************************
 *  
 *	@file
 *	Copyright &copy; Magna Electronics in Auburn Hills. All rights reserved
 *	
 *	$Author: Sangsig Kim (E37039) $ 
 *	$MAGNA Electronics$
 *	$Date: 2014/08/10 01:59:28EDT $
 *	$Revision: 0 $
 *
 *	@remarks
 *
 ******************************************************************************/
#ifndef _HIL_DATPlayListFilter_H_
#define _HIL_DATPlayListFilter_H_

#define OID_ADTF_HIL_DATPlayListFilter "adtf.hil.DATPlayListFilter"

#include "ui_GUIFrontEnd.h"
#include "Queries.h"
#include "DB/Retriever.h"
#include "DB/Updator.h"
#include "Queries.h"
#include "UI/ListHandle.h"
#include "Utils/Utilities.h"
#include <QtCore/QDate>
#include <QtGui/QApplication>
#include <QtGui/QProgressDialog>

class DATPlayListFilter : public QObject, public cBaseQtFilter
{
	Q_OBJECT
	ADTF_DECLARE_FILTER_VERSION(OID_ADTF_HIL_DATPlayListFilter, 
		"DATPlayListFilter", 
		OBJCAT_Generic, 
		"Magna_Electrocnis_Specified", 
		MAGNA_VERSION_ID, 
		MAGNA_VERSION_MAIN, 
		MAGNA_VERSION_MINOR, 
		"DATPlayListFilter")

protected:


private:


public:
	static string ID;
    /** 
		*	Class constructor for databaseFilter
		*	@param string for info.
		*
	*/
	QWidget*				m_pFilterWidget;
	Ui_Form		m_oFilterGUI;			// defined in ui_GUIFrontEnd.h

	DATPlayListFilter(const tChar* __info);
	/** 
		*	Class destructor for databaseFilter 
	*/
    virtual ~DATPlayListFilter();

	tHandle	CreateView();
    tResult	ReleaseView();

protected:
	/** 
		* The method is inherited from base class, which initializes all the input pin and output pin.
		* @param [in] eStage The current state of the state machine during initialization.
		* @param [in,out] __exception   An Exception pointer where exceptions will be put when failed.
		* @return   Returns a standard result code.
	*/
    tResult Init(tInitStage eStage, __exception);
	/**
		* The function is called automatically by ADTF. It contains the start routine.
		* The method is inherited from base class.
		* @param [in,out] __exception   An Exception pointer where exceptions will be put when failed.
		* @return   Returns a standard result code.
	*/
	tResult Start(__exception = NULL);
	/**
		* The function is called automatically by ADTF. It contains the stop routine.
		* The method is inherited from base class.
		* @param [in,out] __exception   An Exception pointer where exceptions will be put when failed.
		* @return   Returns a standard result code.
	*/
	tResult Stop(__exception = NULL);
	/**
		* The function is called automatically by ADTF. It contains the shutdown routine.
		* The method is inherited from base class.
		* @param  [in] eStage The current state of the state machine during shutdown
		* @param [in,out] __exception   An Exception pointer where exceptions will be put when failed.
		* @return   Returns a standard result code.
	*/
    tResult Shutdown(tInitStage eStage, __exception);

    /**
		* The function is called automatically by ADTF. It is called if media sample is received.
		* The method is inherited from base class, overwrites cBaseQtFilter and implements IPinEventSink.
		* @param [in] pSource Pointer to the sending pin's IPin interface.
		* @param [in] nEventCode Event code. For allowed values see @ref IPinEventSink::tPinEventCode
		* @param [in] nParam1 Optional integer parameter.
		* @param [in] nParam2 Optional integer parameter.
		* @param [in] pMediaSample Address of an IMediaSample interface pointers.
		* @return   Returns a standard result code.
	*/
    tResult OnPinEvent(IPin* pSource, tInt nEventCode, tInt nParam1, tInt nParam2, IMediaSample* pMediaSample);

	/**
		* The function is called to set the component in running state. 
		* @param [in] nActivationCode The activation type for running.
		* @param [in] pvUserData pointer to a activation structure depending on the activation type. 
		* @param [in] szUserDatasize Size of the activation structure. (in byte)
		* @param [inout] __exception_ptr Address of variable that points to an IException interface. If not using the cException smart pointer, the interface has to be released by calling Unref()...
		* @return   Returns a standard result code.

	*/
	tResult	Run(tInt nActivationCode, const tVoid* pvUserData, tInt szUserDataSize, ucom::IException** __exception_ptr=NULL);
	
private:
	Queries *queries;

	vector<string> event_categories;
	vector<string> date_ranges;

	vector<string> projects;
	vector<string> features;
	vector<string> vins;

	vector<string> events;
	vector<string> annotations;
	vector<string> ai_type;
	vector<string> ai_value;

	vector<string> days;
	vector<string> weathers;
	vector<string> roads;
	vector<string> event_statuses;

	vector<string> clip_list;
	
	string search_condition;
	bool is_all_date;
	


	ListHandle* listhandle;
	QStandardItemModel* project_model;
	QStandardItemModel* selected_project_model;

	QStandardItemModel* vin_model;
	QStandardItemModel* selected_vin_model;

	QStandardItemModel* feature_model;
	QStandardItemModel* selected_feature_model;

	QStandardItemModel* day_type_model;
	QStandardItemModel* selected_day_type_model;

	QStandardItemModel* weather_type_model;
	QStandardItemModel* selected_weather_type_model;

	QStandardItemModel* road_type_model;
	QStandardItemModel* selected_road_type_model;

	QStandardItemModel* event_model;
	QStandardItemModel* selected_event_model;

	QStandardItemModel* annotation_model;
	QStandardItemModel* selected_annotation_model;

	QStandardItemModel* ai_model;
	QStandardItemModel* selected_ai_model;

	QStandardItemModel* ai_value_model;
	QStandardItemModel* selected_ai_value_model;

	QStandardItemModel* event_status_model;
	QStandardItemModel* selected_event_status_model;
	QStandardItemModel* clip_list_model;

	void register_signal_slot();
	void register_signal_slot_for_log_in();
	void initAll();
	void initAllModel();

	void init_level0();
	void init_level1();
	void init_level2();
	void init_level3();
	void init_level4();

	void refeash_level_1();
	void refreash_feature();
	void refreash_vin();

	void refeash_level_2();
	void refreash_event();
	bool is_level0_not_full();
	bool is_level1_not_full();
	bool is_level2_not_full();
	bool is_level3_not_full();
	void refreash_annotation();
	void refreash_ai_type();
	void refreash_ai_value();

	void refeash_level_3();
	void refreash_day();
	void refreash_weather();
	void refreash_road();
	void refreash_event_status();

	void refeash_level_4();
	void refreash_clip_list();

	void to_log_in_mode(bool mode);
	void to_search_mode(bool mode);
	void toAnnotationCategoryMode(bool mode);
	void to_ai_mode(bool mode);
	void to_date_mode(bool mode);
	bool checkAuth(string id, string pass);
	void init_project_list();

	string get_date(QDateEdit* edit, string comp);
	void set_data();

public slots:
	tResult on_btn_login_clicked();
	tResult on_chk_date_clicked();
	tResult on_chk_eyeq_event_clicked();
	tResult on_chk_fcm_event_clicked();
	tResult on_chk_user_event_clicked();
	tResult on_chk_radar_event_clicked();
	tResult on_txt_search_edited(const QString &search_text);
	tResult on_chk_annotation_clicked();
	tResult on_chk_search_clicked();
	tResult on_chk_ai_clicked();
	tResult on_dateEdit_changed();
	tResult on_dateEdit_2_changed();
	tResult make();
	void initWorkspaceDirectory();
	tResult on_btn_change_pw_clicked();
	tResult on_btn_change_cancel_clicked();
	tResult on_btn_clip_clicked();
	tResult on_btn_change_clicked();
	tResult project_select();
	tResult project_deselect();
	tResult feature_select();
	tResult feature_deselect();
	tResult vin_select();
	tResult vin_deselect();

	tResult ai_value_deselect();
	tResult day_type_select();
	tResult day_type_deselect();
	tResult weather_type_select();
	tResult weather_type_deselect();
	tResult road_type_select();
	tResult road_type_deselect();
	tResult event_status_select();
	tResult event_status_deselect();
	tResult event_select();
	tResult event_deselect();
	tResult annotation_select();
	tResult annotation_deselect();
	tResult ai_select();
	tResult ai_deselect();
	tResult ai_value_select();
};

#endif
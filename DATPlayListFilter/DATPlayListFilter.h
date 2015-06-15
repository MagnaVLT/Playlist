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

	void register_signal_slot();
	void register_signal_slot_for_log_in();
	void initAll();
	void initAllModel();
	void init_project_list();
	void init_vin_list();
	void init_feature_list();
	void init_day_type_list();
	void init_weather_type_list();
	void init_road_type_list();
	void init_event_list();
	void init_predefined_annotation_list();
	void init_additional_information_list();
	void init_event_status_list();
	void refeash_level_1();
	void refeash_level_2();
	void refeash_level_3();
	void refeash_level_4();
	void to_log_in_mode(bool mode);
	bool checkAuth(string id, string pass);

public slots:
	tResult on_btn_login_clicked();
	tResult on_chk_date_clicked();
	tResult on_chk_eyeq_event_clicked();
	tResult on_chk_fcm_event_clicked();
	tResult on_chk_user_event_clicked();
	tResult on_chk_radar_event_clicked();
	tResult on_chk_annotation_clicked();
	tResult on_chk_search_clicked();
	tResult on_dateEdit_changed();
	tResult on_dateEdit_2_changed();
	tResult on_btn_change_pw_clicked();
	tResult on_btn_change_cancel_clicked();
	tResult on_btn_change_clicked();
};

#endif
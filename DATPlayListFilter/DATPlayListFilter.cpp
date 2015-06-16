/*****************************************************************************
 *     ADTF Template Project Filter
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


#include "stdafx.h"
#include "DATPlayListFilter.h"

ADTF_FILTER_PLUGIN("DATPlayListFilter", OID_ADTF_HIL_DATPlayListFilter, DATPlayListFilter);

string DATPlayListFilter::ID = "";

DATPlayListFilter::DATPlayListFilter(const tChar* __info):cBaseQtFilter(__info)
{
}

DATPlayListFilter::~DATPlayListFilter()
{
}

tResult DATPlayListFilter::Init(tInitStage eStage, __exception)
{
    RETURN_IF_FAILED(cBaseQtFilter::Init(eStage, __exception_ptr))
    
    if (eStage == StageFirst)
    {
	}
	else if (eStage == StageNormal)
    {
    }
    else if (eStage == StageGraphReady)
    {
    }

    RETURN_NOERROR;
}

tResult DATPlayListFilter::Start(__exception)
{
	return cBaseQtFilter::Start(__exception_ptr);		// TODO	RETURN_IF_FAILED generates a warning [created on 07/02/2014]
}

tResult DATPlayListFilter::Stop(__exception)
{
    return cBaseQtFilter::Stop(__exception_ptr);
}

tResult DATPlayListFilter::Shutdown(tInitStage eStage, __exception)
{

    if (eStage == StageGraphReady)
    {
    }
    else if (eStage == StageNormal)
    {
    }
    else if (eStage == StageFirst)
    {
    }

    return cBaseQtFilter::Shutdown(eStage, __exception_ptr);
}

tResult DATPlayListFilter::OnPinEvent(IPin *pSource, tInt nEventCode, tInt nParam1, tInt nParam2, IMediaSample *pMediaSample)
{
	RETURN_NOERROR;
}

tResult DATPlayListFilter::Run(tInt nActivationCode, const tVoid* pvUserData, tInt szUserDataSize, ucom::IException** __exception_ptr/* =NULL */)
{
	return cBaseQtFilter::Run(nActivationCode, pvUserData, szUserDataSize, __exception_ptr);
}












tHandle DATPlayListFilter::CreateView()
{
	m_pFilterWidget = new QWidget();
    m_oFilterGUI.setupUi(m_pFilterWidget);
	queries = new Queries();
	this->m_oFilterGUI.grp_pwchange->setVisible(false);
	this->to_log_in_mode(true);
	this->register_signal_slot_for_log_in();

	return (tHandle)m_pFilterWidget;
}

void DATPlayListFilter::initAll()
{
	this->register_signal_slot();
	this->initAllModel();
	
}

void DATPlayListFilter::initAllModel()
{
	this->init_level0();
	this->init_level1();
	this->init_level2();
	this->init_level3();
	this->init_level4();
}
void DATPlayListFilter::init_level0()
{
	this->m_oFilterGUI.chk_fcm_event->setChecked(false);
	this->m_oFilterGUI.chk_eyeq_event->setChecked(false);
	this->m_oFilterGUI.chk_user_event->setChecked(false);
	this->m_oFilterGUI.chk_radar->setChecked(false);
	this->m_oFilterGUI.chk_date->setChecked(true);
}

void DATPlayListFilter::init_level1()
{
	project_model = new QStandardItemModel();
	selected_project_model = new QStandardItemModel();
	this->m_oFilterGUI.list_project->setModel(this->project_model);
	this->m_oFilterGUI.list_selected_project->setModel(this->selected_project_model);
	feature_model = new QStandardItemModel();
	selected_feature_model = new QStandardItemModel();
	this->m_oFilterGUI.list_feature->setModel(this->feature_model);
	this->m_oFilterGUI.list_selected_feature->setModel(this->selected_feature_model);

	vin_model = new QStandardItemModel();
	selected_vin_model = new QStandardItemModel();
	this->m_oFilterGUI.list_vin->setModel(this->vin_model);
	this->m_oFilterGUI.list_selected_vin->setModel(this->selected_vin_model);

	init_project_list();

}

void DATPlayListFilter::init_level2()
{
	event_model = new QStandardItemModel();
	selected_event_model = new QStandardItemModel();
	
	this->m_oFilterGUI.list_event->setModel(this->event_model);
	this->m_oFilterGUI.list_selected_event->setModel(this->selected_event_model);
	
	annotation_model = new QStandardItemModel();
	selected_annotation_model = new QStandardItemModel();
	this->m_oFilterGUI.list_annotation->setModel(this->annotation_model);
	this->m_oFilterGUI.list_selected_annotation->setModel(this->selected_annotation_model);


}

void DATPlayListFilter::init_level3()
{
	day_type_model = new QStandardItemModel();
	selected_day_type_model = new QStandardItemModel();
	weather_type_model = new QStandardItemModel();
	selected_weather_type_model = new QStandardItemModel();
	road_type_model = new QStandardItemModel();
	selected_road_type_model = new QStandardItemModel();
	event_status_model = new QStandardItemModel();
	selected_event_status_model = new QStandardItemModel();

	this->m_oFilterGUI.list_day->setModel(this->day_type_model);
	this->m_oFilterGUI.list_selected_day->setModel(this->selected_day_type_model);
	this->m_oFilterGUI.list_weather->setModel(this->weather_type_model);
	this->m_oFilterGUI.list_selected_weather->setModel(this->selected_weather_type_model);
	this->m_oFilterGUI.list_road->setModel(this->road_type_model);
	this->m_oFilterGUI.list_selected_road->setModel(this->selected_road_type_model);
	this->m_oFilterGUI.list_event_status->setModel(this->event_status_model);
	this->m_oFilterGUI.list_selected_event_status->setModel(this->selected_event_status_model);

}


void DATPlayListFilter::init_level4()
{
	clip_list_model = new QStandardItemModel();
	this->m_oFilterGUI.list_clip_list->setModel(this->clip_list_model);
}

void DATPlayListFilter::init_project_list()
{
	this->selected_project_model = new QStandardItemModel();
	this->m_oFilterGUI.list_selected_project->setModel(this->selected_project_model);
	string query =	queries->get_project_list(ID);
	project_model = new QStandardItemModel();
	this->listhandle->addItemsFromDB(m_oFilterGUI.list_project, project_model, queries->get_fields_name_id(), query);
}

void DATPlayListFilter::refeash_level_1()
{
	this->refreash_vin();
	this->refreash_feature();
}

void DATPlayListFilter::refreash_feature()
{
	this->refreash_vin();
}

void DATPlayListFilter::refreash_vin()
{
}

void DATPlayListFilter::refeash_level_2()
{
	this->refreash_event();
	this->refreash_annotation();
	this->refreash_additional_information();

}

void DATPlayListFilter::refreash_event()
{

}

void DATPlayListFilter::refreash_annotation()
{

}

void DATPlayListFilter::refreash_additional_information()
{

}

void DATPlayListFilter::refeash_level_3()
{
	this->refreash_day();
	this->refreash_weather();
	this->refreash_road();
	this->refreash_event_status();
}


void DATPlayListFilter::refreash_day()
{

}

void DATPlayListFilter::refreash_weather()
{
	
}

void DATPlayListFilter::refreash_road()
{

}

void DATPlayListFilter::refreash_event_status()
{

}

void DATPlayListFilter::refeash_level_4()
{
	this->refreash_clip_list();
}

void DATPlayListFilter::refreash_clip_list(){

}

void DATPlayListFilter::set_data()
{

	if(this->m_oFilterGUI.chk_fcm_event->isChecked()==true) event_categories.push_back("1");
	if(this->m_oFilterGUI.chk_eyeq_event->isChecked()==true) event_categories.push_back("2");
	if(this->m_oFilterGUI.chk_user_event->isChecked()==true) event_categories.push_back("3");
	if(this->m_oFilterGUI.chk_radar->isChecked()==true) event_categories.push_back("4");

	if(!this->m_oFilterGUI.chk_date->isChecked())
	{
		date_ranges.push_back(this->get_date(this->m_oFilterGUI.dateEdit, "-"));
		date_ranges.push_back(this->get_date(this->m_oFilterGUI.dateEdit_2, "-"));
	}

	projects = this->listhandle->getSelectedItemTextList(this->m_oFilterGUI.list_selected_project, 1);
	features = this->listhandle->getSelectedItemTextList(this->m_oFilterGUI.list_selected_feature, 1);
	vins = this->listhandle->getSelectedItemTextList(this->m_oFilterGUI.list_selected_vin, 1);

	events = this->listhandle->getSelectedItemTextList(this->m_oFilterGUI.list_selected_event, 1);
	annotations = this->listhandle->getSelectedItemTextList(this->m_oFilterGUI.list_selected_annotation, 1);
	additional_informations = this->listhandle->getSelectedItemTextList(this->m_oFilterGUI.list_selected_ai, 1);

	days = this->listhandle->getSelectedItemTextList(this->m_oFilterGUI.list_selected_day, 1);
	weathers = this->listhandle->getSelectedItemTextList(this->m_oFilterGUI.list_selected_weather, 1);
	roads = this->listhandle->getSelectedItemTextList(this->m_oFilterGUI.list_selected_road, 1);
	event_statuses = this->listhandle->getSelectedItemTextList(this->m_oFilterGUI.list_selected_event_status, 1);

}





void DATPlayListFilter::register_signal_slot_for_log_in()
{
	connect(m_oFilterGUI.txt_loginpw, SIGNAL(returnPressed()),m_oFilterGUI.btn_login,SIGNAL(clicked()));
	connect(m_oFilterGUI.txt_change_pw2, SIGNAL(returnPressed()),m_oFilterGUI.btn_change,SIGNAL(clicked()));
	connect(m_oFilterGUI.btn_login, SIGNAL(clicked()), this, SLOT(on_btn_login_clicked()));
	connect(m_oFilterGUI.btn_change_pw, SIGNAL(clicked()), this, SLOT(on_btn_change_pw_clicked()));
	connect(m_oFilterGUI.btn_change_cancel, SIGNAL(clicked()), this, SLOT(on_btn_change_cancel_clicked()));
	connect(m_oFilterGUI.btn_change, SIGNAL(clicked()), this, SLOT(on_btn_change_clicked()));
}

tResult DATPlayListFilter::on_chk_date_clicked()
{

	RETURN_NOERROR;
}

tResult DATPlayListFilter::on_chk_eyeq_event_clicked()
{

	RETURN_NOERROR;
}

tResult DATPlayListFilter::on_chk_fcm_event_clicked()
{

	RETURN_NOERROR;
}

tResult DATPlayListFilter::on_chk_user_event_clicked()
{

	RETURN_NOERROR;
}

tResult DATPlayListFilter::on_chk_radar_event_clicked()
{

	RETURN_NOERROR;
}

tResult DATPlayListFilter::on_chk_annotation_clicked()
{

	RETURN_NOERROR;
}

tResult DATPlayListFilter::on_chk_search_clicked()
{

	RETURN_NOERROR;
}

tResult DATPlayListFilter::on_dateEdit_changed()
{

	RETURN_NOERROR;
}

tResult DATPlayListFilter::project_select()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_project, this->project_model, m_oFilterGUI.list_selected_project, this->selected_project_model);
	this->set_data();
	this->refeash_level_1();
	this->refeash_level_2();
	this->refeash_level_3();
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::project_deselect()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_selected_project, this->selected_project_model, m_oFilterGUI.list_project, this->project_model);
	this->set_data();
	this->refeash_level_1();
	this->refeash_level_2();
	this->refeash_level_3();
	this->refeash_level_4();

	RETURN_NOERROR;
}

tResult DATPlayListFilter::feature_select()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_feature, this->feature_model, m_oFilterGUI.list_selected_feature, this->selected_feature_model);
	this->set_data();
	this->refeash_level_1();
	this->refeash_level_2();
	this->refeash_level_3();
	this->refeash_level_4();

	RETURN_NOERROR;
}

tResult DATPlayListFilter::feature_deselect()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_selected_feature, this->selected_feature_model, m_oFilterGUI.list_feature, this->feature_model);
	this->set_data();
	this->refeash_level_1();
	this->refeash_level_2();
	this->refeash_level_3();
	this->refeash_level_4();

	RETURN_NOERROR;
}
tResult DATPlayListFilter::vin_select()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_vin, this->vin_model, m_oFilterGUI.list_selected_vin, this->selected_vin_model);
	this->refeash_level_1();
	this->refeash_level_2();
	this->refeash_level_3();
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::vin_deselect()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_selected_vin, this->selected_vin_model, m_oFilterGUI.list_vin, this->vin_model);
	this->refeash_level_1();
	this->refeash_level_2();
	this->refeash_level_3();
	this->refeash_level_4();
	RETURN_NOERROR;
}


tResult DATPlayListFilter::day_type_select()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_day, this->day_type_model, m_oFilterGUI.list_selected_day, this->selected_day_type_model);
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::day_type_deselect()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_selected_day, this->selected_day_type_model, m_oFilterGUI.list_day, this->day_type_model);
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::weather_type_select()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_weather, this->weather_type_model, m_oFilterGUI.list_selected_weather, this->selected_weather_type_model);
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::weather_type_deselect()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_selected_weather, this->selected_weather_type_model, m_oFilterGUI.list_weather, this->weather_type_model);
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::road_type_select()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_road, this->road_type_model, m_oFilterGUI.list_selected_road, this->selected_road_type_model);
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::road_type_deselect()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_selected_road, this->selected_road_type_model, m_oFilterGUI.list_road, this->road_type_model);
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::event_status_select()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_event_status, this->event_status_model, m_oFilterGUI.list_selected_event_status, this->selected_event_status_model);
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::event_status_deselect()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_selected_event_status, this->selected_event_status_model, m_oFilterGUI.list_event_status, this->event_status_model);
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::event_select()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_event, this->event_model, m_oFilterGUI.list_selected_event, this->selected_event_model);
	this->refeash_level_3();
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::event_deselect()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_selected_event, this->selected_event_model, m_oFilterGUI.list_event, this->event_model);
	this->refeash_level_3();
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::annotation_select()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_annotation, this->annotation_model, m_oFilterGUI.list_selected_annotation, this->selected_annotation_model);
	this->refeash_level_3();
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::annotation_deselect()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_selected_annotation, this->selected_annotation_model, m_oFilterGUI.list_annotation, this->annotation_model);
	this->refeash_level_3();
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::ai_select()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_ai, this->additional_information_model, m_oFilterGUI.list_selected_ai, this->selected_additional_information_model);
	this->refeash_level_3();
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::ai_deselect()
{
	this->listhandle->moveSelectedItemWithDelete(m_oFilterGUI.list_selected_ai, this->selected_additional_information_model, m_oFilterGUI.list_ai, this->additional_information_model);
	this->refeash_level_3();
	this->refeash_level_4();
	RETURN_NOERROR;
}

tResult DATPlayListFilter::on_dateEdit_2_changed()
{

	RETURN_NOERROR;
}


tResult DATPlayListFilter::on_btn_change_pw_clicked(){
	this->m_oFilterGUI.grp_pwchange->setVisible(true);
	this->m_oFilterGUI.txt_cur_pw->setEchoMode(QLineEdit::Password);
	this->m_oFilterGUI.txt_change_pw->setEchoMode(QLineEdit::Password);
	this->m_oFilterGUI.txt_change_pw2->setEchoMode(QLineEdit::Password);
	this->m_oFilterGUI.txt_change_id->setFocus(Qt::MouseFocusReason);
	RETURN_NOERROR;
}

tResult DATPlayListFilter::on_btn_change_cancel_clicked(){
	this->m_oFilterGUI.txt_cur_pw->setText(QString(""));
	this->m_oFilterGUI.txt_change_pw->setText(QString(""));
	this->m_oFilterGUI.txt_change_pw2->setText(QString(""));
	this->m_oFilterGUI.txt_change_id->setText(QString(""));
	this->m_oFilterGUI.grp_pwchange->setVisible(false);
	RETURN_NOERROR;
}


tResult DATPlayListFilter::on_btn_change_clicked(){

	string userid = this->m_oFilterGUI.txt_change_id->text().toStdString();
	string password = this->m_oFilterGUI.txt_cur_pw->text().toStdString();
	string p1 = this->m_oFilterGUI.txt_change_pw->text().toStdString();
	string p2 = this->m_oFilterGUI.txt_change_pw2->text().toStdString();

	if(this->checkAuth(userid, password)==false)
	{
		MagnaUtil::show_message("Invalid ID and Password.");
		RETURN_NOERROR;
	}else if(p1!=p2)
	{
		MagnaUtil::show_message("The passwords are not matched");
		RETURN_NOERROR;
	}
	string query = queries->get_update_password(userid, p1);
	(new Updator(query))->execute();

	this->m_oFilterGUI.grp_pwchange->setVisible(false);
	MagnaUtil::show_message("Your password has been changed.");

	this->m_oFilterGUI.txt_loginpw->setFocus(Qt::MouseFocusReason);
	this->m_oFilterGUI.txt_loginid->setText(this->m_oFilterGUI.txt_change_id->text());
	RETURN_NOERROR;
}

tResult DATPlayListFilter::on_btn_login_clicked(){
	string userid = this->m_oFilterGUI.txt_loginid->text().toStdString();
	string password = this->m_oFilterGUI.txt_loginpw->text().toStdString();

	if(this->checkAuth(userid, password)==true)
	{
		DATPlayListFilter::ID = userid;
		string text = DATPlayListFilter::ID + " is logged in";		
		this->m_oFilterGUI.lbl_user->setText(QString(text.c_str()));
		this->m_oFilterGUI.txt_loginid->setText(QString(""));
		this->m_oFilterGUI.txt_loginpw->setText(QString(""));
		this->to_log_in_mode(false);
		this->initAll();
	}else
	{
		MagnaUtil::show_message("Invalid ID and Password.");
	}

	RETURN_NOERROR;
}

bool DATPlayListFilter::checkAuth(string id, string pass)
{
	vector<string> field;
	field.push_back("cnt");
	string query = queries->get_login_query(id, pass);
	map<string, vector<string>> data = (new Retriever(field, query))->getData();

	int record = MagnaUtil::stringTointeger(data["cnt"].at(0));
	if(record == 0) return false;
	else return true;
}

void DATPlayListFilter::register_signal_slot()
{

	connect(m_oFilterGUI.chk_date, SIGNAL(clicked()), this, SLOT(on_chk_date_clicked()));

	connect(m_oFilterGUI.chk_eyeq_event, SIGNAL(clicked()), this, SLOT(on_chk_eyeq_event_clicked()));
	connect(m_oFilterGUI.chk_fcm_event, SIGNAL(clicked()), this, SLOT(on_chk_fcm_event_clicked()));
	connect(m_oFilterGUI.chk_user_event, SIGNAL(clicked()), this, SLOT(on_chk_user_event_clicked()));
	connect(m_oFilterGUI.chk_radar, SIGNAL(clicked()), this, SLOT(on_chk_radar_event_clicked()));

	connect(m_oFilterGUI.chk_annotation, SIGNAL(clicked()), this, SLOT(on_chk_annotation_clicked()));
	connect(m_oFilterGUI.chk_search, SIGNAL(clicked()), this, SLOT(on_chk_search_clicked()));

	connect(m_oFilterGUI.dateEdit, SIGNAL(dateChanged(QDate)), this, SLOT(on_dateEdit_changed()));
	connect(m_oFilterGUI.dateEdit_2, SIGNAL(dateChanged(QDate)), this, SLOT(on_dateEdit_2_changed()));

	connect(m_oFilterGUI.btn_s_project, SIGNAL(clicked()), this, SLOT(project_select()));
	connect(m_oFilterGUI.btn_d_project, SIGNAL(clicked()), this, SLOT(project_deselect()));
	connect(m_oFilterGUI.btn_s_feature, SIGNAL(clicked()), this, SLOT(feature_select()));
	connect(m_oFilterGUI.btn_d_feature, SIGNAL(clicked()), this, SLOT(feature_deselect()));
	connect(m_oFilterGUI.btn_s_vin, SIGNAL(clicked()), this, SLOT(vin_select()));
	connect(m_oFilterGUI.btn_d_vin, SIGNAL(clicked()), this, SLOT(vin_deselect()));

	connect(m_oFilterGUI.btn_s_event, SIGNAL(clicked()), this, SLOT(event_select()));
	connect(m_oFilterGUI.btn_d_event, SIGNAL(clicked()), this, SLOT(event_deselect()));
	connect(m_oFilterGUI.btn_s_annotation, SIGNAL(clicked()), this, SLOT(annotation_select()));
	connect(m_oFilterGUI.btn_d_annotation, SIGNAL(clicked()), this, SLOT(annotation_deselect()));
	connect(m_oFilterGUI.btn_s_ai, SIGNAL(clicked()), this, SLOT(ai_select()));
	connect(m_oFilterGUI.btn_d_ai, SIGNAL(clicked()), this, SLOT(ai_deselect()));

	connect(m_oFilterGUI.btn_s_daytype, SIGNAL(clicked()), this, SLOT(day_type_select()));
	connect(m_oFilterGUI.btn_d_daytype, SIGNAL(clicked()), this, SLOT(day_type_deselect()));
	connect(m_oFilterGUI.btn_s_weathertype, SIGNAL(clicked()), this, SLOT(weather_type_select()));
	connect(m_oFilterGUI.btn_d_weathertype, SIGNAL(clicked()), this, SLOT(weather_type_deselect()));
	connect(m_oFilterGUI.btn_s_roadtype, SIGNAL(clicked()), this, SLOT(road_type_select()));
	connect(m_oFilterGUI.btn_d_roadtype, SIGNAL(clicked()), this, SLOT(road_type_deselect()));
	connect(m_oFilterGUI.btn_s_event_status, SIGNAL(clicked()), this, SLOT(event_status_select()));
	connect(m_oFilterGUI.btn_d_event_status, SIGNAL(clicked()), this, SLOT(event_status_deselect()));

	//connect(m_oFilterGUI.btn_s_project, SIGNAL(clicked()), this, SLOT(select()));
	//connect(m_oFilterGUI.listEventAnnotation, SIGNAL(clicked(const QModelIndex)), this, SLOT(on_list_event_annotation_clicked(QModelIndex)));
	//connect(m_oFilterGUI.cbo_i_feature, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cbo_i_feature_changed()));	
	//connect(m_oFilterGUI.txt_m, SIGNAL(editingFinished()), this, SLOT(on_txt_m_edited()));

	connect(m_oFilterGUI.txt_search, SIGNAL(textChanged(const QString &)), this, SLOT(on_txt_search_edited(const QString &)));
}


string DATPlayListFilter::get_date(QDateEdit* edit, string comp)
{
	string year = MagnaUtil::integerToString(edit->date().year());
	string month = MagnaUtil::integerToString(edit->date().month());
	if(edit->date().month()<10) month = "0" + month;
	string day = MagnaUtil::integerToString(edit->date().day());
	if(edit->date().day()<10) day = "0" + day;
	return year+comp+month+comp+day;
}

void DATPlayListFilter::to_log_in_mode(bool mode)
{
	this->m_oFilterGUI.grp0->setVisible(!mode);
	this->m_oFilterGUI.grp1->setVisible(!mode);
	this->m_oFilterGUI.grp2->setVisible(!mode);
	this->m_oFilterGUI.grp3->setVisible(!mode);
	this->m_oFilterGUI.grp4->setVisible(!mode);
	this->m_oFilterGUI.grp_login->setVisible(mode);
	this->m_oFilterGUI.txt_loginpw->setEchoMode(QLineEdit::Password);
}


tResult DATPlayListFilter::ReleaseView()
{

	RETURN_NOERROR;
}
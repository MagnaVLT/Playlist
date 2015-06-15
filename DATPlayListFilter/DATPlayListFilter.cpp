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
	string query = "update users set password = PASSWORD('"+p1+"') where id = '" + userid + "';";
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
	string query = "select count(*) as cnt from users where id = '" + id + "' and password = PASSWORD('"+pass+"');";
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

	//connect(m_oFilterGUI.listEventAnnotation, SIGNAL(clicked(const QModelIndex)), this, SLOT(on_list_event_annotation_clicked(QModelIndex)));
	//connect(m_oFilterGUI.cbo_i_feature, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cbo_i_feature_changed()));	
	//connect(m_oFilterGUI.txt_m, SIGNAL(editingFinished()), this, SLOT(on_txt_m_edited()));

	connect(m_oFilterGUI.txt_search, SIGNAL(textChanged(const QString &)), this, SLOT(on_txt_search_edited(const QString &)));
}

void DATPlayListFilter::initAll()
{

}

void DATPlayListFilter::initAllModel()
{

}

void DATPlayListFilter::init_project_list()
{

}

void DATPlayListFilter::init_vin_list()
{

}

void DATPlayListFilter::init_feature_list()
{

}

void DATPlayListFilter::init_day_type_list()
{

}

void DATPlayListFilter::init_weather_type_list()
{

}

void DATPlayListFilter::init_road_type_list()
{

}

void DATPlayListFilter::init_event_list()
{

}

void DATPlayListFilter::init_predefined_annotation_list()
{

}

void DATPlayListFilter::init_additional_information_list()
{

}

void DATPlayListFilter::init_event_status_list()
{

}

void DATPlayListFilter::refeash_level_1()
{

}


void DATPlayListFilter::refeash_level_2()
{

}

void DATPlayListFilter::refeash_level_3()
{

}

void DATPlayListFilter::refeash_level_4()
{

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
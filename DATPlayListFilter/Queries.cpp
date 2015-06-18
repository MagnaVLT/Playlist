#include "Queries.h"
#include "Utils/Utilities.h"

Queries::Queries(void)
{
}

Queries::~Queries(void)
{
}

string Queries::get_login_query(string id, string pass)
{
	return "select count(*) as cnt from users where id = '" + id + "' and password = PASSWORD('"+pass+"')";
}

string Queries::get_update_password(string id, string pass)
{
	return "update users set password = PASSWORD('"+pass+"') where id = '" + id + "';";
}

string Queries::get_project_list(string id)
{
	return "select b.name as name, b.id as id from users_project_map a, project b where projectid = id and userid = '"+id+"';";
}

std::string Queries::get_feature_list(vector<string> projects, string userid)
{
	string query = "select a.name, a.id from feature_list a, users_feature_project_map b where a.id = b.featureid and b.userid = '" + userid + "' ";
	query = this->addFieldsViaInStatement("b.projectid", projects, query, 2, false);
	query += " order by a.id;";
	return query;
}

string Queries::get_event_list(vector<vector<string>> conditions, vector<string> condition_fields, bool is_all_date)
{
	string query = "select a.name, a.id from event_list a, event_report b where a.id = b.eventid ";

	for(unsigned int i = 0 ; i < conditions.size()-1; i++)
	{
		if(condition_fields.at(i)=="b.vin") query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, 2, true);
		else query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, 2, false);
	}
	
	if(is_all_date==false) query += " and date(b.localpctime) >= '" + (conditions.at(conditions.size()-1)).at(0) + "' and date(b.localpctime) <= '" + (conditions.at(conditions.size()-1)).at(1) + "' ";
	query += "group by a.id order by a.id;";

	return query;
}

std::string Queries::get_annotation_list(vector<vector<string>> conditions, vector<string> condition_fields)
{
	string query = "select name, id from predefined_annotation_list ";

	for(unsigned int i = 0 ; i < conditions.size(); i++)
	{
		query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+1, false);
	}

	query += "order by projectid, featureid, id;";

	return query;
}

string Queries::get_ai_type_list(vector<vector<string>> conditions, vector<string> condition_fields, bool is_all_date)
{
	string query = "SELECT b.name as name, a.typeid as id ";
	query += " FROM additional_event_report a, additional_event_type b, ";
	query += " (select reportid, vin from event_report, event_list where eventid = id ";

	for(unsigned int i = 0 ; i < conditions.size()-1; i++)
	{
		if(condition_fields.at(i)=="vin") query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, true);
		else query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, false);
	}

	if(is_all_date==false) query += " and date(localpctime) >= '" + (conditions.at(conditions.size()-1)).at(0) + "' and date(localpctime) <= '" + (conditions.at(conditions.size()-1)).at(1) + "' ";
	
	query += " ) d ";
	query += " where a.typeid = b.id and a.reportid = d.ReportID and a.vin = d.vin ";
	query += " group by name, id order by id;";
	return query;
}


string Queries::get_ai_value_list(vector<vector<string>> conditions)
{
	string query = "SELECT name, value FROM additional_event_report a, additional_event_type b where typeid = id  ";

	for(unsigned int i = 0 ; i < conditions.size(); i++)
	{
		query = this->addFieldsViaInStatement("typeid", conditions.at(i), query, 2, false);
	}

	query += " group by name, value ";
	query += " order by value; ";

	return query;
}

std::string Queries::get_vin_list(vector<vector<string>> conditions, bool is_all_date, vector<string>date_rages, vector<string> event_categories)
{
	string query =  "select a.vin as vin from event_report a, event_list b ";
	query += " where a.eventid = b.id ";
	query = this->addFieldsViaInStatement("projectid", conditions.at(0), query, 2, false);
	if(conditions.size()>1) query = this->addFieldsViaInStatement("b.featureid", conditions.at(1), query, 3, false);
	if(is_all_date==false) query+= " and date(a.localpctime) >= '" + date_rages.at(0) + "' and date(a.localpctime) <= '" + date_rages.at(1) + "' ";
	
	if(event_categories.size()==0)
	{
		query += " and a.eventcategoryid = -1 ";
	}else{
		this->addFieldsViaInStatement("a.eventcategoryid", event_categories, query, 4, false);
	}

	query += "group by vin order by vin;";

	return query;
}







std::string Queries::get_day_list(vector<vector<string>> conditions, vector<string> condition_fields, bool is_all_date, string search_condition)
{
	string query = "";
	if(!conditions.at(6).empty())
	{
		query = "select b.name as name, a.daytypeid as id from clip_info a, daytype b, ( ";
		query += " select clipid, typeid, value from event_report a, additional_event_report b ";
		query += " where a.reportid = b.reportid and a.vin = b.vin ";

		for(unsigned int i = 0 ; i < conditions.size()-1; i++)
		{
			if(condition_fields.at(i)=="a.vin") query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, true);
			else query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, false);
		}

		if(is_all_date==false) query += " and date(localpctime) >= '" + (conditions.at(conditions.size()-1)).at(0) + "' and date(localpctime) <= '" + (conditions.at(conditions.size()-1)).at(1) + "' ";
		if(!search_condition.empty()) query += " and userannotation like '%"+search_condition+"%' ";
		query += " ) d ";

		query += "";

		query += " where a.clipid = d.clipid and a.daytypeid = b.id  ";
		query += " group by daytypeid, name order by daytypeid; ";
	}else{
		query = "select b.name as name, a.daytypeid as id from clip_info a, daytype b, ( ";
		query += " select clipid from event_report a ";

		for(unsigned int i = 0 ; i < conditions.size()-1; i++)
		{
			if(condition_fields.at(i)=="a.vin") query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+1, true);
			else query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+1, false);
		}

		if(is_all_date==false) query += " and date(localpctime) >= '" + (conditions.at(conditions.size()-1)).at(0) + "' and date(localpctime) <= '" + (conditions.at(conditions.size()-1)).at(1) + "' ";
		if(!search_condition.empty()) query += " and userannotation like '%"+search_condition+"%' ";
		query += " ) d ";

		query += "";

		query += " where a.clipid = d.clipid and a.daytypeid = b.id  ";
		query += " group by daytypeid, name order by daytypeid; ";
	}
	return query;
}



std::string Queries::get_weather_list(vector<vector<string>> conditions, vector<string> condition_fields, bool is_all_date, string search_condition)
{
	string query = "";
	if(!conditions.at(6).empty())
	{
		query = "select b.name as name, a.weathertypeid as id from clip_info a, weathertype b, ( ";
		query += " select clipid, typeid, value from event_report a, additional_event_report b ";
		query += " where a.reportid = b.reportid and a.vin = b.vin ";

		for(unsigned int i = 0 ; i < conditions.size()-1; i++)
		{
			if(condition_fields.at(i)=="a.vin") query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, true);
			else query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, false);
		}

		if(is_all_date==false) query += " and date(localpctime) >= '" + (conditions.at(conditions.size()-1)).at(0) + "' and date(localpctime) <= '" + (conditions.at(conditions.size()-1)).at(1) + "' ";
		if(!search_condition.empty()) query += " and userannotation like '%"+search_condition+"%' ";
		query += " ) d ";

		query += "";

		query += " where a.clipid = d.clipid and a.weathertypeid = b.id  ";
		query += " group by weathertypeid, name order by weathertypeid; ";
	}else{

		query = "select b.name as name, a.weathertypeid as id from clip_info a, weathertype b, ( ";
		query += " select clipid from event_report a ";

		for(unsigned int i = 0 ; i < conditions.size()-1; i++)
		{
			if(condition_fields.at(i)=="a.vin") query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+1, true);
			else query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+1, false);
		}

		if(is_all_date==false) query += " and date(localpctime) >= '" + (conditions.at(conditions.size()-1)).at(0) + "' and date(localpctime) <= '" + (conditions.at(conditions.size()-1)).at(1) + "' ";
		if(!search_condition.empty()) query += " and userannotation like '%"+search_condition+"%' ";
		query += " ) d ";

		query += " where a.clipid = d.clipid and a.weathertypeid = b.id  ";
		query += " group by weathertypeid, name order by weathertypeid; ";

	}
	

	return query;
}

std::string Queries::get_road_list(vector<vector<string>> conditions, vector<string> condition_fields, bool is_all_date, string search_condition)
{
	string query = "";
	if(!conditions.at(6).empty())
	{
		query = "select b.name as name, a.roadtypeid as id from clip_info a, roadtype b, ( ";
		query += " select clipid, typeid, value from event_report a, additional_event_report b ";
		query += " where a.reportid = b.reportid and a.vin = b.vin ";

		for(unsigned int i = 0 ; i < conditions.size()-1; i++)
		{
			if(condition_fields.at(i)=="a.vin") query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, true);
			else query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, false);
		}

		if(is_all_date==false) query += " and date(localpctime) >= '" + (conditions.at(conditions.size()-1)).at(0) + "' and date(localpctime) <= '" + (conditions.at(conditions.size()-1)).at(1) + "' ";
		if(!search_condition.empty()) query += " and userannotation like '%"+search_condition+"%' ";
		query += " ) d ";

		query += "";

		query += " where a.clipid = d.clipid and a.roadtypeid = b.id  ";
		query += " group by roadtypeid, name order by roadtypeid; ";
	}else{

		query = "select b.name as name, a.roadtypeid as id from clip_info a, roadtype b, ( ";
		query += " select clipid from event_report a ";

		for(unsigned int i = 0 ; i < conditions.size()-1; i++)
		{
			if(condition_fields.at(i)=="a.vin") query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+1, true);
			else query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+1, false);
		}

		if(is_all_date==false) query += " and date(localpctime) >= '" + (conditions.at(conditions.size()-1)).at(0) + "' and date(localpctime) <= '" + (conditions.at(conditions.size()-1)).at(1) + "' ";
		if(!search_condition.empty()) query += " and userannotation like '%"+search_condition+"%' ";
		query += " ) d ";

		query += " where a.clipid = d.clipid and a.roadtypeid = b.id  ";
		query += " group by roadtypeid, name order by roadtypeid; ";

	}


	return query;
}

std::string Queries::get_event_status_list(vector<vector<string>> conditions, vector<string> condition_fields, bool is_all_date, string search_condition)
{
	string query = "";

	if(!conditions.at(6).empty())
	{
		query = " select b.name as name, eventstatusid as id from event_report a, event_status_list b, additional_event_report c ";
		query += " where a.eventstatusid = b.id and a.reportid = c.reportid and a.vin = c.vin ";

		for(unsigned int i = 0 ; i < conditions.size()-1; i++)
		{
			if(condition_fields.at(i)=="a.vin") query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, true);
			else query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, false);
		}

		if(is_all_date==false) query += " and date(localpctime) >= '" + (conditions.at(conditions.size()-1)).at(0) + "' and date(localpctime) <= '" + (conditions.at(conditions.size()-1)).at(1) + "' ";
		if(!search_condition.empty()) query += " and userannotation like '%"+search_condition+"%' ";
		query += " group by eventstatusid order by eventstatusid;";
	}else{
		query = " select b.name as name, eventstatusid as id from event_report a, event_status_list b ";
		query += " where a.eventstatusid = b.id ";

		for(unsigned int i = 0 ; i < conditions.size()-1; i++)
		{
			if(condition_fields.at(i)=="a.vin") query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, true);
			else query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, false);
		}

		if(is_all_date==false) query += " and date(localpctime) >= '" + (conditions.at(conditions.size()-1)).at(0) + "' and date(localpctime) <= '" + (conditions.at(conditions.size()-1)).at(1) + "' ";
		if(!search_condition.empty()) query += " and userannotation like '%"+search_condition+"%' ";
		query += " group by eventstatusid order by eventstatusid;";
	}

	return query;
}





std::string Queries::get_clip_list(vector<vector<string>> conditions, vector<string> condition_fields, bool is_all_date, string search_condition)
{

	string query = "";
	if(!conditions.at(6).empty())
	{

		query = " select b.clipname from event_report a, clip_info b, additional_event_report c ";
		query += " where a.reportid = c.reportid and a.vin = c.vin and a.clipid = b.clipid ";

		for(unsigned int i = 0 ; i < conditions.size()-1; i++)
		{
			if(condition_fields.at(i)=="a.vin") query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, true);
			else query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, false);
		}

		if(is_all_date==false) query += " and date(a.localpctime) >= '" + (conditions.at(conditions.size()-1)).at(0) + "' and date(a.localpctime) <= '" + (conditions.at(conditions.size()-1)).at(1) + "' ";
		if(!search_condition.empty()) query += " and userannotation like '%"+search_condition+"%' ";
		query += " group by b.clipname;";

	}else
	{
		query = " select b.clipname from event_report a, clip_info b ";
		query += " where a.clipid = b.clipid ";

		for(unsigned int i = 0 ; i < conditions.size()-1; i++)
		{
			if(condition_fields.at(i)=="a.vin") query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, true);
			else query = this->addFieldsViaInStatement(condition_fields.at(i), conditions.at(i), query, i+2, false);
		}

		if(is_all_date==false) query += " and date(a.localpctime) >= '" + (conditions.at(conditions.size()-1)).at(0) + "' and date(a.localpctime) <= '" + (conditions.at(conditions.size()-1)).at(1) + "' ";
		if(!search_condition.empty()) query += " and userannotation like '%"+search_condition+"%' ";
		query += " group by b.clipname;";

	}

	return query;
}





std::string Queries::addFieldsViaInStatement(string field, vector<string> values, string query, int order, bool is_text)
{
	if(values.size()>0)
	{	
		if(order == 1)query += " where ";
		else query += " and ";
		query += " " + field + " in (";
		if(is_text==false)
		{
			for(unsigned int i = 0; i < values.size()-1; i++) query+= values.at(i) + ", " ;
			query += values.at(values.size()-1);
		}else{
			for(unsigned int i = 0; i < values.size()-1; i++) query+= "'" + values.at(i) + "', " ;
			query +=  "'"+values.at(values.size()-1) + "'";
		}
		
		
		query += ") ";
	}
	

	return query;
}

string Queries::addFieldsViaOrStatement(string field, vector<string> values, string query)
{
	if(values.size()>0)
	{
		query += " and (";
		for(unsigned int i = 0 ; i < values.size()-1 ; i++)
		{
			string v = values.at(i);
			query += field + " = " + v + " or ";
		}
		string v = values.at(values.size()-1);
		query += field + " = " + v + ") ";

	}else{
		query += " and " + field + " = -1 ";
	}	

	return query;
}


string Queries::get_day_type_list()
{
	return "select name, id from daytype;";
}

string Queries::get_weather_type_list()
{
	return "select name, id from weathertype;";
}

string Queries::get_road_type_list()
{
	return "select name, id from roadtype;";
}

vector<string> Queries::get_fields_name_id()
{
	vector<string> field;
	field.push_back("name");
	field.push_back("id");
	return field;
}

vector<string> Queries::get_fields_name()
{
	vector<string> field;
	field.push_back("name");
	return field;
}

vector<string> Queries::get_fields_ai()
{
	vector<string> field;
	field.push_back("name");
	field.push_back("id");
	return field;
}

vector<string> Queries::get_fields_ai_value()
{
	vector<string> field;
	field.push_back("name");
	field.push_back("value");
	return field;
}

vector<string> Queries::get_fields_vin()
{
	vector<string> field;
	field.push_back("vin");
	return field;
}

vector<string> Queries::get_condition_for_event()
{
	vector<string> field;
	field.push_back("b.projectid");
	field.push_back("a.featureid");
	field.push_back("b.vin");
	field.push_back("b.eventcategoryid");
	return field;
}

vector<string> Queries::get_condition_for_annotation()
{
	vector<string> field;
	field.push_back("projectid");
	field.push_back("featureid");
	return field;
}

vector<string> Queries::get_condition_for_ai()
{
	vector<string> field;
	field.push_back("projectid");
	field.push_back("featureid");
	field.push_back("vin");
	field.push_back("eventcategoryid");
	
	return field;
}

vector<string> Queries::get_condition_for_level3()
{
	vector<string> field;

	field.push_back("eventcategoryid");
	field.push_back("projectid");
	field.push_back("a.vin");
	field.push_back("eventid");
	field.push_back("predefinedannotationid");
	field.push_back("typeid");
	field.push_back("value");

	return field;
}

vector<string> Queries::get_condition_for_event_status()
{
	vector<string> field;

	field.push_back("eventcategoryid");
	field.push_back("projectid");
	field.push_back("a.vin");
	field.push_back("eventid");
	field.push_back("predefinedannotationid");
	field.push_back("c.typeid");
	field.push_back("c.value");

	return field;
}

vector<string> Queries::get_condition_for_clips()
{
	vector<string> field;

	field.push_back("a.eventcategoryid");
	field.push_back("a.projectid");
	field.push_back("a.vin");
	field.push_back("a.eventid");
	field.push_back("a.predefinedannotationid");
	field.push_back("c.typeid");
	field.push_back("c.value");
	field.push_back("b.daytypeid");
	field.push_back("b.weathertypeid");
	field.push_back("b.roadtypeid");
	field.push_back("a.eventstatusid");
	return field;
}

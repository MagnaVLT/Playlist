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
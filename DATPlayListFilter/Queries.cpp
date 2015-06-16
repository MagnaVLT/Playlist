#include "Queries.h"


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
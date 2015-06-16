#pragma once
#include <string>
#include <vector>

using namespace std;

class Queries
{
public:
	Queries(void);
	~Queries(void);

	string get_login_query(string id, string pass);
	string get_update_password(string id, string pass);
	string get_project_list(string id);
	string get_day_type_list();
	string get_weather_type_list();
	string get_road_type_list();
	vector<string> get_fields_name_id();

};

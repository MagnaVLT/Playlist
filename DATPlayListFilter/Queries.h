#pragma once
#include "stdafx.h"
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
	string get_feature_list(vector<string> projects, string userid);
	string get_event_list(vector<vector<string>> conditions, vector<string> condition_fields, bool is_all_date);
	string get_annotation_list(vector<vector<string>> conditions, vector<string> condition_fields);
	string get_ai_list(vector<vector<string>> conditions, vector<string> condition_fields, bool is_all_date);
	string get_vin_list(vector<vector<string>> project_id, bool is_all_date, vector<string>date_rages, vector<string> event_categories);
	string addFieldsViaInStatement(string field, vector<string> values, string query, int order, bool is_text);
	string addFieldsViaOrStatement(string field, vector<string> values, string query);
	string get_day_type_list();
	string get_weather_type_list();
	string get_road_type_list();
	vector<string> get_fields_name_id();

	vector<string> get_fields_vin();
	vector<string> get_condition_for_event();
	vector<string> get_condition_for_annotation();
	vector<string> get_condition_for_ai();
};


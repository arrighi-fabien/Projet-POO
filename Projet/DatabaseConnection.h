#pragma once
using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

ref class DatabaseConnection {
private:
	String^ sql_connection_string;
	String^ sql_query;
	SqlConnection^ sql_connection;
	SqlCommand^ sql_command;
	SqlDataAdapter^ sql_data_adapter;
	DataSet^ sql_data_set;
	bool is_connected = false;
public:
	DatabaseConnection();
	void setQuery(String^ query);
	void executeQuery(String^ query);
	DataSet^ executeQuerySelect(String^ query, String^ table_name);
	DataSet^ getDataSet();
	bool isConnected();
};
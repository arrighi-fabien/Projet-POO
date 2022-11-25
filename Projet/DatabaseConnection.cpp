#include "DatabaseConnection.h"

DatabaseConnection::DatabaseConnection() {
	this->sql_connection_string = "Data Source=LAPTOP-9A8NS6MC;Initial Catalog=prosit_6;Integrated Security=True";
	this->sql_connection = gcnew SqlConnection(this->sql_connection_string);
	this->sql_command = gcnew SqlCommand();
	this->sql_command->CommandType = CommandType::Text;
}

void DatabaseConnection::setQuery(String^ query) {
	if (query != "") {
		this->sql_query = query;
	}
	else {
		throw gcnew Exception("Query is null");
	}
}

void DatabaseConnection::executeQuery(String^ query) {
	this->setQuery(query);
	this->sql_command->CommandText = this->sql_query;
	this->sql_connection->Open();
	this->sql_command->ExecuteNonQuery();
	this->sql_connection->Close();
}

DataSet^ DatabaseConnection::executeQuerySelect(String^ query, String^ table_name) {
	this->setQuery(query);
	this->sql_data_adapter = gcnew SqlDataAdapter(this->sql_command);
	this->sql_data_set = gcnew DataSet();
	this->sql_command->CommandText = this->sql_query;
	this->sql_data_adapter->SelectCommand->Connection = this->sql_connection;
	this->sql_data_adapter->Fill(this->sql_data_set, table_name);
	return this->sql_data_set;
}

DataSet^ DatabaseConnection::getDataSet() {
	return this->sql_data_set;
}
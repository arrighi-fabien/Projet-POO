#include "DatabaseConnection.h"
using namespace System::Windows::Forms;

DatabaseConnection::DatabaseConnection() {
	this->sql_connection_string = "Data Source=LAPTOP-9A8NS6MC;Initial Catalog=projet;Integrated Security=True";
	try {
		this->sql_connection = gcnew SqlConnection(this->sql_connection_string);
		this->sql_connection->Open();
		this->sql_connection->Close();
		this->sql_command = gcnew SqlCommand();
		this->sql_command->CommandType = CommandType::Text;
	}
	catch (Exception^ e) {
		MessageBox::Show("Echec de la connexion à la base de données.\nVeuillez réessayer dans quelques instant.\nSi le problème persiste, contactez un administrateur de l'application", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
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
	this->sql_command->Connection = this->sql_connection;
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

int DatabaseConnection::executeQueryInsert(String^ query) {
	this->setQuery(query);
	this->sql_command->CommandText = this->sql_query;
	this->sql_connection->Open();
	this->sql_command->Connection = this->sql_connection;
	int id = Convert::ToInt32(this->sql_command->ExecuteScalar());
	this->sql_connection->Close();
	return id;
}

DataSet^ DatabaseConnection::getDataSet() {
	return this->sql_data_set;
}

bool DatabaseConnection::isConnected() {
	try {
		this->sql_connection->Open();
		this->sql_connection->Close();
		this->is_connected = true;
	}
	catch (Exception^ e) {
		this->is_connected = false;
	}
	return this->is_connected;
}
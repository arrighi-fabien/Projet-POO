#include "GpCustomer.h"

GpCustomer::GpCustomer() {
	this->customer = gcnew Customer();
	this->billing_address = gcnew DataSet();
	this->shipping_address = gcnew DataSet();
	this->db = gcnew DatabaseConnection();
}

GpCustomer::~GpCustomer() {
	delete this->customer;
	delete this->billing_address;
	delete this->shipping_address;
	delete this->db;
}

void GpCustomer::setCustomer(Customer^ customer) {
	this->customer = customer;
}

void GpCustomer::setBillingAddress(DataSet^ billing_address) {
	this->billing_address = billing_address;
}

void GpCustomer::setShippingAddress(DataSet^ shipping_address) {
	this->shipping_address = shipping_address;
}

void GpCustomer::setDb(DatabaseConnection^ db) {
	this->db = db;
}

Customer^ GpCustomer::getCustomer() {
	return this->customer;
}

DataSet^ GpCustomer::getBillingAddress() {
	return this->billing_address;
}

DataSet^ GpCustomer::getShippingAddress() {
	return this->shipping_address;
}

DatabaseConnection^ GpCustomer::getDb() {
	return this->db;
}

void GpCustomer::selectCustomer(int id) {
	this->getDb()->executeQuerySelect("SELECT * FROM customer WHERE id_customer = " + id, "Customer");
	DataSet^ data = this->getDb()->getDataSet();
	this->getCustomer()->setIdCustomer(id);
	this->getCustomer()->setFirstName(Convert::ToString(data->Tables["Customer"]->Rows[0]->ItemArray[1]));
	this->getCustomer()->setLastName(Convert::ToString(data->Tables["Customer"]->Rows[0]->ItemArray[2]));
	this->getCustomer()->setBirthDate(Convert::ToDateTime(data->Tables["Customer"]->Rows[0]->ItemArray[3]));
	if (data->Tables["Customer"]->Rows[0]->ItemArray[4] != System::DBNull::Value) {
		this->getCustomer()->setFirstPurchase(Convert::ToDateTime(data->Tables["Customer"]->Rows[0]->ItemArray[4]));
	}
	else {
		this->getCustomer()->setFirstPurchase(Convert::ToDateTime("01/01/1900"));
	}
	this->getDb()->executeQuerySelect("SELECT Address.id_address, address, additional_address, postal_code, Address.id_city, city_name, city.id_country, country_name FROM delivered_to JOIN Address ON delivered_to.id_address = Address.id_address JOIN city ON Address.id_city = city.id_city JOIN country ON city.id_country = country.id_country WHERE id_customer = " + this->getCustomer()->getIdCustomer(), "CustomerShippingAddress");
	this->setShippingAddress(this->getDb()->getDataSet());
	this->getDb()->executeQuerySelect("SELECT Address.id_address, address, additional_address, postal_code, Address.id_city, city_name, city.id_country, country_name FROM billed_to JOIN Address ON billed_to.id_address = Address.id_address JOIN city ON Address.id_city = city.id_city JOIN country ON city.id_country = country.id_country WHERE id_customer = " + this->getCustomer()->getIdCustomer(), "CustomerBillingAddress");
	this->setBillingAddress(this->getDb()->getDataSet());
}

void GpCustomer::insertCustomer() {
	int id_user = this->getDb()->executeQueryInsert("INSERT INTO customer (first_name, last_name, birth_date, first_purchase) VALUES ('" + this->getCustomer()->getFirstName() + "', '" + this->getCustomer()->getLastName() + "', '" + this->getCustomer()->getBirthDate() + "', '" + this->getCustomer()->getFirstPurchase() + "'); SELECT @@IDENTITY");
	Address^ address = gcnew Address();
	for (int i = 0; i < this->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows->Count-1; i++) {
		address->setCity(this->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[3]->ToString());
		address->setCountry(this->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[4]->ToString());
		address->CityCountryExist(this->getDb());
		int id_address = this->getDb()->executeQueryInsert("INSERT INTO address (address, additional_address, postal_code, id_city) VALUES ('" + this->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[0] + "', '" + this->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[1] + "', '" + this->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[2] + "', (SELECT id_city FROM city WHERE city_name = '" + this->getShippingAddress()->Tables["CustomerShippingAddress"]->Rows[i]->ItemArray[3] + "')); SELECT @@IDENTITY");
		this->getDb()->executeQuery("INSERT INTO delivered_to (id_customer, id_address) VALUES ('" + id_user + "', '" + id_address + "')");
	}
	for (int i = 0; i < this->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows->Count-1; i++) {
		address->setCity(this->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[3]->ToString());
		address->setCountry(this->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[4]->ToString());
		address->CityCountryExist(this->getDb());
		int id_address = this->getDb()->executeQueryInsert("INSERT INTO address (address, additional_address, postal_code, id_city) VALUES ('" + this->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[0] + "', '" + this->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[1] + "', '" + this->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[2] + "', (SELECT id_city FROM city WHERE city_name = '" + this->getBillingAddress()->Tables["CustomerBillingAddress"]->Rows[i]->ItemArray[3] + "')); SELECT @@IDENTITY");
		this->getDb()->executeQuery("INSERT INTO billed_to (id_customer, id_address) VALUES ('" + id_user + "', '" + id_address + "')");
	}
}

DataSet^ GpCustomer::customerPreview(int id, String^ last_name, String^ first_name) {
	DataSet^ data;
	String^ first_part_query = "SELECT id_customer AS Identifiant_client, last_name AS Nom, first_name AS Prénom, birth_date AS Date_naissance FROM customer WHERE ";
	if (id > 0) {
		data = this->getDb()->executeQuerySelect(first_part_query + "id_customer = " + id, "Preview");
	}
	else if (last_name != "" && first_name != "") {
		data = this->getDb()->executeQuerySelect(first_part_query + "last_name LIKE '" + last_name + "%' AND first_name LIKE '" + first_name + "%'", "Preview");
	}
	else if (last_name != "") {
		data = this->getDb()->executeQuerySelect(first_part_query + "last_name LIKE '" + last_name + "%'", "Preview");
	}
	else if (first_name != "") {
		data = this->getDb()->executeQuerySelect(first_part_query + "first_name LIKE '" + first_name + "%'", "Preview");
	}
	else {
		return data;
	}
	return data;
}

void GpCustomer::addValueDataSet(DataSet^ data, int row, String^ table, String^ column, String^ value) {
	data->Tables[table]->Rows[row]->ItemArray[data->Tables[table]->Columns[column]->Ordinal] = value;
}
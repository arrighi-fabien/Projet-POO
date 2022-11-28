#include "Staff.h"
#include "DatabaseConnection.h"
using namespace System;

Staff::Staff() {
	DatabaseConnection^ db = gcnew DatabaseConnection();
}

void Staff::setIdStaff(int id_staff) {
	this->id_staff = id_staff;
}

void Staff::setFirstName(String^ first_name) {
	this->first_name = first_name;
}

void Staff::setLastName(String^ last_name) {
	this->last_name = last_name;
}

void Staff::setHiringDate(DateTime^ hiring_date) {
	this->hiring_date = hiring_date;
}

void Staff::setIdManager(int id_manager) {
	this->id_manager = id_manager;
}

void Staff::setIdAddress(int id_address) {
	this->id_address = id_address;
}

void Staff::setAddress(String^ address) {
	this->address = address;
}

void Staff::setAddressO(String^ address_o) {
	this->address_o = address_o;
}

void Staff::setPostalCode(String^ postal_code) {
	this->postal_code = postal_code;
}

void Staff::setIdCity(int id_city) {
	this->id_city = id_city;
}

void Staff::setCity(String^ city) {
	this->city = city;
}

void Staff::setIdCountry(int id_country) {
	this->id_country = id_country;
}

void Staff::setCountry(String^ country) {
	this->country = country;
}

int Staff::getIdStaff() {
	return this->id_staff;
}

String^ Staff::getFirstName() {
	return this->first_name;
}

String^ Staff::getLastName() {
	return this->last_name;
}

DateTime^ Staff::getHiringDate() {
	return this->hiring_date;
}

int Staff::getIdManager() {
	return this->id_manager;
}

int Staff::getIdAddress() {
	return this->id_address;
}

String^ Staff::getAddress() {
	return this->address;
}

String^ Staff::getAddressO() {
	return this->address_o;
}

String^ Staff::getPostalCode() {
	return this->postal_code;
}

int Staff::getIdCity() {
	return this->id_city;
}

String^ Staff::getCity() {
	return this->city;
}

int Staff::getIdCountry() {
	return this->id_country;
}

String^ Staff::getCountry() {
	return this->country;
}

void Staff::selectStaff(int id) {
	DatabaseConnection^ db = gcnew DatabaseConnection();
	db->executeQuerySelect("SELECT id_staff, first_name, last_name, hiring_date, id_manager, Address.id_address, address, additional_address, postal_code, Address.id_city, city_name, city.id_country, country_name FROM Staff JOIN Address ON staff.id_address = Address.id_address JOIN city ON Address.id_city = city.id_city JOIN country ON city.id_country = country.id_country WHERE id_staff = " + id, "Staff");
	DataSet^ data = db->getDataSet();
	this->id_staff = Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[0]);
	this->first_name = Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[1]);
	this->last_name = Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[2]);
	this->hiring_date = Convert::ToDateTime(data->Tables["Staff"]->Rows[0]->ItemArray[3]);
	if (data->Tables["Staff"]->Rows[0]->ItemArray[4] != System::DBNull::Value) {
		this->id_manager = Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[4]);
	}
	else {
		this->id_manager = 0;
	}
	this->id_address = Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[5]);
	this->address = Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[6]);
	this->address_o = Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[7]);
	this->postal_code = Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[8]);
	this->id_city = Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[9]);
	this->city = Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[10]);
	this->id_country = Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[11]);
	this->country = Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[12]);
	delete db;
}

void Staff::insertStaff() {
	DatabaseConnection^ db = gcnew DatabaseConnection();
	String^ params;
	params += "@last_name = '" + this->last_name + "', ";
	params += "@first_name = '" + this->first_name + "', ";
	params += "@hiring_date = '" + this->hiring_date + "', ";
	if (this->id_manager > 0) {
		params += "@id_manager = '" + this->id_manager + "', ";
	}
	else {
		params += "@id_manager = NULL, ";
	}
	params += "@address = '" + this->address + "', ";
	if (this->address_o != "") {
		params += "@address_o = '" + this->address_o + "', ";
	}
	else {
		params += "@address_o = NULL, ";
	}
	params += "@postal_code = '" + this->postal_code + "', ";
	params += "@city = '" + this->city + "'";
	String^ query;
	query = "EXEC dbo.add_new_staff " + params;
	db->executeQuery(query);
	delete db;
}

void Staff::updateStaff() {
	DatabaseConnection^ db = gcnew DatabaseConnection();
	if (this->id_manager <= 0) {
		db->executeQuery("UPDATE Staff SET first_name = '" + this->first_name + "', last_name = '" + this->last_name + "', hiring_date = '" + this->hiring_date + "', id_manager = NULL WHERE id_staff = " + this->id_staff);
	}
	else {
		db->executeQuery("UPDATE Staff SET first_name = '" + this->first_name + "', last_name = '" + this->last_name + "', hiring_date = '" + this->hiring_date + "', id_manager = " + this->id_manager + " WHERE id_staff = " + this->id_staff);
	}
	db->executeQuery("UPDATE Address SET address = '" + this->address + "', additional_address = '" + this->address_o + "', postal_code = '" + this->postal_code + "', id_city = (SELECT id_city FROM city WHERE city_name = '" + this->city + "') WHERE id_address = " + this->id_address);
	delete db;
}
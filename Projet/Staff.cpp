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
	setIdStaff(Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[0]));
	setFirstName(Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[1]));
	setLastName(Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[2]));
	setHiringDate(Convert::ToDateTime(data->Tables["Staff"]->Rows[0]->ItemArray[3]));
	if (data->Tables["Staff"]->Rows[0]->ItemArray[4] != System::DBNull::Value) {
		setIdManager(Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[4]));
	}
	else {
		setIdManager(0);
	}
	setIdAddress(Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[5]));
	setAddress(Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[6]));
	if (data->Tables["Staff"]->Rows[0]->ItemArray[7] != System::DBNull::Value) {
		setAddressO(Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[7]));
	}
	else {
		setAddressO("");
	}
	setPostalCode(Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[8]));
	setIdCity(Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[9]));
	setCity(Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[10]));
	setIdCountry(Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[11]));
	setCountry(Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[12]));
	delete db;
}

void Staff::insertStaff() {
	DatabaseConnection^ db = gcnew DatabaseConnection();
	int id = db->executeQueryInsert("INSERT INTO Address (address, additional_address, postal_code, id_city) VALUES ('" + this->address + "', '" + this->address_o + "', '" + this->postal_code + "', (SELECT id_city FROM city WHERE city_name = '" + this->city + "')); SELECT @@IDENTITY");
	if (this->id_manager <= 0) {
		db->executeQuery("INSERT INTO staff (first_name, last_name, hiring_date, id_manager, id_address) VALUES ('" + this->first_name + "', '" + this->last_name + "', '" + this->hiring_date + "', NULL, " + id + ")");
	}
	else {
		db->executeQuery("INSERT INTO staff (first_name, last_name, hiring_date, id_manager, id_address) VALUES ('" + this->first_name + "', '" + this->last_name + "', '" + this->hiring_date + "', " + this->id_manager + ", " + id + ")");
	}
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

void Staff::deleteStaff() {
	DatabaseConnection^ db = gcnew DatabaseConnection();
	this->selectStaff(this->id_staff);
	db->executeQuery("DELETE FROM Staff WHERE id_staff = " + this->id_staff);
	db->executeQuery("DELETE FROM Address WHERE id_address = " + this->id_address);
	delete db;
}
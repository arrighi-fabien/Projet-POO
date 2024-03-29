#include "Address.h"

Address::Address() {
	this->id_address = 0;
	this->address = "";
	this->address_o = "";
	this->postal_code = "";
	this->id_city = 0;
	this->city = "";
	this->id_country = 0;
	this->country = "";
}

void Address::setIdAddress(int id_address) {
	this->id_address = id_address;
}

void Address::setAddress(String^ address) {
	this->address = address;
}

void Address::setAddressO(String^ address_o) {
	this->address_o = address_o;
}

void Address::setPostalCode(String^ postal_code) {
	this->postal_code = postal_code;
}

void Address::setIdCity(int id_city) {
	this->id_city = id_city;
}

void Address::setCity(String^ city) {
	this->city = city;
}

void Address::setIdCountry(int id_country) {
	this->id_country = id_country;
}

void Address::setCountry(String^ country) {
	this->country = country;
}

int Address::getIdAddress() {
	return this->id_address;
}

String^ Address::getAddress() {
	return this->address;
}

String^ Address::getAddressO() {
	return this->address_o;
}

String^ Address::getPostalCode() {
	return this->postal_code;
}

int Address::getIdCity() {
	return this->id_city;
}

String^ Address::getCity() {
	return this->city;
}

int Address::getIdCountry() {
	return this->id_country;
}

String^ Address::getCountry() {
	return this->country;
}

void Address::CityCountryExist(DatabaseConnection^ db) {
	db->executeQuerySelect("SELECT * FROM country WHERE country_name = '" + this->getCountry() + "'", "Country");
	DataSet^ data = db->getDataSet();
	if (data->Tables["Country"]->Rows->Count == 0) {
		db->executeQuery("INSERT INTO country (country_name) VALUES ('" + this->getCountry() + "')");
	}
	delete data;
	db->executeQuerySelect("SELECT * FROM city WHERE city_name = '" + this->getCity() + "' AND id_country = (SELECT id_country FROM country WHERE country_name = '" + this->getCountry() + "')", "City");
	DataSet^ data2 = db->getDataSet();
	if (data2->Tables["City"]->Rows->Count == 0) {
		db->executeQuery("INSERT INTO city (city_name, id_country) VALUES ('" + this->getCity() + "', (SELECT id_country FROM country WHERE country_name = '" + this->getCountry() + "'))");
	}
	delete data2;
}
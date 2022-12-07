#include "Customer.h"

Customer::Customer() {
	this->id_customer = 0;
	this->first_name = "";
	this->last_name = "";
	this->birth_date = DateTime::Now;
	this->first_purchase = DateTime::Now;
}

void Customer::setIdCustomer(int id_customer) {
	this->id_customer = id_customer;
}

void Customer::setFirstName(String^ first_name) {
	this->first_name = first_name;
}

void Customer::setLastName(String^ last_name) {
	this->last_name = last_name;
}

void Customer::setBirthDate(DateTime^ birth_date) {
	this->birth_date = birth_date;
}

void Customer::setFirstPurchase(DateTime^ first_purchase) {
	this->first_purchase = first_purchase;
}

int Customer::getIdCustomer() {
	return this->id_customer;
}

String^ Customer::getFirstName() {
	return this->first_name;
}

String^ Customer::getLastName() {
	return this->last_name;
}

DateTime^ Customer::getBirthDate() {
	return this->birth_date;
}

DateTime^ Customer::getFirstPurchase() {
	return this->first_purchase;
}
#include "Staff.h"

Staff::Staff() {
	//set all value to null
	this->id_staff = 0;
	this->first_name = "";
	this->last_name = "";
	this->hiring_date = DateTime::Now;
	this->id_manager = 0;
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
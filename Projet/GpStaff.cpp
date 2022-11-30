#include "GpStaff.h"

GpStaff::GpStaff() {
	this->setStaff(gcnew Staff());
	this->setAddress(gcnew Address());
	this->setDb(gcnew DatabaseConnection());
}

GpStaff::~GpStaff() {
	delete this->staff;
	delete this->address;
	delete this->db;
}

void GpStaff::setStaff(Staff^ staff) {
	this->staff = staff;
}

void GpStaff::setAddress(Address^ address) {
	this->address = address;
}

Staff^ GpStaff::getStaff() {
	return this->staff;
}

Address^ GpStaff::getAddress() {
	return this->address;
}

void GpStaff::setDb(DatabaseConnection^ db) {
	this->db = db;
}

DatabaseConnection^ GpStaff::getDb() {
	return this->db;
}

void GpStaff::selectStaff(int id) {
	this->getDb()->executeQuerySelect("SELECT id_staff, first_name, last_name, hiring_date, id_manager, Address.id_address, address, additional_address, postal_code, Address.id_city, city_name, city.id_country, country_name FROM staff JOIN Address ON staff.id_address = Address.id_address JOIN city ON Address.id_city = city.id_city JOIN country ON city.id_country = country.id_country WHERE id_staff = " + id, "Staff");
	DataSet^ data = this->getDb()->getDataSet();
	this->getStaff()->setIdStaff(Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[0]));
	this->getStaff()->setFirstName(Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[1]));
	this->getStaff()->setLastName(Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[2]));
	this->getStaff()->setHiringDate(Convert::ToDateTime(data->Tables["Staff"]->Rows[0]->ItemArray[3]));
	if (data->Tables["Staff"]->Rows[0]->ItemArray[4] != System::DBNull::Value) {
		this->getStaff()->setIdManager(Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[4]));
	}
	else {
		this->getStaff()->setIdManager(0);
	}
	this->getAddress()->setIdAddress(Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[5]));
	this->getAddress()->setAddress(Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[6]));
	if (data->Tables["Staff"]->Rows[0]->ItemArray[7] != System::DBNull::Value) {
		this->getAddress()->setAddressO(Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[7]));
	}
	else {
		this->getAddress()->setAddressO("");
	}
	this->getAddress()->setPostalCode(Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[8]));
	this->getAddress()->setIdCity(Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[9]));
	this->getAddress()->setCity(Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[10]));
	this->getAddress()->setIdCountry(Convert::ToInt32(data->Tables["Staff"]->Rows[0]->ItemArray[11]));
	this->getAddress()->setCountry(Convert::ToString(data->Tables["Staff"]->Rows[0]->ItemArray[12]));
}

void GpStaff::insertStaff() {
	this->getAddress()->CityCountryExist(this->getDb());
	int id = this->getDb()->executeQueryInsert("INSERT INTO Address (address, additional_address, postal_code, id_city) VALUES ('" + this->getAddress()->getAddress() + "', '" + this->getAddress()->getAddressO() + "', '" + this->getAddress()->getPostalCode() + "', (SELECT id_city FROM city WHERE city_name = '" + this->getAddress()->getCity() + "')); SELECT @@IDENTITY");
	if (this->getStaff()->getIdManager() <= 0) {
		this->getDb()->executeQuery("INSERT INTO staff (first_name, last_name, hiring_date, id_manager, id_address) VALUES ('" + this->getStaff()->getFirstName() + "', '" + this->getStaff()->getLastName() + "', '" + this->getStaff()->getHiringDate() + "', NULL, " + id + ")");
	}
	else {
		this->getDb()->executeQuery("INSERT INTO staff (first_name, last_name, hiring_date, id_manager, id_address) VALUES ('" + this->getStaff()->getFirstName() + "', '" + this->getStaff()->getLastName() + "', '" + this->getStaff()->getHiringDate() + "', " + this->getStaff()->getIdManager() + ", " + id + ")");
	}
}

void GpStaff::updateStaff() {
	if (this->getStaff()->getIdManager() <= 0) {
		this->getDb()->executeQuery("UPDATE staff SET first_name = '" + this->getStaff()->getFirstName() + "', last_name = '" + this->getStaff()->getLastName() + "', hiring_date = '" + this->getStaff()->getHiringDate() + "', id_manager = NULL WHERE id_staff = " + this->getStaff()->getIdStaff());
	}
	else {
		this->getDb()->executeQuery("UPDATE staff SET first_name = '" + this->getStaff()->getFirstName() + "', last_name = '" + this->getStaff()->getLastName() + "', hiring_date = '" + this->getStaff()->getHiringDate() + "', id_manager = " + this->getStaff()->getIdManager() + " WHERE id_staff = " + this->getStaff()->getIdStaff());
	}
	this->getDb()->executeQuery("UPDATE Address SET address = '" + this->getAddress()->getAddress() + "', additional_address = '" + this->getAddress()->getAddressO() + "', postal_code = '" + this->getAddress()->getPostalCode() + "', id_city = (SELECT id_city FROM city WHERE city_name = '" + this->getAddress()->getCity() + "') WHERE id_address = " + this->getAddress()->getIdAddress());
}

void GpStaff::deleteStaff() {
	this->selectStaff(getStaff()->getIdStaff());
	this->getDb()->executeQuery("DELETE FROM staff WHERE id_staff = " + this->getStaff()->getIdStaff());
	this->getDb()->executeQuery("DELETE FROM Address WHERE id_address = " + this->getAddress()->getIdAddress());
}

DataSet^ GpStaff::staffPreview(int id, String^ last_name, String^ first_name) {
	DataSet^ data;
	String^ first_part_query = "SELECT id_staff AS Identifiant, last_name AS Nom, first_name AS Prénom, hiring_date AS Date_embauche, id_manager AS Manager FROM staff WHERE ";
	if (id > 0) {
		data = this->getDb()->executeQuerySelect(first_part_query + "id_staff = " + id, "StaffPreview");
	}
	else if (last_name != "" && first_name != "") {
		data = this->getDb()->executeQuerySelect(first_part_query + "last_name LIKE '" + last_name + "%' AND first_name LIKE '" + first_name + "%'", "StaffPreview");
	}
	else if (last_name != "") {
		data = this->getDb()->executeQuerySelect(first_part_query + "last_name LIKE '" + last_name + "%'", "StaffPreview");
	}
	else if (first_name != "") {
		data = this->getDb()->executeQuerySelect(first_part_query + "first_name LIKE '" + first_name + "%'", "StaffPreview");
	}
	else {
		return data;
	}
	return data;
}
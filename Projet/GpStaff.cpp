#include "GpStaff.h"
#include "DatabaseConnection.h"

GpStaff::GpStaff() {
	this->setStaff(gcnew Staff());
	this->setAddress(gcnew Address());
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

void GpStaff::selectStaff(int id) {
	DatabaseConnection^ db = gcnew DatabaseConnection();
	db->executeQuerySelect("SELECT id_staff, first_name, last_name, hiring_date, id_manager, Address.id_address, address, additional_address, postal_code, Address.id_city, city_name, city.id_country, country_name FROM staff JOIN Address ON staff.id_address = Address.id_address JOIN city ON Address.id_city = city.id_city JOIN country ON city.id_country = country.id_country WHERE id_staff = " + id, "Staff");
	DataSet^ data = db->getDataSet();
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
	delete db;
}

void GpStaff::insertStaff() {
	DatabaseConnection^ db = gcnew DatabaseConnection();
	int id = db->executeQueryInsert("INSERT INTO Address (address, additional_address, postal_code, id_city) VALUES ('" + this->getAddress()->getAddress() + "', '" + this->getAddress()->getAddressO() + "', '" + this->getAddress()->getPostalCode() + "', (SELECT id_city FROM city WHERE city_name = '" + this->getAddress()->getCity() + "')); SELECT @@IDENTITY");
	if (this->getStaff()->getIdManager() <= 0) {
		db->executeQuery("INSERT INTO staff (first_name, last_name, hiring_date, id_manager, id_address) VALUES ('" + this->getStaff()->getFirstName() + "', '" + this->getStaff()->getLastName() + "', '" + this->getStaff()->getHiringDate() + "', NULL, " + id + ")");
	}
	else {
		db->executeQuery("INSERT INTO staff (first_name, last_name, hiring_date, id_manager, id_address) VALUES ('" + this->getStaff()->getFirstName() + "', '" + this->getStaff()->getLastName() + "', '" + this->getStaff()->getHiringDate() + "', " + this->getStaff()->getIdManager() + ", " + id + ")");
	}
	delete db;
}

void GpStaff::updateStaff() {
	DatabaseConnection^ db = gcnew DatabaseConnection();
	if (this->getStaff()->getIdManager() <= 0) {
		db->executeQuery("UPDATE staff SET first_name = '" + this->getStaff()->getFirstName() + "', last_name = '" + this->getStaff()->getLastName() + "', hiring_date = '" + this->getStaff()->getHiringDate() + "', id_manager = NULL WHERE id_staff = " + this->getStaff()->getIdStaff());
	}
	else {
		db->executeQuery("UPDATE staff SET first_name = '" + this->getStaff()->getFirstName() + "', last_name = '" + this->getStaff()->getLastName() + "', hiring_date = '" + this->getStaff()->getHiringDate() + "', id_manager = " + this->getStaff()->getIdManager() + " WHERE id_staff = " + this->getStaff()->getIdStaff());
	}
	db->executeQuery("UPDATE Address SET address = '" + this->getAddress()->getAddress() + "', additional_address = '" + this->getAddress()->getAddressO() + "', postal_code = '" + this->getAddress()->getPostalCode() + "', id_city = (SELECT id_city FROM city WHERE city_name = '" + this->getAddress()->getCity() + "') WHERE id_address = " + this->getAddress()->getIdAddress());
	delete db;
}

void GpStaff::deleteStaff() {
	DatabaseConnection^ db = gcnew DatabaseConnection();
	this->selectStaff(getStaff()->getIdStaff());
	db->executeQuery("DELETE FROM staff WHERE id_staff = " + this->getStaff()->getIdStaff());
	db->executeQuery("DELETE FROM Address WHERE id_address = " + this->getAddress()->getIdAddress());
	delete db;
}

DataSet^ GpStaff::staffPreview(int id, String^ last_name, String^ first_name) {
	DatabaseConnection^ db = gcnew DatabaseConnection();
	DataSet^ data;
	String^ first_part_query = "SELECT id_staff AS Identifiant, last_name AS Nom, first_name AS Prénom, hiring_date AS Date_embauche, id_manager AS Manager FROM staff WHERE ";
	if (id > 0) {
		data = db->executeQuerySelect(first_part_query + "id_staff = " + id, "StaffPreview");
	}
	else if (last_name != "" && first_name != "") {
		data = db->executeQuerySelect(first_part_query + "last_name LIKE '" + last_name + "%' AND first_name LIKE '" + first_name + "%'", "StaffPreview");
	}
	else if (last_name != "") {
		data = db->executeQuerySelect(first_part_query + "last_name LIKE '" + last_name + "%'", "StaffPreview");
	}
	else if (first_name != "") {
		data = db->executeQuerySelect(first_part_query + "first_name LIKE '" + first_name + "%'", "StaffPreview");
	}
	else {
		return data;
	}
	delete db;
	return data;
}
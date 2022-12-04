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
	this->getCustomer()->setFirstName(Convert::ToString(data->Tables[0]->Rows[0]->ItemArray[1]));
	this->getCustomer()->setLastName(Convert::ToString(data->Tables[0]->Rows[0]->ItemArray[2]));
	this->getCustomer()->setBirthDate(Convert::ToDateTime(data->Tables[0]->Rows[0]->ItemArray[3]));
	this->getCustomer()->setFirstPurchase(Convert::ToDateTime(data->Tables[0]->Rows[0]->ItemArray[4]));
	this->getDb()->executeQuerySelect("SELECT Address.id_address, address AS Adresse, additional_address AS Adresse_complémentaire, postal_code AS Code_postal, Address.id_city, city_name AS Ville, city.id_country, country_name AS Pays FROM delivered_to JOIN Address ON delivered_to.id_address = Address.id_address JOIN city ON Address.id_city = city.id_city JOIN country ON city.id_country = country.id_country WHERE id_customer = " + this->getCustomer()->getIdCustomer(), "CustomerShippingAddress");
	this->setShippingAddress(this->getDb()->getDataSet());
	this->getDb()->executeQuerySelect("SELECT Address.id_address, address AS Adresse, additional_address AS Adresse_complémentaire, postal_code AS Code_postal, Address.id_city, city_name AS Ville, city.id_country, country_name AS Pays FROM billed_to JOIN Address ON billed_to.id_address = Address.id_address JOIN city ON Address.id_city = city.id_city JOIN country ON city.id_country = country.id_country WHERE id_customer = " + this->getCustomer()->getIdCustomer(), "CustomerBillingAddress");
	this->setBillingAddress(this->getDb()->getDataSet());
	//insert all id_address value in a tab
	this->id_shipping_address = gcnew array<int>(this->getShippingAddress()->Tables[0]->Rows->Count);
	for (int i = 0; i < this->getShippingAddress()->Tables[0]->Rows->Count; i++) {
		this->id_shipping_address[i] = Convert::ToInt32(this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[0]);
	}
	this->id_billing_address = gcnew array<int>(this->getBillingAddress()->Tables[0]->Rows->Count);
	for (int i = 0; i < this->getBillingAddress()->Tables[0]->Rows->Count; i++) {
		this->id_billing_address[i] = Convert::ToInt32(this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[0]);
	}
	
}

void GpCustomer::insertCustomer() {
	int id_user = this->getDb()->executeQueryInsert("INSERT INTO customer (first_name, last_name, birth_date, first_purchase) VALUES ('" + this->getCustomer()->getFirstName() + "', '" + this->getCustomer()->getLastName() + "', '" + this->getCustomer()->getBirthDate() + "', '" + this->getCustomer()->getFirstPurchase() + "'); SELECT @@IDENTITY");
	Address^ address = gcnew Address();
	for (int i = 0; i < this->getShippingAddress()->Tables[0]->Rows->Count-1; i++) {
		address->setCity(this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[4]->ToString());
		address->setCountry(this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[5]->ToString());
		address->CityCountryExist(this->getDb());
		int id_address = this->getDb()->executeQueryInsert("INSERT INTO address (address, additional_address, postal_code, id_city) VALUES ('" + this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[1] + "', '" + this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[2] + "', '" + this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[3] + "', (SELECT id_city FROM city WHERE city_name = '" + this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[4] + "')); SELECT @@IDENTITY");
		this->getDb()->executeQuery("INSERT INTO delivered_to (id_customer, id_address) VALUES ('" + id_user + "', '" + id_address + "')");
	}
	for (int i = 0; i < this->getBillingAddress()->Tables[0]->Rows->Count-1; i++) {
		address->setCity(this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[4]->ToString());
		address->setCountry(this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[5]->ToString());
		address->CityCountryExist(this->getDb());
		int id_address = this->getDb()->executeQueryInsert("INSERT INTO address (address, additional_address, postal_code, id_city) VALUES ('" + this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[1] + "', '" + this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[2] + "', '" + this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[3] + "', (SELECT id_city FROM city WHERE city_name = '" + this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[4] + "')); SELECT @@IDENTITY");
		this->getDb()->executeQuery("INSERT INTO billed_to (id_customer, id_address) VALUES ('" + id_user + "', '" + id_address + "')");
	}
}

void GpCustomer::updateCustomer() {
	this->getDb()->executeQuery("UPDATE customer SET first_name = '" + this->getCustomer()->getFirstName() + "', last_name = '" + this->getCustomer()->getLastName() + "', birth_date = '" + this->getCustomer()->getBirthDate() + "', first_purchase = '" + this->getCustomer()->getFirstPurchase() + "' WHERE id_customer = " + this->getCustomer()->getIdCustomer());
	int nb_shipping_address = this->getDb()->executeQueryInsert("SELECT COUNT(*) FROM delivered_to WHERE id_customer = " + this->getCustomer()->getIdCustomer());
	int nb_billing_address = this->getDb()->executeQueryInsert("SELECT COUNT(*) FROM billed_to WHERE id_customer = " + this->getCustomer()->getIdCustomer());
	Address^ address = gcnew Address();
	int i = 0;
	for (i = 0; i < this->getShippingAddress()->Tables[0]->Rows->Count - 1; i++) {
		address->setCity(this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[4]->ToString());
		address->setCountry(this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[5]->ToString());
		address->CityCountryExist(this->getDb());
		if (i < nb_shipping_address) {
			this->getDb()->executeQuery("UPDATE address SET address = '" + this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[1] + "', additional_address = '" + this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[2] + "', postal_code = '" + this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[3] + "', id_city = (SELECT id_city FROM city WHERE city_name = '" + this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[4] + "') WHERE id_address = " + this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[0]);
			//delete the id _shipping_address from the array
			int j = 0;
			for (j = 0; j < this->id_shipping_address->Length; j++) {
				if (this->id_shipping_address[j] == Convert::ToInt32(this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[0])) {
					this->id_shipping_address[j] = 0;
					break;
				}
			}
		}
		else {
			int id_address = this->getDb()->executeQueryInsert("INSERT INTO address (address, additional_address, postal_code, id_city) VALUES ('" + this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[1] + "', '" + this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[2] + "', '" + this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[3] + "', (SELECT id_city FROM city WHERE city_name = '" + this->getShippingAddress()->Tables[0]->Rows[i]->ItemArray[4] + "')); SELECT @@IDENTITY");
			this->getDb()->executeQuery("INSERT INTO delivered_to (id_customer, id_address) VALUES ('" + this->getCustomer()->getIdCustomer() + "', '" + id_address + "')");
		}
	}
	if (i < nb_shipping_address) {
		//find the id_address to delete with the id_billing_address
		for (int j = 0; j < this->id_shipping_address->Length; j++) {
			if (this->id_shipping_address[j] != 0) {
				this->getDb()->executeQuery("DELETE FROM address WHERE id_address = " + this->id_shipping_address[j]);
			}
		}
	}
	i = 0;
	for (i = 0; i < this->getBillingAddress()->Tables[0]->Rows->Count - 1; i++) {
		address->setCity(this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[4]->ToString());
		address->setCountry(this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[5]->ToString());
		address->CityCountryExist(this->getDb());
		if (i < nb_billing_address) {
			this->getDb()->executeQuery("UPDATE address SET address = '" + this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[1] + "', additional_address = '" + this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[2] + "', postal_code = '" + this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[3] + "', id_city = (SELECT id_city FROM city WHERE city_name = '" + this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[4] + "') WHERE id_address = " + this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[0]);
			int j = 0;
			for (j = 0; j < this->id_billing_address->Length; j++) {
				if (this->id_billing_address[j] == Convert::ToInt32(this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[0])) {
					this->id_billing_address[j] = 0;
					break;
				}
			}
		}
		else {
			int id_address = this->getDb()->executeQueryInsert("INSERT INTO address (address, additional_address, postal_code, id_city) VALUES ('" + this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[1] + "', '" + this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[2] + "', '" + this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[3] + "', (SELECT id_city FROM city WHERE city_name = '" + this->getBillingAddress()->Tables[0]->Rows[i]->ItemArray[4] + "')); SELECT @@IDENTITY");
			this->getDb()->executeQuery("INSERT INTO billed_to (id_customer, id_address) VALUES ('" + this->getCustomer()->getIdCustomer() + "', '" + id_address + "')");
		}
	}
	if (i < nb_billing_address) {
		//find the id_address to delete with the id_billing_address
		for (int j = 0; j < this->id_billing_address->Length; j++) {
			if (this->id_billing_address[j] != 0) {
				this->getDb()->executeQuery("DELETE FROM address WHERE id_address = " + this->id_billing_address[j]);
			}
		}
	}
}

void GpCustomer::deleteCustomer() {
	for (int i = 0; i < this->id_shipping_address->Length; i++) {
		this->getDb()->executeQuery("DELETE FROM delivered_to WHERE id_address = " + this->id_shipping_address[i]);
		this->getDb()->executeQuery("DELETE FROM address WHERE id_address = " + this->id_shipping_address[i]);
	}
	for (int i = 0; i < this->id_billing_address->Length; i++) {
		this->getDb()->executeQuery("DELETE FROM billed_to WHERE id_address = " + this->id_billing_address[i]);
		this->getDb()->executeQuery("DELETE FROM address WHERE id_address = " + this->id_billing_address[i]);
	}
	this->getDb()->executeQuery("DELETE FROM customer WHERE id_customer = " + this->getCustomer()->getIdCustomer());
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
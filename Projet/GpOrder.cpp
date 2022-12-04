#include "GpOrder.h"

GpOrder::GpOrder() {
	order = gcnew Orders();
	order_contain = gcnew DataSet();
	customer = gcnew GpCustomer();
	db = gcnew DatabaseConnection();
}

void GpOrder::setOrder(Orders^ order) {
	this->order = order;
}

void GpOrder::setOrderContain(DataSet^ orderContain) {
	this->order_contain = orderContain;
}

void GpOrder::setCustomer(GpCustomer^ customer) {
	this->customer = customer;
}

void GpOrder::setDb(DatabaseConnection^ db) {
	this->db = db;
}

Orders^ GpOrder::getOrder() {
	return this->order;
}

DataSet^ GpOrder::getOrderContain() {
	return this->order_contain;
}

GpCustomer^ GpOrder::getCustomer() {
	return this->customer;
}

DatabaseConnection^ GpOrder::getDb() {
	return this->db;
}

String^ GpOrder::createOrderReference(String^ firstName, String^ lastName, String^ city) {
	String^ year = DateTime::Now.Year.ToString();
	String^ orderReference = firstName->Substring(0, 2) + lastName->Substring(0, 2) + year + city->Substring(0, 3);
	this->getDb()->executeQuerySelect("SELECT COUNT(*) FROM orders WHERE order_reference LIKE '" + orderReference + "%'", "Orders");
	int count = Convert::ToInt32(this->getDb()->getDataSet()->Tables[0]->Rows[0]->ItemArray[0]);
	orderReference += (count + 1).ToString();
	return orderReference->ToUpper();
}

void GpOrder::addOrder(int id_shipping_address, int id_billing_address, String^ shipping_city) {
	String^ order_reference = this->createOrderReference(this->getCustomer()->getCustomer()->getFirstName(), this->getCustomer()->getCustomer()->getLastName(), shipping_city);
	int id = this->getDb()->executeQueryInsert("INSERT INTO orders (order_reference, delivery_date, id_customer, id_shipping_address, id_billing_address) VALUES ('" + order_reference + "', '" + this->getOrder()->getDeliveryDate() + "', " + this->getCustomer()->getCustomer()->getIdCustomer() + ", " + id_shipping_address + ", " + id_billing_address + "); SELECT @@IDENTITY;");
	for (int i = 0; i < this->getOrderContain()->Tables[0]->Rows->Count; i++) {
		this->getDb()->executeQueryInsert("INSERT INTO order_contain (id_order, id_item, id_item_price, quantity, commercial_discount) VALUES (" + id + ", " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[0] + ", " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[1] + ", " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[2] + ", " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[3] + ");");
		this->getDb()->executeQueryInsert("UPDATE item SET in_stock = in_stock - " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[2] + " WHERE id_item = " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[0] + ";");
	}
}
#include "GpOrder.h"

GpOrder::GpOrder() {
	order = gcnew Orders();
	order_contain = gcnew DataSet();
	customer = gcnew GpCustomer();
	db = gcnew DatabaseConnection();
}

GpOrder::~GpOrder() {
	delete order;
	delete order_contain;
	delete customer;
	delete db;
}

void GpOrder::setOrder(Orders^ order) {
	this->order = order;
}

void GpOrder::setOrderContain(DataSet^ orderContain) {
	this->order_contain = orderContain;
}

void GpOrder::setPreviousOrderContain(DataSet^ previousOrderContain) {
	this->previous_order_contain = previousOrderContain;
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

DataSet^ GpOrder::getPreviousOrderContain() {
	return this->previous_order_contain;
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
		this->getDb()->executeQuery("INSERT INTO order_contain (id_order, id_item, id_item_price, quantity, commercial_discount) VALUES (" + id + ", " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[0] + ", " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[1] + ", " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[2] + ", " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[3] + ");");
		this->getDb()->executeQuery("UPDATE item SET in_stock = in_stock - " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[2] + " WHERE id_item = " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[0] + ";");
	}
}

void GpOrder::selectOrder(int id) {
	this->getDb()->executeQuerySelect("SELECT * FROM orders WHERE id_order = " + id, "Orders");
	DataSet^ data = this->getDb()->getDataSet();
	this->getOrder()->setIdOrder(Convert::ToInt32(data->Tables[0]->Rows[0]->ItemArray[0]));
	this->getOrder()->setOrderReference(data->Tables[0]->Rows[0]->ItemArray[1]->ToString());
	this->getOrder()->setDeliveryDate(Convert::ToDateTime(data->Tables[0]->Rows[0]->ItemArray[2]));
	this->getOrder()->setIssueDate(Convert::ToDateTime(data->Tables[0]->Rows[0]->ItemArray[3]));
	this->getOrder()->setIdShippingAddress(Convert::ToInt32(data->Tables[0]->Rows[0]->ItemArray[6]));
	this->getOrder()->setIdBillingAddress(Convert::ToInt32(data->Tables[0]->Rows[0]->ItemArray[7]));
	this->getDb()->executeQuerySelect("SELECT item.id_item, order_contain.id_item_price, item_reference, item_name, item_price_et, vat_rate, quantity, commercial_discount, in_stock, id_order_contain FROM order_contain JOIN item ON order_contain.id_item = item.id_item JOIN item_price ON order_contain.id_item_price = item_price.id_item_price WHERE id_order = " + id, "OrderContain");
	this->setOrderContain(this->getDb()->getDataSet());
	this->setPreviousOrderContain(this->getDb()->getDataSet());
}

void GpOrder::updateOrder(int id_shipping_address, int id_billing_address) {
	this->getDb()->executeQuery("UPDATE orders SET delivery_date = '" + this->getOrder()->getDeliveryDate() + "', id_shipping_address = " + id_shipping_address + ", id_billing_address = " + id_billing_address + " WHERE id_order = " + this->getOrder()->getIdOrder() + ";");
	for (int i = 0; i < this->getPreviousOrderContain()->Tables[0]->Rows->Count; i++) {
		this->getDb()->executeQuery("UPDATE item SET in_stock = in_stock + " + this->getPreviousOrderContain()->Tables[0]->Rows[i]->ItemArray[6] + " WHERE id_item = " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[0] + ";");
		this->getDb()->executeQuery("DELETE FROM order_contain WHERE id_order_contain = " + this->getPreviousOrderContain()->Tables[0]->Rows[i]->ItemArray[9] + ";");
	}
	for (int i = 0; i < this->getOrderContain()->Tables[0]->Rows->Count; i++) {
		this->getDb()->executeQuery("INSERT INTO order_contain (id_order, id_item, id_item_price, quantity, commercial_discount) VALUES (" + this->getOrder()->getIdOrder() + ", " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[0] + ", " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[1] + ", " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[2] + ", " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[3] + ");");
		this->getDb()->executeQuery("UPDATE item SET in_stock = in_stock - " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[2] + " WHERE id_item = " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[0] + ";");
	}
}

void GpOrder::deleteOrder() {
	for (int i = 0; i < this->getOrderContain()->Tables[0]->Rows->Count; i++) {
		this->getDb()->executeQuery("UPDATE item SET in_stock = in_stock + " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[6] + " WHERE id_item = " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[0] + ";");
		this->getDb()->executeQuery("DELETE FROM order_contain WHERE id_order_contain = " + this->getOrderContain()->Tables[0]->Rows[i]->ItemArray[9] + ";");
	}
	this->getDb()->executeQuery("DELETE FROM orders WHERE id_order = " + this->getOrder()->getIdOrder() + ";");
}

DataSet^ GpOrder::orderPreview(String^ order_reference, String^ customer_lname) {
	DataSet^ data;
	String^ first_part_query = "SELECT id_order, orders.id_customer, order_reference AS Référence_commande, issue_date AS Passage_commande, customer.last_name AS Nom_client, customer.first_name AS Prénom_client FROM orders JOIN customer ON orders.id_customer = customer.id_customer WHERE ";
	String^ end_part_query = " ORDER BY issue_date DESC";
	if (order_reference != "") {
		data = this->getDb()->executeQuerySelect(first_part_query + "order_reference LIKE '" + order_reference + "%'" + end_part_query, "Preview");
	}
	else if (customer_lname != "") {
		data = this->getDb()->executeQuerySelect(first_part_query + "last_name LIKE '" + customer_lname + "%'" + end_part_query, "Preview");
	}
	else {
		return data;
	}
	return data;
}
#include "Orders.h"

Orders::Orders() {
	this->id_order = 0;
	this->order_reference = "";
	this->delivery_date = DateTime::Now;
	this->issue_date = DateTime::Now;
	this->pay_date = DateTime::Now;
	this->id_customer = 0;
}

void Orders::setIdOrder(int id_order) {
	this->id_order = id_order;
}

void Orders::setOrderReference(String^ order_reference) {
	this->order_reference = order_reference;
}

void Orders::setDeliveryDate(DateTime^ delivery_date) {
	this->delivery_date = delivery_date;
}

void Orders::setIssueDate(DateTime^ issue_date) {
	this->issue_date = issue_date;
}

void Orders::setPayDate(DateTime^ pay_date) {
	this->pay_date = pay_date;
}

void Orders::setIdCustomer(int id_customer) {
	this->id_customer = id_customer;
}

int Orders::getIdOrder() {
	return this->id_order;
}

String^ Orders::getOrderReference() {
	return this->order_reference;
}

DateTime^ Orders::getDeliveryDate() {
	return this->delivery_date;
}

DateTime^ Orders::getIssueDate() {
	return this->issue_date;
}

DateTime^ Orders::getPayDate() {
	return this->pay_date;
}

int Orders::getIdCustomer() {
	return this->id_customer;
}
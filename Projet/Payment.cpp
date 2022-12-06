#include "Payment.h"

Payment::Payment() {
	this->id_payment = 0;
	this->payment_date = DateTime::Now;
	this->payment_amount = 0.0;
	this->id_payment_method = 0;
	this->payment_method = "";
}

void Payment::setIdPayment(int id_payment) {
	this->id_payment = id_payment;
}

void Payment::setPaymentDate(DateTime^ payment_date) {
	this->payment_date = payment_date;
}

void Payment::setPaymentAmount(float payment_amount) {
	this->payment_amount = payment_amount;
}

void Payment::setIdPaymentMethod(int id_payment_method) {
	this->id_payment_method = id_payment_method;
}

void Payment::setPaymentMethod(String^ payment_method) {
	this->payment_method = payment_method;
}

int Payment::getIdPayment() {
	return this->id_payment;
}

DateTime^ Payment::getPaymentDate() {
	return this->payment_date;
}

float Payment::getPaymentAmount() {
	return this->payment_amount;
}

int Payment::getIdPaymentMethod() {
	return this->id_payment_method;
}

String^ Payment::getPaymentMethod() {
	return this->payment_method;
}

DataSet^ Payment::getPaymentMethods(DatabaseConnection^ db) {
	DataSet^ ds = gcnew DataSet();
	ds = db->executeQuerySelect("SELECT * FROM payment_method", "payment_method");
	return ds;
}

void Payment::savePayment(int id_order, DataSet^ ds) {
	DatabaseConnection^ db = gcnew DatabaseConnection();
	for (int i = 0; i < ds->Tables[0]->Rows->Count; i++) {
		if (ds->Tables[0]->Rows[i]->ItemArray[3]->ToString() == "") {
			db->executeQueryInsert("INSERT INTO payment (payment_date, payment_amount, id_order, id_payment_method) VALUES ('" + ds->Tables[0]->Rows[i]->ItemArray[0]->ToString() + "', '" + ds->Tables[0]->Rows[i]->ItemArray[1]->ToString() + "', '" + id_order + "', (SELECT id_payment_method FROM payment_method WHERE payment_method = '" + ds->Tables[0]->Rows[i]->ItemArray[2]->ToString() + "'))");
		}
	}
}

DataSet^ Payment::getPayments(DatabaseConnection^ db, int id_order) {
	DataSet^ ds = gcnew DataSet();
	ds = db->executeQuerySelect("SELECT payment_date, payment_amount, payment_method, id_payment FROM payment JOIN payment_method ON payment.id_payment_method = payment_method.id_payment_method WHERE id_order = " + id_order, "payment");
	return ds;
}
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
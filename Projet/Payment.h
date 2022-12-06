#pragma once
#include "DatabaseConnection.h"
using namespace System;
using namespace System::Data;

ref class Payment {
private:
	int id_payment;
	DateTime^ payment_date;
	float payment_amount;
	int id_payment_method;
	String^ payment_method;
public:
	Payment();
	void setIdPayment(int);
	void setPaymentDate(DateTime^);
	void setPaymentAmount(float);
	void setIdPaymentMethod(int);
	void setPaymentMethod(String^);
	int getIdPayment();
	DateTime^ getPaymentDate();
	float getPaymentAmount();
	int getIdPaymentMethod();
	String^ getPaymentMethod();
	DataSet^ getPaymentMethods(DatabaseConnection^ db);
};
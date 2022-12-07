#pragma once
using namespace System;

ref class Customer {
private:
	int id_customer;
	String^ first_name;
	String^ last_name;
	DateTime^ birth_date;
	DateTime^ first_purchase;
public:
	Customer();
	void setIdCustomer(int);
	void setFirstName(String^);
	void setLastName(String^);
	void setBirthDate(DateTime^);
	void setFirstPurchase(DateTime^);
	int getIdCustomer();
	String^ getFirstName();
	String^ getLastName();
	DateTime^ getBirthDate();
	DateTime^ getFirstPurchase();
};
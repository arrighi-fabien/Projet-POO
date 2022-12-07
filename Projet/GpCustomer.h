#pragma once
#include "Customer.h"
#include "Address.h"
#include "DatabaseConnection.h"
using namespace System;
using namespace System::Data;

ref class GpCustomer {
private:
	Customer^ customer;
	DataSet^ billing_address;
	DataSet^ shipping_address;
	DatabaseConnection^ db;
	array<int>^ id_billing_address;
	array<int>^ id_shipping_address;
public:
	GpCustomer();
	~GpCustomer();
	void setCustomer(Customer^);
	void setBillingAddress(DataSet^);
	void setShippingAddress(DataSet^);
	void setDb(DatabaseConnection^);
	Customer^ getCustomer();
	DataSet^ getBillingAddress();
	DataSet^ getShippingAddress();
	DatabaseConnection^ getDb();
	bool selectCustomer(int);
	void insertCustomer();
	void updateCustomer();
	void deleteCustomer();
	DataSet^ customerPreview(int, String^, String^);
};
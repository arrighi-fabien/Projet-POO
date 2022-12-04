#pragma once
using namespace System;

ref class Orders {
private:
	int id_order;
	String^ order_reference;
	DateTime^ delivery_date;
	DateTime^ issue_date;
	DateTime^ pay_date;
	int id_customer;
	int id_shipping_address;
	int id_billing_address;
public:
	Orders();
	void setIdOrder(int);
	void setOrderReference(String^);
	void setDeliveryDate(DateTime^);
	void setIssueDate(DateTime^);
	void setPayDate(DateTime^);
	void setIdCustomer(int);
	void setIdShippingAddress(int);
	void setIdBillingAddress(int);
	int getIdOrder();
	String^ getOrderReference();
	DateTime^ getDeliveryDate();
	DateTime^ getIssueDate();
	DateTime^ getPayDate();
	int getIdCustomer();
	int getIdShippingAddress();
	int getIdBillingAddress();
};
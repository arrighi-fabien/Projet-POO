#pragma once
#include "GpCustomer.h"
#include "Orders.h"
#include "OrderContain.h"
#include "Address.h"
#include "DatabaseConnection.h"

ref class GpOrder {
private:
	Orders^ order;
	DataSet^ order_contain;
	GpCustomer^ customer;
	DatabaseConnection^ db;
public:
	GpOrder();
	void setOrder(Orders^ order);
	void setOrderContain(DataSet^ order_contain);
	void setCustomer(GpCustomer^ customer);
	void setDb(DatabaseConnection^ db);
	Orders^ getOrder();
	DataSet^ getOrderContain();
	GpCustomer^ getCustomer();
	DatabaseConnection^ getDb();
	String^ createOrderReference(String^, String^, String^);
	void addOrder(int, int, String^);
};
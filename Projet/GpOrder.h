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
	DataSet^ previous_order_contain;
	GpCustomer^ customer;
	DatabaseConnection^ db;
public:
	GpOrder();
	~GpOrder();
	void setOrder(Orders^ order);
	void setOrderContain(DataSet^ order_contain);
	void setPreviousOrderContain(DataSet^ previous_order_contain);
	void setCustomer(GpCustomer^ customer);
	void setDb(DatabaseConnection^ db);
	Orders^ getOrder();
	DataSet^ getOrderContain();
	DataSet^ getPreviousOrderContain();
	GpCustomer^ getCustomer();
	DatabaseConnection^ getDb();
	String^ createOrderReference(String^, String^, String^);
	void addOrder(int, int, String^);
	void selectOrder(int);
	void updateOrder(int, int);
	void deleteOrder();
	DataSet^ orderPreview(String^, String^);
};
#pragma once
using namespace System;

ref class OrderContain {
private:
	int quantity;
	float commercial_discount;
	int id_item;
	int id_item_price;
	int id_order;
public:
	OrderContain();
	void setQuantity(int);
	void setCommercialDiscount(float);
	void setIdItem(int);
	void setIdItemPrice(int);
	void setIdOrder(int);
	int getQuantity();
	float getCommercialDiscount();
	int getIdItem();
	int getIdItemPrice();
	int getIdOrder();
};
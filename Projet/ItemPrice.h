#pragma once
using namespace System;

ref class ItemPrice {
private:
	int id_item_price;
	float vat_rate;
	float item_price_et;
	DateTime^ date_change;
	int id_item;
public:
	ItemPrice();
	void setIdItemPrice(int id_item_price);
	void setVatRate(float vat_rate);
	void setItemPriceEt(float item_price_et);
	void setDateChange(DateTime^ date_change);
	void setIdItem(int id_item);
	int getIdItemPrice();
	float getVatRate();
	float getItemPriceEt();
	DateTime^ getDateChange();
	int getIdItem();
};
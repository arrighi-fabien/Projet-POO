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
	void setIdItemPrice(int);
	void setVatRate(float);
	void setItemPriceEt(float);
	void setDateChange(DateTime^);
	void setIdItem(int);
	int getIdItemPrice();
	float getVatRate();
	float getItemPriceEt();
	DateTime^ getDateChange();
	int getIdItem();
};
#include "ItemPrice.h"

ItemPrice::ItemPrice() {
	
}

void ItemPrice::setIdItemPrice(int id_item_price) {
	this->id_item_price = id_item_price;
}

void ItemPrice::setVatRate(float vat_rate) {
	this->vat_rate = vat_rate;
}

void ItemPrice::setItemPriceEt(float item_price_et) {
	this->item_price_et = item_price_et;
}

void ItemPrice::setDateChange(DateTime^ date_change) {
	this->date_change = date_change;
}

void ItemPrice::setIdItem(int id_item) {
	this->id_item = id_item;
}

int ItemPrice::getIdItemPrice() {
	return this->id_item_price;
}

float ItemPrice::getVatRate() {
	return this->vat_rate;
}

float ItemPrice::getItemPriceEt() {
	return this->item_price_et;
}

DateTime^ ItemPrice::getDateChange() {
	return this->date_change;
}

int ItemPrice::getIdItem() {
	return this->id_item;
}
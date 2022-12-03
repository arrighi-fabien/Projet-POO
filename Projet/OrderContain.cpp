#include "OrderContain.h"

OrderContain::OrderContain() {
	this->quantity = 0;
	this->commercial_discount = 0.0;
	this->id_item = 0;
	this->id_item_price = 0;
	this->id_order = 0;
}

void OrderContain::setQuantity(int quantity) {
	this->quantity = quantity;
}

void OrderContain::setCommercialDiscount(float commercial_discount) {
	this->commercial_discount = commercial_discount;
}

void OrderContain::setIdItem(int id_item) {
	this->id_item = id_item;
}

void OrderContain::setIdItemPrice(int id_item_price) {
	this->id_item_price = id_item_price;
}

void OrderContain::setIdOrder(int id_order) {
	this->id_order = id_order;
}

int OrderContain::getQuantity() {
	return this->quantity;
}

float OrderContain::getCommercialDiscount() {
	return this->commercial_discount;
}

int OrderContain::getIdItem() {
	return this->id_item;
}

int OrderContain::getIdItemPrice() {
	return this->id_item_price;
}

int OrderContain::getIdOrder() {
	return this->id_order;
}
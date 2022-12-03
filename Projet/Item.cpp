#include "Item.h"

Item::Item() {
	
}

void Item::setIdItem(int id_item) {
	this->id_item = id_item;
}

void Item::setItemReference(String^ item_reference) {
	this->item_reference = item_reference;
}

void Item::setItemName(String^ item_name) {
	this->item_name = item_name;
}

void Item::setInStock(int in_stock) {
	this->in_stock = in_stock;
}

void Item::setRestockingLevel(int restocking_level) {
	this->restocking_level = restocking_level;
}

void Item::setIdItemCategory(int id_item_category) {
	this->id_item_category = id_item_category;
}

void Item::setItemCategoryName(String^ item_category_name) {
	this->item_category_name = item_category_name;
}

int Item::getIdItem() {
	return this->id_item;
}

String^ Item::getItemReference() {
	return this->item_reference;
}

String^ Item::getItemName() {
	return this->item_name;
}

int Item::getInStock() {
	return this->in_stock;
}

int Item::getRestockingLevel() {
	return this->restocking_level;
}

int Item::getIdItemCategory() {
	return this->id_item_category;
}

String^ Item::getItemCategoryName() {
	return this->item_category_name;
}
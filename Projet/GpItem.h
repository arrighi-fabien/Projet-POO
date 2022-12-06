#pragma once
#include "Item.h"
#include "ItemPrice.h"
#include "DatabaseConnection.h"
using namespace System;
using namespace System::Data;

ref class GpItem {
private:
	Item^ item;
	ItemPrice^ itemPrice;
	DatabaseConnection^ db;
public:
	GpItem();
	~GpItem();
	void setItem(Item^ item);
	void setItemPrice(ItemPrice^ itemPrice);
	void setDb(DatabaseConnection^ db);
	Item^ getItem();
	ItemPrice^ getItemPrice();
	DatabaseConnection^ getDb();
	void selectItem(String^ item_reference);
	void insertItem();
	void updateItem(bool);
	void deleteItem();
	DataSet^ itemCategory();
	DataSet^ priceHistory();
	DataSet^ itemPreview(String^, String^);
};
#pragma once
using namespace System;
using namespace System::Data;

ref class Item {
private:
	int id_item;
	String^ item_reference;
	String^ item_name;
	int in_stock;
	int restocking_level;
	int id_item_category;
	String^ item_category_name;
public:
	Item();
	void setIdItem(int);
	void setItemReference(String^);
	void setItemName(String^);
	void setInStock(int);
	void setRestockingLevel(int);
	void setIdItemCategory(int);
	void setItemCategoryName(String^);
	int getIdItem();
	String^ getItemReference();
	String^ getItemName();
	int getInStock();
	int getRestockingLevel();
	int getIdItemCategory();
	String^ getItemCategoryName();
};
#include "GpItem.h"

GpItem::GpItem() {
	this->item = gcnew Item();
	this->itemPrice = gcnew ItemPrice();
	this->db = gcnew DatabaseConnection();
}

void GpItem::setItem(Item^ item) {
	this->item = item;
}

void GpItem::setItemPrice(ItemPrice^ itemPrice) {
	this->itemPrice = itemPrice;
}

void GpItem::setDb(DatabaseConnection^ db) {
	this->db = db;
}

Item^ GpItem::getItem() {
	return this->item;
}

ItemPrice^ GpItem::getItemPrice() {
	return this->itemPrice;
}

DatabaseConnection^ GpItem::getDb() {
	return this->db;
}

void GpItem::selectItem(String^ item_reference) {
	this->getDb()->executeQuerySelect("SELECT * FROM item JOIN item_category ON item.id_item_category = item_category.id_item_category WHERE item_reference = '" + item_reference + "'", "Item");
	DataSet^ data = this->getDb()->getDataSet();
	this->getDb()->executeQuerySelect("SELECT TOP 1 * FROM item_price WHERE id_item = " + Convert::ToInt32(data->Tables[0]->Rows[0]->ItemArray[0]) + " ORDER BY date_change DESC", "ItemPrice");
	DataSet^ data2 = this->getDb()->getDataSet();
	this->getItem()->setIdItem(Convert::ToInt32(data->Tables[0]->Rows[0]->ItemArray[0]));
	this->getItem()->setItemReference(data->Tables[0]->Rows[0]->ItemArray[1]->ToString());
	this->getItem()->setItemName(data->Tables[0]->Rows[0]->ItemArray[2]->ToString());
	this->getItem()->setInStock(Convert::ToInt32(data->Tables[0]->Rows[0]->ItemArray[3]));
	this->getItem()->setRestockingLevel(Convert::ToInt32(data->Tables[0]->Rows[0]->ItemArray[4]));
	this->getItem()->setIdItemCategory(Convert::ToInt32(data->Tables[0]->Rows[0]->ItemArray[5]));
	this->getItem()->setItemCategoryName(data->Tables[0]->Rows[0]->ItemArray[7]->ToString());
	this->getItemPrice()->setIdItemPrice(Convert::ToInt32(data2->Tables[0]->Rows[0]->ItemArray[0]));
	this->getItemPrice()->setVatRate(Convert::ToDouble(data2->Tables[0]->Rows[0]->ItemArray[1]));
	this->getItemPrice()->setItemPriceEt(Convert::ToDouble(data2->Tables[0]->Rows[0]->ItemArray[2]));
}

void GpItem::insertItem() {
	String^ price = Convert::ToString(this->getItemPrice()->getItemPriceEt());
	price = price->Replace(",", ".");
	String^ vat_rate = Convert::ToString(this->getItemPrice()->getVatRate());
	vat_rate = vat_rate->Replace(",", ".");
	int id = this->getDb()->executeQueryInsert("INSERT INTO item (item_reference, item_name, in_stock, restocking_level, id_item_category) VALUES ('" + this->getItem()->getItemReference() + "', '" + this->getItem()->getItemName() + "', " + this->getItem()->getInStock() + ", " + this->getItem()->getRestockingLevel() + ", (SELECT id_item_category FROM item_category WHERE item_category_name = '" + this->getItem()->getItemCategoryName() + "')) SELECT @@IDENTITY");
	this->getDb()->executeQuery("INSERT INTO item_price (vat_rate, item_price_et, id_item) VALUES (" + vat_rate + ", " + price + "," + id + ")");
}

void GpItem::updateItem(bool updatePrice) {
	if (updatePrice) {
		String^ price = Convert::ToString(this->getItemPrice()->getItemPriceEt());
		price = price->Replace(",", ".");
		String^ vat_rate = Convert::ToString(this->getItemPrice()->getVatRate());
		vat_rate = vat_rate->Replace(",", ".");
		this->getDb()->executeQuery("INSERT INTO item_price (id_item, vat_rate, item_price_et) VALUES (" + this->getItem()->getIdItem() + ", " + vat_rate + ", " + price + ")");
	}
	else {
		this->getDb()->executeQuery("UPDATE item SET item_reference = '" + this->getItem()->getItemReference() + "', item_name = '" + this->getItem()->getItemName() + "', in_stock = " + this->getItem()->getInStock() + ", restocking_level = " + this->getItem()->getRestockingLevel() + ", id_item_category = " + this->getItem()->getIdItemCategory() + " WHERE id_item = " + this->getItem()->getIdItem());
	}
}

void GpItem::deleteItem() {
	this->getDb()->executeQuery("DELETE FROM item_price WHERE id_item = " + this->getItem()->getIdItem());
	this->getDb()->executeQuery("DELETE FROM item WHERE id_item = " + this->getItem()->getIdItem());
}

DataSet^ GpItem::itemCategory() {
	this->getDb()->executeQuerySelect("SELECT * FROM item_category", "ItemCategory");
	return this->getDb()->getDataSet();
}

DataSet^ GpItem::priceHistory() {
	this->getDb()->executeQuerySelect("SELECT item_price_et AS Prix_HT, vat_rate AS TVA, date_change AS Date_changement FROM item_price WHERE id_item = " + this->getItem()->getIdItem() + " ORDER BY date_change DESC", "ItemPriceHistory");
	return this->getDb()->getDataSet();
}

DataSet^ GpItem::itemPreview(String^ item_reference, String^ item_name) {
	DataSet^ data;
	String^ first_part_query = "SELECT TOP 1 item_reference AS Référence, item_name AS Désignation, item_price_et AS Prix_HT, vat_rate AS Taux_TVA FROM item JOIN item_price ON item.id_item = item_price.id_item WHERE ";
	String^ end_part_query = " ORDER BY date_change DESC";
	if (item_reference != "") {
		data = this->getDb()->executeQuerySelect(first_part_query + "item_reference LIKE '" + item_reference + "%'" + end_part_query, "Preview");
	}
	else if (item_name != "") {
		data = this->getDb()->executeQuerySelect(first_part_query + "item_name LIKE '" + item_name + "%'" + end_part_query, "Preview");
	}
	else {
		return data;
	}
	return data;
}
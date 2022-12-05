#include "GpStat.h"

GpStat::GpStat() {
	db = gcnew DatabaseConnection();
}

void GpStat::setDb(DatabaseConnection^ db) {
	this->db = db;
}

DatabaseConnection^ GpStat::getDb() {
	return db;
}

DataSet^ GpStat::getItemUnderRestockingLevel() {
	this->getDb()->executeQuerySelect("SELECT item_reference, item_name, in_stock, restocking_level FROM Item WHERE in_stock < restocking_level", "Stat");
	return this->getDb()->getDataSet();
}

String^ GpStat::getStockCommercialValue() {
	float total = 0;
	this->getDb()->executeQuerySelect("SELECT id_item FROM item", "Stat");
	DataSet^ data = this->getDb()->getDataSet();
	int nb_item = Convert::ToInt32(data->Tables["Stat"]->Rows->Count);
	DataSet^ data2;
	for (int i = 0; i < nb_item; i++) {
		this->getDb()->executeQuerySelect("SELECT item_price_et, vat_rate, in_stock FROM item JOIN item_price ON item.id_item = item_price.id_item WHERE id_item_price IN (SELECT TOP 1 id_item_price FROM item_price JOIN item ON item_price.id_item = item.id_item WHERE item.id_item = " + data->Tables["Stat"]->Rows[i]->ItemArray[0] + " ORDER BY date_change DESC)", "Stat");
		data2 = this->getDb()->getDataSet();
		total += Convert::ToSingle(data2->Tables["Stat"]->Rows[0]->ItemArray[0]) * (Convert::ToSingle(data2->Tables["Stat"]->Rows[0]->ItemArray[1]) + 1) * Convert::ToInt32(data2->Tables["Stat"]->Rows[0]->ItemArray[2]);
	}
	total = roundf(total * 100) / 100;
	String^ total_str = Convert::ToString(total + " €");
	return total_str;
}

String^ GpStat::getTotalSpendCustomer(int id_customer) {
	float total = 0;
	this->getDb()->executeQuerySelect("SELECT SUM(item_price_et * (vat_rate + 1) * quantity) FROM item_price JOIN order_contain ON item_price.id_item_price = order_contain.id_item_price JOIN orders ON order_contain.id_order = orders.id_order WHERE id_customer = " + id_customer, "Stat");
	DataSet^ data = this->getDb()->getDataSet();
	//detect if dataset id null
	if (data->Tables["Stat"]->Rows[0]->ItemArray[0] != System::DBNull::Value) {
		total = Convert::ToSingle(data->Tables["Stat"]->Rows[0]->ItemArray[0]);
		total = roundf(total * 100) / 100;
		String^ total_str = Convert::ToString(total + " €");
		return total_str;
	}
	MessageBox::Show("Veuillez entrer un id de client valide", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
#pragma once
#include "DatabaseConnection.h"
#include <math.h>
using namespace System;
using namespace System::Windows::Forms;

ref class GpStat {
private:
	DatabaseConnection^ db;
public:
	GpStat();
	~GpStat();
	void setDb(DatabaseConnection^);
	DatabaseConnection^ getDb();
	DataSet^ getItemUnderRestockingLevel();
	String^ getStockCommercialValue();
	String^ getTotalSpendCustomer(int);
	DataSet^ getTop10Item();
	DataSet^ getWorst10Item();
};
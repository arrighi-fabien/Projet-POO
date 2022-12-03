#pragma once
#include "DatabaseConnection.h"
#include <math.h>
using namespace System;

ref class GpStat {
private:
	DatabaseConnection^ db;
public:
	GpStat();
	void setDb(DatabaseConnection^);
	DatabaseConnection^ getDb();
	DataSet^ getItemUnderRestockingLevel();
	String^ getStockCommercialValue();
};
#pragma once
#include "Staff.h"
#include "Address.h"
#include "DatabaseConnection.h"
using namespace System;
using namespace System::Data;

ref class GpStaff {
private:
	Staff^ staff;
	Address^ address;
	DatabaseConnection^ db;
public:
	GpStaff();
	~GpStaff();
	void setStaff(Staff^);
	void setAddress(Address^);
	void setDb(DatabaseConnection^);
	Staff^ getStaff();
	Address^ getAddress();
	DatabaseConnection^ getDb();
	void selectStaff(int);
	void insertStaff();
	void updateStaff();
	void deleteStaff();
	DataSet^ staffPreview(int, String^, String^);
};
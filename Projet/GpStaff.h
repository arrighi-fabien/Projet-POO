#pragma once
#include "Staff.h"
#include "Address.h"
using namespace System;
using namespace System::Data;

ref class GpStaff {
private:
	Staff^ staff;
	Address^ address;
public:
	GpStaff();
	void setStaff(Staff^);
	void setAddress(Address^);
	Staff^ getStaff();
	Address^ getAddress();
	void selectStaff(int);
	void insertStaff();
	void updateStaff();
	void deleteStaff();
	DataSet^ staffPreview(int, String^, String^);
};
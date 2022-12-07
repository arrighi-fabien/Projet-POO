#pragma once
using namespace System;

ref class Staff {
private:
	int id_staff;
	String^ first_name;
	String^ last_name;
	DateTime^ hiring_date;
	int id_manager;
public:
	Staff();
	void setIdStaff(int);
	void setFirstName(String^);
	void setLastName(String^);
	void setHiringDate(DateTime^);
	void setIdManager(int);
	int getIdStaff();
	String^ getFirstName();
	String^ getLastName();
	DateTime^ getHiringDate();
	int getIdManager();
};
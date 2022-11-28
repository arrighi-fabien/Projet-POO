#pragma once
using namespace System;

ref class Staff {
private:
	int id_staff;
	String^ first_name;
	String^ last_name;
	DateTime^ hiring_date;
	int id_manager;
	int id_address;
	String^ address;
	String^ address_o;
	String^ postal_code;
	int id_city;
	String^ city;
	int id_country;
	String^ country;
public:
	Staff();
	void setIdStaff(int);
	void setFirstName(String^);
	void setLastName(String^);
	void setHiringDate(DateTime^);
	void setIdManager(int);
	void setIdAddress(int);
	void setAddress(String^);
	void setAddressO(String^);
	void setPostalCode(String^);
	void setIdCity(int);
	void setCity(String^);
	void setIdCountry(int);
	void setCountry(String^);
	int getIdStaff();
	String^ getFirstName();
	String^ getLastName();
	DateTime^ getHiringDate();
	int getIdManager();
	int getIdAddress();
	String^ getAddress();
	String^ getAddressO();
	String^ getPostalCode();
	int getIdCity();
	String^ getCity();
	int getIdCountry();
	String^ getCountry();

	void selectStaff(int);
	void insertStaff();
	void updateStaff();
	//void deleteStaff();
};
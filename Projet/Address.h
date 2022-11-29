#pragma once
using namespace System;

ref class Address {
private:
	int id_address;
	String^ address;
	String^ address_o;
	String^ postal_code;
	int id_city;
	String^ city;
	int id_country;
	String^ country;
public:
	Address();
	void setIdAddress(int);
	void setAddress(String^);
	void setAddressO(String^);
	void setPostalCode(String^);
	void setIdCity(int);
	void setCity(String^);
	void setIdCountry(int);
	void setCountry(String^);
	int getIdAddress();
	String^ getAddress();
	String^ getAddressO();
	String^ getPostalCode();
	int getIdCity();
	String^ getCity();
	int getIdCountry();
	String^ getCountry();
};
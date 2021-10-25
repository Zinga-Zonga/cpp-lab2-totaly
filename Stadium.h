#pragma once
#include<iostream>
#include <string>
#include <fstream>

class Stadium
{
public:

	Stadium();
	Stadium(const std::string& adress, const std::string& club, const int& capacity, const int& sectorsAmount, const int& visitors);
	//~Stadium();
	// --------------------------------------------------get/set---------------------------------------------------------------
	std::string getAdress();
	void setAdress(const std::string& adress);

	std::string getClub();
	void setClub(const std::string& club);

	int getCapacity();
	void setCapacity(const int& capacity); // вместительность

	int getSectorsAmount();
	void setSectorsAmount(const int& sa);

	int getAttendance();
	void setAttendance(int attend); // посещаемость

	friend std::ostream& operator<< (std::ostream& out, const Stadium& point);
	// ----------------------------------------------------------------------------------------------------------------------------
	

	void serialize();
	void serialize(const std::string& filename);
	void deserialize();
	void deserialize(const std::string& filename);
	void GenVisitors();

private:
	void attendCalculate();
	std::string adress_;
	std::string club_;
	int capacity_;
	int sectrorsAmount_;
	float attendance_;
	int visitors_ = 0;
};


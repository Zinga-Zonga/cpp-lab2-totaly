#pragma once
#include <iostream>

class Vector

{
public:
	Vector();
	Vector(const int size);
	~Vector();
	
	int size();

	int& operator[] (const int index);
	void operator++(); // post
	void operator++(int); // pre
	void operator--(); // post
	void operator--(int); //pre

	
	void printFormatted();

	friend std::ostream& operator<< (std::ostream& out, const Vector& point);

private:
	int size_;
	int* vector;
	


};


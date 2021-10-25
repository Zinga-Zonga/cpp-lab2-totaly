#include "Vector.h"
#include <iostream>

Vector::Vector()
{
	vector = new int[1];
	size_ = 1;
}

Vector::Vector(const int size) {
	vector = new int[size];
	size_ = size;
}
Vector::~Vector()
{
	delete[] vector;
}
int Vector::size()
{
	int size = size_;
	return size;
}
int& Vector::operator[](const int index)
{
	return vector[index];
}
void Vector::operator++()
{
	for (int i = 0; i < size_; i++) {
		vector[i]++;
	}
	
}

void Vector::operator++(int)
{
	for (int i = 0; i < size_; i++)
	{
		++vector[i];
	}
	
}

void Vector::operator--()
{
	for (int i = 0; i < size_; i++) {
		vector[i]--;
	}
	
}

void Vector::operator--(int)
{
	for (int i = 0; i < size_; i++)
	{
		--vector[i];
	}
	
}

void Vector::printFormatted()
{
	printf("[ ");
	for (int i = 0; i < size_; i++) {
		printf("%d, ", vector[i]);
	}
	printf(" ]\n");
}

std::ostream& operator << (std::ostream& out, const Vector& vector)
{
	out << "[ ";
	for (int i = 0; i < vector.size_; i++) {
		out << vector.vector[i] << ", ";
	}
	out << " ]\n";
	return out;
}

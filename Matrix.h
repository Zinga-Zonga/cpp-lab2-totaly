#pragma once
class Matrix
{
public:
	Matrix(const int rows_, const int cols_);
	~Matrix();

	//void initialize
	void operator++();
	void operator++(int);
	void operator--();
	void operator--(int);

	int at(int i, int j);
	void setAt(int i, int j, int val);

	int getRows();
	int getCols();

	void printFormated();
private:
	int rows_;
	int cols_;
	int** matrix;
};


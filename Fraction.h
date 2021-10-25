#pragma once
#include <iostream>
#include <string>
/*Написать класс Fraction для представления обыкновенных дробей (как отношения двух целых чисел x/y).
 Перегрузить операторы +, -, *, / для дробей.
 Реализовать метод void reduce() для сокращения дроби, а также статические методы:
 int gcd(int n, int m)
функция для нахождения наибольшего общего делителя чисел n и m;
 void printAsFraction(double decimal_fraction)
 void printAsFraction(char* decimal_fraction)
перегруженные методы вывода десятичной дроби в виде обыкновенной
(например, при значении decimal_fraction = 0.43 на экране должно вывестись 43/100, при 0.25 – 1/4 и т.д.).
Также реализовать в виде статического члена класса счетчик всех созданных на данный момент в программе экземпляров дробей.
Продемонстрировать работу созданного класса. Создать несколько объектов дробей.
Произвести операции сложения, вычитания, умножения и деления дробей. Вывести на экран результаты.
Показать также результаты работы статических методов класса.*/
class Fraction
{

public:
	Fraction();
	Fraction(int n, int m); // x = n/m
	// ~Fraction();
	void setM(int m);
	void setN(int n);
	int getM();
	int getN();
	int getTotalFractions();

	Fraction operator+(const Fraction& term);
	Fraction operator-(const Fraction& subtrahend);
	Fraction operator*(const Fraction& factor);
	Fraction operator/(const Fraction& divisor);

	void reduce(); // сократить
	static int gcd(int n, int m); // наибольший общий делитель по алгоритму евклида
	static int lcm(int a, int b);
	static void printAsFraction(double decimal_fraction); // вывод если инпут цифры
	static void printAsFraction(char* decimal_fraction); // вывод если инпут текст
	void printFrac();


private:
	int n_;
	int m_;
	static int countFractions;

};


#include "Fraction.h"
#include <string>

int Fraction::countFractions = 0;
void Fraction::reduce()
{
	int divider = gcd(n_, m_);
	n_ = n_ / divider;
	m_ = m_ / divider;
}

int Fraction::gcd(int m, int n)
{
/*Ѕольшее число поделить на меньшее.
ћеньшее число поделить на остаток, который получаетс€ после делени€.
ѕервый остаток поделить на второй остаток.
¬торой остаток поделить на третий и т.д.
ƒеление продолжаетс€ до тех пор, пока в остатке не получитс€ нуль.ѕоследний делитель и есть наибольший общий делитель.*/
	int remain;
	if (n < m) {
		while (n%m != 0) {
			remain = n % m;
			n = m;
			m = remain;
		}
	}
	else {
		while (m % n != 0) {
			remain = m % n;
			m = n;
			n = remain;
		}
	}
	return remain;
	
}

int Fraction::lcm(int a, int b)
{
		int numerator = a * b;
		if (numerator < 0)
			a = -a;
		int divisor = gcd(a, b);
		return (numerator / divisor);
}

void Fraction::printAsFraction(double decimal_fraction)
{
	std::string inputToString = std::to_string(decimal_fraction);
	const char* inputInChar = inputToString.c_str();
	int m, n;
	int length = strlen(inputInChar);
	int floatDot=0;
	int lastNonZero = 0;
	int ten = 0;
	for (int i = 0; i < length; i++) {
		if (inputInChar[i] == '.')
			floatDot = i;
		else if(floatDot != 0){
			++ten;
		}
	}
	n = pow(10, ten);
	m = decimal_fraction * n;
	int delitel = gcd(n, m);
	n /= delitel;
	m /= delitel;
	std::cout << m << '/' << n << std::endl;
}

void Fraction::printAsFraction(char* decimal_fraction)
{
	double inputNum = atof(decimal_fraction);
	int m, n;
	int length = strlen(decimal_fraction);
	int floatDot=0;
	int lastNonZero = 0;
	int ten = 0;
	for (int i = 0; i < length; i++) {
		if (decimal_fraction[i] == '.')
			floatDot = i;
		else if(floatDot != 0){
			++ten;
		}
	}
	n = pow(10, ten);
	m = inputNum * n;
	int delitel = gcd(n, m);
	n /= delitel;
	m /= delitel;
	std::cout << m << '/' << n << std::endl;

}

void Fraction::printFrac()
{
	std::cout << m_ << '/' << n_ << std::endl;
}

Fraction::Fraction()
{
	countFractions++;

}

Fraction::Fraction(int m, int n)
{
	countFractions++;
	n_ = n;
	m_ = m;

}

void Fraction::setM(int m)
{
	m_ = m;
}

void Fraction::setN(int n)
{
	n_ = n;
}

int Fraction::getM()
{
	int m = m_;
	return m;
}

int Fraction::getN()
{
	int n = n_;
	return n;
}

int Fraction::getTotalFractions()
{
	return countFractions;
}

Fraction Fraction::operator+(const Fraction& term)
{
	Fraction out;
	int aM = this->m_;
	int aN = this->n_;
	int bM = term.m_;
	int bN = term.n_;
	if (aM == bM) {
		out.setM(aM + bM);
		out.setN(aN);
	}
	else {
		int commonMult = aN * bN;                                      
		aM *= bN;
		bM *= aN;
		int totalM = aM + bM;
		int mult = gcd(totalM, commonMult);
		out.setM(totalM/mult);
		out.setN(commonMult/mult);
	}
	return out;
}

Fraction Fraction::operator-(const Fraction& subtrahend)
{
	Fraction out;
	int aM = this->m_;
	int aN = this->n_;
	int bM = subtrahend.m_;
	int bN = subtrahend.n_;
	if (aM == bM) {
		out.setM(aM + bM);
		out.setN(aN);
	}
	else {
		int commonMult = aN * bN;
		aM *= bN;
		bM *= aN;
		int totalM = aM - bM;
		int mult = gcd(totalM, commonMult);
		out.setM(totalM / mult);
		out.setN(commonMult / mult);
	}
	return out;
}

Fraction Fraction::operator*(const Fraction& factor)
{
	Fraction out;
	int aM = this->m_;
	int aN = this->n_;
	int bM = factor.m_;
	int bN = factor.n_;
	int totalM, totalN;
	totalM = aM * bM;
	totalN = bN * bN;
	int mult = gcd(totalM, totalN);
	out.setM(totalM/mult);
	out.setN(totalN/mult);
	return out;
}

Fraction Fraction::operator/(const Fraction& divisor)
{
	Fraction out;
	int aM = this->m_;
	int aN = this->n_;
	int bM = divisor.m_;
	int bN = divisor.n_;
	int totalM, totalN;
	totalM = aM * bN;
	totalN = aN * bM;
	int mult = gcd(totalM, totalN);
	out.setM(totalM / mult);
	out.setN(totalN / mult);
	return out;
}


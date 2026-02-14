//определение методов и функций

#include <iostream>
#include <sstream>
#include "complex/complex.hpp"

//консрукторы
Complex::Complex(const double real)
	:Complex(real, 0.0) //? почему не в теле функции
{
}

Complex::Complex(const double real, const double imaginary)
	: re(real)
	, im(imaginary)
{
}

//операторы
bool Complex::operator==(const Complex& rhs) const 
{
	return (abs(re - rhs.re) < 0.01) && (abs(im - rhs.im) < 0.01);
	//return (re == rhs.re) && (im == rhs.im);
}
bool Complex::operator!=(const Complex& rhs) const
{ 
	return !operator==(rhs); 
}


Complex& Complex::operator+=(const Complex& rhs)//? почему здесь передаётся ссылка, а при double нет
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex& Complex::operator+=(const double rhs)
{
	return operator+=(Complex(rhs));
}


Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex& Complex::operator-=(const double rhs)
{
	return operator-=(Complex(rhs));
}

Complex& Complex::operator*=(const Complex& rhs)
{	
	re = re * rhs.re - im * rhs.im;
	im = re * rhs.im + im * rhs.re;
	return *this;
}

Complex& Complex::operator*=(const double rhs)
{
	re *= rhs;
	im *= rhs;
	return *this;
}

//перегруженные операторы
std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

//методы
std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaginary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaginary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}


//функция
bool testParse(const std::string& str) {
	std::istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		std::cout << "Read success: " << str << " -> " << z << std::endl;
	}
	else {
		std::cout << "Read error  : " << str << " -> " << z << std::endl;
	}
	return istrm.good();
}
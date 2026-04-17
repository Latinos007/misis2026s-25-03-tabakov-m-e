#pragma once

#ifndef HZ
#define HZ

#include <iostream>
#include <string>

class DioStrB {
public:
	DioStrB() = default;

	bool checks(char& ch) { return 1; }


	void readFrom(std::istream& src);

	

	void writeTo(std::ostream& ostrm) {
		ostrm << val_;
		val_ = "";
	}
	
	std::string val() { return val_; }

private:
	std::string val_;
};




//перегруженные операторы
/*
std::ostream& operator<<(std::ostream& ostrm, DioStrB& rhs)
{
	return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, DioStrB& rhs)
{
	return rhs.readFrom(istrm);
}
*/
#endif
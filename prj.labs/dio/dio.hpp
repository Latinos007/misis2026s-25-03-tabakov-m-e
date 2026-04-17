#pragma once

#ifndef HZ
#define HZ

#include <iostream>
#include <string>

class DioStrB {
public:
	DioStrB() = default;

	bool checks(char& ch) { return 1; }


	std::istream& readFrom(std::istream& src);

	std::ostream& write_to(std::ostream& ostrm);

	std::string val() { return val_; }

private:
	std::string val_;
	char mrk_ = 's';
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
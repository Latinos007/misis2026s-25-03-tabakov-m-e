#pragma once

#ifndef HZ
#define HZ

#include <iostream>

class DioStrB {
public:
	DioStrB() = default;


	std::istream& readFrom(const std::istream& istrm) {

	}


	std::ostream& writeTo(std::ostream& ostrm) const {

	}
//private:
	//char32_t* val_ = nullptr;
	std::string val_;
};




//перегруженные операторы
std::ostream& operator<<(std::ostream& ostrm, const DioStrB& rhs)
{
	return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, DioStrB& rhs)
{
	return rhs.readFrom(istrm);
}
#endif
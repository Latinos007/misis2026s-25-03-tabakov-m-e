#include "dio/dio.hpp"
#include <iostream>
#include <string>

std::istream& DioStrB::readFrom(std::istream& src) {
	
	char mark = src.get();
	if (mark == mrk_) {
		int32_t size;
		src.read(reinterpret_cast<char*>(&size), sizeof(size);
		val_.resize(size - 1);
		src.read(val_.data(), size);
	}
	else {
		src.setstate(std::ios_base::badbit);
	}

	return src;
}

std::ostream& DioStrB::write_to(std::ostream& ostrm) {
	int32_t size = val_.size();
	size += 1;
	ostrm.put(mrk_);
	ostrm.write(reinterpret_cast<char*>(&size), sizeof(size));
	ostrm.write(val_.data(), size);
	return ostrm;
}
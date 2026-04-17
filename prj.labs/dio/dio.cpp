#include "dio/dio.hpp"
#include <iostream>
#include <string>

void DioStrB::readFrom(std::istream& src) {
	int byte;
	for (int i = 0; i < 10; i++) {
		byte = src.get();
		std::cout << byte<<std::endl;
		val_.push_back(static_cast<char>(byte));
	}
}
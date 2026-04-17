#include <iostream>
#include <string>
#include <fstream>

#include "dio/dio.hpp"

int main() {
	
	std::ifstream file("C:\\Users\\tme20\\source\\repos\\misis2026s-25-03-tabakov-m-e\\prj.test\\read_test.txt", std::ios::binary);

	
	//std::cout << static_cast<int>('f');

	DioStrB reader;
	reader.readFrom(file);
	reader.writeTo(std::cout);
}
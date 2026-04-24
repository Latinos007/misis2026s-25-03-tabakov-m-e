#include <iostream>
#include <string>
#include <fstream>

//#include "dio/dio.hpp"
#include "bitsetd/bitsetd.hpp"

int main() {
	
	std::ifstream read_file("D:\\gitrepos\\misis2026s-25-03-tabakov-m-e\\prj.test\\read_test.bin", std::ios::binary);

	//std::cout << '1';

	
	//чтение
	
	BitsetD bst(1, false);

	bst.read_from(read_file);

	bst.print_bits();
	
	std::cout << std::endl;

	//запись
	uint64_t mask = 0b00110010'00110101;
	int32_t size = 32;
	BitsetD msg(mask, size);
	msg.print_bits();

	std::ofstream write_file("D:\\gitrepos\\misis2026s-25-03-tabakov-m-e\\prj.test\\write_test.bin", std::ios::binary);

	bst.write_to(write_file);
}
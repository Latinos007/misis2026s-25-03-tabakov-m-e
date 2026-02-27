#include <iostream>
#include "bitsetd/bitsetd.hpp"

#include <bitset>
#include <vector>

int main() {
	BitsetD v1(2, 0);
	BitsetD v2(999919378172);
	//v.bits_print();
	std::cout << std::bitset<32>(v2.data_[1]) << ' ';
	std::cout << std::bitset<32>(v2.data_[0]) << std::endl;

	v2.invert();
	//v2.fill(0);

	std::cout << std::bitset<32>(v2.data_[1]) << ' ';
	std::cout << std::bitset<32>(v2.data_[0]) << std::endl;
	v2.print_bits();
}
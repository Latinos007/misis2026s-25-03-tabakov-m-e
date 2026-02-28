#include <iostream>
#include "bitsetd/bitsetd.hpp"

#include <bitset>
#include <vector>

int main() {
	BitsetD v1(19109831);
	BitsetD v2(19378175);
	//v.bits_print();
	//std::cout << std::bitset<32>(v2.data_[1]) << ' ';

	//v2.invert();
	//v2.fill(0);

	std::cout << std::endl;
	v2.print_bits();

	v2 <<= 24;
	std::cout << std::endl << "operation complete" << std::endl;

	v2.print_bits();
	std::cout << std::endl << v2.capacity_ << std::endl;

}
//#include "bitsetd.hpp"
#include <iostream>
#include <bitset>

int main() {
	int a = 0b10010;
	int b = 0b11101;
	int c = 0;
	c = a & b;
	std::bitset<8> x(c);
	std::cout << x;
}
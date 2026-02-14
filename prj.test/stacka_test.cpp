#include <stacka/stacka.hpp>
#include <iostream>

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include <doctest/doctest.h>


int main() {
	StackA a;
	for (int i = 10; i < 20; i++) {
		a.push(i);
	}

	StackA b;
	for (int i = 10; i < 20; i++) {
		b.push(i);
	}

	StackA c(a);
	StackA d;
	d = a;

	for (int i = 10; i < 20; i++) {
		std::cout << a.top() << ' ';
		std::cout << b.top() << ' ';
		std::cout << c.top() << ' ';
		std::cout << d.top() << '\n';
		a.pop(); b.pop(); c.pop(); d.pop();
	}
	b.push(0);
	std::cout << a.is_empty() << b.is_empty();

	
}
/*
TEST_CASE("init") {
	StackA s;
	s.push(10);
	CHECK(s.top() == 10);
}
*/
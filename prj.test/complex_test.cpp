#include <complex/complex.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>


TEST_CASE("init") {
	Complex z0;
	CHECK(0 == z0.re);
	CHECK(0 == z0.im);

	Complex z1(2.0, 3.0);
	CHECK(2.0 == z1.re);
	CHECK(3.0 == z1.im);
}

TEST_CASE("testParse") {
	CHECK(1 == testParse("{8.9,9}"));
	CHECK(1 == testParse("{8.9, 9}"));
	CHECK(0 == testParse("{8.9,9"));
}

TEST_CASE("default operators") {
	Complex z2(2.0, 3.0);
	Complex z3(1.0, 5.0);
	CHECK(Complex(3.0, 8.0) == z2 + z3);
	CHECK(Complex(1.0, -2.0) == z2 - z3);
	CHECK(true == (z2 == z2));
	CHECK(true == (z2 != z3));
}

TEST_CASE("assignment operators") {
	Complex z4 (2.0, 3.0);
	Complex z5 (1.0, 1.5);
}
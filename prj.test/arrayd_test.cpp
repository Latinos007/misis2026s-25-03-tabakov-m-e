#include <arrayd/arrayd.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("init") {
	ArrayD a(10);
	//ArrayD b[10]{ 0.0f };
	CHECK(a[0] == 0.0f);
}
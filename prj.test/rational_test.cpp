#include <rational/rational.hpp>
#include <iostream>
#include <sstream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Constructor and normalization") {
    Rational r1(6, 8);
    CHECK(r1 == Rational(3, 4));

    Rational r2(-6, 8);
    CHECK(r2 == Rational(-3, 4));

    Rational r3(6, -8);
    CHECK(r3 == Rational(-3, 4));

    Rational r4(-6, -8);
    CHECK(r4 == Rational(3, 4));
}

TEST_CASE("Zero denominator") {
    CHECK_THROWS_AS(Rational(1, 0), std::invalid_argument);
}

TEST_CASE("Coampare") {
    CHECK(Rational(1, 2) == Rational(2, 4));
    CHECK(Rational(1, 2) != Rational(3, 4));

    CHECK(Rational(1, 3) < Rational(1, 2));
    CHECK(Rational(3, 4) > Rational(2, 3));

    CHECK(Rational(2, 3) <= Rational(2, 3));
    CHECK(Rational(3, 3) >= Rational(1, 3));
}

TEST_CASE("Arithmetic") {
    CHECK(Rational(1, 2) + Rational(1, 3) == Rational(5, 6));
    CHECK(Rational(1, 2) - Rational(1, 3) == Rational(1, 6));
    CHECK(Rational(1, 2) * Rational(1, 3) == Rational(1, 6));
    CHECK(Rational(1, 2) / Rational(1, 3) == Rational(3, 2));
}

TEST_CASE("Arithmetic assignment operators") {
    Rational r(1, 2);

    r += Rational(1, 3);
    CHECK(r == Rational(5, 6));

    r -= Rational(1, 6);
    CHECK(r == Rational(2, 3));

    r *= Rational(3, 4);
    CHECK(r == Rational(1, 2));

    r /= Rational(1, 4);
    CHECK(r == Rational(2, 1));
}

TEST_CASE("Arithmetic with int") {
    CHECK(Rational(1, 2) + 1 == Rational(3, 2));
    CHECK(Rational(3, 2) - 1 == Rational(1, 2));
    CHECK(Rational(2, 3) * 3 == Rational(2, 1));
    CHECK(Rational(3, 2) / 3 == Rational(1, 2));

    CHECK(1 + Rational(1, 2) == Rational(3, 2));
    CHECK(1 - Rational(1, 2) == Rational(1, 2));
    CHECK(2 * Rational(3, 4) == Rational(3, 2));
    CHECK(1 / Rational(1, 2) == Rational(2, 1));
}

TEST_CASE("Division by zero") {
    Rational r1(1, 2);
    Rational r2(0, 1);
    CHECK_THROWS_AS(r1 / r2, std::invalid_argument);
    CHECK_THROWS_AS(r1 /= r2, std::invalid_argument);
}

TEST_CASE("Output") {
    Rational r(3, -4);
    std::ostringstream ostrm;
    ostrm << r;
    CHECK(ostrm.str() == "-3/4");
}

TEST_CASE("Input") {
    Rational r;
    std::istringstream istrm("5/6");
    istrm >> r;
    CHECK(r == Rational(5, 6));
}

TEST_CASE("Wrong input") {
    Rational r1;
    std::istringstream istrm1("(5/6)");
    istrm1 >> r1;
    CHECK(istrm1.fail());

    Rational r2;
    std::istringstream istrm2("{5:6}");
    istrm2 >> r2;
    CHECK(istrm2.fail());
    
    Rational r3;
    std::istringstream istrm3("{5/0}");
    istrm3 >> r3;
    CHECK(istrm3.fail());

    Rational r4;
    std::istringstream istrm4("abcdef");
    istrm4 >> r4;
    CHECK(istrm4.fail());
}
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <stackl/stackl.hpp>

TEST_CASE("push, pop, top, is_empty)") {
    StackL stack;

    CHECK(stack.is_empty() == true);

    SUBCASE("") {
        stack.push(42);
        CHECK(stack.is_empty() == false);
        CHECK(stack.top() == 42);
    }

    SUBCASE("") {
        stack.push(10);
        stack.push(20);
        stack.push(30);

        CHECK(stack.top() == 30);
        stack.pop();
        CHECK(stack.top() == 20);
        stack.pop();
        CHECK(stack.top() == 10);
        stack.pop();
        CHECK(stack.is_empty() == true);
    }

    SUBCASE("") {
        stack.push(100);
        stack.top() = 200;
        CHECK(stack.top() == 200);
    }
}

TEST_CASE("") {
    StackL stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.clear();
    CHECK(stack.is_empty() == true);
}

TEST_CASE("") {
    StackL s1;
    s1.push(10);
    s1.push(20);

    StackL s2(s1);
    CHECK(s2.top() == 20);
    s2.pop();
    CHECK(s2.top() == 10);
    CHECK(s1.top() == 20);

    StackL s3;
    s3.push(100);
    s3 = s1;
    CHECK(s3.top() == 20);
    s3.pop();
    CHECK(s3.top() == 10);
    CHECK(s1.top() == 20);
}
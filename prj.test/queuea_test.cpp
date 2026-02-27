/*
int main() {
	QueueA n;
	for (int i = 0; i < 21; i++) {
		n.push(i);
	}

	n.pop();
	n.pop();
	for (int i = 0; i < 21; i++) {
		n.push(i);
	}

	QueueA m;
	n.pop();
	n.pop();
	n.pop();
	n.pop();
	m = n;
	m.pop();
	for (int i = 0; i < 21; i++) {
		m.push(i);
	}
	std::cout << n.is_empty() << " " << n.size() << std::endl;
	std::cout << m.is_empty() << " " << m.size() << std::endl;

}
*/
// test_queuea.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <queuea/queuea.hpp>
#include <cstdint>
#include <vector>

TEST_CASE("QueueA: новая очередь пустая") {
    QueueA q;
    CHECK(q.is_empty());
    CHECK(q.size() == 0);
}

TEST_CASE("QueueA: push/pop базовый FIFO") {
    QueueA q;
    q.push(10);
    q.push(20);
    q.push(30);

    CHECK_FALSE(q.is_empty());
    CHECK(q.size() == 3);

    CHECK(q.pop() == 10);
    CHECK(q.size() == 2);

    CHECK(q.pop() == 20);
    CHECK(q.pop() == 30);

    CHECK(q.is_empty());
    CHECK(q.size() == 0);
}

TEST_CASE("QueueA: чередование операций") {
    QueueA q;

    q.push(1);
    CHECK(q.pop() == 1);
    CHECK(q.is_empty());

    q.push(2);
    q.push(3);
    CHECK(q.pop() == 2);

    q.push(4);
    CHECK(q.pop() == 3);
    CHECK(q.pop() == 4);

    CHECK(q.is_empty());
    CHECK(q.size() == 0);
}

TEST_CASE("QueueA: много элементов (провоцируем resize)") {
    QueueA q;
    const int N = 1000;

    for (int i = 0; i < N; ++i) q.push(i);
    CHECK(q.size() == N);

    for (int i = 0; i < N; ++i) {
        CHECK(q.pop() == i);
    }

    CHECK(q.is_empty());
    CHECK(q.size() == 0);
}

//TEST_CASE("QueueA: копирующий конструктор делает независимую копию") {

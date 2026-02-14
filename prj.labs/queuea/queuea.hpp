#pragma once
#ifndef QUEUEA_2026
#define QUEUEA_2026

#include <cstddef>
#include <cstdint>
#include <stdexcept>

class QueueA {
private:
	std::ptrdiff_t last_ = -1;
	std::ptrdiff_t first_ = 0;
	int64_t* data_ = nullptr;
	int64_t capacity_ = 0;
	
	void resize(const int64_t& newsize);
public:
	QueueA();
	QueueA(const QueueA& src);
	QueueA& operator=(const QueueA& rhs);

	~QueueA();

	int64_t pop();
	void push(int64_t newelement);

	int64_t size() const;
	bool is_empty() const;
};

#endif
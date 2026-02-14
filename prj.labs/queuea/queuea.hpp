#pragma once
#ifndef QUEUEA_2026
#define QUEUEA_2026


#include <cstddef>
#include <cstdint>

class QueueA {
private:
	std::ptrdiff_t last_ = 0;
	int64_t* data_ = nullptr;
	int capacity_ = 0;

public:
	QueueA() {};
};

#endif
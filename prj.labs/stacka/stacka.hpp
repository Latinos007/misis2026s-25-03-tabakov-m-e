#pragma once
#ifndef STACKA_STACKA_HPP1
#define STACKA_STACKA_HPP1

#include <cstddef>
#include <cstdint>

class StackA {
public:
	StackA() :last_(0), data_(new int64_t[10]), capacity_(10) {};
	StackA(const StackA& src);

	~StackA();

	StackA& operator=(const StackA& rhs);

	[[nodiscard]] bool is_empty() const noexcept;

	void push(const int64_t val);
	void pop() noexcept;

	[[nodiscard]] int64_t& top();

	[[nodiscard]] int64_t top() const;

	void clear() noexcept;

private:
	std::ptrdiff_t last_ = 0;
	int64_t* data_ = nullptr;
	int capacity_ = 0;

	void resize(const int newsize);
};

#endif
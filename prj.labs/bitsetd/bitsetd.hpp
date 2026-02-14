#pragma once
#ifndef BITSETD_2026
#define BITSETD_2026

#include <vector>

class BitsetD {
public:
	BitsetD() = default;
	BitsetD(const int& setsize)
		:size_(setsize)
	{
		data_.resize(setsize/32 + 1);
	}

	BitsetD(const BitsetD& src);
	BitsetD& operator=(const BitsetD& rhs);

	~BitsetD();

	void set(const int32_t& index, const bool& val);
	bool get(const int32_t& index) const;

	void fill(const bool& val);

	int32_t size() const;
	void resize(const int32_t newsize);

private:
	std::vector<int32_t> data_;
	int32_t size_ = 0;
};

#endif
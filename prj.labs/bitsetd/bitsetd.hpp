#pragma once
#ifndef BITSETD_022026
#define BITSETD_022026

#include <vector>

class BitsetD {
public:
	BitsetD() = default;
	BitsetD(const int32_t& setsize, const bool& setvalue);
	BitsetD(const std::uint64_t mask);
	BitsetD(const BitsetD& src);
	BitsetD& operator=(const BitsetD& rhs);

	~BitsetD() = default;

	int32_t size() const;
	void resize(const int32_t& newsize);
	void set(const int32_t& idx, const bool& val);
	bool get(const int32_t& idx) const;

	//operator
	bool operator==(const BitsetD& rhs) const noexcept;
	void invert() noexcept;
	void fill(const bool& val) noexcept;
	BitsetD& shift(const std::int32_t idx) noexcept;
	BitsetD& operator<<=(const std::int32_t shift);
	BitsetD& operator>>=(const std::int32_t shift);
	BitsetD& operator&=(const BitsetD& rhs);
	BitsetD& operator|=(const BitsetD& rhs);
	BitsetD& operator^=(const BitsetD& rhs);

	void print_bits() const;
//private:
	std::vector<uint32_t> data_;
	int32_t size_ = 0;
	int32_t capacity_ = 0;
};

//BitsetD operator<<(const BitsetD& lhs, const std::int32_t shift);

//BitsetD operator>>(const BitsetD& lhs, const std::int32_t shift);


#endif
#include "bitsetd/bitsetd.hpp"

#include <vector>
#include <stdexcept>
#include <cmath>

//otlado4ka
#include <iostream>

BitsetD::BitsetD(const int32_t& setcapacity, const bool& setvalue)
	:capacity_(setcapacity),
	size_((setcapacity / 32) + 1),
	data_(0)	
	{
	if (setcapacity < 0) {
		throw std::invalid_argument("size can not be negative");
	}

	data_.resize(size_, 0);
	if (1 == setvalue) {
		int i = 0;
		for (; i < size_ - 1; i++) {
			data_[i] = UINT32_MAX;
		}
		data_[i] = pow(2, setcapacity - (32 * (size_ - 1))) - 1;
	}
	
}

BitsetD::BitsetD(const std::uint64_t mask):
	BitsetD(64,bool(0))
{
	capacity_ = std::floor(std::log2(mask)) + 1;
	data_[0] = mask % uint64_t(std::pow(2, 32));
	data_[1] = mask / std::pow(2, 32);
}

BitsetD::BitsetD(const BitsetD& src):
	capacity_(src.capacity_),
	size_(src.size_),
	data_(src.data_)
{}

BitsetD& BitsetD::operator=(const BitsetD& rhs) {
	capacity_ = rhs.capacity_;
	size_ = rhs.size_;
	data_ = rhs.data_;
	return *this;
}

int32_t BitsetD::size() const {
	return capacity_;
}

void BitsetD::resize(const int32_t& newcapacity) {
	if (newcapacity < capacity_) {
		throw std::invalid_argument("new size is smaller then old");
	}
	if (newcapacity > capacity_) {
		capacity_ = newcapacity;
		size_ = capacity_ / 32 + 1;
		data_.resize(size_);
	}
}

bool BitsetD::get(const int32_t& idx) const {
	if (idx >= capacity_) {
		throw std::out_of_range("out of range");
	}
	uint32_t mask = std::pow(2, idx % 32);
	uint32_t numpart = data_[idx / 32];
	return bool(mask & numpart);

}

void BitsetD::set(const int32_t& idx, const bool& val) {
	if (idx >= capacity_) {
		throw std::out_of_range("out of range");
	}
	uint32_t mask = std::pow(2, idx % 32);
	uint32_t numpart = data_[idx / 32];
	if (val) {
		data_[idx / 32] = numpart | mask;
	}
	else {
		data_[idx / 32] = numpart & ~mask;
	}
}

void BitsetD::invert() noexcept {
	for (int i = 0; i < capacity_; i++) {
		set(i, !get(i));
	}
}

void BitsetD::fill(const bool& val) noexcept {
	for (int i = 0; i < capacity_; i++) {
		set(i, val);
	}
}

//operators
bool BitsetD::operator==(const BitsetD& rhs) const noexcept {
	if (data_ == rhs.data_) {
		return 1;
	}
	return 0;
}
BitsetD& BitsetD::operator&=(const BitsetD& rhs) {
	if (capacity_ != rhs.capacity_) {
		throw std::invalid_argument("the size of the objects must be the same");
	}
	for (int i = 0; i < size_; i++) {
		data_[i] &= rhs.data_[i];
	}
}
BitsetD& BitsetD::operator|=(const BitsetD& rhs) {
	if (capacity_ != rhs.capacity_) {
		throw std::invalid_argument("the size of the objects must be the same");
	}
	for (int i = 0; i < size_; i++) {
		data_[i] |= rhs.data_[i];
	}
}
BitsetD& BitsetD::operator^=(const BitsetD& rhs) {
	if (capacity_ != rhs.capacity_) {
		throw std::invalid_argument("the size of the objects must be the same");
	}
	for (int i = 0; i < size_; i++) {
		data_[i] ^= rhs.data_[i];
	}
}
BitsetD& BitsetD::operator<<=(const std::int32_t shift) {
	/*
	for (int i = 0; i < size_; i++) {
		data_[i] <<= shift;
	}
	*/
}

void BitsetD::print_bits() const {
	if (size_ == 0) {
		throw std::invalid_argument("size<1");
	}
	for (int i = capacity_ - 1; i >=0; i--) {
		std::cout << get(i);
	}
}
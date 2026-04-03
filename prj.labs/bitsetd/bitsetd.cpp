#include "bitsetd/bitsetd.hpp"

#include <vector>
#include <stdexcept>
#include <cmath>
#include <cstdint>

//otlado4ka
#include <iostream>

BitsetD::BitsetD(const int32_t& setcapacity, const bool& setvalue)
	:capacity_(setcapacity),
	data_(0)
	{
	if (setcapacity < 0) {
		throw std::invalid_argument("size can not be negative");
	}

	data_.resize(setcapacity/32+1, 0);
	if (1 == setvalue) {
		int i = 0;
		for (; i < data_.size() - 1; i++) {
			data_[i] = 1u;
		}
		data_[i] = pow(2, setcapacity - (32 * (data_.size() - 1))) - 1;
	}
}

BitsetD::BitsetD(const std::uint64_t mask, const std::int32_t size)
	: capacity_(size)
	, data_{ static_cast<uint32_t>(mask),
			 static_cast<uint32_t>(mask >> 32) } {
}

BitsetD::BitsetD(const BitsetD& src):
	capacity_(src.capacity_),
	data_(src.data_)
{}

BitsetD& BitsetD::operator=(const BitsetD& rhs) {
	capacity_ = rhs.capacity_;
	data_ = rhs.data_;
	return *this;
}

BitsetD& BitsetD::operator=(BitsetD&& src) {

}

int32_t BitsetD::size() const noexcept{
	return capacity_;
}

void BitsetD::resize(const int32_t& newcapacity) {
	if (newcapacity < capacity_) {
		throw std::invalid_argument("new size is smaller then old");
	}
	if (newcapacity > capacity_) {
		capacity_ = newcapacity;
		data_.resize(capacity_ / 32 + 1);
	}
}

bool BitsetD::get(const int32_t& idx) const {
	if (idx >= capacity_ or idx < 0) {
		throw std::out_of_range("out of range");
	}
	uint32_t mask = std::pow(2, idx % 32);
	uint32_t numpart = data_[idx / 32];
	return bool(mask & numpart);
}

void BitsetD::set(const int32_t& idx, const bool& val) {
	if (idx >= capacity_ || idx < 0) {
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

BitsetD& BitsetD::invert() noexcept {
	BitsetD& lhs(*this);
	for (int i = 0; i < capacity_; i++) {
		lhs.set(i, !get(i));
	}
	return lhs;
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
	for (int i = 0; i < data_.size(); i++) {
		data_[i] &= rhs.data_[i];
	}
	return *this;
}
BitsetD& BitsetD::operator|=(const BitsetD& rhs) {
	if (capacity_ != rhs.capacity_) {
		throw std::invalid_argument("the size of the objects must be the same");
	}
	for (int i = 0; i < data_.size(); i++) {
		data_[i] |= rhs.data_[i];
	}
	return *this;
}
BitsetD& BitsetD::operator^=(const BitsetD& rhs) {
	if (capacity_ != rhs.capacity_) {
		throw std::invalid_argument("the size of the objects must be the same");
	}
	for (int i = 0; i < data_.size(); i++) {
		data_[i] ^= rhs.data_[i];
	}
	return *this;
}

BitsetD& BitsetD::operator<<=(const std::int32_t shift) {
	BitsetD tempset(capacity_, false);
	for (int32_t i = shift; i < capacity_; i++) {
		tempset.set(i, this->get(i - shift));
	}
	data_ = tempset.data_;
	return *this;
}

BitsetD& BitsetD::operator>>=(const std::int32_t shift) {
	BitsetD tempset(capacity_, false);
	for (int32_t i = (capacity_-1) - shift; i >= 0; i--) {
		tempset.set(i, this->get(i + shift));
	}
	data_ = tempset.data_;
	return *this;
}

BitsetD& BitsetD::shift(const int32_t idx) noexcept {
	BitsetD tempset(capacity_, false);
	if (0 < idx) {
		int32_t normalized_idx = ((idx % capacity_) != 0) ? idx % capacity_ : idx;

		for (int i = 0; i < normalized_idx; i++) {
			tempset.set(i, this->get(capacity_ - normalized_idx + i));
		}
		for (int i = normalized_idx; i < capacity_; i++) {
			tempset.set(i, this->get(i- normalized_idx));
		}
		data_ = tempset.data_;
	}
	else if (0 > idx) {
		int32_t normalized_idx = -1 * idx;
		normalized_idx = (normalized_idx % capacity_) ? normalized_idx % capacity_ : normalized_idx;

		for (int i = 0; i < capacity_- normalized_idx; i++) {
			tempset.set(i, this->get(normalized_idx + i));
		}
		for (int i = capacity_- normalized_idx; i < capacity_; i++) {
			tempset.set(i, this->get(i - capacity_ + normalized_idx));
		}
		data_ = tempset.data_;
	}
	
	return *this;
}

void BitsetD::print_bits() const {
	if (data_.size() == 0) {
		throw std::invalid_argument("size<1");
	}
	for (int i = capacity_ - 1; i >=0; i--) {
		std::cout << get(i);
	}
}

BitsetD operator<<(const BitsetD& lhs, const std::int32_t shift) {
	BitsetD x(lhs);
	x <<= shift;
	return x;
}

BitsetD operator>>(const BitsetD& lhs, const std::int32_t shift) {
	BitsetD x(lhs);
	x >>= shift;
	return x;
}

BitsetD operator&(const BitsetD& lhs, const BitsetD& rhs) {
	BitsetD x(lhs);
	x &= rhs;
	return x;
}

BitsetD operator|(const BitsetD& lhs, const BitsetD& rhs) {
	BitsetD x(lhs);
	x |= rhs;
	return x;
}

BitsetD operator^(const BitsetD& lhs, const BitsetD& rhs) {
	BitsetD x(lhs);
	x ^= rhs;
	return x;
}
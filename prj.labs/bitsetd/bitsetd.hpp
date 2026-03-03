#pragma once
#ifndef BITSETD_022026
#define BITSETD_022026

#include <vector>

class BitsetD {
public:
	BitsetD() = default;
	BitsetD(const BitsetD& src);
	BitsetD(const int32_t& setsize, const bool& setvalue);
	BitsetD(const std::uint64_t mask);

	BitsetD& operator=(const BitsetD& rhs);

	~BitsetD() = default;

	int32_t size() const noexcept;
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

private:
	std::vector<uint32_t> data_;
	int32_t size_ = 0;
	int32_t capacity_ = 0;

public:
	class BitProx {
	public:
		BitProx() = delete;
		BitProx(const BitProx&) = delete;
		~BitProx() = default;
		BitProx& operator=(const BitProx&) = delete;
		BitProx(BitsetD& bs, const int32_t idx) : bs_(bs), idx_(idx) {}
		operator bool() const { return bs_.get(idx_); }
		void operator=(const bool val) { bs_.set(idx_, val); }
	private:
		BitsetD& bs_;
		const int32_t idx_ = 0;
	};
	class BitProxC {
	public:
		BitProxC() = delete;
		BitProxC(const BitProxC&) = delete;
		~BitProxC() = default;
		BitProxC& operator=(const BitProxC&) = delete;
		BitProxC(const BitsetD& bs, const int32_t idx) : val_(bs.get(idx)) {}
		operator bool() const { return val_; }
	private:
		bool val_ = false;
	};

	BitProx operator[](const std::int32_t idx) { return BitProx(*this, idx); }
	BitProxC operator[](const std::int32_t idx) const { return BitProxC(*this, idx); }
};


inline BitsetD operator~(const BitsetD& rhs) noexcept {
	BitsetD x(rhs);
	x.invert();
	return x;
}

BitsetD operator<<(const BitsetD& lhs, const std::int32_t shift);

BitsetD operator>>(const BitsetD& lhs, const std::int32_t shift);

BitsetD operator&(const BitsetD& lhs, const BitsetD& rhs);

BitsetD operator|(const BitsetD& lhs, const BitsetD& rhs);

BitsetD operator^(const BitsetD& lhs, const BitsetD& rhs);
#endif
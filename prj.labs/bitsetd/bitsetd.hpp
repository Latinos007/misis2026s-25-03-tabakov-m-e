#pragma once
#ifndef BITSETD_022026
#define BITSETD_022026

#include <cstdint>
#include <string>
#include <vector>

class BitsetD {
public:
	BitsetD() = default;

	BitsetD(const BitsetD& src);
	BitsetD(BitsetD&& src) = default;

	BitsetD(const int32_t& setsize, const bool& setvalue);
	BitsetD(const std::uint64_t mask, const int32_t size);

	BitsetD& operator=(const BitsetD& rhs);
	BitsetD& operator=(BitsetD&& src) {};

	~BitsetD() = default;

	int32_t size() const noexcept;
	void resize(const int32_t& newsize);
	void set(const int32_t& idx, const bool& val);
	bool get(const int32_t& idx) const;

	//operators
	bool operator==(const BitsetD& rhs) const noexcept;
	BitsetD& invert() noexcept;
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
	int32_t capacity_ = 0;

public:
	class BitR {
		friend class BitsetD;
	public:
		operator bool() const noexcept { return val_; }
	private:
		BitR() = delete;
		BitR(const BitR&) = delete;
		BitR(BitR&&) = delete;
		BitR(const BitsetD& bs, const int32_t idx) : val_(bs.get(idx)) {}
		~BitR() = default;
		BitR& operator=(const BitR&) = delete;
		BitR& operator=(BitR&&) = delete;
	private:
		bool val_ = false;
	};

	class BitW {
		friend class BitsetD;
	public:
		operator bool() const noexcept { return bs_.get(idx_); }
		void operator=(const bool val) noexcept { bs_.set(idx_, val); }
		void operator=(const BitW& rhs) noexcept { operator=(rhs.operator bool()); }
		void operator=(BitW&& rhs) noexcept { operator=(rhs.operator bool()); }
	private:
		BitW(BitsetD& bs, const int32_t idx) : bs_(bs), idx_(idx) {}
		BitW() = delete;
		BitW(const BitW&) = delete;
		BitW(BitW&&) = delete;
		~BitW() = default;
	private:
		BitsetD& bs_;
		const int32_t idx_ = 0;
	};

	BitW operator[](const std::int32_t idx)& { return BitW(*this, idx); }
	BitR operator[](const std::int32_t idx) const& { return BitR(*this, idx); }
};


inline BitsetD operator~(const BitsetD& rhs) noexcept {
	return BitsetD(rhs).invert();
}

BitsetD operator<<(const BitsetD& lhs, const std::int32_t shift);

BitsetD operator>>(const BitsetD& lhs, const std::int32_t shift);

BitsetD operator&(const BitsetD& lhs, const BitsetD& rhs);

BitsetD operator|(const BitsetD& lhs, const BitsetD& rhs);

BitsetD operator^(const BitsetD& lhs, const BitsetD& rhs);
#endif
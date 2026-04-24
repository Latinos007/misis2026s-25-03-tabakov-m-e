#pragma once
#ifndef BITSETD_022026
#define BITSETD_022026

#include <cstdint>
#include <string>
#include <vector>
#include <iostream>
#include <string>

class BitsetD {

private:
	std::vector<uint32_t> data_;
	int32_t capacity_ = 0;
	const char mrk_ = 0x42;

public:
	BitsetD() = default;

	BitsetD(const BitsetD& src);
	BitsetD(BitsetD&& src) = default;

	BitsetD(int32_t setsize, bool setvalue, bool debug);
	BitsetD(std::uint64_t mask, int32_t size);

	BitsetD& operator=(const BitsetD& rhs);
	//BitsetD& operator=(BitsetD&& src) noexcept;

	~BitsetD() = default;

	int32_t size() const noexcept;
	void resize(int32_t newsize);
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

	//ios binary
	enum class StrFormat : int32_t {
		Bin = 1,      ///< суффикс "b0" и разделители по 4 от младших, пример: b0010'0001
		BinNoPreSep,  ///< без суффикса и разделителей, пример: 0100001
		Oct,
		Hex,
		Def = Bin,
		Default = Def
	};
	//std::string to_string(const StrFormat fmt = StrFormat::Def, const int32_t len = 0) const;
	
private:
	// размер элемента буффера в битах (chunk bit size)
	static const int32_t chunk_bi_s = 32;
	// размер элемента буффера в байтах (chunk byte size)
	static const int32_t chunk_by_s = 4;
	// минимальный размер буфера для текущего размера битсета (chunk count for current bitset size)
	int32_t chunks_count() const { return (capacity_ + chunk_bi_s - 1) / chunk_bi_s; }

public:
	std::istream& read_from(std::istream& istrm);
	std::ostream& write_to(std::ostream& ostrm);
	std::uint8_t hash_gen(std::vector<uint32_t> msg);

	//debug
	void print_bits() const;



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
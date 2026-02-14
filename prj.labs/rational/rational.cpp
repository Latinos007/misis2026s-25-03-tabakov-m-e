#include <rational/rational.hpp>
#include <stdexcept>
#include <sstream>


Rational::Rational(const int32_t num, const int32_t den)
    : num_(num), den_(den) {
    if (0 == den_) {
        throw std::invalid_argument("Zero denumenator");
    }
    Normalize();
}

std::int32_t Rational::mygcd(const std::int32_t& a, const std::int32_t& b) noexcept {
    std::int32_t mx = std::max(a, b);
    std::int32_t mn = std::min(a, b);
    std::int32_t g = 1;
    std::int32_t last = mn;

    while (last != 0) {
        g = last;
        last = mx % mn;
        mx = mn;
        mn = last;
    }

    return g;
}

void Rational::Normalize() noexcept {
    std::int32_t g = mygcd(num_, den_);
    num_ /= g;
    den_ /= g;

    if (den_ < 0) {//перемещение минуса в числитель
        num_ = -num_;
        den_ = -den_;
    }
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const noexcept {
    ostrm << num_ << div << den_;
    return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) noexcept {
    int32_t num(0);
    char div_ch;
    int32_t den(1);

    istrm >> num >> div_ch >> den;

    if (istrm.fail()) {
        return istrm;
    }

    if (div_ch != Rational::div) {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }

    if (den == 0) {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }

    num_ = num;
    den_ = den;
    Normalize();

    return istrm;
}

//ios
std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
    return rhs.WriteTo(ostrm);
}
std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept {
    return rhs.ReadFrom(istrm);
}


//сравнение
bool Rational::operator==(const Rational& rhs) const noexcept {
    return (num_ == rhs.num_ && den_ == rhs.den_);
}

bool Rational::operator!=(const Rational& rhs) const noexcept {
    return !(*this == rhs);
}

bool Rational::operator<(const Rational& rhs) const noexcept {
    return num_ * rhs.den_ < rhs.num_ * den_;
}

bool Rational::operator<=(const Rational& rhs) const noexcept {
    return *this < rhs || *this == rhs;
}

bool Rational::operator>(const Rational& rhs) const noexcept {
    return rhs < *this;
}

bool Rational::operator>=(const Rational& rhs) const noexcept {
    return rhs <= *this;
}


//присваивание
Rational& Rational::operator+=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.den_ + rhs.num_ * den_;
    den_ *= rhs.den_;
    Normalize();
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.den_ - rhs.num_ * den_;
    den_ *= rhs.den_;
    Normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
    num_ *= rhs.num_;
    den_ *= rhs.den_;
    Normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
    if (rhs.num_ == 0) {
        throw std::invalid_argument("Division by zero");
    }
    num_ *= rhs.den_;
    den_ *= rhs.num_;
    Normalize();
    return *this;
}

Rational& Rational::operator+=(const int32_t rhs) noexcept {
    return *this += Rational(rhs);
}
Rational& Rational::operator-=(const int32_t rhs) noexcept {
    return *this -= Rational(rhs);
}
Rational& Rational::operator*=(const int32_t rhs) noexcept {
    return *this *= Rational(rhs);
}
Rational& Rational::operator/=(const int32_t rhs) {
    return *this /= Rational(rhs);
}



//арифметика
[[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
    Rational ans = lhs;
    return ans += rhs;
}
[[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
    Rational ans = lhs;
    return ans -= rhs;
}
[[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
    Rational ans = lhs;
    return ans *= rhs;
}
[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs) {
    Rational ans = lhs;
    return ans /= rhs;
}


[[nodiscard]] Rational operator+(const Rational& lhs, const int32_t rhs) noexcept {
    Rational ans = lhs;
    return ans += rhs;
}
[[nodiscard]] Rational operator-(const Rational& lhs, const int32_t rhs) noexcept {
    Rational ans = lhs;
    return ans -= rhs;
}
[[nodiscard]] Rational operator*(const Rational& lhs, const int32_t rhs) noexcept {
    Rational ans = lhs;
    return ans *= rhs;
}
[[nodiscard]] Rational operator/(const Rational& lhs, const int32_t rhs) {
    Rational ans = lhs;
    return ans /= rhs;
}


[[nodiscard]] Rational operator+(const int32_t lhs, const Rational& rhs) noexcept {
    Rational ans(lhs);
    return ans += rhs;
}
[[nodiscard]] Rational operator-(const int32_t lhs, const Rational& rhs) noexcept {
    Rational ans(lhs);
    return ans -= rhs;
}
[[nodiscard]] Rational operator*(const int32_t lhs, const Rational& rhs) noexcept {
    Rational ans(lhs);
    return ans *= rhs;
}
[[nodiscard]] Rational operator/(const int32_t lhs, const Rational& rhs) {
    Rational ans(lhs);
    return ans /= rhs;
}
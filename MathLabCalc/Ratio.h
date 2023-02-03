#pragma once
#include "Int.h"


namespace calc {


class Ratio {
   private:
    long long x = 0, y = 1;


    static const long long gcd(long long a, long long b) noexcept;


    void optimize();

   public:
    Ratio() noexcept = default;
    Ratio(const Ratio&) noexcept = default;
    Ratio(Ratio&&) noexcept = default;
    ~Ratio() noexcept = default;

    Ratio& operator=(const Ratio&) noexcept = default;
    Ratio& operator=(Ratio&&) noexcept = default;


    Ratio(long long x, long long y);


    Ratio(const Int& val) noexcept;


    operator std::wstring() const;


    const long long getX() const noexcept;
    const long long getY() const noexcept;


    const double getDouble() const noexcept;


    const MathType convert() const noexcept;


    const Ratio operator+() const noexcept;
    const Ratio operator-() const noexcept;


    const Ratio operator+(const Ratio& val) const;
    const Ratio operator-(const Ratio& val) const;
    const Ratio operator*(const Ratio& val) const;
    const Ratio operator/(const Ratio& val) const;


    const bool operator==(const Ratio& val) const;
    const bool operator!=(const Ratio& val) const;
    const bool operator<(const Ratio& val) const;
    const bool operator<=(const Ratio& val) const;
    const bool operator>(const Ratio& val) const;
    const bool operator>=(const Ratio& val) const;
};
}  // namespace calc

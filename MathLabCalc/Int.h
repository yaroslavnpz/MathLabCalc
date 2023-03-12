#pragma once
#include "begMathTypes.h"


namespace calc {


class Int {
   private:
    int64_t data = 0;


   public:
    constexpr Int() noexcept = default;
    constexpr Int(const Int&) noexcept = default;
    constexpr Int(Int&&) noexcept = default;
    ~Int() noexcept = default;


    constexpr Int(const int64_t data) noexcept;


    Int& operator=(const Int&) noexcept = default;
    Int& operator=(Int&&) noexcept = default;


    operator std::wstring() const;


    constexpr int64_t getData() const noexcept;


    friend constexpr Int operator+(const Int val) noexcept;
    friend constexpr Int operator-(const Int val) noexcept;
    friend constexpr Int operator~(const Int val) noexcept;

    friend constexpr Int operator+(const Int a, const Int b) noexcept;
    friend constexpr Int operator-(const Int a, const Int b) noexcept;
    friend constexpr Int operator*(const Int a, const Int b) noexcept;
    friend constexpr Int operator%(const Int a, const Int b);
    friend constexpr Int intDiv(const Int a, const Int b);

    friend MathType operator/(const Int a, const Int b);


    friend constexpr Int operator&(const Int a, const Int b) noexcept;
    friend constexpr Int operator|(const Int a, const Int b) noexcept;
    friend constexpr Int operator^(const Int a, const Int b) noexcept;
    friend constexpr Int operator<<(const Int a, const Int b) noexcept;
    friend constexpr Int operator>>(const Int a, const Int b) noexcept;


    friend constexpr bool operator==(const Int a, const Int b) noexcept;
    friend constexpr bool operator!=(const Int a, const Int b) noexcept;
    friend constexpr bool operator<(const Int a, const Int b) noexcept;
    friend constexpr bool operator<=(const Int a, const Int b) noexcept;
    friend constexpr bool operator>(const Int a, const Int b) noexcept;
    friend constexpr bool operator>=(const Int a, const Int b) noexcept;


    friend Int abs(const Int val) noexcept;
    friend MathType sqrt(const Int val) noexcept;
};

}  // namespace calc

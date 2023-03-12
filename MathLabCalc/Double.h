#pragma once
#include "begMathTypes.h"


#include "Int.h"


namespace calc {


class Double {
   private:
    long double data = 0.0L;

   public:
    constexpr Double() noexcept = default;
    constexpr Double(const Double&) noexcept = default;
    constexpr Double(Double&&) noexcept = default;
    ~Double() noexcept = default;


    constexpr Double(const long double data);
    constexpr Double(const Int val);


    Double& operator=(const Double&) noexcept = default;
    Double& operator=(Double&&) noexcept = default;


    operator std::wstring() const;

    constexpr long double getData() const noexcept;


    friend constexpr Double operator+(const Double val) noexcept;
    friend constexpr Double operator-(const Double val) noexcept;


    friend constexpr Double operator+(const Double a, const Double b) noexcept;
    friend constexpr Double operator-(const Double a, const Double b) noexcept;
    friend constexpr Double operator*(const Double a, const Double b) noexcept;
    friend constexpr Double operator/(const Double a, const Double b) noexcept;


    friend constexpr bool operator==(const Double a, const Double b) noexcept;
    friend constexpr bool operator!=(const Double a, const Double b) noexcept;
    friend constexpr bool operator<(const Double a, const Double b) noexcept;
    friend constexpr bool operator<=(const Double a, const Double b) noexcept;
    friend constexpr bool operator>(const Double a, const Double b) noexcept;
    friend constexpr bool operator>=(const Double a, const Double b) noexcept;


    friend Double abs(const Double val) noexcept;
    friend Double sqrt(const Double val);

    friend Double sin(const Double val) noexcept;
    friend Double cos(const Double val) noexcept;
    friend Double tg(const Double val);
    friend Double ctg(const Double val);

    friend Double asin(const Double val);
    friend Double acos(const Double val);
    friend Double atg(const Double val);

    friend Double log2(const Double val);
    friend Double log10(const Double val);
    friend Double ln(const Double val);

    friend Double log(const Double val, const Double base);

    friend Double pow(const Double val, const Double base);
};

}  // namespace calc

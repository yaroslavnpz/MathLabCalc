#pragma once
#include "begMathTypes.h"

#include "Int.h"


namespace calc {


/// @brief Класс для хранения дроби, использующей 2 целых числа по 64 бит
class Ratio {
   private:
    int64_t x = 0;
    int64_t y = 1;


    static int64_t gcd(int64_t a, int64_t b) noexcept;


    void optimize();


   public:
    constexpr Ratio() noexcept = default;
    constexpr Ratio(const Ratio&) noexcept = default;
    constexpr Ratio(Ratio&&) noexcept = default;
    ~Ratio() noexcept = default;

    constexpr Ratio& operator=(const Ratio&) noexcept = default;
    constexpr Ratio& operator=(Ratio&&) noexcept = default;


    constexpr Ratio(int64_t val) noexcept : x(val) {}
    constexpr Ratio(Int val) noexcept : x(val.getData()) {}
    Ratio(int64_t x, int64_t y);


    /// @brief Значение переменной в стандартных типах
    /// @return Значение переменной в стандартных типах
    constexpr std::pair<int64_t, int64_t> getData() const noexcept {
        return {x, y};
    }


    constexpr double getDouble() const noexcept {
        return double(x) / double(y);
    }


    /// @brief Строка, хранящая имя типа
    /// @return Строка, хранящая имя типа
    const std::wstring getType() const;


    /// @brief Строка, хранящая значение переменной
    /// @return Строка, хранящая значение переменной
    const std::wstring getName() const;


    Ratio operator+() const noexcept {
        return *this;
    }
    Ratio operator-() const noexcept {
        return Ratio(-x, y);
    }


    Ratio operator+(const Ratio& val) const noexcept;
    Ratio operator-(const Ratio& val) const noexcept;
    Ratio operator*(const Ratio& val) const noexcept;
    Ratio operator/(const Ratio& val) const;


    bool operator==(const Ratio& val) const noexcept;
    bool operator!=(const Ratio& val) const noexcept;
    bool operator<(const Ratio& val) const noexcept;
    bool operator<=(const Ratio& val) const noexcept;
    bool operator>(const Ratio& val) const noexcept;
    bool operator>=(const Ratio& val) const noexcept;
};


constexpr Ratio abs(const Ratio& val) noexcept {
    return val >= 0 ? val : -val;
}


Double sqrt(const Ratio& val);


Double log2(const Ratio& val);
Double log10(const Ratio& val);
Double ln(const Ratio& val);


Double sin(const Ratio& val) noexcept;
Double cos(const Ratio& val) noexcept;
Double tg(const Ratio& val) noexcept;
Double ctg(const Ratio& val) noexcept;

Double asin(const Ratio& val);
Double acos(const Ratio& val);
Double atg(const Ratio& val);


Double pow(const Ratio& val, const Ratio& base) noexcept;
Double log(const Ratio& val, const Ratio& base) noexcept;


}  // namespace calc

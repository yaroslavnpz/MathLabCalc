#pragma once
#include "Int64.h"


namespace calc {


/// @brief Класс для хранения дроби, использующей 2 целых числа по 64 бит
class Ratio64 {
   private:
    int64_t x = 0;
    int64_t y = 1;


    static int64_t gcd(int64_t a, int64_t b) noexcept;


    void optimize();


   public:
    constexpr Ratio64() noexcept = default;
    constexpr Ratio64(const Ratio64&) noexcept = default;
    constexpr Ratio64(Ratio64&&) noexcept = default;
    ~Ratio64() noexcept = default;

    constexpr Ratio64& operator=(const Ratio64&) noexcept = default;
    constexpr Ratio64& operator=(Ratio64&&) noexcept = default;


    constexpr Ratio64(int64_t val) noexcept : x(val) {}
    constexpr Ratio64(Int64 val) noexcept : x(val.getData()) {}
    Ratio64(int64_t x, int64_t y);


    /// @brief Значение переменной в стандартных типах
    /// @return Значение переменной в стандартных типах
    constexpr std::pair<int64_t, int64_t> getData() const noexcept {
        return {x, y};
    }


    /// @brief Строка, хранящая имя типа
    /// @return Строка, хранящая имя типа
    const std::wstring getType() const;


    /// @brief Строка, хранящая значение переменной
    /// @return Строка, хранящая значение переменной
    const std::wstring getName() const;


    friend constexpr Ratio64 operator+(const Ratio64& val) noexcept;
    friend constexpr Ratio64 operator-(const Ratio64& val) noexcept;

    friend Ratio64 operator+(const Ratio64& a, const Ratio64& b);
    friend Ratio64 operator-(const Ratio64& a, const Ratio64& b);
    friend Ratio64 operator*(const Ratio64& a, const Ratio64& b);
    friend Ratio64 operator/(const Ratio64& a, const Ratio64& b);

    friend bool operator==(const Ratio64& a, const Ratio64& b);
    friend bool operator!=(const Ratio64& a, const Ratio64& b);
    friend bool operator<(const Ratio64& a, const Ratio64& b);
    friend bool operator<=(const Ratio64& a, const Ratio64& b);
    friend bool operator>(const Ratio64& a, const Ratio64& b);
    friend bool operator>=(const Ratio64& a, const Ratio64& b);

    friend Ratio64 abs(const Ratio64& val) noexcept;

    friend Ratio64 min(const Ratio64& a, const Ratio64& b);
    friend Ratio64 max(const Ratio64& a, const Ratio64& b);
};


constexpr Ratio64 operator+(const Ratio64& val) noexcept {
    return val;
}
constexpr Ratio64 operator-(const Ratio64& val) noexcept {
    return Ratio64(-val.x, val.y);
}

Ratio64 operator+(const Ratio64& a, const Ratio64& b);
Ratio64 operator-(const Ratio64& a, const Ratio64& b);
Ratio64 operator*(const Ratio64& a, const Ratio64& b);
Ratio64 operator/(const Ratio64& a, const Ratio64& b);

bool operator==(const Ratio64& a, const Ratio64& b);
bool operator!=(const Ratio64& a, const Ratio64& b);
bool operator<(const Ratio64& a, const Ratio64& b);
bool operator<=(const Ratio64& a, const Ratio64& b);
bool operator>(const Ratio64& a, const Ratio64& b);
bool operator>=(const Ratio64& a, const Ratio64& b);

Ratio64 abs(const Ratio64& val) noexcept;

Ratio64 min(const Ratio64& a, const Ratio64& b);
Ratio64 max(const Ratio64& a, const Ratio64& b);

}  // namespace calc

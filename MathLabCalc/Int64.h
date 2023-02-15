#pragma once
#include "exceptions.h"


namespace calc {


class Ratio64;


/// @brief Класс для хранения целочисленного 64 битного типа
class Int64 {
   private:
    int64_t data = 0;

   public:
    constexpr Int64() noexcept = default;
    constexpr Int64(const Int64&) noexcept = default;
    constexpr Int64(Int64&&) noexcept = default;
    ~Int64() noexcept = default;

    constexpr Int64& operator=(const Int64&) noexcept = default;
    constexpr Int64& operator=(Int64&&) noexcept = default;


    constexpr Int64(int64_t data) noexcept : data(data) {}


    /// @brief Значение переменной в стандартных типах
    /// @return Значение переменной в стандартных типах
    constexpr int64_t getData() const noexcept {
        return data;
    }


    /// @brief Строка, хранящая имя типа
    /// @return Строка, хранящая имя типа
    const std::wstring getType() const;


    /// @brief Строка, хранящая значение переменной
    /// @return Строка, хранящая значение переменной
    const std::wstring getName() const;


    // friends operators -----------------------------------------------------------------------------------------------

    friend constexpr Int64 operator+(Int64 val) noexcept;
    friend constexpr Int64 operator-(Int64 val) noexcept;
    friend constexpr Int64 operator~(Int64 val) noexcept;

    friend constexpr Int64 operator+(Int64 a, Int64 b) noexcept;
    friend constexpr Int64 operator-(Int64 a, Int64 b) noexcept;
    friend constexpr Int64 operator*(Int64 a, Int64 b) noexcept;

    friend Ratio64 operator/(Int64 a, Int64 b);

    friend constexpr Int64 operator%(Int64 a, Int64 b);
    friend constexpr Int64 intDiv(Int64 a, Int64 b);

    friend constexpr Int64 operator&(Int64 a, Int64 b) noexcept;
    friend constexpr Int64 operator|(Int64 a, Int64 b) noexcept;
    friend constexpr Int64 operator^(Int64 a, Int64 b) noexcept;
    friend constexpr Int64 operator<<(Int64 a, Int64 b);
    friend constexpr Int64 operator>>(Int64 a, Int64 b);

    friend constexpr Int64 operator==(Int64 a, Int64 b) noexcept;
    friend constexpr Int64 operator!=(Int64 a, Int64 b) noexcept;
    friend constexpr Int64 operator<(Int64 a, Int64 b) noexcept;
    friend constexpr Int64 operator<=(Int64 a, Int64 b) noexcept;
    friend constexpr Int64 operator>(Int64 a, Int64 b) noexcept;
    friend constexpr Int64 operator>=(Int64 a, Int64 b) noexcept;

    friend constexpr Int64 abs(Int64 val) noexcept;

    friend constexpr Int64 min(Int64 a, Int64 b) noexcept;
    friend constexpr Int64 max(Int64 a, Int64 b) noexcept;
};


Ratio64 operator/(Int64 a, Int64 b);


constexpr Int64 operator+(Int64 val) noexcept {
    return val;
}
constexpr Int64 operator-(Int64 val) noexcept {
    return -val.data;
}
constexpr Int64 operator~(Int64 val) noexcept {
    return ~val.data;
}

constexpr Int64 operator+(Int64 a, Int64 b) noexcept {
    return a.data + b.data;
}
constexpr Int64 operator-(Int64 a, Int64 b) noexcept {
    return a.data - b.data;
}
constexpr Int64 operator*(Int64 a, Int64 b) noexcept {
    return a.data * b.data;
}

constexpr Int64 operator%(Int64 a, Int64 b) {
    if (b.data == 0)
        throw BadOperator();
    return a.data % b.data;
}
constexpr Int64 intDiv(Int64 a, Int64 b) {
    if (b.data == 0)
        throw BadOperator();
    return a.data / b.data;
}

constexpr Int64 operator&(Int64 a, Int64 b) noexcept {
    return a.data & b.data;
}
constexpr Int64 operator|(Int64 a, Int64 b) noexcept {
    return a.data | b.data;
}
constexpr Int64 operator^(Int64 a, Int64 b) noexcept {
    return a.data ^ b.data;
}
constexpr Int64 operator<<(Int64 a, Int64 b) {
    if (b.data < 0)
        throw BadOperator();
    return a.data << b.data;
}
constexpr Int64 operator>>(Int64 a, Int64 b) {
    if (b.data < 0)
        throw BadOperator();
    return a.data >> b.data;
}

constexpr Int64 operator==(Int64 a, Int64 b) noexcept {
    return a.data == b.data;
}
constexpr Int64 operator!=(Int64 a, Int64 b) noexcept {
    return a.data != b.data;
}
constexpr Int64 operator<(Int64 a, Int64 b) noexcept {
    return a.data < b.data;
}
constexpr Int64 operator<=(Int64 a, Int64 b) noexcept {
    return a.data <= b.data;
}
constexpr Int64 operator>(Int64 a, Int64 b) noexcept {
    return a.data > b.data;
}
constexpr Int64 operator>=(Int64 a, Int64 b) noexcept {
    return a.data >= b.data;
}

constexpr Int64 abs(Int64 val) noexcept {
    return val.data < 0 ? -val.data : val.data;
}

constexpr Int64 min(Int64 a, Int64 b) noexcept {
    return a.data < b.data ? a : b;
}
constexpr Int64 max(Int64 a, Int64 b) noexcept {
    return a.data > b.data ? a : b;
}


}  // namespace calc

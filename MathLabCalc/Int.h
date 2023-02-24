#pragma once
#include "exceptions.h"


namespace calc {


class Ratio;
class Double;


/// @brief Класс для хранения целочисленного 64 битного типа
class Int {
   private:
    int64_t data = 0;

   public:
    constexpr Int() noexcept = default;
    constexpr Int(const Int&) noexcept = default;
    constexpr Int(Int&&) noexcept = default;
    ~Int() noexcept = default;

    constexpr Int& operator=(const Int&) noexcept = default;
    constexpr Int& operator=(Int&&) noexcept = default;


    constexpr Int(int64_t data) noexcept : data(data) {}


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


    constexpr Int operator+() const noexcept {
        return *this;
    }
    constexpr Int operator-() const noexcept {
        return -data;
    }
    constexpr Int operator~() const noexcept {
        return ~data;
    }


    constexpr Int operator+(Int val) const noexcept {
        return data + val.data;
    }
    constexpr Int operator-(Int val) const noexcept {
        return data - val.data;
    }
    constexpr Int operator*(Int val) const noexcept {
        return data * val.data;
    }
    constexpr Int operator%(Int val) const {
        if (val.data == 0)
            throw DivizionByZero();
        return data % val.data;
    }
    constexpr Int intDiv(Int val) const {
        if (val.data == 0)
            throw DivizionByZero();
        return data / val.data;
    }


    Ratio operator/(Int val) const;


    constexpr Int operator&(Int val) const noexcept {
        return data & val.data;
    }
    constexpr Int operator|(Int val) const noexcept {
        return data | val.data;
    }
    constexpr Int operator^(Int val) const noexcept {
        return data ^ val.data;
    }
    constexpr Int operator<<(Int val) const noexcept {
        return data << val.data;
    }
    constexpr Int operator>>(Int val) const noexcept {
        return data >> val.data;
    }


    constexpr bool operator==(Int val) const noexcept {
        return data == val.data;
    }
    constexpr bool operator!=(Int val) const noexcept {
        return data != val.data;
    }
    constexpr bool operator<(Int val) const noexcept {
        return data < val.data;
    }
    constexpr bool operator<=(Int val) const noexcept {
        return data <= val.data;
    }
    constexpr bool operator>(Int val) const noexcept {
        return data > val.data;
    }
    constexpr bool operator>=(Int val) const noexcept {
        return data >= val.data;
    }
};


constexpr Int abs(Int val) noexcept {
    return val >= 0 ? val : -val;
}

Double sqrt(Int val);


Double log2(Int val);
Double log10(Int val);
Double ln(Int val);

Double sin(Int val);
Double cos(Int val);
Double tg(Int val);
Double ctg(Int val);

Double asin(Int val);
Double acos(Int val);
Double atg(Int val);

Double pow(Int a, Int base) noexcept;
Double log(Int a, Int base);

}  // namespace calc

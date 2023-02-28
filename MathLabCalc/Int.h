#pragma once
#include "begMathTypes.h"


namespace calc {


/// @brief Класс для хранения целочисленного 64 битного типа
class Int {
   private:
    int64_t data = 0;

   public:
    constexpr Int() noexcept = default;
    constexpr Int(const Int&) noexcept = default;
    constexpr Int(Int&&) noexcept = default;
    ~Int() noexcept = default;

    Int& operator=(const Int&) noexcept = default;
    Int& operator=(Int&&) noexcept = default;


    constexpr Int(const int64_t data) noexcept : data(data) {}


    /// @brief Значение переменной в стандартных типах
    /// @return Значение переменной в стандартных типах
    constexpr const int64_t getData() const noexcept {
        return data;
    }


    /// @brief Строка, хранящая имя типа
    /// @return Строка, хранящая имя типа
    const std::wstring getType() const;


    /// @brief Строка, хранящая значение переменной
    /// @return Строка, хранящая значение переменной
    const std::wstring getName() const;


    constexpr const Int operator+() const noexcept {
        return *this;
    }
    constexpr const Int operator-() const noexcept {
        return -data;
    }
    constexpr const Int operator~() const noexcept {
        return ~data;
    }


    constexpr const Int operator+(const Int val) const noexcept {
        return data + val.data;
    }
    constexpr const Int operator-(const Int val) const noexcept {
        return data - val.data;
    }
    constexpr const Int operator*(const Int val) const noexcept {
        return data * val.data;
    }
    constexpr const Int operator%(const Int val) const {
        if (val.data == 0)
            throw DivizionByZero();
        return data % val.data;
    }
    constexpr const Int intDiv(const Int val) const {
        if (val.data == 0)
            throw DivizionByZero();
        return data / val.data;
    }


    const Ratio operator/(const Int val) const;


    constexpr const Int operator&(const Int val) const noexcept {
        return data & val.data;
    }
    constexpr const Int operator|(const Int val) const noexcept {
        return data | val.data;
    }
    constexpr const Int operator^(const Int val) const noexcept {
        return data ^ val.data;
    }
    constexpr const Int operator<<(const Int val) const noexcept {
        return data << val.data;
    }
    constexpr const Int operator>>(const Int val) const noexcept {
        return data >> val.data;
    }


    constexpr const bool operator==(const Int val) const noexcept {
        return data == val.data;
    }
    constexpr const bool operator!=(const Int val) const noexcept {
        return data != val.data;
    }
    constexpr const bool operator<(const Int val) const noexcept {
        return data < val.data;
    }
    constexpr const bool operator<=(const Int val) const noexcept {
        return data <= val.data;
    }
    constexpr const bool operator>(const Int val) const noexcept {
        return data > val.data;
    }
    constexpr const bool operator>=(const Int val) const noexcept {
        return data >= val.data;
    }
};


constexpr const Int abs(const Int val) noexcept {
    return val >= 0 ? val : -val;
}

const Double sqrt(const Int val);


const Double log2(const Int val);
const Double log10(const Int val);
const Double ln(const Int val);

const Double sin(const Int val);
const Double cos(const Int val);
const Double tg(const Int val);
const Double ctg(const Int val);

const Double asin(const Int val);
const Double acos(const Int val);
const Double atg(const Int val);

const Double pow(const Int a, const Int base) noexcept;
const Double log(const Int a, const Int base);

}  // namespace calc

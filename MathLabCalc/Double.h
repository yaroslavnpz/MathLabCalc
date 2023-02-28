#pragma once
#include "begMathTypes.h"

#include "Int.h"
#include "Ratio.h"


namespace calc {


/// @brief Класс для хранения целочисленного 64 битного типа
class Double {
   private:
    double data = 0;

   public:
    constexpr Double() noexcept = default;
    constexpr Double(const Double&) noexcept = default;
    constexpr Double(Double&&) noexcept = default;
    ~Double() noexcept = default;

    Double& operator=(const Double&) noexcept = default;
    Double& operator=(Double&&) noexcept = default;


    constexpr Double(const double data) noexcept : data(data) {}
    constexpr Double(const Int val) noexcept : data(val.getData()) {}


    /// @brief Значение переменной в стандартных типах
    /// @return Значение переменной в стандартных типах
    constexpr const double getData() const noexcept {
        return data;
    }


    /// @brief Строка, хранящая имя типа
    /// @return Строка, хранящая имя типа
    const std::wstring getType() const;


    /// @brief Строка, хранящая значение переменной
    /// @return Строка, хранящая значение переменной
    const std::wstring getName() const;


    constexpr const Double operator+() const noexcept {
        return *this;
    }
    constexpr const Double operator-() const noexcept {
        return -data;
    }


    constexpr const Double operator+(const Double val) const noexcept {
        return data + val.data;
    }
    constexpr const Double operator-(const Double val) const noexcept {
        return data - val.data;
    }
    constexpr const Double operator*(const Double val) const noexcept {
        return data * val.data;
    }
    constexpr const Double operator/(const Double val) const noexcept {
        return data / val.data;
    }


    constexpr const bool operator==(const Double val) const noexcept {
        return data == val.data;
    }
    constexpr const bool operator!=(const Double val) const noexcept {
        return data != val.data;
    }
    constexpr const bool operator<(const Double val) const noexcept {
        return data < val.data;
    }
    constexpr const bool operator<=(const Double val) const noexcept {
        return data <= val.data;
    }
    constexpr const bool operator>(const Double val) const noexcept {
        return data > val.data;
    }
    constexpr const bool operator>=(const Double val) const noexcept {
        return data >= val.data;
    }
};


constexpr const Double abs(const Double val) noexcept {
    return val >= 0 ? val : -val;
}

const Double sqrt(const Double val);


const Double log2(const Double val);
const Double log10(const Double val);
const Double ln(const Double val);


const Double sin(const Double val) noexcept;
const Double cos(const Double val) noexcept;
const Double tg(const Double val) noexcept;
const Double ctg(const Double val) noexcept;

const Double asin(const Double val);
const Double acos(const Double val);
const Double atg(const Double val);


const Double pow(const Double val, const Double base) noexcept;
const Double log(const Double val, const Double base);

}  // namespace calc

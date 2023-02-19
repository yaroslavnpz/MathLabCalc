#pragma once
#include "exceptions.h"
#include "Int.h"


namespace calc {


class MathType;


/// @brief Класс для хранения целочисленного 64 битного типа
class Double {
   private:
    double data = 0;

   public:
    constexpr Double() noexcept = default;
    constexpr Double(const Double&) noexcept = default;
    constexpr Double(Double&&) noexcept = default;
    ~Double() noexcept = default;

    constexpr Double& operator=(const Double&) noexcept = default;
    constexpr Double& operator=(Double&&) noexcept = default;


    constexpr Double(double data) noexcept : data(data) {}
    constexpr Double(Int val) noexcept : data(val.getData()) {}


    /// @brief Значение переменной в стандартных типах
    /// @return Значение переменной в стандартных типах
    constexpr double getData() const noexcept {
        return data;
    }


    /// @brief Строка, хранящая имя типа
    /// @return Строка, хранящая имя типа
    const std::wstring getType() const;


    /// @brief Строка, хранящая значение переменной
    /// @return Строка, хранящая значение переменной
    const std::wstring getName() const;


    constexpr Double operator+() const noexcept {
        return *this;
    }
    constexpr Double operator-() const noexcept {
        return -data;
    }


    constexpr Double operator+(Double val) const noexcept {
        return data + val.data;
    }
    constexpr Double operator-(Double val) const noexcept {
        return data - val.data;
    }
    constexpr Double operator*(Double val) const noexcept {
        return data * val.data;
    }
    constexpr Double operator/(Double val) const noexcept {
        return data / val.data;
    }


    constexpr bool operator==(Double val) const noexcept {
        return data == val.data;
    }
    constexpr bool operator!=(Double val) const noexcept {
        return data != val.data;
    }
    constexpr bool operator<(Double val) const noexcept {
        return data < val.data;
    }
    constexpr bool operator<=(Double val) const noexcept {
        return data <= val.data;
    }
    constexpr bool operator>(Double val) const noexcept {
        return data > val.data;
    }
    constexpr bool operator>=(Double val) const noexcept {
        return data >= val.data;
    }
};


constexpr Double abs(Double val) noexcept {
    return val >= 0 ? val : -val;
}

Double sqrt(Double val);


Double log2(Double val);
Double log10(Double val);
Double ln(Double val);


Double sin(Double val) noexcept;
Double cos(Double val) noexcept;
Double tg(Double val) noexcept;
Double ctg(Double val) noexcept;

Double asin(Double val);
Double acos(Double val);
Double atg(Double val);


Double pow(Double val, Double base) noexcept;
Double log(Double val, Double base);


constexpr Double min(Double a, Double b) noexcept {
    return a < b ? a : b;
}
constexpr Double max(Double a, Double b) noexcept {
    return a > b ? a : b;
}

}  // namespace calc

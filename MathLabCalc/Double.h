#pragma once
#include "Int64.h"


namespace calc {

class Ratio;
class Float;


/// @brief Класс для хранения перменной типа double
class Double {
   private:
    double data = 0.0;

   public:
    constexpr Double() noexcept = default;
    constexpr Double(const Double&) noexcept = default;
    constexpr Double(Double&&) noexcept = default;
    ~Double() noexcept = default;

    constexpr Double& operator=(const Double&) noexcept;
    constexpr Double& operator=(Double&&) noexcept;


    Double(double val) noexcept;
    Double(Int64 val) noexcept;
    constexpr Double(Float val) noexcept;
    constexpr Double(const Ratio& val) noexcept;


    /// @brief Строка, хранящая имя типа
    /// @return Строка, хранящая имя типа
    const std::wstring getType() const;


    /// @brief Строка, хранящая значение переменной
    /// @return Строка, хранящая значение переменной
    const std::wstring getName() const;


    /// @brief Значение переменной в стандартных типах
    /// @return Значение переменной в стандартных типах
    constexpr double getData() const noexcept;


    friend Double operator+(Double val) noexcept;
    friend Double operator-(Double val) noexcept;
    friend Double operator~(Double val) noexcept;

    friend Double operator+(Double a, Double b) noexcept;
    friend Double operator-(Double a, Double b) noexcept;
    friend Double operator*(Double a, Double b) noexcept;
    friend Double operator/(Double a, Double b) noexcept;


    friend const bool operator==(Double a, Double b) noexcept;
    friend const bool operator!=(Double a, Double b) noexcept;
    friend const bool operator<(Double a, Double b) noexcept;
    friend const bool operator<=(Double a, Double b) noexcept;
    friend const bool operator>(Double a, Double b) noexcept;
    friend const bool operator>=(Double a, Double b) noexcept;
};


Double operator+(Double val) noexcept;
Double operator-(Double val) noexcept;
Double operator~(Double val) noexcept;

Double operator+(Double a, Double b) noexcept;
Double operator-(Double a, Double b) noexcept;
Double operator*(Double a, Double b) noexcept;
Double operator/(Double a, Double b) noexcept;


const bool operator==(Double a, Double b) noexcept;
const bool operator!=(Double a, Double b) noexcept;
const bool operator<(Double a, Double b) noexcept;
const bool operator<=(Double a, Double b) noexcept;
const bool operator>(Double a, Double b) noexcept;
const bool operator>=(Double a, Double b) noexcept;
}  // namespace calc

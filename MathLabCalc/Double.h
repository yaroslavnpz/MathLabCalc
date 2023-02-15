#pragma once
#include "exceptions.h"
#include "Int64.h"


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
    constexpr Double(Int64 val) noexcept : data(val.getData()) {}


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
};

}  // namespace calc

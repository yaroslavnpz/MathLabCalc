#pragma once
#include "Double.h"
#include "Int64.h"
#include "exceptions.h"


#include <complex>


namespace calc {


/// @brief Класс для хранения значений true and false
class Complex {
   private:
    std::complex<double> data = false;

   public:
    Complex() noexcept = default;
    Complex(const Complex&) noexcept = default;
    Complex(Complex&&) noexcept = default;
    ~Complex() noexcept = default;

    Complex& operator=(const Complex&) noexcept = default;
    Complex& operator=(Complex&&) noexcept = default;


    Complex(std::complex<double>& data) noexcept : data(data) {}
    Complex(Int64 val) noexcept;
    Complex(Ratio val) noexcept;
    Complex(Double val) noexcept;


    /// @brief Значение переменной в стандартных типах
    /// @return Значение переменной в стандартных типах
    std::complex<double> getData() const noexcept {
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

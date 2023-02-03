#pragma once
#include "Float.h"


#include <complex>


namespace calc {


class Complex {
   private:
    std::complex<double> data;

   public:
    Complex() noexcept = default;
    Complex(const Complex&) noexcept = default;
    Complex(Complex&&) noexcept = default;

    Complex& operator=(const Complex&) noexcept = default;
    Complex& operator=(Complex&&) noexcept = default;


    Complex(const std::complex<double> val) noexcept;


    Complex(const Int& val) noexcept;
    Complex(const Ratio& val) noexcept;
    Complex(const Float& val) noexcept;


    static const bool gen(const std::wstring& str, MathType& val);


    const double getX() const noexcept;
    const double getY() const noexcept;


    const Complex operator+() const noexcept;
    const Complex operator-() const noexcept;


    const Complex operator+(const Complex& val) const noexcept;
    const Complex operator-(const Complex& val) const noexcept;
    const Complex operator*(const Complex& val) const noexcept;
    const Complex operator/(const Complex& val) const noexcept;


    const bool operator==(const Complex& val) const noexcept;
    const bool operator!=(const Complex& val) const noexcept;
    const bool operator<(const Complex& val) const noexcept;
    const bool operator<=(const Complex& val) const noexcept;
    const bool operator>(const Complex& val) const noexcept;
    const bool operator>=(const Complex& val) const noexcept;
};


}  // namespace calc

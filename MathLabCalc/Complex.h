#pragma once
#include "begMathTypes.h"


#include "Double.h"


namespace calc {


class Complex {
   private:
    std::complex<long double> data = 0.0L;

   public:
    constexpr Complex() noexcept = default;
    constexpr Complex(const Complex&) noexcept = default;
    constexpr Complex(Complex&&) noexcept = default;
    ~Complex() noexcept = default;


    constexpr Complex(const std::complex<long double>& data) noexcept;
    constexpr Complex(std::complex<long double>&& data) noexcept;
    constexpr Complex(const Int val) noexcept;
    constexpr Complex(const Double val) noexcept;


    Complex& operator=(const Complex&) noexcept = default;
    Complex& operator=(Complex&&) noexcept = default;


    operator std::wstring() const;


    constexpr std::complex<long double> getData() const noexcept;


    friend constexpr Complex operator+(Complex val) noexcept;
    friend constexpr Complex operator-(Complex val) noexcept;


    friend constexpr Complex operator+(Complex a, const Complex& b) noexcept;
    friend constexpr Complex operator-(Complex a, const Complex& b) noexcept;
    friend constexpr Complex operator*(Complex a, const Complex& b) noexcept;
    friend constexpr Complex operator/(Complex a, const Complex& b) noexcept;


    friend constexpr bool operator==(const Complex& a, const Complex& b) noexcept;
    friend constexpr bool operator!=(const Complex& a, const Complex& b) noexcept;
};
}  // namespace calc

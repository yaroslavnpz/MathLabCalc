#pragma once
#include "Double.h"
#include "begMathTypes.h"


#include <complex>


namespace calc {


class Complex {
   private:
    std::complex<double> data = 0;

    public:
    constexpr Complex() noexcept = default;
    constexpr Complex(const Complex&) noexcept = default;
    constexpr Complex(Complex&&) noexcept = default;
    ~Complex() noexcept = default;

    Complex(const std::complex<double>& val) noexcept;
    Complex(const Int& val) noexcept;
    Complex(const Ratio& val) noexcept;
    Complex(const Double& val) noexcept;


    const std::complex<double> getData() const noexcept {
        return data;
    }


    const std::wstring getType() const;


    const std::wstring getName() const;


    const Complex operator+() const noexcept;
    const Complex operator-() const noexcept;

    const Complex operator+(const Complex& val) const noexcept;
    const Complex operator-(const Complex& val) const noexcept;
    const Complex operator*(const Complex& val) const noexcept;
    const Complex operator/(const Complex& val) const noexcept;


    const bool operator==(const Complex& val) const noexcept;
    const bool operator!=(const Complex& val) const noexcept;
};


const Complex sqrt(const Complex& val);

const Complex log10(const Complex& val);
const Complex ln(const Complex& val);

const Complex sin(const Complex& val);
const Complex cos(const Complex& val);
const Complex tg(const Complex& val);
const Complex ctg(const Complex& val);

const Complex asin(const Complex& val);
const Complex acos(const Complex& val);
const Complex atg(const Complex& val);

const Complex pow(const Complex& val, const Complex& base);
const Complex log(const Complex& val, const Complex& base);
}  // namespace calc

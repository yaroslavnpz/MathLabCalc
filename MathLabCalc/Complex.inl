#pragma once
#include "Complex.h"

namespace calc {

constexpr calc::Complex::Complex(const std::complex<long double>& data) noexcept : data(data) {}

constexpr Complex::Complex(std::complex<long double>&& data) noexcept : data(data) {}

constexpr Complex::Complex(const Int val) noexcept : data(val.getData()) {}

constexpr Complex::Complex(const Double val) noexcept :data(val.getData()) {}

Complex::operator std::wstring() const {
    return std::to_wstring(data.real()) + L" + " + std::to_wstring(data.imag()) + L"i";
}

constexpr std::complex<long double> Complex::getData() const noexcept {
    return data;
}

constexpr Complex operator+(Complex val) noexcept {
    return val;
}

constexpr Complex operator-(Complex val) noexcept {
    return -val;
}

constexpr Complex operator+(const Complex& a, const Complex& b) noexcept {
    return a.data + b.data;
}

constexpr Complex operator-(const Complex& a, const Complex& b) noexcept {
    return a.data - b.data;
}

constexpr Complex operator*(const Complex& a, const Complex& b) noexcept {
    return a.data * b.data;
}

constexpr Complex operator/(const Complex& a, const Complex& b) noexcept {
    return a.data / b.data;
}
constexpr bool operator==(const Complex& a, const Complex& b) noexcept {
    return a.data == b.data;
}
constexpr bool operator!=(const Complex& a, const Complex& b) noexcept {
    return a.data != b.data;
}
}  // namespace calc

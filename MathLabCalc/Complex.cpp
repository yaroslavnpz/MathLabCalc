#include "Complex.h"


namespace calc {

Complex::Complex(const std::complex<double>& val) noexcept : data(val) {}

Complex::Complex(const Int& val) noexcept : data(val.getData()) {}

Complex::Complex(const Ratio& val) noexcept : data(val.getDouble()) {}

Complex::Complex(const Double& val) noexcept : data(val.getData()) {}

const std::wstring calc::Complex::getType() const {
    return L"Complex";
}

const std::wstring Complex::getName() const {
    return std::to_wstring(data.real()) + L" + " + std::to_wstring(data.imag()) + L"i";
}

const Complex Complex::operator+() const noexcept {
    return *this;
}

const Complex Complex::operator-() const noexcept {
    return -data;
}

const Complex Complex::operator+(const Complex& val) const noexcept {
    return data + val.data;
}

const Complex Complex::operator-(const Complex& val) const noexcept {
    return data - val.data;
}

const Complex Complex::operator*(const Complex& val) const noexcept {
    return data * val.data;
}

const Complex Complex::operator/(const Complex& val) const noexcept {
    return data / val.data;
}

const bool Complex::operator==(const Complex& val) const noexcept {
    return data == val.data;
}

const bool Complex::operator!=(const Complex& val) const noexcept {
    return data != val.data;
}


const Complex sqrt(const Complex& val) {
    return std::sqrt(val.getData());
}

const Complex log10(const Complex& val) {
    return std::log10(val.getData());
}

const Complex ln(const Complex& val) {
    return std::log(val.getData());
}

const Complex sin(const Complex& val) {
    return std::sin(val.getData());
}

const Complex cos(const Complex& val) {
    return std::cos(val.getData());
}

const Complex tg(const Complex& val) {
    return std::tan(val.getData());
}

const Complex ctg(const Complex& val) {
    return std::complex<double>(1, 0) / std::tan(val.getData());
}

const Complex asin(const Complex& val) {
    return std::asin(val.getData());
}

const Complex acos(const Complex& val) {
    return std::acos(val.getData());
}

const Complex atg(const Complex& val) {
    return std::atan(val.getData());
}

const Complex pow(const Complex& val, const Complex& base) {
    return std::pow(val.getData(), base.getData());
}

const Complex log(const Complex& val, const Complex& base) {
    return std::log(val.getData()) / std::log(base.getData());
}

}  // namespace calc

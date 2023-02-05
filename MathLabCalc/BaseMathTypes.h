#pragma once
#include <cmath>
#include <complex>
#include <string>


namespace calc {


#define MATHTYPESLIST std::monostate, Bool, Int, Float, Complex


class MathType;


class Bool {
   private:
    bool data = false;

   public:
    constexpr Bool() noexcept = default;
    constexpr Bool(const Bool&) noexcept = default;
    constexpr Bool(Bool&&) noexcept = default;
    ~Bool() noexcept = default;

    constexpr Bool& operator=(const Bool&) noexcept = default;
    constexpr Bool& operator=(Bool&&) noexcept = default;


    constexpr Bool(const bool val) noexcept : data(val) {}


    operator std::wstring() const {
        if (data)
            return L"True";
        else
            return L"False";
    }


    static const bool gen(const std::wstring& str, MathType& val);


    constexpr const bool getBool() const noexcept {
        return data;
    }


    constexpr const Bool operator!() const noexcept {
        return !data;
    }


    constexpr const Bool operator+(const Bool& val) const noexcept {
        return data || val.data;
    }
    constexpr const Bool operator*(const Bool& val) const noexcept {
        return data && val.data;
    }

    constexpr const Bool operator||(const Bool& val) const noexcept {
        return data || val.data;
    }
    constexpr const Bool operator&&(const Bool& val) const noexcept {
        return data && val.data;
    }


    constexpr const bool operator==(const Bool& val) const noexcept {
        return data == val.data;
    }
    constexpr const bool operator!=(const Bool& val) const noexcept {
        return data != val.data;
    }
    constexpr const bool operator<(const Bool& val) const noexcept {
        return data < val.data;
    }
    constexpr const bool operator<=(const Bool& val) const noexcept {
        return data <= val.data;
    }
    constexpr const bool operator>(const Bool& val) const noexcept {
        return data > val.data;
    }
    constexpr const bool operator>=(const Bool& val) const noexcept {
        return data >= val.data;
    }
};


class Int {
   private:
    long long data = 0;

   public:
    constexpr Int() noexcept = default;
    constexpr Int(const Int&) noexcept = default;
    constexpr Int(Int&&) noexcept = default;
    ~Int() noexcept = default;

    constexpr Int& operator=(const Int&) noexcept = default;
    constexpr Int& operator=(Int&&) noexcept = default;


    constexpr Int(const long long val) noexcept : data(val) {}


    operator std::wstring() const {
        return std::to_wstring(data);
    }


    static const bool gen(const std::wstring& str, MathType& val);


    constexpr const long long getInt() const noexcept {
        return data;
    }


    constexpr const Int operator+() const noexcept {
        return *this;
    }
    constexpr const Int operator-() const noexcept {
        return -data;
    }
    constexpr const Int operator~() const noexcept {
        return ~data;
    }


    constexpr const Int operator+(const Int& val) const noexcept {
        return data + val.data;
    }
    constexpr const Int operator-(const Int& val) const noexcept {
        return data - val.data;
    }
    constexpr const Int operator*(const Int& val) const noexcept {
        return data * val.data;
    }


    constexpr const Int intDiv(const Int& val) const {
        return data / val.data;
    }
    constexpr const Int operator%(const Int& val) const {
        return data % val.data;
    }

    const MathType operator/(const Int& val) const;


    constexpr const Int operator|(const Int& val) const noexcept {
        return data | val.data;
    }
    constexpr const Int operator&(const Int& val) const noexcept {
        return data & val.data;
    }
    constexpr const Int operator^(const Int& val) const noexcept {
        return data ^ val.data;
    }
    constexpr const Int operator<<(const Int& val) const noexcept {
        return data << val.data;
    }
    constexpr const Int operator>>(const Int& val) const noexcept {
        return data >> val.data;
    }


    constexpr const bool operator==(const Int& val) const noexcept {
        return data == val.data;
    }
    constexpr const bool operator!=(const Int& val) const noexcept {
        return data != val.data;
    }
    constexpr const bool operator<(const Int& val) const noexcept {
        return data < val.data;
    }
    constexpr const bool operator<=(const Int& val) const noexcept {
        return data <= val.data;
    }
    constexpr const bool operator>(const Int& val) const noexcept {
        return data > val.data;
    }
    constexpr const bool operator>=(const Int& val) const noexcept {
        return data >= val.data;
    }
};


class Ratio {
   private:
    long long x = 0, y = 1;


    constexpr static const long long gcd(long long a, long long b) noexcept {
        while (b != 0) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }


    constexpr void optimize() {
        if (y == 0)
            throw -1;
        if (y < 0)
            x = -x, y = -y;
        auto d = gcd(abs(x), y);
        x /= d;
        y /= d;
    }

   public:
    constexpr Ratio() noexcept = default;
    constexpr Ratio(const Ratio&) noexcept = default;
    constexpr Ratio(Ratio&&) noexcept = default;
    ~Ratio() noexcept = default;

    constexpr Ratio& operator=(const Ratio&) noexcept = default;
    constexpr Ratio& operator=(Ratio&&) noexcept = default;


    constexpr Ratio(long long x, long long y) : x(x), y(y) {
        optimize();
    }


    constexpr Ratio(const Int& val) noexcept : x(val.getInt()), y(1) {}


    operator std::wstring() const {
        return std::to_wstring(getDouble());
    }


    constexpr const long long getNumerator() const noexcept {
        return x;
    }
    constexpr const long long getDenominator() const noexcept {
        return y;
    }


    constexpr const double getDouble() const noexcept {
        return double(x) / double(y);
    }


    const MathType convert() const noexcept;


    constexpr const Ratio operator+() const noexcept {
        return *this;
    }
    const Ratio operator-() const noexcept {
        return Ratio(-x, y);
    }


    const Ratio operator+(const Ratio& val) const;
    const Ratio operator-(const Ratio& val) const;
    const Ratio operator*(const Ratio& val) const;
    const Ratio operator/(const Ratio& val) const;


    const bool operator==(const Ratio& val) const;
    const bool operator!=(const Ratio& val) const;
    const bool operator<(const Ratio& val) const;
    const bool operator<=(const Ratio& val) const;
    const bool operator>(const Ratio& val) const;
    const bool operator>=(const Ratio& val) const;
};


class Float {
   private:
    double data = 0.0;

   public:
    constexpr Float() noexcept = default;
    constexpr Float(const Float&) noexcept = default;
    constexpr Float(Float&&) noexcept = default;

    constexpr Float& operator=(const Float&) noexcept = default;
    constexpr Float& operator=(Float&&) noexcept = default;


    constexpr Float(const double val) noexcept : data(val) {}


    constexpr Float(const Int& val) noexcept : data(val.getInt()) {}
    constexpr Float(const Ratio& val) noexcept : data(val.getDouble()) {}


    static const bool gen(const std::wstring& str, MathType& val);


    constexpr const double getDouble() const noexcept {
        return data;
    }


    constexpr const Float operator+() const noexcept {
        return *this;
    }
    constexpr const Float operator-() const noexcept {
        return -data;
    }


    constexpr const Float operator+(const Float& val) const noexcept {
        return data + val.data;
    }
    constexpr const Float operator-(const Float& val) const noexcept {
        return data - val.data;
    }
    constexpr const Float operator*(const Float& val) const noexcept {
        return data * val.data;
    }
    constexpr const Float operator/(const Float& val) const noexcept {
        return data / val.data;
    }


    constexpr const bool operator==(const Float& val) const noexcept {
        return data == val.data;
    }
    constexpr const bool operator!=(const Float& val) const noexcept {
        return data != val.data;
    }
    constexpr const bool operator<(const Float& val) const noexcept {
        return data < val.data;
    }
    constexpr const bool operator<=(const Float& val) const noexcept {
        return data <= val.data;
    }
    constexpr const bool operator>(const Float& val) const noexcept {
        return data > val.data;
    }
    constexpr const bool operator>=(const Float& val) const noexcept {
        return data >= val.data;
    }
};


class Complex {
   private:
    std::complex<double> data;

   public:
    Complex() noexcept = default;
    Complex(const Complex&) noexcept = default;
    Complex(Complex&&) noexcept = default;

    Complex& operator=(const Complex&) noexcept = default;
    Complex& operator=(Complex&&) noexcept = default;


    Complex(const std::complex<double> val) noexcept : data(val) {}


    Complex(const Int& val) noexcept : data(val.getInt()) {}
    Complex(const Ratio& val) noexcept : data(val.getDouble()) {}
    Complex(const Float& val) noexcept : data(val.getDouble()) {}


    static const bool gen(const std::wstring& str, MathType& val);


    const double getReal() const noexcept {
        return data.real();
    }
    const double getImag() const noexcept {
        return data.imag();
    }


    const Complex operator+() const noexcept {
        return *this;
    }
    const Complex operator-() const noexcept {
        return -data;
    }


    const Complex operator+(const Complex& val) const noexcept {
        return data + val.data;
    }
    const Complex operator-(const Complex& val) const noexcept {
        return data - val.data;
    }
    const Complex operator*(const Complex& val) const noexcept {
        return data * val.data;
    }
    const Complex operator/(const Complex& val) const noexcept {
        return data / val.data;
    }


    const bool operator==(const Complex& val) const noexcept {
        return data == val.data;
    }
    const bool operator!=(const Complex& val) const noexcept {
        return data != val.data;
    }
};


}  // namespace calc

#pragma once
#include <cmath>
#include <string>
#include <complex>


namespace calc {


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
    Int() noexcept = default;
    Int(const Int&) noexcept = default;
    Int(Int&&) noexcept = default;
    ~Int() noexcept = default;

    Int& operator=(const Int&) noexcept = default;
    Int& operator=(Int&&) noexcept = default;


    Int(const long long val) noexcept : data(val) {}

    /*
    operator std::wstring() const {
        return std::to_wstring(data);
    }


    static const bool gen(const std::wstring& str, MathType& val);
    */

    const long long getInt() const noexcept {
        return data;
    }


    const Int operator+() const noexcept {
        return *this;
    }
    const Int operator-() const noexcept {
        return -data;
    }
    const Int operator~() const noexcept {
        return ~data;
    }


    const Int operator+(const Int& val) const noexcept {
        return data + val.data;
    }
    const Int operator-(const Int& val) const noexcept {
        return data - val.data;
    }
    const Int operator*(const Int& val) const noexcept {
        return data * val.data;
    }


    const Int intDiv(const Int& val) const;
    const Int operator%(const Int& val) const;

    const MathType operator/(const Int& val) const;


    const Int operator|(const Int& val) const noexcept;
    const Int operator&(const Int& val) const noexcept;
    const Int operator^(const Int& val) const noexcept;
    const Int operator<<(const Int& val) const noexcept;
    const Int operator>>(const Int& val) const noexcept;


    const bool operator==(const Int& val) const noexcept;
    const bool operator!=(const Int& val) const noexcept;
    const bool operator<(const Int& val) const noexcept;
    const bool operator<=(const Int& val) const noexcept;
    const bool operator>(const Int& val) const noexcept;
    const bool operator>=(const Int& val) const noexcept;
};


class Ratio {
   private:
    long long x = 0, y = 1;


    static const long long gcd(long long a, long long b) noexcept;


    void optimize();

   public:
    Ratio() noexcept = default;
    Ratio(const Ratio&) noexcept = default;
    Ratio(Ratio&&) noexcept = default;
    ~Ratio() noexcept = default;

    Ratio& operator=(const Ratio&) noexcept = default;
    Ratio& operator=(Ratio&&) noexcept = default;


    Ratio(long long x, long long y) : x(x), y(y) {
        optimize();
    }


    Ratio(const Int& val) noexcept;


    // operator std::wstring() const;


    const long long getX() const noexcept;
    const long long getY() const noexcept;


    const double getDouble() const noexcept;


    const MathType convert() const noexcept;


    const Ratio operator+() const noexcept;
    const Ratio operator-() const noexcept;


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
    Float() noexcept = default;
    Float(const Float&) noexcept = default;
    Float(Float&&) noexcept = default;

    Float& operator=(const Float&) noexcept = default;
    Float& operator=(Float&&) noexcept = default;


    Float(const double val) noexcept;


    Float(const Int& val) noexcept;
    Float(const Ratio& val) noexcept;


    static const bool gen(const std::wstring& str, MathType& val);


    const double getDouble() const noexcept;


    const Float operator+() const noexcept;
    const Float operator-() const noexcept;


    const Float operator+(const Float& val) const noexcept;
    const Float operator-(const Float& val) const noexcept;
    const Float operator*(const Float& val) const noexcept;
    const Float operator/(const Float& val) const noexcept;


    const bool operator==(const Float& val) const noexcept;
    const bool operator!=(const Float& val) const noexcept;
    const bool operator<(const Float& val) const noexcept;
    const bool operator<=(const Float& val) const noexcept;
    const bool operator>(const Float& val) const noexcept;
    const bool operator>=(const Float& val) const noexcept;
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

#include "BaseMathTypes.h"

#include "MathType.h"


namespace calc {

const MathType Ratio::convert() const noexcept {
    if (y == 1)
        return Int(x);
    if (abs(x) > (long long)(1e9) || y > (long long)(1e9))
        return Float(getDouble());
    return *this;
}

const Ratio Ratio::operator+(const Ratio& val) const {
    auto d = gcd(y, val.y);
    return Ratio(x * (val.y / d) + val.x * (y / d), (y / d) * val.y);
}

const Ratio Ratio::operator-(const Ratio& val) const {
    auto d = gcd(y, val.y);
    return Ratio(x * (val.y / d) - val.x * (y / d), (y / d) * val.y);
}

const Ratio Ratio::operator*(const Ratio& val) const {
    return Ratio(x * val.x, y * val.y);
}

const Ratio Ratio::operator/(const Ratio& val) const {
    return Ratio(x * val.y, y * val.x);
}

const bool Ratio::operator==(const Ratio& val) const {
    auto d = gcd(y, val.y);
    return x * (val.y / d) == val.x * (y / d);
}

const bool Ratio::operator!=(const Ratio& val) const {
    auto d = gcd(y, val.y);
    return x * (val.y / d) != val.x * (y / d);
}

const bool Ratio::operator<(const Ratio& val) const {
    auto d = gcd(y, val.y);
    return x * (val.y / d) < val.x * (y / d);
}

const bool Ratio::operator<=(const Ratio& val) const {
    auto d = gcd(y, val.y);
    return x * (val.y / d) <= val.x * (y / d);
}

const bool Ratio::operator>(const Ratio& val) const {
    auto d = gcd(y, val.y);
    return x * (val.y / d) > val.x * (y / d);
}

const bool Ratio::operator>=(const Ratio& val) const {
    auto d = gcd(y, val.y);
    return x * (val.y / d) >= val.x * (y / d);
}

const bool Bool::gen(const std::wstring& str, MathType& val) {
    if (str == L"True" || str == L"true") {
        val = Bool(true);
        return true;
    } else if (str == L"False" || str == L"false") {
        val = Bool(false);
        return true;
    }
    return false;
}

const bool Int::gen(const std::wstring& str, MathType& val) {
    std::wstringstream stream;
    stream << str;
    long long buf;
    stream >> buf;
    if (stream.bad() || stream.fail() || !stream.eof()) {
        val = Int(buf);
        return true;
    }
    return false;
}

const MathType Int::operator/(const Int& val) const {
    if (data % val.data == 0)
        return data / val.data;
    return Ratio(data, val.data);
}


const bool Float::gen(const std::wstring& str, MathType& val) {
    std::wstringstream stream;
    stream << str;
    double buf;
    stream >> buf;
    if (stream.bad() || stream.fail() || !stream.eof()) {
        val = Float(buf);
        return true;
    }
    return false;
}

const bool Complex::gen(const std::wstring& str, MathType& val) {
    if (str == L"i") {
        val = Complex(0, 1);
        return true;
    }
    return false;
}

}  // namespace calc

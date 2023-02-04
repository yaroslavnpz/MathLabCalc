#include "BaseMathTypes.h"

namespace calc {

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
}  // namespace calc

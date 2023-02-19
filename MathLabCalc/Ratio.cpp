#include "Ratio.h"
#include "Double.h"


namespace calc {

int64_t Ratio::gcd(int64_t a, int64_t b) noexcept {
    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void Ratio::optimize() {
    if (y == 0)
        throw DivizionByZero();
    if (y < 0)
        x = -x, y = -y;

    auto d = Ratio::gcd(::abs(x), y);
    x /= d;
    y /= d;
}

Ratio::Ratio(int64_t x, int64_t y) : x(x), y(y) {
    optimize();
}

const std::wstring Ratio::getType() const {
    return L"Ratio";
}

const std::wstring Ratio::getName() const {
    return std::to_wstring(double(x) / double(y));
}


Ratio Ratio::operator+(const Ratio& val) const noexcept {
    auto d = Ratio::gcd(y, val.y);
    return Ratio(x * (val.y / d) + val.x * (y / d), (y / d) * val.y);
}

Ratio Ratio::operator-(const Ratio& val) const noexcept {
    auto d = Ratio::gcd(y, val.y);
    return Ratio(x * (val.y / d) - val.x * (y / d), (y / d) * val.y);
}

Ratio Ratio::operator*(const Ratio& val) const noexcept {
    return Ratio(x * val.x, y * val.y);
}

Ratio Ratio::operator/(const Ratio& val) const {
    return Ratio(x * val.y, y * val.x);
}

bool Ratio::operator==(const Ratio& val) const noexcept {
    auto d = Ratio::gcd(y, val.y);
    return x * (val.y / d) == val.x * (y / d);
}

bool Ratio::operator!=(const Ratio& val) const noexcept {
    auto d = Ratio::gcd(y, val.y);
    return x * (val.y / d) != val.x * (y / d);
}

bool Ratio::operator<(const Ratio& val) const noexcept {
    auto d = Ratio::gcd(y, val.y);
    return x * (val.y / d) < val.x * (y / d);
}

bool Ratio::operator<=(const Ratio& val) const noexcept {
    auto d = Ratio::gcd(y, val.y);
    return x * (val.y / d) <= val.x * (y / d);
}

bool Ratio::operator>(const Ratio& val) const noexcept {
    auto d = Ratio::gcd(y, val.y);
    return x * (val.y / d) > val.x * (y / d);

}  // namespace calc

bool Ratio::operator>=(const Ratio& val) const noexcept {
    auto d = Ratio::gcd(y, val.y);
    return x * (val.y / d) >= val.x * (y / d);
}

Double sqrt(const Ratio& val) {
    return ::sqrt(val.getDouble());
}

Double log2(const Ratio& val) {
    return ::log2(val.getDouble());
}

Double log10(const Ratio& val) {
    return ::log10(val.getDouble());
}

Double ln(const Ratio& val) {
    return ::log(val.getDouble());
}

Double sin(const Ratio& val) noexcept {
    return ::sin(val.getDouble());
}

Double cos(const Ratio& val) noexcept {
    return ::cos(val.getDouble());
}

Double tg(const Ratio& val) noexcept {
    return ::tan(val.getDouble());
}

Double ctg(const Ratio& val) noexcept {
    return 1.0 / ::tan(val.getDouble());
}

Double asin(const Ratio& val) {
    return ::asin(val.getDouble());
}

Double acos(const Ratio& val) {
    return ::acos(val.getDouble());
}

Double atg(const Ratio& val) {
    return ::atan(val.getDouble());
}

Double pow(const Ratio& val, const Ratio& base) noexcept {
    return ::pow(val.getDouble(), base.getDouble());
}

Double log(const Ratio& val, const Ratio& base) noexcept {
    return ::log(val.getDouble()) / ::log(base.getDouble());
}

}  // namespace calc

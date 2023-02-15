#include "Ratio64.h"


namespace calc {

int64_t Ratio64::gcd(int64_t a, int64_t b) noexcept {
    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void Ratio64::optimize() {
    if (y == 0)
        throw DivizionByZero();
    if (x < 0)
        x = -x, y = -y;
    auto d = gcd(::abs(x), y);
    x /= d;
    y /= d;
}

Ratio64::Ratio64(int64_t x, int64_t y) : x(x), y(y) {
    optimize();
}

const std::wstring Ratio64::getType() const {
    return L"Ratio64";
}

const std::wstring Ratio64::getName() const {
    return std::to_wstring(x) + L"/" + std::to_wstring(y);
}

Ratio64 operator+(const Ratio64& a, const Ratio64& b) {
    auto d = Ratio64::gcd(a.y, b.y);
    return Ratio64(a.x * (b.y / d) + b.x * (a.y / d), (a.y / d) * b.y);
}

Ratio64 operator-(const Ratio64& a, const Ratio64& b) {
    auto d = Ratio64::gcd(a.y, b.y);
    return Ratio64(a.x * (b.y / d) - b.x * (a.y / d), (a.y / d) * b.y);
}

Ratio64 operator*(const Ratio64& a, const Ratio64& b) {
    return Ratio64(a.x * b.x, a.y * b.y);
}

Ratio64 operator/(const Ratio64& a, const Ratio64& b) {
    return Ratio64(a.x * b.y, a.y * b.x);
}

bool operator==(const Ratio64& a, const Ratio64& b) {
    auto d = Ratio64::gcd(a.y, b.y);
    return a.x * (b.y / d) == b.x * (a.y / d);
}

bool operator!=(const Ratio64& a, const Ratio64& b) {
    auto d = Ratio64::gcd(a.y, b.y);
    return a.x * (b.y / d) != b.x * (a.y / d);
}

bool operator<(const Ratio64& a, const Ratio64& b) {
    auto d = Ratio64::gcd(a.y, b.y);
    return a.x * (b.y / d) < b.x * (a.y / d);
}

bool operator<=(const Ratio64& a, const Ratio64& b) {
    auto d = Ratio64::gcd(a.y, b.y);
    return a.x * (b.y / d) <= b.x * (a.y / d);
}

bool operator>(const Ratio64& a, const Ratio64& b) {
    auto d = Ratio64::gcd(a.y, b.y);
    return a.x * (b.y / d) > b.x * (a.y / d);
}

bool operator>=(const Ratio64& a, const Ratio64& b) {
    auto d = Ratio64::gcd(a.y, b.y);
    return a.x * (b.y / d) >= b.x * (a.y / d);
}

Ratio64 abs(const Ratio64& val) {
    if(val.x < 0)
        return -val;
    return val;
}

Ratio64 min(const Ratio64& a, const Ratio64& b) {
    return a < b ? a : b;
}

Ratio64 max(const Ratio64& a, const Ratio64& b) {
    return a > b ? a : b;
}

}  // namespace calc

#include "Ratio.h"


namespace calc {

const Int Ratio::gcd(Int a, Int b) noexcept {
    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void Ratio::optimize() {
    if (y < 0)
        x = -x, y = -y;
    auto d = gcd(x, y);
    x /= d;
    y /= d;

    if (y == 0)
        throw ExceptionDivizionByZero();
}

Ratio::Ratio(const Int x, const int y) noexcept : x(x), y(y) {
    optimize();
}

const Ratio Ratio::operator+() const noexcept {
    return *this;
}

const Ratio Ratio::operator-() const noexcept {
    return Ratio(-x, y);
}

const Ratio Ratio::operator+(const Ratio& val) const noexcept {
    auto d = gcd(y, val.y);
    return Ratio(x * (val.y / d) + val.x * (y / d), (y / d) * val.y);
}

const Ratio Ratio::operator-(const Ratio& val) const noexcept {
    auto d = gcd(y, val.y);
    return Ratio(x * (val.y / d) - val.x * (y / d), (y / d) * val.y);
}

const Ratio Ratio::operator*(const Ratio& val) const noexcept {
    return Ratio(x * val.x, y * val.y);
}

const Ratio Ratio::operator/(const Ratio& val) const noexcept {
    return Ratio(x * val.y, y * val.x);
}

const bool Ratio::operator==(const Ratio& val) const noexcept {
    auto d = gcd(y, val.y);
    return x * (val.y / d) == val.x * (y / d);
}


#if IS_CPP20

const auto Ratio::operator<=>(const Ratio& val) const noexcept {
    auto d = gcd(y, val.y);
    return x * (val.y / d) <=> val.x * (y / d);
}

#else


#endif

}  // namespace calc

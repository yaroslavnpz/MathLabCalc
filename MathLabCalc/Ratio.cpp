#include "Ratio.h"


namespace calc {

const long long gcd(long long a, long long b) noexcept {
    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void Ratio::optimize() {
    if (y == 0)
        throw 1; //divizion by zero
    if (y < 0)
        x = -x, y = -y;
    auto d = gcd(abs(x), abs(y));
    x /= d;
    y /= d;
}

Ratio::Ratio(long long x, long long y) : x(x), y(y) {
    optimize();
}

Ratio::Ratio(const Int& val) noexcept :x(val.getInt()), y(1) {}

}  // namespace calc

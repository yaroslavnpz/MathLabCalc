#include "Seg.h"
#include "MathType.h"


#include <algorithm>


namespace calc {

template <typename Fn>
Seg conv(const Seg& val, Fn fn) {
    Seg res;
    for (size_t i = 0; i < 2; ++i)
        res[i] = fn(val[i]);
    if (res[0] > res[1])
        std::swap(res[0], res[1]);
    return res;
}

template <typename Fn>
Seg conv2(const Seg& a, const Seg& b, Fn fn) {
    Seg res;

    for (size_t j = 0; j < 2; ++j)
        res[j] = fn(a[0], b[j]);
    if (res[0] > res[1])
        std::swap(res[0], res[1]);
    for (size_t j = 0; j < 2; ++j) {
        auto buf = fn(a[1], b[j]);
        res[0] = std::min(res[0], buf);
        res[1] = std::max(res[1], buf);
    }
    return res;
}

MathType& Seg::operator[](size_t iter) {
    return _data[iter];
}

const MathType Seg::operator[](size_t iter) const {
    return _data[iter];
}

Seg::Seg() : _data(new MathType[2]) {}

Seg::Seg(const Seg& val) : _data(new MathType[2]) {
    std::copy(val._data, val._data + 2, _data);
}

Seg::Seg(Seg&& val) noexcept {
    if (_data != val._data) {
        _data = val._data;
    }
    val._data = nullptr;
}

Seg::~Seg() noexcept {
    delete[] _data;
}

Seg& Seg::operator=(const Seg& val) {
    std::copy(val._data, val._data + 2, _data);
    return *this;
}

Seg& Seg::operator=(Seg&& val) noexcept {
    if (_data != val._data) {
        std::swap(_data, val._data);
        delete[] val._data;
    }
    val._data = nullptr;
    return *this;
}

Seg::Seg(const MathType& val) : _data(new MathType[2]) {
    _data[0] = _data[1] = val;
}

Seg::Seg(const MathType& a, const MathType& b) : _data(new MathType[2]) {
    _data[0] = a;
    _data[1] = b;
}

Seg::Seg(Bool val) :_data(new MathType[2]) {
    _data[0] = _data[1] = val;
}

Seg::Seg(Int val) : _data(new MathType[2]) {
    _data[0] = _data[1] = val;
}

Seg::Seg(const Ratio& val) : _data(new MathType[2]) {
    _data[0] = _data[1] = val;
}

Seg::Seg(Double val) : _data(new MathType[2]) {
    _data[0] = _data[1] = val;
}

const std::wstring Seg::getType() const {
    return L"Seg";
}

const std::wstring Seg::getName() const {
    return L"(" + _data[0].getName() + L", " + _data[1].getName() + L")";
}

Seg Seg::operator+() const {
    return conv(*this, [](const auto& a) { return +a; });
}

Seg Seg::operator-() const {
    return conv(*this, [](const auto& a) { return -a; });
}

Seg Seg::operator!() const {
    return conv(*this, [](const auto& a) { return !a; });
}

Seg Seg::operator~() const {
    return conv(*this, [](const auto& a) { return ~a; });
}

Seg Seg::operator+(const Seg& val) const {
    return conv2(*this, val, [](const auto& a, const auto& b) { return a + b; });
}

Seg Seg::operator-(const Seg& val) const {
    return conv2(*this, val, [](const auto& a, const auto& b) { return a - b; });
}

Seg Seg::operator*(const Seg& val) const {
    return conv2(*this, val, [](const auto& a, const auto& b) { return a * b; });
}

Seg Seg::operator/(const Seg& val) const {
    return conv2(*this, val, [](const auto& a, const auto& b) { return a / b; });
}

Seg Seg::operator%(const Seg& val) const {
    return conv2(*this, val, [](const auto& a, const auto& b) { return a % b; });
}

Seg Seg::intDiv(const Seg& val) const {
    return conv2(*this, val, [](const auto& a, const auto& b) { return a.intDiv(b); });
}

Seg Seg::operator&(const Seg& val) const {
    return conv2(*this, val, [](const auto& a, const auto& b) { return a & b; });
}

Seg Seg::operator|(const Seg& val) const {
    return conv2(*this, val, [](const auto& a, const auto& b) { return a | b; });
}

Seg Seg::operator^(const Seg& val) const {
    return conv2(*this, val, [](const auto& a, const auto& b) { return a ^ b; });
}

Seg Seg::operator<<(const Seg& val) const {
    return conv2(*this, val, [](const auto& a, const auto& b) { return a << b; });
}

Seg Seg::operator>>(const Seg& val) const {
    return conv2(*this, val, [](const auto& a, const auto& b) { return a >> b; });
}

Seg Seg::operator&&(const Seg& val) const {
    return conv2(*this, val, [](const auto& a, const auto& b) { return a && b; });
}

Seg Seg::operator||(const Seg& val) const {
    return conv2(*this, val, [](const auto& a, const auto& b) { return a || b; });
}

bool Seg::operator==(const Seg& val) const {
    return _data[0] < val[1] && val[0] < _data[1];
}

bool Seg::operator!=(const Seg& val) const {
    return !(*this == val);
}

bool Seg::operator<(const Seg& val) const {
    return _data[1] < val[0];
}

bool Seg::operator<=(const Seg& val) const {
    return _data[0] < val[1];
}

bool Seg::operator>(const Seg& val) const {
    return val[1] < _data[0];
}

bool Seg::operator>=(const Seg& val) const {
    return val[0] < _data[1];
}

Seg abs(const Seg& val) {
    return conv(val, [](const auto& a) { return abs(a); });
}

Seg sqrt(const Seg& val) {
    return conv(val, [](const auto& a) { return sqrt(a); });
}

Seg log2(const Seg& val) {
    return conv(val, [](const auto& a) { return log2(a); });
}

Seg log10(const Seg& val) {
    return conv(val, [](const auto& a) { return log10(a); });
}

Seg ln(const Seg& val) {
    return conv(val, [](const auto& a) { return ln(a); });
}

Seg sin(const Seg& val) {
    return conv(val, [](const auto& a) { return sin(a); });
}

Seg cos(const Seg& val) {
    return conv(val, [](const auto& a) { return cos(a); });
}

Seg tg(const Seg& val) {
    return conv(val, [](const auto& a) { return tg(a); });
}

Seg ctg(const Seg& val) {
    return conv(val, [](const auto& a) { return ctg(a); });
}

Seg asin(const Seg& val) {
    return conv(val, [](const auto& a) { return asin(a); });
}

Seg acos(const Seg& val) {
    return conv(val, [](const auto& a) { return acos(a); });
}

Seg atg(const Seg& val) {
    return conv(val, [](const auto& a) { return atg(a); });
}

Seg pow(const Seg& val, const MathType& base) {
    return conv(val, [&](const auto& a) { return pow(a, base); });
}

Seg pow(const Seg& val, const Seg& base) {
    return conv2(val, base, [](const auto& a, const auto& b) { return pow(a, b); });
}

Seg log(const Seg& val, const MathType& base) {
    return conv(val, [&](const auto& a) { return log(a, base); });
}

Seg log(const Seg& val, const Seg& base) {
    return conv2(val, base, [](const auto& a, const auto& b) { return log(a, b); });
}

}  // namespace calc

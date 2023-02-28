#include "Int.h"
#include "MathType.h"
#include "Double.h"


namespace calc {

const std::wstring Int::getType() const {
    return L"Int";
}

const std::wstring Int::getName() const {
    return std::to_wstring(data);
}

const Ratio Int::operator/(const Int val) const {
    return Ratio(data, val.data);
}

const Double sqrt(const Int val) {
    if (val.getData() < 0)
        throw BadOperator();
    return ::sqrt(val.getData());
}

const Double log2(const Int val) {
    return ::log2(val.getData());
}

const Double log10(const Int val) {
    return ::log10(val.getData());
}

const Double ln(const Int val) {
    return ::log(val.getData());
}

const Double sin(const Int val) {
    return ::sin(val.getData());
}

const Double cos(const Int val) {
    return ::cos(val.getData());
}

const Double tg(const Int val) {
    return ::tan(val.getData());
}

const Double ctg(const Int val) {
    return 1.0 / ::tan(val.getData());
}

const Double asin(const Int val) {
    return ::asin(val.getData());
}

const Double acos(const Int val) {
    return ::acos(val.getData());
}

const Double atg(const Int val) {
    return ::atan(val.getData());
}

const Double pow(const Int a, const Int base) noexcept {
    return ::pow(a.getData(), base.getData());
}

const Double log(const Int a, const Int base) {
    return ::log(a.getData()) / ::log(base.getData());
}

}  // namespace calc

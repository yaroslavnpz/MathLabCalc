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

Ratio Int::operator/(Int val) const {
    return Ratio(data, val.data);
}

Double sqrt(Int val) {
    if (val.getData() < 0)
        throw BadOperator();
    return ::sqrt(val.getData());
}

Double log2(Int val) {
    return ::log2(val.getData());
}

Double log10(Int val) {
    return ::log10(val.getData());
}

Double ln(Int val) {
    return ::log(val.getData());
}

Double sin(Int val) {
    return ::sin(val.getData());
}

Double cos(Int val) {
    return ::cos(val.getData());
}

Double tg(Int val) {
    return ::tan(val.getData());
}

Double ctg(Int val) {
    return 1.0 / ::tan(val.getData());
}

Double asin(Int val) {
    return ::asin(val.getData());
}

Double acos(Int val) {
    return ::acos(val.getData());
}

Double atg(Int val) {
    return ::atan(val.getData());
}

Double pow(Int a, Int base) noexcept {
    return ::pow(a.getData(), base.getData());
}

Double log(Int a, Int base) {
    return ::log(a.getData()) / ::log(base.getData());
}

}  // namespace calc

#include "Double.h"


namespace calc {

const std::wstring Double::getType() const {
    return L"Double";
}

const std::wstring Double::getName() const {
    return std::to_wstring(data);
}


Double sqrt(Double val) {
    return ::sqrt(val.getData());
}

Double log2(Double val) {
    return ::log2(val.getData());
}

Double log10(Double val) {
    return ::log10(val.getData());
}

Double ln(Double val) {
    return ::log(val.getData());
}

Double sin(Double val) noexcept {
    return ::sin(val.getData());
}

Double cos(Double val) noexcept {
    return ::cos(val.getData());
}

Double tg(Double val) noexcept {
    return ::tan(val.getData());
}

Double ctg(Double val) noexcept {
    return 1.0 / ::tan(val.getData());
}

Double asin(Double val) {
    return ::asin(val.getData());
}

Double acos(Double val) {
    return ::acos(val.getData());
}

Double atg(Double val) {
    return ::atan(val.getData());
}

Double pow(Double val, Double base) noexcept {
    return ::pow(val.getData(), base.getData());
}

Double log(Double val, Double base) {
    return ln(val) / ln(base);
}

}  // namespace calc

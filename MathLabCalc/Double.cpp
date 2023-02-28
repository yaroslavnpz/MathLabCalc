#include "Double.h"


namespace calc {

const std::wstring Double::getType() const {
    return L"Double";
}

const std::wstring Double::getName() const {
    return std::to_wstring(data);
}


const Double sqrt(const Double val) {
    return ::sqrt(val.getData());
}

const Double log2(const Double val) {
    return ::log2(val.getData());
}

const Double log10(const Double val) {
    return ::log10(val.getData());
}

const Double ln(const Double val) {
    return ::log(val.getData());
}

const Double sin(const Double val) noexcept {
    return ::sin(val.getData());
}

const Double cos(const Double val) noexcept {
    return ::cos(val.getData());
}

const Double tg(const Double val) noexcept {
    return ::tan(val.getData());
}

const Double ctg(const Double val) noexcept {
    return 1.0 / ::tan(val.getData());
}

const Double asin(const Double val) {
    return ::asin(val.getData());
}

const Double acos(const Double val) {
    return ::acos(val.getData());
}

const Double atg(const Double val) {
    return ::atan(val.getData());
}

const Double pow(const Double val, const Double base) noexcept {
    return ::pow(val.getData(), base.getData());
}

const Double log(const Double val, const Double base) {
    return ln(val) / ln(base);
}

}  // namespace calc

#include "MathType.h"
#include "for_operators.h"


namespace calc {

MathType::MathType(const std::monostate& val) : data(val) {}

MathType::MathType(const Bool& val) : data(val) {}

MathType::MathType(const Int& val) : data(val) {}

MathType::MathType(const Float& val) : data(val) {}

MathType::MathType(const Complex& val) : data(val) {}

const MathType MathType::operator+() const {
    auto fn = [&](const auto& a) {
        if constexpr (has_positive_v<decltype(a)>)
            return MathType(+a);
        else
            return MathType(std::monostate());
    };
    return std::visit(fn, data);
}

const MathType MathType::operator-() const {
    auto fn = [&](const auto& a) {
        if constexpr (has_negative_v<decltype(a)>)
            return MathType(-a);
        else
            return MathType(std::monostate());
    };
    return std::visit(fn, data);
}


}  // namespace calc

#include "MathType.h"
#include "for_operators.h"


namespace calc {

MathType::MathType(const std::monostate& val) : data(val) {}

MathType::MathType(const bool val) :data(Bool(val)) {}

MathType::MathType(const Bool& val) : data(val) {}

MathType::MathType(const Int& val) : data(val) {}

MathType::MathType(const Ratio& val) {
    (*this) = val.convert();
}

MathType::MathType(const Float& val) : data(val) {}

MathType::MathType(const Complex& val) : data(val) {}

const MathType MathType::operator+() const {
    auto fn = [&](const auto& a) {
        if constexpr (has_positive_v<decltype(a)>)
            return MathType(+a);
        else
            return MathType(Error());
    };
    return std::visit(fn, data);
}

const MathType MathType::operator-() const {
    auto fn = [&](const auto& a) {
        if constexpr (has_negative_v<decltype(a)>)
            return MathType(-a);
        else
            return MathType(Error());
    };
    return std::visit(fn, data);
}

const MathType MathType::operator!() const {
    auto fn = [&](const auto& a) {
        if constexpr (has_log_not_v<decltype(a)>)
            return MathType(!a);
        else
            return MathType(Error());
    };
    return std::visit(fn, data);
}

const MathType MathType::operator~() const {
    auto fn = [&](const auto& a) {
        if constexpr (has_bin_not_v<decltype(a)>)
            return MathType(~a);
        else
            return MathType(Error());
    };
    return std::visit(fn, data);
}

const MathType MathType::operator+(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_plus_v<decltype(a), decltype(b)>)
            return a + b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_plus_v<decltype(a), decltype(a)>)
            return a + static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_plus_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) + b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator-(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_minus_v<decltype(a), decltype(b)>)
            return a - b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_minus_v<decltype(a), decltype(a)>)
            return a - static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_minus_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) - b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator*(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_mul_v<decltype(a), decltype(b)>)
            return a * b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_mul_v<decltype(a), decltype(a)>)
            return a * static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_mul_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) * b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator/(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_div_v<decltype(a), decltype(b)>)
            return a / b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_div_v<decltype(a), decltype(a)>)
            return a / static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_div_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) / b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator%(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_mod_v<decltype(a), decltype(b)>)
            return a % b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_mod_v<decltype(a), decltype(a)>)
            return a % static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_mod_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) % b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::intDiv(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_int_div_v<decltype(a), decltype(b)>)
            return a.intDiv(b);
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_int_div_v<decltype(a), decltype(a)>)
            return a.intDiv(static_cast<decltype(a)>(b));
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_int_div_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a).intDiv(b);
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator&(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_bin_and_v<decltype(a), decltype(b)>)
            return a & b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_bin_and_v<decltype(a), decltype(a)>)
            return a & static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_bin_and_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) & b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator|(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_bin_or_v<decltype(a), decltype(b)>)
            return a | b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_bin_or_v<decltype(a), decltype(a)>)
            return a | static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_bin_or_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) | b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator^(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_bin_xor_v<decltype(a), decltype(b)>)
            return a ^ b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_bin_xor_v<decltype(a), decltype(a)>)
            return a ^ static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_bin_xor_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) ^ b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator<<(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_bin_left_v<decltype(a), decltype(b)>)
            return a << b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_bin_left_v<decltype(a), decltype(a)>)
            return a << static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_bin_left_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) << b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator>>(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_bin_right_v<decltype(a), decltype(b)>)
            return a >> b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_bin_right_v<decltype(a), decltype(a)>)
            return a >> static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_bin_right_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) >> b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator&&(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_log_and_v<decltype(a), decltype(b)>)
            return a && b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_log_and_v<decltype(a), decltype(a)>)
            return a && static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_log_and_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) && b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator||(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_log_or_v<decltype(a), decltype(b)>)
            return a || b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_log_or_v<decltype(a), decltype(a)>)
            return a || static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_log_or_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) || b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator==(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_equal_v<decltype(a), decltype(b)>)
            return a == b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_equal_v<decltype(a), decltype(a)>)
            return a == static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_equal_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) == b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator!=(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_equal_v<decltype(a), decltype(b)>)
            return a == b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_equal_v<decltype(a), decltype(a)>)
            return a == static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_equal_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) == b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator<(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_comp_v<decltype(a), decltype(b)>)
            return a < b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_comp_v<decltype(a), decltype(a)>)
            return a < static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_comp_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) < b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator<=(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_comp_v<decltype(a), decltype(b)>)
            return a <= b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_comp_v<decltype(a), decltype(a)>)
            return a <= static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_comp_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) <= b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator>(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_comp_v<decltype(a), decltype(b)>)
            return a > b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_comp_v<decltype(a), decltype(a)>)
            return a > static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_comp_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) > b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}

const MathType MathType::operator>=(const MathType& val) const {
    auto fn = [&](const auto& a, const auto& b) -> const MathType {
        if constexpr (has_comp_v<decltype(a), decltype(b)>)
            return a >= b;
        else if constexpr (is_convertible_to_v<decltype(b), decltype(a)> && has_comp_v<decltype(a), decltype(a)>)
            return a >= static_cast<decltype(a)>(b);
        else if constexpr (is_convertible_to_v<decltype(a), decltype(b)> && has_comp_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) >= b;
        else
            return Error();
    };
    return std::visit(fn, data, val.data);
}
}  // namespace calc

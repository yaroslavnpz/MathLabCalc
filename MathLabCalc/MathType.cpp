#include "MathType.h"
#include "exceptions.h"


#include "MathType_templates.inl"


namespace calc {

const std::wstring MathType::getType() const {
    return std::visit([](const auto& a) { return a.getType(); }, data);
}

const std::wstring MathType::getName() const {
    return std::visit([](const auto& a) { return a.getName(); }, data);
}

MathType MathType::operator+() const {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_plus_v<decltype(a)>)
            return +a;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data);
}

MathType MathType::operator-() const {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_minus_v<decltype(a)>)
            return -a;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data);
}

MathType MathType::operator!() const {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_log_not_v<decltype(a)>)
            return !a;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data);
}

MathType MathType::operator~() const {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_bin_not_v<decltype(a)>)
            return ~a;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data);
}

MathType MathType::operator+(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_add_v<decltype(a), decltype(b)>)
            return a + b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_add_v<decltype(a), decltype(a)>)
            return a + static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_add_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) + b;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data, val.data);
}

MathType MathType::operator-(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_sub_v<decltype(a), decltype(b)>)
            return a - b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_sub_v<decltype(a), decltype(a)>)
            return a - static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_sub_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) - b;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data, val.data);
}

MathType MathType::operator*(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_mul_v<decltype(a), decltype(b)>)
            return a * b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_mul_v<decltype(a), decltype(a)>)
            return a * static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_mul_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) * b;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data, val.data);
}

MathType MathType::operator/(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_div_v<decltype(a), decltype(b)>)
            return a / b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_div_v<decltype(a), decltype(a)>)
            return a / static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_div_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) / b;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data, val.data);
}

MathType MathType::operator%(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_mod_v<decltype(a), decltype(b)>)
            return a % b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_mod_v<decltype(a), decltype(a)>)
            return a % static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_mod_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) % b;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data, val.data);
}

MathType MathType::intDiv(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_int_div_v<decltype(a), decltype(b)>)
            return a.intDiv(b);
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_int_div_v<decltype(a), decltype(a)>)
            return a.intDiv(static_cast<decltype(a)>(b));
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_int_div_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a).intDiv(b);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data, val.data);
}

MathType MathType::operator&(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_bin_and_v<decltype(a), decltype(b)>)
            return a & b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_bin_and_v<decltype(a), decltype(a)>)
            return a & static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_bin_and_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) & b;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data, val.data);
}

MathType MathType::operator|(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_bin_or_v<decltype(a), decltype(b)>)
            return a | b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_bin_or_v<decltype(a), decltype(a)>)
            return a | static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_bin_or_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) | b;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data, val.data);
}

MathType MathType::operator^(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_bin_xor_v<decltype(a), decltype(b)>)
            return a ^ b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_bin_xor_v<decltype(a), decltype(a)>)
            return a ^ static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_bin_xor_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) ^ b;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data, val.data);
}

MathType MathType::operator<<(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_bin_left_v<decltype(a), decltype(b)>)
            return a << b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_bin_left_v<decltype(a), decltype(a)>)
            return a << static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_bin_left_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) << b;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data, val.data);
}

MathType MathType::operator>>(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_bin_right_v<decltype(a), decltype(b)>)
            return a >> b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_bin_right_v<decltype(a), decltype(a)>)
            return a >> static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_bin_right_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) >> b;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data, val.data);
}

MathType MathType::operator||(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_log_or_v<decltype(a), decltype(b)>)
            return a || b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_log_or_v<decltype(a), decltype(a)>)
            return a || static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_log_or_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) || b;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data, val.data);
}

MathType MathType::operator&&(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_log_and_v<decltype(a), decltype(b)>)
            return a && b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_log_and_v<decltype(a), decltype(a)>)
            return a && static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_log_and_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) && b;
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data, val.data);
}

bool MathType::operator==(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> bool {
        if constexpr (can_equal_v<decltype(a), decltype(b)>)
            return a == b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_equal_v<decltype(a), decltype(a)>)
            return a == static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_equal_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) == b;
        else
            throw BadOperator();
        return false;
    };
    return std::visit(fn, data, val.data);
}

bool MathType::operator!=(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> bool {
        if constexpr (can_equal_v<decltype(a), decltype(b)>)
            return a != b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_equal_v<decltype(a), decltype(a)>)
            return a != static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_equal_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) != b;
        else
            throw BadOperator();
        return false;
    };
    return std::visit(fn, data, val.data);
}

bool MathType::operator<(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> bool {
        if constexpr (can_comp_v<decltype(a), decltype(b)>)
            return a < b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_comp_v<decltype(a), decltype(a)>)
            return a < static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_comp_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) < b;
        else
            throw BadOperator();
        return false;
    };
    return std::visit(fn, data, val.data);
}

bool MathType::operator<=(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> bool {
        if constexpr (can_comp_v<decltype(a), decltype(b)>)
            return a <= b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_comp_v<decltype(a), decltype(a)>)
            return a <= static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_comp_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) <= b;
        else
            throw BadOperator();
        return false;
    };
    return std::visit(fn, data, val.data);
}

bool MathType::operator>(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> bool {
        if constexpr (can_comp_v<decltype(a), decltype(b)>)
            return a > b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_comp_v<decltype(a), decltype(a)>)
            return a > static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_comp_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) > b;
        else
            throw BadOperator();
        return false;
    };
    return std::visit(fn, data, val.data);
}

bool MathType::operator>=(const MathType& val) const {
    auto fn = [](const auto& a, const auto& b) -> bool {
        if constexpr (can_comp_v<decltype(a), decltype(b)>)
            return a >= b;
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_comp_v<decltype(a), decltype(a)>)
            return a >= static_cast<decltype(a)>(b);
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_comp_v<decltype(b), decltype(b)>)
            return static_cast<decltype(b)>(a) >= b;
        else
            throw BadOperator();
        return false;
    };
    return std::visit(fn, data, val.data);
}

MathType MathType::operator[](const MathType& iter) const {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_itert_v<decltype(a), decltype(b)>)
            return a[b];
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data, iter.data);
}

MathType MathType::size() const {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_size_v<decltype(a)>)
            return a.size();
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, data);
}

MathType abs(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_abs_v<decltype(a)>)
            return abs(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType sqrt(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_sqrt_v<decltype(a)>)
            return sqrt(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType log2(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_log2_v<decltype(a)>)
            return log2(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType log10(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_log10_v<decltype(a)>)
            return log10(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType ln(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_ln_v<decltype(a)>)
            return ln(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType sin(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_sin_v<decltype(a)>)
            return sin(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType cos(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_cos_v<decltype(a)>)
            return cos(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType tg(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_tg_v<decltype(a)>)
            return tg(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType ctg(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_ctg_v<decltype(a)>)
            return ctg(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType asin(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_asin_v<decltype(a)>)
            return asin(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType acos(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_acos_v<decltype(a)>)
            return acos(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType atg(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_atg_v<decltype(a)>)
            return atg(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType pow(const MathType& val, const MathType& base) {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_pow_v<decltype(a), decltype(b)>)
            return pow(a, b);
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_pow_v<decltype(a), decltype(a)>)
            return pow(a, static_cast<decltype(a)>(b));
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_pow_v<decltype(b), decltype(b)>)
            return pow(static_cast<decltype(b)>(a), b);
        else
            throw BadOperator();
        return false;
    };
    return std::visit(fn, val.data, base.data);
}

MathType log(const MathType& val, const MathType& base) {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_log_v<decltype(a), decltype(b)>)
            return log(a, b);
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_log_v<decltype(a), decltype(a)>)
            return log(a, static_cast<decltype(a)>(b));
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_log_v<decltype(b), decltype(b)>)
            return log(static_cast<decltype(b)>(a), b);
        else
            throw BadOperator();
        return false;
    };
    return std::visit(fn, val.data, base.data);
}

MathType sort(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_sort_v<decltype(a)>)
            return sort(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType unique(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_unique_v<decltype(a)>)
            return unique(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType reverse(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_reverse_v<decltype(a)>)
            return reverse(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType join(const MathType& val, const MathType& add) {
    auto fn = [](const auto& a, const auto& b) -> MathType {
        if constexpr (can_join_v<decltype(a), decltype(b)>)
            return join(a, b);
        else if constexpr (std::is_convertible_v<decltype(b), decltype(a)> && can_join_v<decltype(a), decltype(a)>)
            return join(a, static_cast<decltype(a)>(b));
        else if constexpr (std::is_convertible_v<decltype(a), decltype(b)> && can_join_v<decltype(b), decltype(b)>)
            return join(static_cast<decltype(b)>(a), b);
        else
            throw BadOperator();
        return false;
    };
    return std::visit(fn, val.data, add.data);
}

MathType min(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_min1_v<decltype(a)>)
            return min(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

MathType max(const MathType& val) {
    auto fn = [](const auto& a) -> MathType {
        if constexpr (can_max1_v<decltype(a)>)
            return max(a);
        else
            throw BadOperator();
        return MathType();
    };
    return std::visit(fn, val.data);
}

}  // namespace calc

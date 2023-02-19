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


// Нужно написать еще реализации...

}  // namespace calc

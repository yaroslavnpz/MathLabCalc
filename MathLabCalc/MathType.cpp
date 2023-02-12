#include "MathType.h"
#include "exceptions.h"


namespace calc {

template <typename Ty1, typename Ty2, typename Buf = void>
constexpr bool can_plus = false;
template <typename Ty1, typename Ty2>
constexpr bool can_plus<Ty1, Ty2, std::enable_if_t<!std::is_same_v<decltype(std::declval<Ty1>() + std::declval<Ty2>()), void>, void>> =
    true;

MathType::MathType(Int64 val) noexcept : data(val) {}

MathType::MathType(Double val) noexcept : data(val) {}

const std::wstring MathType::getType() const {
    return std::visit([](const auto& val) { return val.getType(); }, data);
}

const std::wstring MathType::getName() const {
    return std::visit([](const auto& val) { return val.getName(); }, data);
}

MathType MathType::operator+(const MathType& val) {
    return std::visit([](const auto& a, const auto& b) { return a + b; }, data, val.data);
}


}  // namespace calc

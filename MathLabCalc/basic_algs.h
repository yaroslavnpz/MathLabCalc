#pragma once
#include "exceptions.h"


namespace calc {


namespace comp {


template <typename A, typename v = void>
constexpr bool can_less_v = false;
template <typename A>
constexpr bool can_less_v<A, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() < std::declval<A>()), void>, void>> = true;

template <typename A, typename v = void>
constexpr bool can_more_v = false;
template <typename A>
constexpr bool can_more_v<A, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() > std::declval<A>()), void>, void>> = true;


}  // namespace comp


template <typename Ty>
constexpr std::enable_if_t<comp::can_less_v<Ty>, Ty> min(const Ty& a, const Ty& b) {
    return a < b ? a : b;
}

template <typename Ty>
constexpr std::enable_if_t<comp::can_more_v<Ty>, Ty> max(const Ty& a, const Ty& b) {
    return a > b ? a : b;
}


}  // namespace calc

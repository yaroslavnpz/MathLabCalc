#pragma once
#include "MathType.h"


namespace calc {


template <typename Ty1, typename Ty2>
static constexpr bool is_same = false;
template <typename Ty>
static constexpr bool is_same<Ty, Ty> = true;


template <typename Val, typename... List>
static constexpr bool in_list_v = false;
template <typename Val, typename... List>
static constexpr bool in_list_v<Val, Val, List...> = true;
template <typename Val, typename Ty, typename... List>
static constexpr bool in_list_v<Val, Ty, List...> = in_list_v<Val, List...>;


template <typename Ty>
static constexpr bool is_math_types_v = in_list_v<Ty, MATHTYPESLIST>;


template <typename... List>
static constexpr bool is_any_v = true;


template <typename Ty, typename T = void>
struct HasPositive : public std::false_type {};
template <typename Ty>
struct HasPositive<Ty, std::enable_if_t<!is_same<decltype(+std::declval<Ty>()), void>, void>> : public std::true_type {};
template<typename Ty>
constexpr bool has_positive_v = HasPositive<Ty>::value;


template <typename Ty, typename T = void>
struct HasNegative : public std::false_type {};
template <typename Ty>
struct HasNegative<Ty, std::enable_if_t<!is_same<decltype(-std::declval<Ty>()), void>, void>> : public std::true_type {};
template <typename Ty>
constexpr bool has_negative_v = HasNegative<Ty>::value;


template <typename Ty, typename T = void>
struct HasPlus : public std::false_type {};
template <typename Ty>
struct HasPlus<Ty, std::enable_if_t<!is_same<decltype(std::declval<Ty>() + std::declval<Ty>()), void>, void>> : public std::true_type {};
template <typename Ty>
constexpr bool has_plus_v = HasPlus<Ty>::value;


template <typename Ty, typename T = void>
struct HasMinus : public std::false_type {};
template <typename Ty>
struct HasMinus<Ty, std::enable_if_t<!is_same<decltype(std::declval<Ty>() - std::declval<Ty>()), void>, void>> : public std::true_type {};
template <typename Ty>
constexpr bool has_minus_v = HasMinus<Ty>::value;

}  // namespace calc

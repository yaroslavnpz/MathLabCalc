#pragma once
#include "MathType.h"


namespace calc {


template <typename Ty1, typename Ty2>
constexpr bool is_same_v = false;
template <typename Ty>
constexpr bool is_same_v<Ty, Ty> = true;


template <typename Val, typename... List>
constexpr bool in_list_v = false;
template <typename Val, typename... List>
constexpr bool in_list_v<Val, Val, List...> = true;
template <typename Val, typename Ty, typename... List>
constexpr bool in_list_v<Val, Ty, List...> = in_list_v<Val, List...>;


template <typename Ty>
constexpr bool is_math_types_v = in_list_v<Ty, MATHTYPESLIST>;


template<bool val, typename Ty>
using if_t = std::enable_if_t<val, Ty>;


template<typename From, typename To>
constexpr bool is_convertible_to_v = std::is_convertible_v<From, To>;


// for operators


template<typename Ty, typename T = void>
constexpr bool has_positive_v = false;
template<typename Ty>
constexpr bool has_positive_v<Ty, if_t<!is_same_v<decltype(+std::declval<Ty>()), void>, void>> = true;


template <typename Ty, typename T = void>
constexpr bool has_negative_v = false;
template <typename Ty>
constexpr bool has_negative_v<Ty, if_t<!is_same_v<decltype(-std::declval<Ty>()), void>, void>> = true;


template <typename Ty, typename T = void>
constexpr bool has_log_not_v = false;
template <typename Ty>
constexpr bool has_log_not_v<Ty, if_t<!is_same_v<decltype(!std::declval<Ty>()), void>, void>> = true;


template <typename Ty, typename T = void>
constexpr bool has_bin_not_v = false;
template <typename Ty>
constexpr bool has_bin_not_v<Ty, if_t<!is_same_v<decltype(~std::declval<Ty>()), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_plus_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_plus_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>() + std::declval<Ty2>()), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_minus_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_minus_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>() - std::declval<Ty2>()), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_mul_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_mul_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>() * std::declval<Ty2>()), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_div_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_div_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>() / std::declval<Ty2>()), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_mod_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_mod_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>() % std::declval<Ty2>()), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_int_div_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_int_div_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>().intDiv(std::declval<Ty2>())), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_bin_and_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_bin_and_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>() & std::declval<Ty2>()), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_bin_or_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_bin_or_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>() | std::declval<Ty2>()), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_bin_xor_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_bin_xor_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>() ^ std::declval<Ty2>()), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_bin_left_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_bin_left_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>() << std::declval<Ty2>()), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_bin_right_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_bin_right_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>() >> std::declval<Ty2>()), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_log_and_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_log_and_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>() && std::declval<Ty2>()), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_log_or_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_log_or_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>() || std::declval<Ty2>()), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_equal_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_equal_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>() == std::declval<Ty2>()), void>, void>> = true;


template <typename Ty1, typename Ty2, typename T = void>
constexpr bool has_comp_v = false;
template <typename Ty1, typename Ty2>
constexpr bool has_comp_v<Ty1, Ty2, if_t<!is_same_v<decltype(std::declval<Ty1>() < std::declval<Ty2>()), void>, void>> = true;


}  // namespace calc

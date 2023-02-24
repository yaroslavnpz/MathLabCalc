#pragma once
#include "MathType.h"


namespace calc {

template <typename Ty, typename v = void>
constexpr bool can_plus_v = false;
template <typename Ty>
constexpr bool can_plus_v<Ty, std::enable_if_t<!std::is_same_v<decltype(+std::declval<Ty>()), void>, void>> = true;


template <typename Ty, typename v = void>
constexpr bool can_minus_v = false;
template <typename Ty>
constexpr bool can_minus_v<Ty, std::enable_if_t<!std::is_same_v<decltype(-std::declval<Ty>()), void>, void>> = true;


template <typename Ty, typename v = void>
constexpr bool can_log_not_v = false;
template <typename Ty>
constexpr bool can_log_not_v<Ty, std::enable_if_t<!std::is_same_v<decltype(!std::declval<Ty>()), void>, void>> = true;


template <typename Ty, typename v = void>
constexpr bool can_bin_not_v = false;
template <typename Ty>
constexpr bool can_bin_not_v<Ty, std::enable_if_t<!std::is_same_v<decltype(~std::declval<Ty>()), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_add_v = false;
template <typename A, typename B>
constexpr bool can_add_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() + std::declval<B>()), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_sub_v = false;
template <typename A, typename B>
constexpr bool can_sub_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() - std::declval<B>()), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_mul_v = false;
template <typename A, typename B>
constexpr bool can_mul_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() * std::declval<B>()), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_div_v = false;
template <typename A, typename B>
constexpr bool can_div_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() / std::declval<B>()), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_mod_v = false;
template <typename A, typename B>
constexpr bool can_mod_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() % std::declval<B>()), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_int_div_v = false;
template <typename A, typename B>
constexpr bool can_int_div_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>().intDiv(std::declval<B>())), void>, void>> =
    true;


template <typename A, typename B, typename v = void>
constexpr bool can_bin_and_v = false;
template <typename A, typename B>
constexpr bool can_bin_and_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() & std::declval<B>()), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_bin_or_v = false;
template <typename A, typename B>
constexpr bool can_bin_or_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() | std::declval<B>()), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_bin_xor_v = false;
template <typename A, typename B>
constexpr bool can_bin_xor_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() ^ std::declval<B>()), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_bin_left_v = false;
template <typename A, typename B>
constexpr bool can_bin_left_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() << std::declval<B>()), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_bin_right_v = false;
template <typename A, typename B>
constexpr bool can_bin_right_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() >> std::declval<B>()), void>, void>> =
    true;


template <typename A, typename B, typename v = void>
constexpr bool can_log_and_v = false;
template <typename A, typename B>
constexpr bool can_log_and_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() && std::declval<B>()), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_log_or_v = false;
template <typename A, typename B>
constexpr bool can_log_or_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() || std::declval<B>()), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_equal_v = false;
template <typename A, typename B>
constexpr bool can_equal_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() == std::declval<B>()), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_comp_v = false;
template <typename A, typename B>
constexpr bool can_comp_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>() < std::declval<B>()), void>, void>> = true;


template <typename Ty, typename v = void>
constexpr bool can_abs_v = false;
template <typename Ty>
constexpr bool can_abs_v<Ty, std::enable_if_t<!std::is_same_v<decltype(abs(std::declval<Ty>())), void>, void>> = true;

template <typename Ty, typename v = void>
constexpr bool can_sqrt_v = false;
template <typename Ty>
constexpr bool can_sqrt_v<Ty, std::enable_if_t<!std::is_same_v<decltype(sqrt(std::declval<Ty>())), void>, void>> = true;


template <typename Ty, typename v = void>
constexpr bool can_log2_v = false;
template <typename Ty>
constexpr bool can_log2_v<Ty, std::enable_if_t<!std::is_same_v<decltype(log2(std::declval<Ty>())), void>, void>> = true;

template <typename Ty, typename v = void>
constexpr bool can_log10_v = false;
template <typename Ty>
constexpr bool can_log10_v<Ty, std::enable_if_t<!std::is_same_v<decltype(log10(std::declval<Ty>())), void>, void>> = true;

template <typename Ty, typename v = void>
constexpr bool can_ln_v = false;
template <typename Ty>
constexpr bool can_ln_v<Ty, std::enable_if_t<!std::is_same_v<decltype(ln(std::declval<Ty>())), void>, void>> = true;


template <typename Ty, typename v = void>
constexpr bool can_sin_v = false;
template <typename Ty>
constexpr bool can_sin_v<Ty, std::enable_if_t<!std::is_same_v<decltype(sin(std::declval<Ty>())), void>, void>> = true;

template <typename Ty, typename v = void>
constexpr bool can_cos_v = false;
template <typename Ty>
constexpr bool can_cos_v<Ty, std::enable_if_t<!std::is_same_v<decltype(cos(std::declval<Ty>())), void>, void>> = true;

template <typename Ty, typename v = void>
constexpr bool can_tg_v = false;
template <typename Ty>
constexpr bool can_tg_v<Ty, std::enable_if_t<!std::is_same_v<decltype(std::declval<Ty>().tg()), void>, void>> = true;

template <typename Ty, typename v = void>
constexpr bool can_ctg_v = false;
template <typename Ty>
constexpr bool can_ctg_v<Ty, std::enable_if_t<!std::is_same_v<decltype(ctg(std::declval<Ty>())), void>, void>> = true;

template <typename Ty, typename v = void>
constexpr bool can_asin_v = false;
template <typename Ty>
constexpr bool can_asin_v<Ty, std::enable_if_t<!std::is_same_v<decltype(asin(std::declval<Ty>())), void>, void>> = true;

template <typename Ty, typename v = void>
constexpr bool can_acos_v = false;
template <typename Ty>
constexpr bool can_acos_v<Ty, std::enable_if_t<!std::is_same_v<decltype(acos(std::declval<Ty>())), void>, void>> = true;

template <typename Ty, typename v = void>
constexpr bool can_atg_v = false;
template <typename Ty>
constexpr bool can_atg_v<Ty, std::enable_if_t<!std::is_same_v<decltype(atg(std::declval<Ty>())), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_pow_v = false;
template <typename A, typename B>
constexpr bool can_pow_v<A, B, std::enable_if_t<!std::is_same_v<decltype(pow(std::declval<A>(), std::declval<B>())), void>, void>> = true;

template <typename A, typename B, typename v = void>
constexpr bool can_log_v = false;
template <typename A, typename B>
constexpr bool can_log_v<A, B, std::enable_if_t<!std::is_same_v<decltype(log(std::declval<A>(), std::declval<B>())), void>, void>> = true;


template <typename Ty, typename v = void>
constexpr bool can_sort_v = false;
template <typename Ty>
constexpr bool can_sort_v<Ty, std::enable_if_t<!std::is_same_v<decltype(sort(std::declval<Ty>())), void>, void>> = true;

template <typename Ty, typename v = void>
constexpr bool can_unique_v = false;
template <typename Ty>
constexpr bool can_unique_v<Ty, std::enable_if_t<!std::is_same_v<decltype(unique(std::declval<Ty>())), void>, void>> = true;

template <typename Ty, typename v = void>
constexpr bool can_reverse_v = false;
template <typename Ty>
constexpr bool can_reverse_v<Ty, std::enable_if_t<!std::is_same_v<decltype(reverse(std::declval<Ty>())), void>, void>> = true;


template <typename A, typename B, typename v = void>
constexpr bool can_join_v = false;
template <typename A, typename B>
constexpr bool can_join_v<A, B, std::enable_if_t<!std::is_same_v<decltype(join(std::declval<A>(), std::declval<B>())), void>, void>> = true;


template <typename Ty, typename v = void>
constexpr bool can_min1_v = false;
template <typename Ty>
constexpr bool can_min1_v<Ty, std::enable_if_t<!std::is_same_v<decltype(min(std::declval<Ty>())), void>, void>> = true;

template <typename Ty, typename v = void>
constexpr bool can_max1_v = false;
template <typename Ty>
constexpr bool can_max1_v<Ty, std::enable_if_t<!std::is_same_v<decltype(max(std::declval<Ty>())), void>, void>> = true;

template <typename A, typename B, typename v = void>
constexpr bool can_itert_v = false;
template <typename A, typename B>
constexpr bool can_itert_v<A, B, std::enable_if_t<!std::is_same_v<decltype(std::declval<A>()[std::declval<B>()]), void>, void>> = true;


template <typename Ty, typename v = void>
constexpr bool can_size_v = false;
template <typename Ty>
constexpr bool can_size_v<Ty, std::enable_if_t<!std::is_same_v<decltype(std::declval<Ty>().size()), void>, void>> = true;

}  // namespace calc


/*
* Реализуются следующие операции:
* +a
* -a
* ~a
* !a
*
* a + b
* a - b
* a * b
* a / b
* a % b
* intDiv(a, b)
*
* a & b
* a | b
* a ^ b
* a << b
* a >> b
*
* a || b
* a && b
*
* a == b
* a != b
* a < b
* a <= b
* a > b
* a >= b
*
* abs(a)
* sqrt(a)
*
* log2(a)
* log10(a)
* ln(a)
*
* sin(a)
* cos(a)
* tg(a)
* ctg(a)
*
* asin(a)
* acos(a)
* atg(a)
*
* pow(a, b)
* log(a, b)
*
* sort(a)
* unique(a)
* reverse(a)
*
* join(a, b)
*
* min(a)
* max(a)
*
* min(a, b)
* max(a, b)
*
* a[b]
*
* size(a)

*/

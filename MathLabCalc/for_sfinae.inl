#pragma once

namespace calc {

template <typename Ty, typename... List>
constexpr bool in_list_v = false;
template <typename Ty, typename... List>
constexpr bool in_list_v<Ty, Ty, List...> = true;
template <typename Ty, typename Ty1, typename... List>
constexpr bool in_list_v<Ty, Ty1, List...> = in_list_v<Ty, List...>;


template <typename Ty>
constexpr bool is_math_types = in_list_v<Ty, Error, Bool, Int, Float, Complex>;


template <typename... List>
constexpr bool are_math_types = true;
template <typename Ty1, typename... List>
constexpr bool are_math_types<Ty1, List...> = is_calc_math_types<Ty1> && are_calc_math_types<List...>;

}  // namespace calc

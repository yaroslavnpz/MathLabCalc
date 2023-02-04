#pragma once
#include "Bool.h"
#include "Complex.h"

/*
namespace calc {


#define MATHTYPESLIST Bool, Int, Float, Complex


template <typename Ty1, typename Ty2>
static constexpr bool is_same_v = false;
template <typename Ty>
static constexpr bool is_same_v<Ty, Ty> = true;


template <typename Val, typename... List>
static constexpr bool in_list_v = false;
template <typename Val, typename Ty, typename... List>
static constexpr bool in_list_v<Val, Ty, List...> = in_list_v<Val, List...>;
template <typename Val, typename... List>
static constexpr bool in_list_v<Val, Val, List...> = true;


template <typename Ty1, typename Ty2>
concept IsSame = is_same_v<Ty1, Ty2>;


template <typename From, typename To>
concept IsConvertible = requires(From a) {
                            { static_cast<To>(a) } -> IsSame<To>;
                        };


template <typename Ty>
concept IsAny = true;


template <typename Ty>
concept IsMathType = in_list_v<Ty, MATHTYPESLIST>;


template <typename Ty, typename Fn>
concept IsCanFunction1 = requires(Ty a, Fn fn) {
                             { fn(a) } -> IsAny;
                         };


template <typename Ty1, typename Ty2, typename Fn>
concept IsCanFunctionForFirst = IsConvertible<Ty2, Ty1> && requires(Ty1 a, Ty2 b, Fn fn) {
                                                               { fn(a, static_cast<Ty1>(b)) } -> IsAny;
                                                           };


template <typename Ty1, typename Ty2, typename Fn>
concept IsCanFunctionForSecond = IsConvertible<Ty1, Ty2> && requires(Ty1 a, Ty2 b, Fn fn) {
                                                                { fn(static_cast<Ty2>(a), b) } -> IsAny;
                                                            };


// operators


template <IsMathType Ty1, IsMathType Ty2>
    requires IsCanFunctionForFirst<Ty1, Ty2, std::plus<Ty1>>
const Ty1 operator+(const Ty1& a, const Ty2& b) {
    return a + static_cast<Ty1>(b);
}


template <IsMathType Ty1, IsMathType Ty2>
    requires IsCanFunctionForSecond<Ty1, Ty2, std::plus<Ty2>>
const Ty2 operator+(const Ty1& a, const Ty2& b) {
    return static_cast<Ty2>(a) + b;
}

}  // namespace calc
*/

#pragma once
#include "MathType.h"


namespace calc {


template <bool val, typename Ty>
struct if_ok_type {};
template <typename Ty>
struct if_ok_type<true, Ty> {
    typedef Ty type;
};


template <typename... List>
struct ForMathType {
    typedef typename if_ok_type<are_math_types<List...>, MathType>::type type;
};


template <typename Ty1, typename Ty2>
const typename ForMathType<Ty1, Ty2>::type operator+(const Ty1& a, const Ty2& b) {
    return Error();
}


}  // namespace calc

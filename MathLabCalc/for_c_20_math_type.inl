#pragma once
#include "MathType.h"


namespace calc {


template<typename Ty>
concept IsMathType = is_math_types<Ty>;


template<IsMathType Ty1, IsMathType Ty2>
const MathType operator+(const Ty1& a, const Ty2& b) {
    return Error();
}


}

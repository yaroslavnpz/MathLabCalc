#pragma once
#include <cmath>
#include <string>


#include "exceptions.h"


namespace calc {

/// @brief Базовый класс всех MathType типов. Особенность его в том, что он описывает все возможные операторы с MathTypes, но по умолчанию
/// бросает исключение BadOperator
class BaseMathType {
   public:
    BaseMathType() noexcept = default;
    BaseMathType(const BaseMathType&) noexcept = default;
    BaseMathType(BaseMathType&&) noexcept = default;
    ~BaseMathType() noexcept = default;


    BaseMathType& operator=(const BaseMathType&) noexcept = default;
    BaseMathType& operator=(BaseMathType&&) noexcept = default;
};


template<typename Ty>
using IfBaseMT = std::enable_if_t<std::is_same_v<Ty, BaseMathType>, BaseMathType>;
template<typename Ty>
using IfBaseMTbool = std::enable_if_t<std::is_same_v<Ty, BaseMathType>, bool>;


template <typename Ty>
IfBaseMT<Ty> operator+(Ty val);
template <typename Ty>
IfBaseMT<Ty> operator-(Ty val);
template <typename Ty>
IfBaseMT<Ty> operator~(Ty a);
template <typename Ty>
IfBaseMT<Ty> operator!(Ty a);


template <typename Ty>
IfBaseMT<Ty> operator+(Ty a, Ty b);
template <typename Ty>
IfBaseMT<Ty> operator-(Ty a, Ty b);
template <typename Ty>
IfBaseMT<Ty> operator*(Ty a, Ty b);
template <typename Ty>
IfBaseMT<Ty> operator/(Ty a, Ty b);
template <typename Ty>
IfBaseMT<Ty> operator%(Ty a, Ty b);

}  // namespace calc

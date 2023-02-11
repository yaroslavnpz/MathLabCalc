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


    BaseMathType operator+() const;
    BaseMathType operator-() const;
    BaseMathType operator!() const;
    BaseMathType operator~() const;

    BaseMathType operator+(BaseMathType val) const;
    BaseMathType operator-(BaseMathType val) const;
    BaseMathType operator*(BaseMathType val) const;
    BaseMathType operator/(BaseMathType val) const;
    BaseMathType operator%(BaseMathType val) const;

    BaseMathType intDiv(BaseMathType val) const;

    BaseMathType operator&(BaseMathType val) const;
    BaseMathType operator|(BaseMathType val) const;
    BaseMathType operator^(BaseMathType val) const;
    BaseMathType operator<<(BaseMathType val) const;
    BaseMathType operator>>(BaseMathType val) const;

    BaseMathType operator&&(BaseMathType val) const;
    BaseMathType operator||(BaseMathType val) const;

    bool operator==(BaseMathType val) const;
    bool operator!=(BaseMathType val) const;
    bool operator<(BaseMathType val) const;
    bool operator<=(BaseMathType val) const;
    bool operator>(BaseMathType val) const;
    bool operator>=(BaseMathType val) const;


    BaseMathType sin() const;
    BaseMathType cos() const;
    BaseMathType tg() const;
    BaseMathType ctg() const;

    BaseMathType asin() const;
    BaseMathType acos() const;
    BaseMathType atg() const;

    BaseMathType log2() const;
    BaseMathType log10() const;
    BaseMathType ln() const;
    BaseMathType log(BaseMathType base) const;

    BaseMathType abs() const;

    BaseMathType sqrt() const;

    BaseMathType pow(BaseMathType base) const;
};


}  // namespace calc

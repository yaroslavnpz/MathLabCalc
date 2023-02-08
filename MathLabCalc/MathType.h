#pragma once
#include "BaseMathTypes.h"
#include "for_operators.h"


#include <variant>


namespace calc {


using Error = std::monostate;


class MathType {
   private:
    std::variant<MATHTYPESLIST> data;

   public:
    MathType() = default;
    MathType(const MathType&) = default;
    MathType(MathType&&) noexcept = default;
    ~MathType() noexcept = default;

    MathType& operator=(const MathType&) = default;
    MathType& operator=(MathType&&) noexcept = default;


    MathType(const std::monostate& val);
    MathType(const bool val);
    MathType(const Bool& val);
    MathType(const Int& val);
    MathType(const Ratio& val);
    MathType(const Float& val);
    MathType(const Complex& val);


    constexpr size_t index() const noexcept {
        return data.index();
    }


    const MathType operator+() const;
    const MathType operator-() const;
    const MathType operator!() const;
    const MathType operator~() const;


    const MathType operator+(const MathType& val) const;
    const MathType operator-(const MathType& val) const;
    const MathType operator*(const MathType& val) const;
    const MathType operator/(const MathType& val) const;
    const MathType operator%(const MathType& val) const;


    const MathType intDiv(const MathType& val) const;


    const MathType operator&(const MathType& val) const;
    const MathType operator|(const MathType& val) const;
    const MathType operator<<(const MathType& val) const;
    const MathType operator>>(const MathType& val) const;
    const MathType operator^(const MathType& val) const;


    const MathType operator&&(const MathType& val) const;
    const MathType operator||(const MathType& val) const;


    const bool operator==(const MathType& val) const;
    const bool operator!=(const MathType& val) const;
    const bool operator<(const MathType& val) const;
    const bool operator<=(const MathType& val) const;
    const bool operator>(const MathType& val) const;
    const bool operator>=(const MathType& val) const;
};


}  // namespace calc

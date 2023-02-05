#pragma once
#include "BaseMathTypes.h"
#include "for_operators.h"


#include <variant>


namespace calc {


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
    MathType(const Bool& val);
    MathType(const Int& val);
    MathType(const Float& val);
    MathType(const Complex& val);


    const MathType operator+() const;
    const MathType operator-() const;
};


}  // namespace calc

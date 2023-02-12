#pragma once
#include <variant>

#include "Double.h"
#include "Int64.h"


namespace calc {


class MathType {
   private:
    std::variant<Int64, Double> data;

   public:
    MathType() = default;
    MathType(const MathType&) = default;
    MathType(MathType&&) noexcept = default;
    ~MathType() noexcept = default;

    MathType& operator=(const MathType&) = default;
    MathType& operator=(MathType&&) noexcept = default;


    MathType(Int64 val) noexcept;
    MathType(Double val) noexcept;


    const std::wstring getType() const;
    const std::wstring getName() const;


    MathType operator+(const MathType& val);
};


}  // namespace calc

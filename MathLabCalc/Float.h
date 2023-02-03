#pragma once
#include "Ratio.h"


namespace calc {


class Float {
   private:
    double data = 0.0;

   public:
    Float() noexcept = default;
    Float(const Float&) noexcept = default;
    Float(Float&&) noexcept = default;

    Float& operator=(const Float&) noexcept = default;
    Float& operator=(Float&&) noexcept = default;


    Float(const double val) noexcept;


    Float(const Int& val) noexcept;
    Float(const Ratio& val) noexcept;


    static const bool gen(const std::wstring& str, MathType& val);


    const double getDouble() const noexcept;


    const Float operator+() const noexcept;
    const Float operator-() const noexcept;


    const Float operator+(const Float& val) const noexcept;
    const Float operator-(const Float& val) const noexcept;
    const Float operator*(const Float& val) const noexcept;
    const Float operator/(const Float& val) const noexcept;


    const bool operator==(const Float& val) const noexcept;
    const bool operator!=(const Float& val) const noexcept;
    const bool operator<(const Float& val) const noexcept;
    const bool operator<=(const Float& val) const noexcept;
    const bool operator>(const Float& val) const noexcept;
    const bool operator>=(const Float& val) const noexcept;
};
}  // namespace calc

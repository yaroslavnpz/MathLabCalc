#pragma once
#include <variant>

#include "Double.h"
#include "Int64.h"
#include "Ratio64.h"
#include "Bool.h"


namespace calc {


#define MATHTYPESLIST Int64, Double


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


    MathType(Int64 val) noexcept;
    MathType(Double val) noexcept;


    const std::wstring getType() const;
    const std::wstring getName() const;


    MathType operator+() const;
    MathType operator-() const;
    MathType operator!() const;
    MathType operator~() const;

    MathType operator+(const MathType& val) const;
    MathType operator-(const MathType& val) const;
    MathType operator*(const MathType& val) const;
    MathType operator/(const MathType& val) const;
    MathType operator%(const MathType& val) const;

    MathType intDiv(const MathType& val) const;

    MathType operator&(const MathType& val) const;
    MathType operator|(const MathType& val) const;
    MathType operator^(const MathType& val) const;
    MathType operator<<(const MathType& val) const;
    MathType operator>>(const MathType& val) const;


    MathType operator&&(const MathType& val) const;
    MathType operator||(const MathType& val) const;


    bool operator==(const MathType& val) const;
    bool operator!=(const MathType& val) const;
    bool operator<(const MathType& val) const;
    bool operator<=(const MathType& val) const;
    bool operator>(const MathType& val) const;
    bool operator>=(const MathType& val) const;


    MathType abs() const;
    MathType sqrt() const;

    MathType log2() const;
    MathType log10() const;
    MathType ln() const;


    MathType sin() const;
    MathType cos() const;
    MathType tg() const;
    MathType ctg() const;
    MathType asin() const;
    MathType acos() const;
    MathType atg() const;


    MathType pow(const MathType& base) const;
    MathType log(const MathType& base) const;


    MathType sort() const;
    MathType unique() const;
    MathType reverse() const;


    MathType join(const MathType& val) const;


    MathType min() const;
    MathType min(const MathType& val) const;
    MathType max() const;
    MathType max(const MathType& val) const;

    MathType operator[](const MathType& iter) const;
};


}  // namespace calc

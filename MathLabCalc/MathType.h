#pragma once
#include <variant>

#include "Bool.h"
#include "Double.h"
#include "Int.h"
#include "Ratio.h"


namespace calc {


#define MATHTYPESLIST Bool, Int, Ratio, Double


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


    MathType(bool val) noexcept : data(Bool(val)) {}
    MathType(Bool val) noexcept : data(val) {}
    MathType(Int val) noexcept : data(val) {}
    MathType(const Ratio& val) noexcept : data(val) {}
    MathType(Double val) noexcept : data(val) {}


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


    MathType operator[](const MathType& iter) const;
};


MathType abs(const MathType& val);
MathType sqrt(const MathType& val);


MathType log2(const MathType& val);
MathType log10(const MathType& val);
MathType ln(const MathType& val);


MathType sin(const MathType& val);
MathType cos(const MathType& val);
MathType tg(const MathType& val);
MathType ctg(const MathType& val);


MathType asin(const MathType& val);
MathType acos(const MathType& val);
MathType atg(const MathType& val);


MathType pow(const MathType& val, const MathType& base);
MathType log(const MathType& val, const MathType& base);


MathType sort(const MathType& val);
MathType unique(const MathType& val);
MathType reverse(const MathType& val);


MathType join(const MathType& val);


MathType min(const MathType& val);
MathType max(const MathType& val);


MathType min(const MathType& a, const MathType& b);
MathType max(const MathType& a, const MathType& b);


}  // namespace calc

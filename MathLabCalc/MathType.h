#pragma once
#include <variant>

#include "begMathTypes.h"


#include "Bool.h"
#include "Double.h"
#include "Int.h"
#include "List.h"
#include "Ratio.h"
#include "Seg.h"
#include "Set.h"
#include "InitList.h"


namespace calc {


#define MATHTYPESLIST Bool, Int, Ratio, Double, List, Seg, Set, InitList


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
    MathType(int val) noexcept : data(Int(val)) {}
    MathType(int64_t val) noexcept : data(Int(val)) {}
    MathType(size_t val) noexcept : data(Int(val)) {}
    MathType(Bool val) noexcept : data(val) {}
    MathType(Int val) noexcept : data(val) {}
    MathType(const Ratio& val) noexcept : data(val) {}
    MathType(Double val) noexcept : data(val) {}
    MathType(const List& val) noexcept : data(val) {}
    MathType(const Seg& val) noexcept : data(val) {}
    MathType(const Set& val) noexcept : data(val) {}


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


    MathType size() const;


    friend MathType abs(const MathType& val);
    friend MathType sqrt(const MathType& val);


    friend MathType log2(const MathType& val);
    friend MathType log10(const MathType& val);
    friend MathType ln(const MathType& val);


    friend MathType sin(const MathType& val);
    friend MathType cos(const MathType& val);
    friend MathType tg(const MathType& val);
    friend MathType ctg(const MathType& val);


    friend MathType asin(const MathType& val);
    friend MathType acos(const MathType& val);
    friend MathType atg(const MathType& val);


    friend MathType pow(const MathType& val, const MathType& base);
    friend MathType log(const MathType& val, const MathType& base);


    friend MathType sort(const MathType& val);
    friend MathType unique(const MathType& val);
    friend MathType reverse(const MathType& val);


    friend MathType join(const MathType& val, const MathType& add);


    friend MathType min(const MathType& val);
    friend MathType max(const MathType& val);


    friend MathType min(const MathType& a, const MathType& b);
    friend MathType max(const MathType& a, const MathType& b);
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


MathType join(const MathType& val, const MathType& add);


MathType min(const MathType& val);
MathType max(const MathType& val);


}  // namespace calc

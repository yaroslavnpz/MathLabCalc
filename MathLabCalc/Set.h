#pragma once
#include "List.h"


#include <set>

namespace calc {


class Set {
   private:
    std::set<MathType> _data;

   public:
    Set() = default;
    Set(const Set&) = default;
    Set(Set&&) noexcept = default;
    ~Set() noexcept = default;


    Set(const std::initializer_list<MathType>& val);
    Set(const MathType& val);
    Set(Bool val);
    Set(Int val);
    Set(Double val);
    Set(const Ratio& val);
    Set(const Seg& val);
    Set(const List& val);


    const std::wstring getType() const;
    const std::wstring getName() const;


    void clear();


    constexpr size_t size() const noexcept {
        return _data.size();
    }

    const Set operator+() const;
    const Set operator-() const;
    const Set operator!() const;
    const Set operator~() const;

    const Set operator+(const Set& val) const;
    const Set operator-(const Set& val) const;
    const Set operator*(const Set& val) const;
    const Set operator/(const Set& val) const;
    const Set operator%(const Set& val) const;

    const Set intDiv(const Set& val) const;

    const Set operator&(const Set& val) const;
    const Set operator|(const Set& val) const;
    const Set operator^(const Set& val) const;
    const Set operator<<(const Set& val) const;
    const Set operator>>(const Set& val) const;

    const Set operator&&(const Set& val) const;
    const Set operator||(const Set& val) const;


    const MathType operator&&(const Bool val) const;
    const MathType operator||(const Bool val) const;


    bool operator==(const Set& val) const;
    bool operator!=(const Set& val) const;
    bool operator<(const Set& val) const;
    bool operator<=(const Set& val) const;
    bool operator>(const Set& val) const;
    bool operator>=(const Set& val) const;


    friend const Set abs(const Set& val);
    friend const Set sqrt(const Set& val);


    friend const Set log2(const Set& val);
    friend const Set log10(const Set& val);
    friend const Set ln(const Set& val);


    friend const Set sin(const Set& val);
    friend const Set cos(const Set& val);
    friend const Set tg(const Set& val);
    friend const Set ctg(const Set& val);


    friend const Set asin(const Set& val);
    friend const Set acos(const Set& val);
    friend const Set atg(const Set& val);


    friend const Set pow(const Set& val, const MathType& base);
    friend const Set pow(const Set& val, const Set& base);
    friend const Set log(const Set& val, const MathType& base);
    friend const Set log(const Set& val, const Set& base);


    friend const Set join(const Set& val, const MathType& add);
    friend const Set join(const Set& val, const Set& add);


    friend MathType min(const Set& val);
    friend MathType max(const Set& val);
};


const Set abs(const Set& val);
const Set sqrt(const Set& val);


const Set log2(const Set& val);
const Set log10(const Set& val);
const Set ln(const Set& val);


const Set sin(const Set& val);
const Set cos(const Set& val);
const Set tg(const Set& val);
const Set ctg(const Set& val);


const Set asin(const Set& val);
const Set acos(const Set& val);
const Set atg(const Set& val);


const Set pow(const Set& val, const MathType& base);
const Set pow(const Set& val, const Set& base);
const Set log(const Set& val, const MathType& base);
const Set log(const Set& val, const Set& base);


const Set join(const Set& val, const MathType& add);
const Set join(const Set& val, const Set& add);


MathType min(const Set& val);
MathType max(const Set& val);



}  // namespace calc

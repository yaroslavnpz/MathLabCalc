#pragma once
#include "BaseMathTypes.h"
#include "MathType.h"


#include <vector>


namespace calc {


class List {
   private:
    std::vector<MathType> data;


    void optimize();

   public:
    List() = default;
    List(const List&) = default;
    List(List&&) noexcept = default;
    ~List() noexcept = default;


    List(const std::initializer_list<MathType>& val);
    List(const MathType& val);


    List& operator=(const List&) = default;
    List& operator=(List&&) noexcept = default;


    const List operator+() const;
    const List operator-() const;

    const List operator+(const List& val) const;
    const List operator-(const List& val) const;
    const List operator*(const List& val) const;
    const List operator/(const List& val) const;
    const List operator%(const List& val) const;


    const List intDiv(const List& val) const;


    const List operator&(const List& val) const;
    const List operator|(const List& val) const;
    const List operator^(const List& val) const;
    const List operator<<(const List& val) const;
    const List operator>>(const List& val) const;


    const List operator||(const List& val) const;
    const List operator&&(const List& val) const;


    const bool operator==(const List& val) const;
    const bool operator!=(const List& val) const;
    const bool operator<(const List& val) const;
    const bool operator<=(const List& val) const;
    const bool operator>(const List& val) const;
    const bool operator>=(const List& val) const;
};


}  // namespace calc

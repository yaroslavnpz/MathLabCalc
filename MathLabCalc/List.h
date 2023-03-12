#pragma once
#include "begMathTypes.h"


namespace calc {


class List {
   private:
    std::vector<MathType> data;

   public:
    List() = default;
    List(const List&) = default;
    List(List&&) noexcept = default;
    ~List() noexcept = default;


    List(const MathType& val);


    List& operator=(const List&) = default;
    List& operator=(List&&) noexcept = default;


    friend List operator+(List val);
    friend List operator-(List val);
    friend List operator!(List val);
    friend List operator~(List val);


    friend List operator+(const List& a, const List& b);
    friend List operator-(const List& a, const List& b);
    friend List operator*(const List& a, const List& b);
    friend List operator/(const List& a, const List& b);
    friend List intDiv(const List& a, const List& b);

    friend List operator&(const List& a, const List& b);
    friend List operator|(const List& a, const List& b);
    friend List operator^(const List& a, const List& b);
    friend List operator<<(const List& a, const List& b);
    friend List operator>>(const List& a, const List& b);


    friend bool operator==(const List& a, const List& b);
    friend bool operator!=(const List& a, const List& b);
    friend bool operator<(const List& a, const List& b);
    friend bool operator<=(const List& a, const List& b);
    friend bool operator>(const List& a, const List& b);
    friend bool operator>=(const List& a, const List& b);


    friend List abs(List val);
    friend List sqrt(List val);

    friend List sin(List val);
    friend List cos(List val);
    friend List tg(List val);
    friend List ctg(List val);

    friend List asin(List val);
    friend List acos(List val);
    friend List atg(List val);

    friend List log2(List val);
    friend List log10(List val);
    friend List ln(List val);

    friend List log(List a, const List& b);

    friend List pow(List a, const List& b);
};
}  // namespace calc

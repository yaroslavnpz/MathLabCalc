#pragma once
#include "BaseMathTypes.h"
#include "MathType.h"


#include <array>


namespace calc {


class Seg {
   private:
    std::array<MathType, 2> data;


    void optimize();

   public:
    Seg() = default;
    Seg(const Seg&) = default;
    Seg(Seg&&) noexcept = default;
    ~Seg() noexcept = default;


    Seg(const MathType& x, const MathType& y);


    Seg& operator=(const Seg&) = default;
    Seg& operator=(Seg&&) noexcept = default;


    const Seg operator+() const;
    const Seg operator-() const;

    const Seg operator+(const Seg& val) const;
    const Seg operator-(const Seg& val) const;
    const Seg operator*(const Seg& val) const;
    const Seg operator/(const Seg& val) const;
    const Seg operator%(const Seg& val) const;


    const Seg intDiv(const Seg& val) const;


    const Seg operator&(const Seg& val) const;
    const Seg operator|(const Seg& val) const;
    const Seg operator^(const Seg& val) const;
    const Seg operator<<(const Seg& val) const;
    const Seg operator>>(const Seg& val) const;


    const Seg operator||(const Seg& val) const;
    const Seg operator&&(const Seg& val) const;


    const bool operator==(const Seg& val) const;
    const bool operator!=(const Seg& val) const;
    const bool operator<(const Seg& val) const;
    const bool operator<=(const Seg& val) const;
    const bool operator>(const Seg& val) const;
    const bool operator>=(const Seg& val) const;
};


class Quad {
   private:
    std::array<MathType, 4> data;


    void optimize();

   public:
    Quad() = default;
    Quad(const Quad&) = default;
    Quad(Quad&&) noexcept = default;
    ~Quad() noexcept = default;


    Quad(const MathType& x, const MathType& y, const MathType& x1, const MathType& y1);


    Quad& operator=(const Quad&) = default;
    Quad& operator=(Quad&&) noexcept = default;


    const Quad operator+() const;
    const Quad operator-() const;

    const Quad operator+(const Quad& val) const;
    const Quad operator-(const Quad& val) const;
    const Quad operator*(const Quad& val) const;
    const Quad operator/(const Quad& val) const;
    const Quad operator%(const Quad& val) const;


    const Quad intDiv(const Quad& val) const;


    const Quad operator&(const Quad& val) const;
    const Quad operator|(const Quad& val) const;
    const Quad operator^(const Quad& val) const;
    const Quad operator<<(const Quad& val) const;
    const Quad operator>>(const Quad& val) const;


    const Quad operator||(const Quad& val) const;
    const Quad operator&&(const Quad& val) const;


    const bool operator==(const Quad& val) const;
    const bool operator!=(const Quad& val) const;
    const bool operator<(const Quad& val) const;
    const bool operator<=(const Quad& val) const;
    const bool operator>(const Quad& val) const;
    const bool operator>=(const Quad& val) const;
};


}  // namespace calc

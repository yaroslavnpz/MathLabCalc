#pragma once

#include "begMathTypes.h"


namespace calc {


class Seg {
   private:
    MathType* _data = nullptr;


    MathType& operator[](size_t iter);
    const MathType operator[](size_t iter) const;

    template <typename Fn>
    friend Seg conv(const Seg& val, Fn fn);
    template <typename Fn>
    friend Seg conv2(const Seg& a, const Seg& b, Fn fn);


   public:
    Seg();
    Seg(const Seg&);
    Seg(Seg&&) noexcept;
    ~Seg() noexcept;

    Seg& operator=(const Seg&);
    Seg& operator=(Seg&&) noexcept;


    Seg(const MathType& val);
    Seg(const MathType& a, const MathType& b);

    Seg(Bool val);
    Seg(Int val);
    Seg(const Ratio& val);
    Seg(Double val);


    const std::wstring getType() const;
    const std::wstring getName() const;


    Seg operator+() const;
    Seg operator-() const;
    Seg operator!() const;
    Seg operator~() const;

    Seg operator+(const Seg& val) const;
    Seg operator-(const Seg& val) const;
    Seg operator*(const Seg& val) const;
    Seg operator/(const Seg& val) const;
    Seg operator%(const Seg& val) const;

    Seg intDiv(const Seg& val) const;

    Seg operator&(const Seg& val) const;
    Seg operator|(const Seg& val) const;
    Seg operator^(const Seg& val) const;
    Seg operator<<(const Seg& val) const;
    Seg operator>>(const Seg& val) const;

    Seg operator&&(const Seg& val) const;
    Seg operator||(const Seg& val) const;


    bool operator==(const Seg& val) const;
    bool operator!=(const Seg& val) const;
    bool operator<(const Seg& val) const;
    bool operator<=(const Seg& val) const;
    bool operator>(const Seg& val) const;
    bool operator>=(const Seg& val) const;


    friend Seg abs(const Seg& val);
    friend Seg sqrt(const Seg& val);


    friend Seg log2(const Seg& val);
    friend Seg log10(const Seg& val);
    friend Seg ln(const Seg& val);


    friend Seg sin(const Seg& val);
    friend Seg cos(const Seg& val);
    friend Seg tg(const Seg& val);
    friend Seg ctg(const Seg& val);


    friend Seg asin(const Seg& val);
    friend Seg acos(const Seg& val);
    friend Seg atg(const Seg& val);


    friend Seg pow(const Seg& val, const MathType& base);
    friend Seg pow(const Seg& val, const Seg& base);
    friend Seg log(const Seg& val, const MathType& base);
    friend Seg log(const Seg& val, const Seg& base);
};


Seg abs(const Seg& val);
Seg sqrt(const Seg& val);


Seg log2(const Seg& val);
Seg log10(const Seg& val);
Seg ln(const Seg& val);


Seg sin(const Seg& val);
Seg cos(const Seg& val);
Seg tg(const Seg& val);
Seg ctg(const Seg& val);


Seg asin(const Seg& val);
Seg acos(const Seg& val);
Seg atg(const Seg& val);


Seg pow(const Seg& val, const MathType& base);
Seg pow(const Seg& val, const Seg& base);
Seg log(const Seg& val, const MathType& base);
Seg log(const Seg& val, const Seg& base);
}  // namespace calc

#pragma once
#include "begMathTypes.h"


#include <memory>


namespace calc {


class List {
   private:
    std::shared_ptr<MathType[]> _data;
    size_t _size = 0;


   public:
    List() noexcept = default;
    List(const List&) noexcept = default;
    List(List&&) noexcept = default;
    ~List() noexcept = default;

    List& operator=(const List&) noexcept = default;
    List& operator=(List&&) noexcept = default;


    List(size_t size);
    List(const std::initializer_list<MathType>& val);
    List(const MathType& val);
    List(Bool val);
    List(Int val);
    List(Double val);
    List(const Ratio& val);
    List(const Seg& val);


    const std::wstring getType() const;
    const std::wstring getName() const;


    void clear();


    constexpr size_t size() const noexcept {
        return _size;
    }


    MathType* begin() noexcept;

    const MathType* begin() const noexcept;

    MathType* end() noexcept;

    const MathType* end() const noexcept;


    const MathType operator[](size_t iter) const;


    const MathType operator[](Int val) const;
    const const List operator[](const List& val) const;


    const List operator+() const;
    const List operator-() const;
    const List operator!() const;
    const List operator~() const;

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

    const List operator&&(const List& val) const;
    const List operator||(const List& val) const;


    bool operator==(const List& val) const;
    bool operator!=(const List& val) const;
    bool operator<(const List& val) const;
    bool operator<=(const List& val) const;
    bool operator>(const List& val) const;
    bool operator>=(const List& val) const;


    friend const List abs(const List& val);
    friend const List sqrt(const List& val);


    friend const List log2(const List& val);
    friend const List log10(const List& val);
    friend const List ln(const List& val);


    friend const List sin(const List& val);
    friend const List cos(const List& val);
    friend const List tg(const List& val);
    friend const List ctg(const List& val);


    friend const List asin(const List& val);
    friend const List acos(const List& val);
    friend const List atg(const List& val);


    friend const List pow(const List& val, const MathType& base);
    friend const List pow(const List& val, const List& base);
    friend const List log(const List& val, const MathType& base);
    friend const List log(const List& val, const List& base);


    friend const List sort(const List& val);
    friend const List unique(const List& val);
    friend const List reverse(const List& val);


    friend const List join(const List& val, const MathType& add);
    friend const List join(const List& val, const List& add);


    friend MathType min(const List& val);
    friend MathType max(const List& val);
};


const List abs(const List& val);
const List sqrt(const List& val);


const List log2(const List& val);
const List log10(const List& val);
const List ln(const List& val);


const List sin(const List& val);
const List cos(const List& val);
const List tg(const List& val);
const List ctg(const List& val);


const List asin(const List& val);
const List acos(const List& val);
const List atg(const List& val);


const List pow(const List& val, const MathType& base);
const List pow(const List& val, const List& base);
const List log(const List& val, const MathType& base);
const List log(const List& val, const List& base);


const List sort(const List& val);
const List unique(const List& val);
const List reverse(const List& val);


const List join(const List& val, const MathType& add);
const List join(const List& val, const List& add);


MathType min(const List& val);
MathType max(const List& val);


}  // namespace calc

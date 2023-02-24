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
    const List operator[](const List& val) const;


    List operator+() const;
    List operator-() const;
    List operator!() const;
    List operator~() const;

    List operator+(const List& val) const;
    List operator-(const List& val) const;
    List operator*(const List& val) const;
    List operator/(const List& val) const;
    List operator%(const List& val) const;

    List intDiv(const List& val) const;

    List operator&(const List& val) const;
    List operator|(const List& val) const;
    List operator^(const List& val) const;
    List operator<<(const List& val) const;
    List operator>>(const List& val) const;

    List operator&&(const List& val) const;
    List operator||(const List& val) const;


    bool operator==(const List& val) const;
    bool operator!=(const List& val) const;
    bool operator<(const List& val) const;
    bool operator<=(const List& val) const;
    bool operator>(const List& val) const;
    bool operator>=(const List& val) const;


    friend List abs(const List& val);
    friend List sqrt(const List& val);


    friend List log2(const List& val);
    friend List log10(const List& val);
    friend List ln(const List& val);


    friend List sin(const List& val);
    friend List cos(const List& val);
    friend List tg(const List& val);
    friend List ctg(const List& val);


    friend List asin(const List& val);
    friend List acos(const List& val);
    friend List atg(const List& val);


    friend List pow(const List& val, const MathType& base);
    friend List pow(const List& val, const List& base);
    friend List log(const List& val, const MathType& base);
    friend List log(const List& val, const List& base);


    friend List sort(const List& val);
    friend List unique(const List& val);
    friend List reverse(const List& val);


    friend List join(const List& val, const MathType& add);
    friend List join(const List& val, const List& add);


    friend MathType min(const List& val);
    friend MathType max(const List& val);
};


List abs(const List& val);
List sqrt(const List& val);


List log2(const List& val);
List log10(const List& val);
List ln(const List& val);


List sin(const List& val);
List cos(const List& val);
List tg(const List& val);
List ctg(const List& val);


List asin(const List& val);
List acos(const List& val);
List atg(const List& val);


List pow(const List& val, const MathType& base);
List pow(const List& val, const List& base);
List log(const List& val, const MathType& base);
List log(const List& val, const List& base);


List sort(const List& val);
List unique(const List& val);
List reverse(const List& val);


List join(const List& val, const MathType& add);
List join(const List& val, const List& add);


MathType min(const List& val);
MathType max(const List& val);


}  // namespace calc

#pragma once
#include <cmath>
#include <string>


namespace calc {


class MathType;


class Int {
   private:
    long long data = 0;

    public:
    Int() noexcept = default;
     Int(const Int&) noexcept = default;
    Int(Int&&) noexcept = default;
     ~Int() noexcept = default;

     Int& operator=(const Int&) noexcept = default;
     Int& operator=(Int&&) noexcept = default;


     Int(const long long val) noexcept;


     operator std::wstring() const;


     static const bool gen(const std::wstring& str, MathType& val);


     const long long getInt() const noexcept;


     const Int operator+() const noexcept;
     const Int operator-() const noexcept;
     const Int operator~() const noexcept;


     const Int operator+(const Int& val) const noexcept;
     const Int operator-(const Int& val) const noexcept;
     const Int operator*(const Int& val) const noexcept;


     const Int intDiv(const Int& val) const;
     const Int operator%(const Int& val) const;

     const MathType operator/(const Int& val) const;


     const Int operator|(const Int& val) const noexcept;
     const Int operator&(const Int& val) const noexcept;
     const Int operator^(const Int& val) const noexcept;
     const Int operator<<(const Int& val) const noexcept;
     const Int operator>>(const Int& val) const noexcept;


     const bool operator==(const Int& val) const noexcept;
     const bool operator!=(const Int& val) const noexcept;
     const bool operator<(const Int& val) const noexcept;
     const bool operator<=(const Int& val) const noexcept;
     const bool operator>(const Int& val) const noexcept;
     const bool operator>=(const Int& val) const noexcept;
};
}

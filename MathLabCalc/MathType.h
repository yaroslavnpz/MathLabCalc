#pragma once
#include <cmath>
#include <complex>
#include <variant>
#include <functional>


namespace calc {

class Error;
class Bool;
class Int;
class Float;
class Complex;
class List;
class Seg;
class Quad;


typedef std::variant<Error, Bool> MathType;


class Error {
   private:
    bool _val = false;

   public:
    Error() noexcept = default;


    const std::wstring wgetName() const;
};


class Bool {
   private:
    bool data = false;

   public:
    Bool() noexcept = default;


    Bool(const bool val) noexcept;


    const std::wstring wgetName() const;


    friend const MathType operator+(const Bool& a, const Bool& b) noexcept;
};


const MathType operator+(const Bool& a, const Bool& b) noexcept;


}  // namespace calc


#include "for_sfinae.inl"

#if ((__cplusplus >= 202002L) || (_MSVC_LANG >= 202002L))
#include "for_c_20_math_type.inl"
#else
#include "for_c_17_math_type.inl"
#endif

#pragma once
#include <cmath>
#include <complex>
#include <variant>


namespace calc {

class Error;
class Bool;
class Int;
class Float;
class Complex;
class List;
class Seg;
class Quad;

using MathType = std::variant<Error, Bool>;


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


template<typename Ty1, typename Ty2>
const MathType operator+(const Ty1& a, const Ty2& b) noexcept {
    return Error();
}



const MathType operator+(const Bool& a, const Bool& b) noexcept;




}  // namespace calc

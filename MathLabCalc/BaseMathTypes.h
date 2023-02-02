#pragma once
#include <algorithm>
#include <cmath>
#include <complex>
#include <exception>
#include <variant>

namespace calc {


#define IS_CPP20 ((__cplusplus >= 202002L) || (_MSVC_LANG >= 202002L))


using Error = std::monostate;
using Bool = bool;
using Int = long long int;
using Float = double;
using Complex = std::complex<double>;


class MathType;


class ExceptionDivizionByZero : public std::exception {
   public:
    ExceptionDivizionByZero() = default;
    ~ExceptionDivizionByZero() noexcept = default;


    const char* what() const noexcept override {
        return "Divizion by zero!";
    }
};


}  // namespace calc

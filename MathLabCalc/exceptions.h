#pragma once
#include <exception>


namespace calc {


class DivizionByZero : public std::exception {
   public:
    DivizionByZero() noexcept = default;
    ~DivizionByZero() noexcept = default;

    const char* what() const override;
};


class BadOperator : public std::exception {
   public:
    BadOperator() noexcept = default;
    ~BadOperator() noexcept = default;

    const char* what() const override;
};


class BadIterator : public std::exception {
   public:
    BadIterator() noexcept = default;
    ~BadIterator() noexcept = default;

    const char* what() const override;
};


}

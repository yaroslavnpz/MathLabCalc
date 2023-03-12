#pragma once
#include "begMathTypes.h"


namespace calc {


class Bool {
   private:
    bool data = false;

   public:
    constexpr Bool() noexcept = default;
    constexpr Bool(const Bool&) noexcept = default;
    constexpr Bool(Bool&&) noexcept = default;
    ~Bool() noexcept = default;


    constexpr Bool(const bool data) noexcept;


    Bool& operator=(const Bool&) noexcept = default;
    Bool& operator=(Bool&&) noexcept = default;


    operator std::wstring() const;


    constexpr bool getData() const noexcept;


    friend constexpr Bool operator!(const Bool val) noexcept;


    friend constexpr Bool operator+(const Bool a, const Bool b) noexcept;
    friend constexpr Bool operator*(const Bool a, const Bool b) noexcept;

    friend constexpr Bool operator||(const Bool a, const Bool b) noexcept;
    friend constexpr Bool operator&&(const Bool a, const Bool b) noexcept;


    friend constexpr bool operator==(const Bool a, const Bool b) noexcept;
    friend constexpr bool operator!=(const Bool a, const Bool b) noexcept;
    friend constexpr bool operator<(const Bool a, const Bool b) noexcept;
    friend constexpr bool operator<=(const Bool a, const Bool b) noexcept;
    friend constexpr bool operator>(const Bool a, const Bool b) noexcept;
    friend constexpr bool operator>=(const Bool a, const Bool b) noexcept;
};
}  // namespace calc


#include "Bool.inl"

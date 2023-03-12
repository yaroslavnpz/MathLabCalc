#pragma once
#include "Bool.h"

namespace calc {

constexpr Bool::Bool(const bool data) noexcept : data(data) {}

Bool::operator std::wstring() const {
    if (data)
        return L"True";
    else
        return L"False";
}

constexpr bool Bool::getData() const noexcept {
    return data;
}

constexpr Bool operator!(const Bool val) noexcept {
    return !val.data;
}

constexpr Bool operator+(const Bool a, const Bool b) noexcept {
    return a.data || b.data;
}

constexpr Bool operator*(const Bool a, const Bool b) noexcept {
    return a.data && b.data;
}

constexpr Bool operator||(const Bool a, const Bool b) noexcept {
    return a.data || b.data;
}

constexpr Bool operator&&(const Bool a, const Bool b) noexcept {
    return a.data && b.data;
}

constexpr bool operator==(const Bool a, const Bool b) noexcept {
    return a.data == b.data;
}

constexpr bool operator!=(const Bool a, const Bool b) noexcept {
    return a.data != b.data;
}

constexpr bool operator<(const Bool a, const Bool b) noexcept {
    return a.data < b.data;
}

constexpr bool operator<=(const Bool a, const Bool b) noexcept {
    return a.data <= b.data;
}

constexpr bool operator>(const Bool a, const Bool b) noexcept {
    return a.data > b.data;
}

constexpr bool operator>=(const Bool a, const Bool b) noexcept {
    return a.data >= b.data;
}


}  // namespace calc

#pragma once
#include <cmath>
#include <string>


namespace calc {


class MathType;


class Bool {
   private:
    bool data = false;

   public:
    constexpr Bool() noexcept = default;
    constexpr Bool(const Bool&) noexcept = default;
    constexpr Bool(Bool&&) noexcept = default;
    ~Bool() noexcept = default;

    constexpr Bool& operator=(const Bool&) noexcept = default;
    constexpr Bool& operator=(Bool&&) noexcept = default;


    constexpr Bool(const bool val) noexcept : data(val) {}


    operator std::wstring() const {
        if (data)
            return L"True";
        else
            return L"False";
    }


    static const bool gen(const std::wstring& str, MathType& val);


    constexpr const bool getBool() const noexcept {
        return data;
    }


    constexpr const Bool operator!() const noexcept {
        return !data;
    }


    constexpr const Bool operator+(const Bool& val) const noexcept {
        return data || val.data;
    }
    constexpr const Bool operator*(const Bool& val) const noexcept {
        return data && val.data;
    }

    constexpr const Bool operator||(const Bool& val) const noexcept {
        return data || val.data;
    }
    constexpr const Bool operator&&(const Bool& val) const noexcept {
        return data && val.data;
    }


    constexpr const bool operator==(const Bool& val) const noexcept {
        return data == val.data;
    }
    constexpr const bool operator!=(const Bool& val) const noexcept {
        return data != val.data;
    }
    constexpr const bool operator<(const Bool& val) const noexcept {
        return data < val.data;
    }
    constexpr const bool operator<=(const Bool& val) const noexcept {
        return data <= val.data;
    }
    constexpr const bool operator>(const Bool& val) const noexcept {
        return data > val.data;
    }
    constexpr const bool operator>=(const Bool& val) const noexcept {
        return data >= val.data;
    }
};


}  // namespace calc

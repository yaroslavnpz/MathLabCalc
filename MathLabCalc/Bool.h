#pragma once
#include "exceptions.h"


namespace calc {


/// @brief Класс для хранения значений true and false
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


    constexpr Bool(bool data) noexcept : data(data) {}


    /// @brief Значение переменной в стандартных типах
    /// @return Значение переменной в стандартных типах
    constexpr bool getData() const noexcept {
        return data;
    }


    /// @brief Строка, хранящая имя типа
    /// @return Строка, хранящая имя типа
    const std::wstring getType() const;


    /// @brief Строка, хранящая значение переменной
    /// @return Строка, хранящая значение переменной
    const std::wstring getName() const;


    constexpr Bool operator!() const noexcept {
        return !data;
    }

    constexpr Bool operator+(Bool val) const noexcept {
        return data + val.data;
    }
    constexpr Bool operator*(Bool val) const noexcept {
        return data * val.data;
    }

    constexpr Bool operator||(Bool val) const noexcept {
        return data || val.data;
    }
    constexpr Bool operator&&(Bool val) const noexcept {
        return data && val.data;
    }

    constexpr bool operator==(Bool val) const noexcept {
        return data == val.data;
    }
    constexpr bool operator!=(Bool val) const noexcept {
        return data != val.data;
    }
    constexpr bool operator<(Bool val) const noexcept {
        return data < val.data;
    }
    constexpr bool operator<=(Bool val) const noexcept {
        return data <= val.data;
    }
    constexpr bool operator>(Bool val) const noexcept {
        return data > val.data;
    }
    constexpr bool operator>=(Bool val) const noexcept {
        return data >= val.data;
    }
};


}  // namespace calc

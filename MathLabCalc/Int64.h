#pragma once
#include <string>


namespace calc {


/// @brief Класс для хранения целочисленного 64 битного типа
class Int64 {
   private:
    int64_t data = 0;

   public:
    constexpr Int64() noexcept = default;
    constexpr Int64(const Int64&) noexcept = default;
    constexpr Int64(Int64&&) noexcept = default;
    ~Int64() noexcept = default;

    constexpr Int64& operator=(const Int64&) noexcept = default;
    constexpr Int64& operator=(Int64&&) noexcept = default;


    constexpr Int64(int64_t data) noexcept;


    /// @brief Строка, хранящая имя типа
    /// @return Строка, хранящая имя типа
    const std::wstring getType() const;


    /// @brief Строка, хранящая значение переменной
    /// @return Строка, хранящая значение переменной
    const std::wstring getName() const;


    /// @brief Значение переменной в стандартных типах
    /// @return Значение переменной в стандартных типах
    constexpr int64_t getData() const noexcept;


    friend Int64 operator+(Int64 val) noexcept;
    friend Int64 operator-(Int64 val) noexcept;
    friend Int64 operator~(Int64 val) noexcept;

    friend Int64 operator+(Int64 a, Int64 b) noexcept;
    friend Int64 operator-(Int64 a, Int64 b) noexcept;
    friend Int64 operator*(Int64 a, Int64 b) noexcept;
    //friend Int64 operator/(Int64 a, Int64 b) noexcept;

    friend Int64 operator%(Int64 a, Int64 b);
    friend Int64 intDiv(Int64 a, Int64 b);


    friend Int64 operator&(Int64 a, Int64 b) noexcept;
    friend Int64 operator|(Int64 a, Int64 b) noexcept;
    friend Int64 operator^(Int64 a, Int64 b) noexcept;
    friend Int64 operator<<(Int64 a, Int64 b);
    friend Int64 operator>>(Int64 a, Int64 b);


    friend const bool operator==(Int64 a, Int64 b) noexcept;
    friend const bool operator!=(Int64 a, Int64 b) noexcept;
    friend const bool operator<(Int64 a, Int64 b) noexcept;
    friend const bool operator<=(Int64 a, Int64 b) noexcept;
    friend const bool operator>(Int64 a, Int64 b) noexcept;
    friend const bool operator>=(Int64 a, Int64 b) noexcept;
};


}  // namespace calc

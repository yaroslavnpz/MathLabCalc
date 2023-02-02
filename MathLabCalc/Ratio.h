#pragma once
#include "BaseMathTypes.h"


namespace calc {


class Ratio {
   private:
    Int x = 0, y = 1;


    static const Int gcd(Int a, Int b) noexcept;


    void optimize();


   public:
    Ratio() noexcept = default;
    Ratio(const Ratio&) noexcept = default;
    Ratio(Ratio&&) noexcept = default;
    ~Ratio() noexcept = default;

    Ratio& operator=(const Ratio&) noexcept = default;
    Ratio& operator=(Ratio&&) noexcept = default;


    Ratio(const Int x, const int y) noexcept;


    const Ratio operator+() const noexcept;
    const Ratio operator-() const noexcept;

    const Ratio operator+(const Ratio& val) const noexcept;
    const Ratio operator-(const Ratio& val) const noexcept;
    const Ratio operator*(const Ratio& val) const noexcept;
    const Ratio operator/(const Ratio& val) const noexcept;


    const bool operator==(const Ratio& val) const noexcept;


#if IS_CPP20

    const auto operator<=>(const Ratio& val) const noexcept;

#else

    // Нужно добавить функции

#endif
};


}  // namespace calc

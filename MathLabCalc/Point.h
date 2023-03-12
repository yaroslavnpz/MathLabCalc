#pragma once
#include "begMathTypes.h"


namespace calc {


class Point {
   private:
    double x = 0, y = 0;

   public:
    constexpr Point() noexcept = default;
    constexpr Point(const Point&) noexcept = default;
    constexpr Point(Point&&) noexcept = default;
    ~Point() noexcept = default;


    Point(const double x, const double y);
    Point(const Double x, const Double y);


    friend constexpr Point operator+(Point val) noexcept;
    friend constexpr Point operator-(Point val) noexcept;

    friend constexpr Point operator+(Point a, const Point& b) noexcept;
    friend constexpr Point operator-(Point a, const Point& b) noexcept;

    friend constexpr Point operator+(Point a, const Double b) noexcept;
    friend constexpr Point operator-(Point a, const Double b) noexcept;
    friend constexpr Point operator*(Point a, const Double b) noexcept;
    friend constexpr Point operator/(Point a, const Double b);


    friend constexpr bool operator==(const Point& a, const Point& b) noexcept;
    friend constexpr bool operator!=(const Point& a, const Point& b) noexcept;
    friend constexpr bool operator<(const Point& a, const Point& b) noexcept;
    friend constexpr bool operator<=(const Point& a, const Point& b) noexcept;
    friend constexpr bool operator>(const Point& a, const Point& b) noexcept;
    friend constexpr bool operator>=(const Point& a, const Point& b) noexcept;
};
}  // namespace calc

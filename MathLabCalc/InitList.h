#pragma once
#include "begMathTypes.h"


namespace calc {


class InitList {
   private:
    std::vector<MathType> data;

   public:
    InitList() = default;
    InitList(const InitList&) = default;
    InitList(InitList&&) noexcept = default;
    ~InitList() noexcept = default;


    InitList(const MathType& val);


    InitList& operator=(const InitList&) = default;
    InitList& operator=(InitList&&) noexcept = default;


    operator std::wstring() const;


    InitList genInitList(const MathType& val);
    InitList genInitList(MathType val);
};
}  // namespace calc

#pragma once
#include "begMathTypes.h"


#include <memory>
#include <vector>


namespace calc {


class InitList {
   private:
    std::shared_ptr<std::vector<MathType>> data;


   public:
    InitList() = default;
    InitList(const InitList&) = default;
    InitList(InitList&&) noexcept = default;
    ~InitList() noexcept = default;


    InitList& operator=(const InitList&) = default;
    InitList& operator=(InitList&&) noexcept = default;


    const std::wstring getType() const {
        return L"InitList";
    }


    const std::wstring getName() const {
        return L"???";
    }


    friend class List;

    friend const InitList makeInitList(const InitList& a, const MathType& b);
    friend const InitList makeInitList(const MathType& a, const MathType& b);
};


const InitList makeInitList(const InitList& a, const MathType& b);
const InitList makeInitList(const MathType& a, const MathType& b);
}  // namespace calc

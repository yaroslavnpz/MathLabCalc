#include "MathType.h"


namespace calc {

const std::wstring calc::Error::wgetName() const {
    return L"Error";
}

Bool::Bool(const bool val) noexcept : data(val) {}

const std::wstring Bool::wgetName() const {
    if (data)
        return L"True";
    else
        return L"False";
}

const MathType operator+(const Bool& a, const Bool& b) noexcept {
    return Bool(a.data || b.data);
}

}  // namespace calc

#include "Int64.h"
#include "MathType.h"


namespace calc {

const std::wstring Int64::getType() const {
    return L"Int64";
}

const std::wstring Int64::getName() const {
    return std::to_wstring(data);
}

Ratio64 operator/(Int64 a, Int64 b) {
    if (b.data == 0)
        throw BadOperator();
    return Ratio64(a.data, b.data);
}

}  // namespace calc

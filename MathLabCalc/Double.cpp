#include "Double.h"


namespace calc {

const std::wstring Double::getType() const {
    return L"Double";
}
const std::wstring Double::getName() const {
    return std::to_wstring(data);
}
}  // namespace calc

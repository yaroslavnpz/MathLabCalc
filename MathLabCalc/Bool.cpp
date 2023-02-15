#include "Bool.h"


namespace calc {


const std::wstring Bool::getType() const {
    return L"Bool";
}

const std::wstring Bool::getName() const {
    if (data)
        return L"True";
    else
        return L"False";
}


}  // namespace calc

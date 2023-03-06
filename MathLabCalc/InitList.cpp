#include "InitList.h"
#include "MathType.h"


namespace calc {


const InitList makeInitList(const InitList& a, const MathType& b) {
    a.data->push_back(b);
    return a;
}

const InitList makeInitList(const MathType& a, const MathType& b) {
    InitList res;
    res.data = std::shared_ptr<std::vector<MathType>>(new std::vector<MathType>(2));
    res.data.get()->operator[](0) = a;
    res.data.get()->operator[](1) = b;
    return res;
}

}  // namespace calc

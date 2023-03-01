#include "MathType.h"
#include "Set.h"


#include <sstream>


namespace calc {

Set::Set(const std::initializer_list<MathType>& val) : _data(val) {}

Set::Set(const MathType& val) {
    _data.insert(val);
}

Set::Set(Bool val) {
    _data.insert(val);
}

Set::Set(Int val) {
    _data.insert(val);
}

Set::Set(Double val) {
    _data.insert(val);
}

Set::Set(const Ratio& val) {
    _data.insert(val);
}

Set::Set(const Seg& val) {
    _data.insert(val);
}

Set::Set(const List& val) {
    for (size_t i = 0; i < val.size(); ++i)
        _data.insert(val[i]);
}

const std::wstring Set::getType() const {
    return L"Set";
}

const std::wstring Set::getName() const {
    std::stringstream stream;
}

void Set::clear() {
    _data.clear();
}

}  // namespace calc

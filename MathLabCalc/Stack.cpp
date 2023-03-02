#include "Stack.h"


namespace calc {

void Stack::push(MathType val) {
    data.push_back(val);
}

void Stack::pop() {
    data.pop_back();
}

MathType Stack::back() const {
    return data.back();
}

MathType Stack::globalVar(size_t iter) const {
    return data[iter];
}

MathType Stack::popBack() {
    auto buf = back();
    pop();
    return buf;
}

MathType Stack::localVar(size_t iter) const {
    return data[pointers.back() + iter];
}

void Stack::breakFunction() {
    data.resize(pointers.back());
    pointers.pop_back();
}

void Stack::callFunction(size_t cnt_args) {
    pointers.push_back(data.size() - cnt_args);
}


}  // namespace calc

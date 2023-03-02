#include "Entity.h"


namespace calc {



const int EntityOperand::getPriority() const noexcept {
    return 100 + add_priority;
}

const Entity::Type EntityOperand::getType() const noexcept {
    return Operand;
}

const size_t EntityOperand::getCntArgs() const noexcept {
    return 0;
}

EntityConstant::EntityConstant(const MathType& data) : data(data) {}

const std::wstring EntityConstant::getName() const {
    return data.getName();
}

const MathType EntityConstant::operator()(Stack& stack) const {
    return data;
}


}  // namespace calc

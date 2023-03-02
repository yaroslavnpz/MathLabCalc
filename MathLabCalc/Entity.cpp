#include "Entity.h"


namespace calc {



const int EntityOperand::getPriority() const noexcept {
    return 100;
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


EntityGlobalConstant::EntityGlobalConstant(const std::wstring name, const MathType& data) : EntityConstant(data), name(name) {}

const std::wstring EntityGlobalConstant::getName() const {
    return name;
}

EntityGlobalArgument::EntityGlobalArgument(const std::wstring& name, const size_t position) : name(name), position(position) {}

const std::wstring EntityGlobalArgument::getName() const {
    return name;
}

const MathType EntityGlobalArgument::operator()(Stack& stack) const {
    return stack.globalVar(position);
}

EntityLocalArgument::EntityLocalArgument(const std::wstring& name, const size_t position) : name(name), position(position) {}

const std::wstring EntityLocalArgument::getName() const {
    return std::wstring();
}

const MathType EntityLocalArgument::operator()(Stack& stack) const {
    return stack.localVar(position);
}

}  // namespace calc

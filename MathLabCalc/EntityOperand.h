#pragma once
#include "Entity.h"


namespace calc {


class EntityOperand : public Entity {
   public:
    EntityOperand() noexcept = default;
    EntityOperand(const EntityOperand&) noexcept = default;
    EntityOperand(EntityOperand&&) noexcept = default;
    ~EntityOperand() noexcept = default;

    /// @brief Приоритет элемента
    /// @return Приоритет элемента
    const int getPriority() const noexcept final override {
        return 100;
    }

    /// @brief Тип элемента
    /// @return Тпи элемента (Entity::Type)
    const Type getType() const noexcept final override {
        return Operand;
    }

    /// @brief Количество аргументов элемента
    /// @return Количество аргументов элемента
    const size_t getCntArgs() const noexcept final override {
        return 0;
    }
};


class EntityConstant : public EntityOperand {
   private:
    MathType data;

   public:
    EntityConstant() = delete;
    EntityConstant(const EntityConstant&) = default;
    EntityConstant(EntityConstant&&) noexcept = default;
    ~EntityConstant() noexcept = default;

    EntityConstant(const MathType& data) : data(data) {}


    /// @brief Имя элемента
    /// @return Строку, хранящую имя элемента
    const std::wstring getName() const override {
        return data.getName();
    }

    /// @brief Результат вычисления данного элемента в программе
    /// @param stack Стек, хранящий текущее состояние выполнения математического выражения
    /// @return Результат вычисления, который в последствии (возмжно) пойдет в стек
    const MathType operator()(Stack& stack) const final override {
        return data;
    }
};


class EntityNamedConstant final : public EntityConstant {
   private:
    std::wstring name;

    public:
    EntityNamedConstant(const EntityNamedConstant&) = default;
     EntityNamedConstant(EntityNamedConstant&&) noexcept = default;
    ~EntityNamedConstant() noexcept = default;

    EntityNamedConstant(const std::wstring& name, const MathType& data) : EntityConstant(data), name(name) {}
    EntityNamedConstant(std::wstring&& name, const MathType& data) : EntityConstant(data), name(name) {}


    /// @brief Имя элемента
    /// @return Строку, хранящую имя элемента
    const std::wstring getName() const override {
        return name;
    }
}
}  // namespace calc

#pragma once
#include "MathType.h"
#include "Stack.h"


#include <string>


namespace calc {

/// @brief Базовый класс для всех объектов, которые принимаются из ввода
class Entity {
   public:
    enum Type { Operand, Prefix, Postfix, Binary };

   protected:
    int add_priority = 0;


   public:
    Entity() noexcept = default;
    Entity(const Entity&) noexcept = default;
    Entity(Entity&&) noexcept = default;
    virtual ~Entity() noexcept = default;


    virtual const int getPriority() const noexcept = 0;
    virtual const Type getType() const noexcept = 0;
    virtual const size_t getCntArgs() const noexcept = 0;


    virtual const std::wstring getName() const = 0;


    virtual const MathType operator()(Stack& stack) const = 0;

    // virtual const Expression derivative(Stack& stack) const = 0;
};


class EntityOperand : public Entity {
   public:
    EntityOperand() noexcept = default;
    EntityOperand(const EntityOperand&) noexcept = default;
    EntityOperand(EntityOperand&&) noexcept = default;
    ~EntityOperand() noexcept = default;


    const int getPriority() const noexcept final override;
    const Type getType() const noexcept final override;
    const size_t getCntArgs() const noexcept final override;
};


class EntityConstant final : public EntityOperand {
   private:
    MathType data;

   public:
    EntityConstant() = default;
    EntityConstant(const EntityConstant&) = default;
    EntityConstant(EntityConstant&&) noexcept = default;
    ~EntityConstant() noexcept = default;

    EntityConstant(const MathType& data);


    const std::wstring getName() const override;


    const MathType operator()(Stack& stack) const override;
};

}  // namespace calc

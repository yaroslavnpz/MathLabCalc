#pragma once
#include "MathType.h"
#include "Stack.h"


#include <string>


namespace calc {

/// @brief Базовый класс для всех объектов, которые принимаются из ввода
class Entity {
   public:
    enum Type { Operand, Prefix, Postfix, Binary };


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


/// @brief Базовый класс для всех операндов. У них неизменный тип, кол-во аргументов (0) и приоритет
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


/// @brief Простая константа при вводе. Например, 1, 3.0, True - это константы
class EntityConstant : public EntityOperand {
   private:
    MathType data;

   public:
    EntityConstant() = default;
    EntityConstant(const EntityConstant&) = default;
    EntityConstant(EntityConstant&&) noexcept = default;
    ~EntityConstant() noexcept = default;

    EntityConstant(const MathType& data);


    const std::wstring getName() const override;


    const MathType operator()(Stack& stack) const final override;
};


/// @brief Это некоторые константы. Например pi
class EntityGlobalConstant : public EntityConstant {
   private:
    std::wstring name;

   public:
    EntityGlobalConstant() = default;
    EntityGlobalConstant(const EntityGlobalConstant&) = default;
    EntityGlobalConstant(EntityGlobalConstant&&) noexcept = default;
    ~EntityGlobalConstant() noexcept = default;

    EntityGlobalConstant(const std::wstring name, const MathType& data);


    const std::wstring getName() const final override;
};


/// @brief Это некоторые переменные, которые были объявлены где-то пользователем
class EntityGlobalArgument : public EntityOperand {
   private:
    std::wstring name;
    size_t position = 0;

   public:
    EntityGlobalArgument() = default;
    EntityGlobalArgument(const EntityGlobalArgument&) = default;
    EntityGlobalArgument(EntityGlobalArgument&&) noexcept = default;
    ~EntityGlobalArgument() noexcept = default;

    EntityGlobalArgument(const std::wstring& name, const size_t position);


    const std::wstring getName() const final override;


    const MathType operator()(Stack& stack) const final override;
};


/// @brief Это перменные, которые принимает функция
class EntityLocalArgument : public EntityOperand {
   private:
    std::wstring name;
    size_t position = 0;

   public:
    EntityLocalArgument() = default;
    EntityLocalArgument(const EntityLocalArgument&) = default;
    EntityLocalArgument(EntityLocalArgument&&) noexcept = default;
    ~EntityLocalArgument() noexcept = default;

    EntityLocalArgument(const std::wstring& name, const size_t position);


    const std::wstring getName() const final override;


    const MathType operator()(Stack& stack) const final override;
};


class EntityOperator : public Entity {
   private:
    std::wstring name;

   public:
    EntityOperator() = default;
    EntityOperator(const EntityOperator&) = default;
    EntityOperator(EntityOperator&&) noexcept = default;
    ~EntityOperator() noexcept = default;

    EntityOperator(const std::wstring& name);


    const std::wstring getName() const final override;
};


class EntityPrefix : public EntityOperator {
   public:
    EntityPrefix() = default;
    EntityPrefix(const EntityPrefix&) = default;
    EntityPrefix(EntityPrefix&&) noexcept = default;
    ~EntityPrefix() noexcept = default;

    EntityPrefix(const std::wstring& name);


    const Type getType() const noexcept final override;
    const size_t getCntArgs() const noexcept final override;
};


class EntityPostfix : public EntityOperator {
   public:
    EntityPostfix() = default;
    EntityPostfix(const EntityPostfix&) = default;
    EntityPostfix(EntityPostfix&&) noexcept = default;
    ~EntityPostfix() noexcept = default;

    EntityPostfix(const std::wstring& name);


    const Type getType() const noexcept final override;
    const size_t getCntArgs() const noexcept final override;
};

class EntityBinary : public EntityOperator {
   public:
    EntityBinary() = default;
    EntityBinary(const EntityBinary&) = default;
    EntityBinary(EntityBinary&&) noexcept = default;
    ~EntityBinary() noexcept = default;

    EntityBinary(const std::wstring& name);


    const Type getType() const noexcept final override;
    const size_t getCntArgs() const noexcept final override;
};

}  // namespace calc

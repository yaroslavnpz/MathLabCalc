#pragma once
#include "Entity.h"


namespace calc {


class EntityOperator : public Entity {
   private:
    std::wstring name;
    int priority = 0;

   public:
    EntityOperator() = delete;
    EntityOperator(const EntityOperator&) = default;
    EntityOperator(EntityOperator&&) noexcept = default;
    ~EntityOperator() noexcept = default;


    EntityOperator(const std::wstring& name, const int priority) : name(name), priority(priority) {}
    EntityOperator(std::wstring&& name, const int priority) noexcept : name(name), priority(priority) {}


    /// @brief Приоритет элемента
    /// @return Приоритет элемента
    const int getPriority() const noexcept final override {
        return priority;
    }


    /// @brief Имя элемента
    /// @return Строку, хранящую имя элемента
    const std::wstring getName() const final override {
        return name;
    }
};


class EntityPrefix : public EntityOperator {
   public:
    EntityPrefix() = delete;
    EntityPrefix(const EntityPrefix&) = default;
    EntityPrefix(EntityPrefix&&) noexcept = default;
    ~EntityPrefix() noexcept = default;


    EntityPrefix(const std::wstring& name, const int priority) : EntityOperator(name, priority) {}
    EntityPrefix(std::wstring&& name, const int priority) noexcept : EntityOperator(name, priority) {}


    /// @brief Тип элемента
    /// @return Тпи элемента (Entity::Type)
    const Type getType() const noexcept final override {
        return Prefix;
    }

    /// @brief Количество аргументов элемента
    /// @return Количество аргументов элемента
    const size_t getCntArgs() const noexcept final override {
        return 1;
    }
};


class EntityPostfix : public EntityOperator {
   public:
    EntityPostfix() = delete;
    EntityPostfix(const EntityPostfix&) = default;
    EntityPostfix(EntityPostfix&&) noexcept = default;
    ~EntityPostfix() noexcept = default;


    EntityPostfix(const std::wstring& name, const int priority) : EntityOperator(name, priority) {}
    EntityPostfix(std::wstring&& name, const int priority) noexcept : EntityOperator(name, priority) {}


    /// @brief Тип элемента
    /// @return Тпи элемента (Entity::Type)
    const Type getType() const noexcept final override {
        return Postfix;
    }

    /// @brief Количество аргументов элемента
    /// @return Количество аргументов элемента
    const size_t getCntArgs() const noexcept final override {
        return 1;
    }
};


class EntityBinary : public EntityOperator {
   public:
    EntityBinary() = delete;
    EntityBinary(const EntityBinary&) = default;
    EntityBinary(EntityBinary&&) noexcept = default;
    ~EntityBinary() noexcept = default;


    EntityBinary(const std::wstring& name, const int priority) : EntityOperator(name, priority) {}
    EntityBinary(std::wstring&& name, const int priority) noexcept : EntityOperator(name, priority) {}


    /// @brief Тип элемента
    /// @return Тпи элемента (Entity::Type)
    const Type getType() const noexcept final override {
        return Binary;
    }

    /// @brief Количество аргументов элемента
    /// @return Количество аргументов элемента
    const size_t getCntArgs() const noexcept final override {
        return 2;
    }
};


class BasicEntityPrefixOperator : public EntityPrefix {
   private:
    std::function<const MathType(const MathType&)> fn;

   public:
    BasicEntityPrefixOperator() = delete;
    BasicEntityPrefixOperator(const BasicEntityPrefixOperator&) = default;
    BasicEntityPrefixOperator(BasicEntityPrefixOperator&&) noexcept = default;
    ~BasicEntityPrefixOperator() noexcept = default;


    BasicEntityPrefixOperator(const std::wstring& name, const int priority, const std::function<const MathType(const MathType&)> fn)
        : EntityPrefix(name, priority), fn(fn) {}
    BasicEntityPrefixOperator(std::wstring&& name, const int priority, const std::function<const MathType(const MathType&)> fn) noexcept
        : EntityPrefix(name, priority), fn(fn) {}


    /// @brief Результат вычисления данного элемента в программе
    /// @param stack Стек, хранящий текущее состояние выполнения математического выражения
    /// @return Результат вычисления, который в последствии (возмжно) пойдет в стек
    const MathType operator()(Stack& stack) const final override {
        auto buf = fn(stack.back());
        stack.pop();
        return buf;
    }
};


class BasicEntityPostfixOperator : public EntityPostfix {
   private:
    std::function<const MathType(const MathType&)> fn;

   public:
    BasicEntityPostfixOperator() = delete;
    BasicEntityPostfixOperator(const BasicEntityPostfixOperator&) = default;
    BasicEntityPostfixOperator(BasicEntityPostfixOperator&&) noexcept = default;
    ~BasicEntityPostfixOperator() noexcept = default;


    BasicEntityPostfixOperator(const std::wstring& name, const int priority, const std::function<const MathType(const MathType&)> fn)
        : EntityPostfix(name, priority), fn(fn) {}
    BasicEntityPostfixOperator(std::wstring&& name, const int priority, const std::function<const MathType(const MathType&)> fn) noexcept
        : EntityPostfix(name, priority), fn(fn) {}


    /// @brief Результат вычисления данного элемента в программе
    /// @param stack Стек, хранящий текущее состояние выполнения математического выражения
    /// @return Результат вычисления, который в последствии (возмжно) пойдет в стек
    const MathType operator()(Stack& stack) const final override {
        auto buf = fn(stack.back());
        stack.pop();
        return buf;
    }
};


class BasicEntityBinaryOperator : public EntityBinary {
   private:
    std::function<const MathType(const MathType&, const MathType&)> fn;

   public:
    BasicEntityBinaryOperator() = delete;
    BasicEntityBinaryOperator(const BasicEntityBinaryOperator&) = default;
    BasicEntityBinaryOperator(BasicEntityBinaryOperator&&) noexcept = default;
    ~BasicEntityBinaryOperator() noexcept = default;


    BasicEntityBinaryOperator(const std::wstring& name,
                              const int priority,
                              const std::function<const MathType(const MathType&, const MathType&)> fn)
        : EntityBinary(name, priority), fn(fn) {}


    BasicEntityBinaryOperator(std::wstring&& name, const int priority, const std::function<const MathType(const MathType&, const MathType&)> fn) noexcept
        : EntityBinary(name, priority), fn(fn) {}


    /// @brief Результат вычисления данного элемента в программе
    /// @param stack Стек, хранящий текущее состояние выполнения математического выражения
    /// @return Результат вычисления, который в последствии (возмжно) пойдет в стек
    const MathType operator()(Stack& stack) const final override {
        auto b = stack.popBack();
        auto a = stack.popBack();
        auto buf = fn(a, b);
        return buf;
    }
};
}  // namespace calc

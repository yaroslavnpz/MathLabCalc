#pragma once
#include "MathType.h"
#include "Stack.h"


#include <string>
#include <functional>


namespace calc {


class Expression;


/// @brief Базовый класс для всех объектов, которые принимаются из ввода
class Entity {
   public:
    enum Type { Operand, Prefix, Postfix, Binary, OpenBrace, CloseBrace };


   public:
    Entity() noexcept = default;
    Entity(const Entity&) noexcept = default;
    Entity(Entity&&) noexcept = default;
    virtual ~Entity() noexcept = default;


    /// @brief Приоритет элемента
    /// @return Приоритет элемента
    virtual const int getPriority() const noexcept = 0;

    /// @brief Тип элемента
    /// @return Тпи элемента (Entity::Type)
    virtual const Type getType() const noexcept = 0;

    /// @brief Количество аргументов элемента
    /// @return Количество аргументов элемента
    virtual const size_t getCntArgs() const noexcept = 0;

    /// @brief Имя элемента
    /// @return Строку, хранящую имя элемента
    virtual const std::wstring getName() const = 0;

    /// @brief Результат вычисления данного элемента в программе
    /// @param stack Стек, хранящий текущее состояние выполнения математического выражения
    /// @return Результат вычисления, который в последствии (возмжно) пойдет в стек
    virtual const MathType operator()(Stack& stack) const = 0;
};


template<typename Ty>
using sh = std::shared_ptr<Ty>;
using pte = sh<const Entity>;


}  // namespace calc


#include "EntityOperand.h"
#include "EntityOperator.h"
#include "EntityFunction.h"

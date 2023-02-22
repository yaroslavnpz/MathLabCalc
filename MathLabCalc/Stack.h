#pragma once
#include <vector>


#include "MathType.h"


namespace calc {

/// @brief Класс для хранения стека вычислений математического выражения
class Stack {
   private:
    std::vector<MathType> data;
    std::vector<size_t> pointers;


   public:
    Stack() = default;
    Stack(const Stack&) = default;
    Stack(Stack&&) noexcept = default;
    ~Stack() noexcept = default;

    Stack& operator=(const Stack&) = default;
    Stack& operator=(Stack&&) noexcept = default;


    /// @brief Функция для добавления элемента в стек
    /// @param val Добавляемый в стек элемент
    void push(MathType val);


    /// @brief Удаление последнего элемента из стека
    void pop();


    /// @brief Последний элемент в стеке
    /// @return Последний элемент в стеке
    MathType back() const;


    /// @brief Удаление последнего элемента из стека
    /// @return Значение последнего элемента
    MathType popBack();


    /// @brief Нахождение глобальной переменной в стеке
    /// @param iter Индекс переменной
    /// @return Значение переменной в стеке
    MathType globalVar(size_t iter) const;


    /// @brief Нахождение локальной переменной, или аргумента функции в стеке
    /// @param iter Индекс переменной
    /// @return Значение аргумента функции
    MathType localVar(size_t iter) const;


    /// @brief Завершает выполнение функции, удаляя все аргументы и т.п.
    void breakFunction();


    /// @brief Вызов функции
    /// @param cnt_args количество аргументов функции
    void callFunction(size_t cnt_args);
};

}  // namespace calc

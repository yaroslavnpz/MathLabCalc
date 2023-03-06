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


    const MathType operator[](const size_t i) const {
        return data[i];
    }
    MathType& operator[](const size_t i) {
        return data[i];
    }


    /// @brief Функция для добавления одного элемента в конец стека
    /// @param val Значение, добовляемое в стек
    void push(const MathType val) {
        data.push_back(val);
    }


    /// @brief Удаление последнего элемента из стека
    void pop() {
        data.pop_back();
    }


    /// @brief Удаление последнего элемента из стека
    /// @return Значение последнего (удаленного) элемента
    const MathType popBack() {
        auto buf = data.back();
        data.pop_back();
        return buf;
    }


    /// @brief Значение последнего элемента
    /// @return Значение последнего элемента
    const MathType back() const {
        return data.back();
    }
    /// @brief Значение последнего элемента
    /// @return Значение последнего элемента
    MathType& back() {
        return data.back();
    }


    /// @brief Спец функция для обращения к аргументам (локальным переменным)
    /// @param iter Индекс аргумента
    /// @return Значение переменной
    const MathType localVariable(const size_t iter) const {
        return data[pointers.back() + iter];
    }


    /// @brief Спец функция для обращения к глобальным переменным
    /// @param iter Индес переменной
    /// @return Значение переменной
    const MathType globalVariable(const size_t iter) const {
        return data[iter];
    }


    /// @brief Спец функция для обращения к аргументам (локальным переменным)
    /// @param iter Индекс аргумента
    /// @return Значение переменной
    MathType& localVariable(const size_t iter);


    /// @brief Спец функция для обращения к глобальным переменным
    /// @param iter Индес переменной
    /// @return Значение переменной
    MathType& globalVariable(const size_t iter);
};

}  // namespace calc

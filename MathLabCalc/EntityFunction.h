#pragma once
#include "EntityOperator.h"


namespace calc {


class EntityFunction : public EntityOperator {
   private:
    std::function<const MathType(const MathType*)> fn;
    size_t cnt_args = 0;

   public:
    EntityFunction() = delete;
    EntityFunction(const EntityFunction&) = default;
    EntityFunction(EntityFunction&&) noexcept = default;
    ~EntityFunction() noexcept = default;


    EntityFunction(const std::wstring& name, const int priority, const size_t cnt_args, std::function<const MathType(const MathType*)> fn)
        : EntityOperator(name, priority), cnt_args(cnt_args), fn(fn) {}


    EntityFunction(std::wstring&& name,
                   const int priority,
                   const size_t cnt_args,
                   std::function<const MathType(const MathType*)> fn) noexcept
        : EntityOperator(name, priority), cnt_args(cnt_args), fn(fn) {}


    /// @brief Результат вычисления данного элемента в программе
    /// @param stack Стек, хранящий текущее состояние выполнения математического выражения
    /// @return Результат вычисления, который в последствии (возмжно) пойдет в стек
    const MathType operator()(Stack& stack) const final override {
        std::unique_ptr<MathType[]> data(new MathType[cnt_args]);
        for (size_t i = 0; i < cnt_args; ++i)
            data[cnt_args - i - 1] = stack.popBack();
        return fn(data.get());
    }
};
}  // namespace calc

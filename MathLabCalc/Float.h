#pragma once
#include "Ratio.h"


namespace calc {


class Float {
   private:
    double data = 0.0;

   public:
    Float() noexcept = default;
    Float(const Float&) noexcept = default;
};
}  // namespace calc

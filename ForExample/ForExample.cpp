//#include "Int.h"

#include <iostream>
// #include <string>


using namespace std;


#include "BaseMathTypes.h"
#include "for_operators.h"
#include "MathType.h"

using namespace calc;


int main() {
    cout << "Hello";

    MathType a = Int(10);
    MathType b = Float(20);

    a = b + a;
    has_minus_v<Bool, Bool>;
    has_bin_and_v<Bool, Bool>;
    has_div_v<Bool, Bool>;
    has_bin_or_v<Float, Float>;
    has_bin_xor_v<Bool, Bool>;
    has_equal_v<Error, Bool>;
    auto c = a < b;
}

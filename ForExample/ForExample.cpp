#include <iostream>
#include "MathType.h"

using namespace std;
using namespace calc;

int main() {
    MathType a, b;
    a = Bool(true);
    b = Bool(false);

    // a = a + 5;


    a = visit([&](const auto& a, const auto& b) { return a + b; }, a, b);
    wcout << visit([&](const auto& a) { return a.wgetName(); }, a) << '\n';
}

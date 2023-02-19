#include <iostream>

using namespace std;


#include "MathType.h"
using namespace calc;


union {
    double a;
    int64_t b;
} s;

int main() {
    MathType a, b;
    a = Int(5);
    b = Int(4);

    wcout << (a / b).getName() << '\n';
}

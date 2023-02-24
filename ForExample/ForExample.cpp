#include <iostream>

using namespace std;


#include "MathType.h"
#include "MathType_templates.inl"
#include "basic_algs.h"
using namespace calc;


union {
    double a;
    int64_t b;
} s;

int main() {
    MathType a, b;

    a = List({Int(1), Int(2), Int(3), Int(4), Int(5), Int(6), Int(7), Int(8), Int(9)});
    b = List({Int(2), Int(4), Int(6)});

    wcout << a[b].getName();
}

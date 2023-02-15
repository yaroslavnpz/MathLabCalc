#include <iostream>

using namespace std;


#include "Double.h"
#include "Int64.h"
// #include "MathType.h"
using namespace calc;


union {
    double a;
    int64_t b;
} s;

int main() {
    s.a = 5;

    cout << (s.b >> 40) << '\n';

    s.a = -5;

    cout << (s.b >> 40)<< '\n';
}

#include <iostream>
#include <complex>

using namespace std;


#include "MathType.h"
using namespace calc;


int main() {
    InitList a;
    a = makeInitList(Int(1), Int(2));
    a = makeInitList(a, Int(3));


    MathType x, y;
    x = y;


    List b = a;


    wcout << b.getName() << '\n';
}

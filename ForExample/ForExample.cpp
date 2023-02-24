#include <iostream>

using namespace std;


#include "MathType.h"
using namespace calc;


int main() {
    MathType a, b;

    a = Seg(2, 3);
    b = List({1, 2, 3, 4});

    
    try {
        wcout << (a + b).getName();
    } catch (const exception& ex) {
        cout << ex.what() << '\n';
    }
}

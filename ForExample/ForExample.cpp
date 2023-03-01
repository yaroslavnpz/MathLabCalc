#include <iostream>
#include <complex>

using namespace std;


#include "MathType.h"
using namespace calc;


int main() {
    MathType a, b;

    complex<double> c = 1;
    cout << sin(c) << '\n';

    Set x = MathType();
    Set y = x;

    //a = Seg(2, 3);
    //b = List({1, 2, 3, 4});

    std::variant<MATHTYPESLIST> data;
    std::variant<MATHTYPESLIST> buf;
    data = buf;

    
    try {
        wcout << (a + b).getName();
    } catch (const exception& ex) {
        cout << ex.what() << '\n';
    }
}

#include <iostream>
#include <algorithm>

using namespace std;


#include "Bool.h"
#include "Int.h"
#include "Double.h"
using namespace calc;



int main() {
    Bool a = true;
    Bool b = false;


    wcout << wstring(a + b) << ' ' << wstring(a * b);
}

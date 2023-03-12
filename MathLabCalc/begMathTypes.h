#pragma once
#include <cmath>
#include <complex>
#include <memory>
#include <sstream>
#include <string>
#include <vector>


namespace calc {


class Bool;
class Int;
class Double;
class Complex;
class Point;
class Seg;

class InitList;
class List;
class Set;


class MathType;



/*

Возможные операции для MathType типов (в том числе для MathType)

+a
-a
!a
~a

a + b
a - b
a * b
a / b
a % b

intDiv(a, b)

a & b
a | b
a ^ b
a << b
a >> b

a && b
a || b

a == b
a != b
a < b
a <= b
a > b
a >= b

abs(a)
sqrt(a)

sin(a)
cos(a)
tg(a)
ctg(a)

asin(a)
acos(a)
atg(a)

log2(a)
log10(a)
ln(a)

log(a, b)

pow(a, b)

min(a, b) реализуется при существовании a < b
max(a, b) реализуется при существовании a > b

*/

}  // namespace calc

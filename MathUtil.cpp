#include "MathUtil.h"

/*
  Calculate the factorial of a number
*/
long MathUtil::factorial(const int n)
{
    long f = 1;
    for (int i = 1; i <= n; ++i)
        f *= i;
    return f;
}
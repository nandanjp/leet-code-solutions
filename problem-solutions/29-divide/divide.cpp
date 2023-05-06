#include <iostream>
#include <utility>
#include <limits>

int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == 1)
        return INT_MIN;
    else if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    else if (dividend == INT_MAX && divisor == 1)
        return INT_MAX;
    else if (divisor == 1)
        return dividend;
    else if (divisor == -1)
        return -dividend;

    long quotient = (long)dividend * divisor;
    bool isNeg = quotient < 0 ? true : false;

    long l_dividend = abs((long)dividend);
    long l_divisor = abs((long)divisor);

    quotient = 0;
    while (l_dividend >= l_divisor)
    {
        l_dividend -= l_divisor;
        ++quotient;
    }
    if (isNeg)
        quotient *= -1;

    return quotient;
}

int main()
{
    long a, b;
    std::cout << "Enter the dividend: ";
    std::cin >> a;
    std::cout << "Enter the divisor: ";
    std::cin >> b;

    std::cout << "a / b = " << a << " / " << b << " = " << divide(a, b) << std::endl;

    std::cout << std::endl;
    return 0;
}
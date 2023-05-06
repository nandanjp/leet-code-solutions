#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int myAtoi(string s)
{
    size_t size = s.size();
    if (size == 0)
        return 0;

    char curr = s[0];
    if (size == 1)
        return isdigit(curr) ? (int)curr - 48 : 0;

    if (!isdigit(curr) && curr != '-' && curr != '+' && curr != ' ')
        return 0;

    bool isNeg = false;

    size_t i = 0;
    while (i < size && s[i] == ' ')
        ++i;

    if (i >= size)
        return 0;

    curr = s[i];
    if (curr == '+' || curr == '-')
    {
        isNeg = curr == '-' ? true : false;
        ++i;
    }

    long currInt = 0;

    for (; i < size; ++i)
    {
        curr = s[i];
        if (!isdigit(curr))
            break;

        currInt = (currInt * 10) + (int)(curr - 48);
        if (currInt > INT_MIN)
            break;
    }

    if (isNeg)
        currInt *= -1;
    if (currInt > INT_MAX)
        currInt = INT_MAX;
    if (currInt < INT_MIN)
        currInt = INT_MIN;

    return currInt;
}

int main()
{
    std::cout << "42, the string, to the number is: " << myAtoi("42") << std::endl;
    std::cout << "-42, the string, to the number is: " << myAtoi("-42") << std::endl;
    std::cout << "4193 with words, the string, to the number is: " << myAtoi("4193 with words") << std::endl;
    std::cout << "0032, the string, to the number is: " << myAtoi("0032") << std::endl;
    std::cout << "003.2123, the string, to the number is: " << myAtoi("003.2123") << std::endl;
    std::cout << "   -42, the string, to the number is: " << myAtoi("   -42") << std::endl;

    std::cout << std::endl;
    return 0;
}
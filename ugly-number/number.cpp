#include <iostream>
#include <iomanip>

using namespace std;

bool isUgly(long n)
{
    while (true)
    {
        if (n == 1 || n == -1)
            return true;
        if (n % 2 == 0)
        {
            n /= 2;
            continue;
        }
        if (n % 3 == 0)
        {
            n /= 3;
            continue;
        }
        if (n % 5 == 0)
        {
            n /= 5;
            continue;
        }
        return false;
    }

    return true;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << "14 is ugly: " << isUgly(14) << std::endl;
    std::cout << "6 is ugly: " << isUgly(6) << std::endl;
    std::cout << "2147483648 is ugly: " << isUgly(2147483648) << std::endl;
    std::cout << "-2147483648 is ugly: " << isUgly(-2147483648) << std::endl;
    std::cout << "14 is ugly: " << isUgly(14) << std::endl;
    std::cout << "14 is ugly: " << isUgly(14) << std::endl;

    std::cout << std::endl;
    return 0;
}

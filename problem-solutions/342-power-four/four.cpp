#include <iostream>
#include <iomanip>

using namespace std;

bool isPowerOfFour(int n)
{
    int multiplier = n < 0 ? -4 : 4;
    long product = 1;

    while (product < n)
        product *= multiplier;

    return product == n;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << "64 is a power of 4: " << isPowerOfFour(64) << std::endl;
    std::cout << "256 is a power of 4: " << isPowerOfFour(256) << std::endl;
    std::cout << "63 is a power of 4: " << isPowerOfFour(63) << std::endl;
    std::cout << "15 is a power of 4: " << isPowerOfFour(15) << std::endl;
    std::cout << "16 is a power of 4: " << isPowerOfFour(16) << std::endl;
    std::cout << "207 is a power of 4: " << isPowerOfFour(207) << std::endl;
    std::cout << "2147483647 is a power of 4: " << std::endl
              << isPowerOfFour(2147483647) << std::endl;

    std::cout << std::endl;
    return 0;
}
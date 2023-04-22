#include <iostream>
#include <stdint.h>

using namespace std;

std::string bit_string(uint32_t n)
{
    std::string out{};
    while (n)
    {
        out.insert(0, to_string(n % 2));
        n >>= 1;
    }
    while (out.length() != 32)
        out.insert(0, to_string(0));

    return out;
}

uint32_t reverseBits(uint32_t n)
{
    // uint32_t rev = 0b00000000000000000000000000000000;
    // uint32_t pad = 0;
    // for (uint32_t i = 31; n != 0; --i)
    // {
    //     pad = ((n & 1) << (i));
    //     rev |= pad;
    //     n >>= 1;
    // }

    // return rev;

    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}

int main()
{
    reverseBits(43261596);

    std::cout << "43261596 to bit string is: " << bit_string(43261596) << std::endl;
    std::cout << "43261596 bits reversed is: " << bit_string(reverseBits(43261596)) << std::endl;

    std::cout << std::endl;
    return 0;
}
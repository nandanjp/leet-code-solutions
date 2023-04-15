#include <iostream>
#include <vector>

using namespace std;

int oneBits(int n)
{
    int ones = 0;
    while (n)
    {
        ones += (n & 1);
        n >>= 1;
    }
    return ones;
}

vector<int> countBits(int n)
{
    std::vector<int> ones(n + 1);
    std::vector<int>::iterator it = ones.begin();
    for (int i = 0; it != ones.end(); ++it, ++i)
        *it = oneBits(i);
    return ones;
}

vector<int> countBits2(int n)
{
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        v[i] = v[i / 2] + i % 2;
    }
    return v;
}

void print_vec(const vector<int> &nums)
{
    std::cout << "[ ";
    for (std::vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it)
        std::cout << *it << (it != nums.end() - 1 ? ", " : "");

    std::cout << "]" << std::endl;
}

void print_vec(vector<int> &&nums)
{
    std::cout << "[ ";
    for (std::vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it)
        std::cout << *it << (it != nums.end() - 1 ? ", " : "");

    std::cout << "]" << std::endl;
}

int main()
{
    int n;
    std::cout << "Enter value of n: ";
    std::cin >> n;

    print_vec(countBits(n));

    std::cout << std::endl;
    return 0;
}
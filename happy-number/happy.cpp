#include <iostream>
#include <set>

using namespace std;

int digit_square_sum(int n)
{
    if (n == 0)
        return 0;
    return (n % 10) * (n % 10) + digit_square_sum(n / 10);
}
bool isHappy(int n)
{
    int curr_sum;
    std::set<int> sums{};

    do
    {
        curr_sum = digit_square_sum(n);
        std::cout << "curr_sum = " << curr_sum << std::endl;
        if (sums.find(curr_sum) != sums.end())
            return false;
        if (curr_sum == 1)
            return true;

        n = curr_sum;
        sums.insert(curr_sum);
    } while (curr_sum != 1);

    return false;
}

int main()
{
    std::cout << "Is 2 a happy number: " << isHappy(2) << std::endl;

    std::cout << std::endl;
    return 0;
}
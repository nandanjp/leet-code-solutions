#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    std::vector<int>::reverse_iterator i{digits.rbegin()};
    if (*i != 9)
    {
        *i += 1;
        return digits;
    }

    *i = (*i + 1) % 10;
    ++i;
    int carry = 1, curr_sum;
    while (i != digits.rend() && carry)
    {
        curr_sum = (*i) + carry;
        carry = curr_sum / 10;
        *i = curr_sum % 10;

        ++i;
    }
    if (carry)
        digits.insert(digits.begin(), 1);

    return digits;
}

void print_vec(std::vector<int> &vec)
{
    std::cout << "[";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << (it != (vec.end() - 1) ? ", " : "");
    std::cout << "]" << std::endl;
}

void print_vec(std::vector<int> &&vec)
{
    std::cout << "[";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << (it != (vec.end() - 1) ? ", " : "");
    std::cout << "]" << std::endl;
}

int main()
{
    vector<int> nums{1, 2, 9};
    print_vec(plusOne(nums));

    std::cout << std::endl;
    return 1;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int> &prices)
{
    if (prices.begin() + 1 == prices.end())
        return 0;

    int max = 0, curr;
    std::vector<int>::iterator buy = prices.begin();
    std::vector<int>::iterator sell = prices.begin() + 1;
    while (sell != prices.end())
    {
        curr = *sell - *buy;
        std::cout << "buy = " << *buy << ", sell = " << *sell << ", curr = " << curr << ", max = " << max << std::endl;
        if (curr < 0)
        {
            ++buy;
            sell = buy + 1;
        }
        else
        {
            if (curr > max)
                max = *sell - *buy;
            ++sell;
        }
    }
    return max;
}

void print_vec(const std::vector<int> &nums)
{
    std::cout << "[";
    for (std::vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it)
        std::cout << *it << (it + 1 != nums.end() ? ", " : "");
    std::cout << "]" << std::endl;
}

int main()
{
    size_t size;
    std::cout << "Enter size of the error: ";
    std::cin >> size;

    vector<int> nums;
    int num;
    std::cout << "Enter numbers into the vector..." << std::endl;

    for (size_t i = 0; i < size; ++i)
    {
        std::cin >> num;
        nums.insert(nums.end(), num);
    }
    print_vec(nums);
    int max = maxProfit(nums);
    std::cout << "Max profit from the vector given: " << max << std::endl;

    std::cout << std::endl;
    return 0;
}
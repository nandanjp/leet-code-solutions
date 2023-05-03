#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int low = 0, high = nums.size(), mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] > target)
            high = mid - 1;
        else if (nums[mid] < target)
            low = mid + 1;
    }
    if (low >= 0 && low < nums.size())
    {
        if (nums[low] < target)
            return low + 1;
    }
    return low;
}

void print_vex(const std::vector<int> &nums)
{
    std::cout << "[";
    for (std::vector<int>::const_iterator it = nums.cbegin(); it != nums.cend(); ++it)
        std::cout << *it << (it + 1 != nums.cend() ? ", " : "");
    std::cout << "]" << std::endl;
}

int main()
{

    std::cout << std::endl;
    return 0;
}
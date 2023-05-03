#include <iostream>
#include <vector>
#include <stdint.h>

using namespace std;

int search(vector<int> &nums, int target)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int16_t left{}, mid{}, right = (int16_t)nums.size() - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int search_with_iterators(vector<int> &nums, int target)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::vector<int>::iterator left = nums.begin(), right = --(nums.end());
    std::vector<int>::iterator mid;

    while (left <= right)
    {
        mid = nums.begin() + ((left - nums.begin()) + (right - nums.begin())) / 2;
        if (*mid == target)
            return mid - nums.begin();
        if (*mid < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> nums{2, 5};
    std::cout << "index of 0 in nums: " << search(nums, 0) << std::endl;

    std::cout << std::endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(const std::vector<int> &nums)
{
    std::cout << "[";
    for (std::vector<int>::const_iterator it = nums.cbegin(); it != nums.cend(); ++it)
        std::cout << *it << (it + 1 != nums.cend() ? ", " : "");
    std::cout << "]" << std::endl;
}

int majorityElement(vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    print_vec(nums);

    int curr = nums[0], num_occurs = 1, max_occurs = 1, maj = nums[0];
    size_t size = nums.size();

    for (size_t i = 1; i < size; ++i)
    {
        std::cout << "curr = " << curr << ", nums[i] = " << nums[i] << ", num_occurs = " << num_occurs << std::endl;
        if (nums[i] != curr)
        {
            if (num_occurs > max_occurs)
            {
                max_occurs = num_occurs;
                maj = curr;
            }
            curr = nums[i];
            num_occurs = 1;
        }
        else
        {
            ++num_occurs;
        }
    }
    if (num_occurs > max_occurs)
    {
        max_occurs = num_occurs;
        maj = curr;
    }
    return maj;
}
int majorityElement2(vector<int> &arr)
{
    int ele = arr[0];
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
            ele = arr[i];
        count += (ele == arr[i]) ? 1 : -1;
    }
    return ele;
}

int main()
{
    vector<int> nums{3, 2, 3};
    majorityElement(nums);
    std::cout << std::endl;
    return 0;
}
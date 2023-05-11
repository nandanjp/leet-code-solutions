#include <iostream>
#include <vector>
#include <string>

using namespace std;

string formatted_range(vector<int> &range)
{
    size_t size = range.size();
    if (size == 0)
        return "";
    if (size == 1)
        return to_string(range[0]);

    return to_string(*(range.begin())) + "->" + to_string(*(range.rbegin()));
}

vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> ranges;
    vector<int> curr_range;

    int size = nums.size() - 1, i = 0;
    size_t curr_range_sz;
    if (size < 0)
        return ranges;

    while (i < size)
    {
        curr_range.emplace_back(nums[i]);
        while (i < size && (long)nums[i + 1] == (long)(nums[i] + 1))
            ++i;

        if (curr_range[0] != nums[i])
            curr_range.emplace_back(nums[i]);
        ranges.emplace_back(formatted_range(curr_range));
        curr_range.clear();

        ++i;
    }
    if (i == size)
    {
        curr_range.emplace_back(nums[i]);
        ranges.emplace_back(formatted_range(curr_range));
    }

    return ranges;
}

template <typename T>
void printVec(const vector<T> &vec)
{
    std::cout << "[";
    for (auto i = vec.cbegin(); i != vec.cend(); ++i)
        std::cout << *i << (i + 1 != vec.cend() ? ", " : "");
    std::cout << "]" << std::endl;
}

int main()
{
    vector<int> nums{0, 2, 3, 4, 6, 8, 9};
    vector<string> ranges = summaryRanges(nums);
    printVec<string>(ranges);

    std::cout << std::endl;
    return 0;
}
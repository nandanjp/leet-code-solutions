#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <utility>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    map<int, vector<int>> num_indices;
    for (vector<int>::const_iterator it = nums.cbegin(); it != nums.cend(); ++it)
    {
        num_indices[*it].emplace_back(it - nums.cbegin());
    }

    for (auto it : num_indices)
    {
        for (vector<int>::const_iterator i = it.second.cbegin(); i != it.second.cend() - 1; ++i)
        {
            if (abs(*i - *(i + 1)) <= k)
                return true;
        }
    }
    return false;
}

bool containsNearbyDuplicate2(vector<int> &nums, int k)
{
    unordered_map<int, int> elements;
    unordered_map<int, int>::iterator found_pair;
    for (vector<int>::const_iterator it = nums.cbegin(); it != nums.cend(); ++it)
    {
        found_pair = elements.find(*it);

        if (found_pair != elements.end())
        {
            if (abs((*found_pair).second - (it - nums.cbegin())) <= k)
                return true;

            (*found_pair).second = it - nums.cbegin();
            continue;
        }
        elements.emplace(make_pair(*it, it - nums.cbegin()));
    }

    return false;
}

int main()
{
    vector<int> nums{1, 2, 3, 1};
    std::cout << std::boolalpha;
    bool contains = containsNearbyDuplicate2(nums, 2);
    std::cout << "nums containsNearbyDuplicate: " << contains << std::endl;

    std::cout << std::endl;
    return 0;
}
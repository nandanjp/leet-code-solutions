#include <iostream>
#include <string>

using namespace std;

bool isUnique(string s)
{
    int hash[128]{};
    for (char c : s)
    {
        if (hash[(int)c] != 0)
            return false;
        ++hash[(int)c];
    }
    return true;
}

int lengthOfLongestSubstring(string s)
{
    size_t length = s.length();
    int left = 0, right = length - 1;

    string curr_sub;
    int longest = 0;
    while (left < length)
    {
        curr_sub = s.substr(left, right - left + 1);
        if (isUnique(curr_sub))
        {
            if (curr_sub.length() > longest)
            {
                longest = curr_sub.length();
                ++left;
                right = length - 1;
            }
        }
        else
        {
        }
        --right;
    }
    return longest;
}

int main()
{

    std::cout << std::endl;
    return 0;
}
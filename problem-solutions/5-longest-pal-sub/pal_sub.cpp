#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string &s)
{
    size_t size = s.size();
    for (size_t i = 0; i < size / 2; ++i)
        if (s[i] != s[size - i - 1])
            return false;

    return true;
}

string longestPalindrome(string s)
{
    size_t size = s.size();
    int left = 0, right = size - 1;

    string longest = "";
    string curr_sub = "";
    while (left < size)
    {
        while (right > left && s[left] != s[right])
            --right;

        if (right < left)
        {
            ++left;
            right = size - 1;
            continue;
        }

        curr_sub = s.substr(left, right - left + 1);

        if (!isPalindrome(curr_sub))
        {
            --right;
            continue;
        }

        if (curr_sub.length() > longest.length())
        {
            longest = curr_sub;
        }
        ++left;
        right = size - 1;
    }
    return longest;
}

int main()
{

    std::cout << "Checking the string 'babad':" << std::endl;
    std::cout << longestPalindrome("babad") << std::endl;

    std::cout << "Checking the string 'cbbd':" << std::endl;
    std::cout << longestPalindrome("cbbd") << std::endl;

    std::cout << "Checking the string 'a':" << std::endl;
    std::cout << longestPalindrome("a") << std::endl;

    std::cout << "Checking the string 'aacabdkacaa':" << std::endl;
    std::cout << longestPalindrome("aacabdkacaa") << std::endl;

    std::cout << "Checking the string 'eabcb':" << std::endl;
    std::cout << longestPalindrome("eabcb") << std::endl;

    std::cout << std::endl;
    return 0;
}
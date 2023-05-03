#include <iostream>

using namespace std;

int strStr(string haystack, string needle)
{
    size_t needle_size = needle.size();
    size_t size = haystack.size() - needle_size;
    bool ret = true;
    for (size_t i = 0; i <= size; ++i)
    {
        ret = true;
        for (size_t j = 0; j < needle_size; ++j)
        {
            if (haystack[i + j] != needle[j])
            {
                ret = false;
                break;
            }
        }
        if (ret)
            return i;
    }
    return -1;
}

int main()
{

    std::cout << std::endl;
    return 0;
}
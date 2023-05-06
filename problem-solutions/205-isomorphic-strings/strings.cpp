#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

bool isIsomorphic(string s, string t)
{
    size_t s_size = s.length(), t_size = t.length();
    if (s_size != t_size)
        return false;

    std::map<char, char> t_map_s_char;

    for (size_t i = 0; i < s_size; ++i)
    {
        if (t_map_s_char.find(s[i]) == t_map_s_char.end())
        {
            t_map_s_char[s[i]] = t[i];
        }
        else if (t_map_s_char[s[i]] != t[i])
            return false;
    }

    t_map_s_char.clear();

    for (size_t i = 0; i < s_size; ++i)
    {
        if (t_map_s_char.find(t[i]) == t_map_s_char.end())
        {
            t_map_s_char[t[i]] = s[i];
        }
        else if (t_map_s_char[t[i]] != s[i])
            return false;
    }

    return true;
}

bool isIsomorphic2(string s, string t)
{
    int t_map_s_char[128] = {};
    size_t s_size = s.length();

    for (size_t i = 0; i < s_size; ++i)
    {
        if (t_map_s_char[(int)s[i]] == 0)
            t_map_s_char[(int)s[i]] = t[i];
        else if (t_map_s_char[(int)s[i]] != t[i])
            return false;
    }

    for (size_t i = 0; i < 128; ++i)
        t_map_s_char[i] = 0;

    for (size_t i = 0; i < s_size; ++i)
    {
        if (t_map_s_char[(int)t[i]] == 0)
            t_map_s_char[(int)t[i]] = s[i];
        else if (t_map_s_char[(int)t[i]] != s[i])
            return false;
    }

    return true;
}

int main()
{
    string s, t;

    std::cout << "Enter string s: ";
    std::cin >> s;
    std::cin.ignore();
    std::cout << "Enter string t: ";
    std::cin >> t;

    std::cout << std::boolalpha;
    std::cout << "s = '" << s << "' and t = '" << t << "' are isomorphic:" << std::endl;
    std::cout << isIsomorphic2(s, t) << std::endl;

    std::cout << std::endl;
    return 0;
}
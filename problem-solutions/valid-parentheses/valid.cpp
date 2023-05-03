#include <iostream>
#include <iomanip>
#include <stack>
#include <string>

using namespace std;

void print_stack(std::stack<char> s)
{
    std::cout << "[ ";
    while (!s.empty())
    {
        std::cout << s.top();
        s.pop();
        std::cout << (!s.empty() ? ", " : "");
    }
    std::cout << " ]" << std::endl;
}

bool isValid(const std::string &s)
{
    std::stack<char> st;
    std::string::const_iterator end = s.end();
    for (std::string::const_iterator i = s.begin(); i != end; ++i)
    {
        std::cout << "st.top(): " << (st.empty() ? '_' : st.top()) << ", s[i]: " << *i << std::endl;
        if (*i == ')')
        {
            if (st.empty() || st.top() != '(')
                return false;
            st.pop();
        }
        else if (*i == '}')
        {
            if (st.empty() || st.top() != '{')
                return false;
            st.pop();
        }
        else if (*i == ']')
        {
            if (st.empty() || st.top() != '[')
                return false;
            st.pop();
        }
        else
            st.emplace(*i);
    }
    return st.empty();
}

bool isValid2(string s)
{
    std::string st;
    char last;

    for (std::string::const_iterator i = s.begin(); i != s.end(); ++i)
    {
        if (*i == '(' || *i == '[' || *i == '{')
        {
            st.push_back(*i);
            continue;
        }

        if (st.begin() == st.end())
            return false;

        last = *st.rbegin();
        if (*i == ')' && last != '(')
            return false;
        if (*i == ']' && last != '[')
            return false;
        if (*i == '}' && last != '{')
            return false;

        st.pop_back();
    }
    return st.empty();
}

int main()
{
    std::string s{};
    std::cout << "Enter the string of braces: ";
    std::cin >> s;

    std::stack<char> st;
    for (const char c : s)
        st.push(c);

    print_stack(st);
    bool valid = isValid(s);
    std::cout << std::boolalpha;
    std::cout << "Is the string of braces, '" << s << "' valid: " << valid << std::endl;

    std::cout << std::endl;
    return 0;
}
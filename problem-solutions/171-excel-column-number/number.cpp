#include <iostream>
#include <string>

using namespace std;

int titleToNumber(string columnTitle)
{
    // int currDig = 0;
    // int number = 0;
    // for (string::iterator i = columnTitle.begin(); i != columnTitle.end(); ++i)
    // {
    //     number *= 26;
    //     currDig = static_cast<int>(*i) - 64;
    //     std::cout << "currDig = " << currDig << ", number = " << number << std::endl;
    //     number += currDig;
    // }
    // return number;
    int number = 0;
    for (string::iterator i = columnTitle.begin(); i != columnTitle.end(); ++i)
        number = number * 26 + (*i - 64);

    return number;
}

int main()
{
    string columnTitle;

    std::cout << "Enter the column title: ";
    std::cin >> columnTitle;

    std::cout << "'" << columnTitle << "' to number is:" << std::endl;
    std::cout << titleToNumber(columnTitle) << std::endl;

    std::cout << std::endl;
    return 0;
}
#include <iostream>
#include <string>
#include <utility>

using namespace std;

string convertToTitle(int columnNumber)
{
    if (columnNumber == 1)
        return "A";

    string column = "";
    char columnChar;
    while (columnNumber)
    {
        std::cout << "column number = " << columnNumber << std::endl;

        if (columnNumber % 26 == 0)
        {
            columnChar = 'Z';
            columnNumber -= 26;
        }
        else
        {
            columnChar = (char)(columnNumber % 26 + 64);
            columnNumber -= columnNumber % 26;
        }

        column += columnChar;
        columnNumber /= 26;
    }

    size_t size = column.size();
    for (size_t i = 0; i < size / 2; ++i)
        swap(column[i], column[size - i - 1]);

    return column;
}

int main()
{
    int columnNumber;
    std::cout << "Enter column number: ";
    std::cin >> columnNumber;

    std::cout << "Column Number " << columnNumber << " as string: " << std::endl;
    std::cout << convertToTitle(columnNumber) << std::endl;

    std::cout << std::endl;
    return 0;
}
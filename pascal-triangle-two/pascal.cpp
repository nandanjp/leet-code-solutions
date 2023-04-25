#include <iostream>
#include <vector>

using namespace std;

void print_vec(const std::vector<int> &nums);

vector<int> getRow(int rowIndex)
{
    vector<int> curr_row{1};
    vector<int> next_row;
    int i = 0, j, k, size;
    while (i < rowIndex)
    {
        next_row = std::vector<int>(curr_row.size() + 1);
        next_row[0] = 1;
        next_row[curr_row.size()] = 1;

        size = curr_row.size() - 1;
        for (j = 0; j < size; ++j)
            next_row[j + 1] = curr_row[j] + curr_row[j + 1];
        /*
                 1
                1 1
               1 2 1
              1 3 3 1
             1 4 6 4 1
           1 5 10 10 5 1
         1 6 15 20 15 6 1
        1 7 21 35 15 21 7 1
        */

        std::cout << "The " << i << "th row is:";
        print_vec(next_row);
        curr_row = next_row;
        ++i;
    }
    return curr_row;
}

vector<int> getRow2(int rowIndex)
{
    vector<int> curr_row{1};
    for (int i = 0; i < rowIndex; ++i)
    {
        for (vector<int>::iterator j = curr_row.begin(); j != curr_row.end() - 1; ++j)
            *j += *(j + 1);
        curr_row.insert(curr_row.begin(), 1);
    }

    return curr_row;
}

void print_vec(const std::vector<int> &nums)
{
    std::cout << "[";
    for (std::vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it)
        std::cout << *it << (it + 1 != nums.end() ? ", " : "");
    std::cout << "]" << std::endl;
}

int main()
{
    int row;
    std::cout << "Enter the ith row of Pascal's Triangle: ";
    std::cin >> row;

    vector<int> pascal_row = getRow(row);
    std::cout << "The " << row << "th row of Pascal's Triangle is:";
    print_vec(pascal_row);

    std::cout << std::endl;
    return 0;
}
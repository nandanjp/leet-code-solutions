#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> row{{1}};
    vector<int> newRow, prevRow;
    for (size_t i = 1; i < numRows; ++i)
    {
        newRow = {1};
        prevRow = row[i - 1];
        for (size_t j = 0; j < i - 1; ++j)
        {
            newRow.emplace_back(prevRow[j] + prevRow[j + 1]);
        }
        newRow.emplace_back(1);
        row.push_back(newRow);
    }
    return row;
}

int main()
{

    std::cout << std::endl;
    return 0;
}
#include <iostream>
#include <string>
#include <utility>

using namespace std;

void reverseStr(string &s)
{
    size_t size = s.size();
    for (size_t i = 0; i < size / 2; ++i)
        std::swap(s[i], s[size - 1 - i]);
}

string addStrings(string num1, string num2)
{
    if (num1 == "0" && num2 == "0")
        return "0";

    if (num1.size() < num2.size())
        std::swap(num1, num2);

    size_t num1_size = num1.size(), num2_size = num2.size(), i;
    for (i = 0; i < num1_size / 2; ++i)
        std::swap(num1[i], num1[num1_size - 1 - i]);
    for (i = 0; i < num2_size / 2; ++i)
        std::swap(num2[i], num2[num2_size - 1 - i]);

    string sum(num1_size + 1, '0');

    int curr_dig_num1, curr_dig_num2;
    int carry = 0, dig_sum;

    for (i = 0; i < num2_size; ++i)
    {
        curr_dig_num1 = num1[i] - 48;
        curr_dig_num2 = num2[i] - 48;

        dig_sum = (carry + curr_dig_num1 + curr_dig_num2) % 10;
        carry = (carry + curr_dig_num1 + curr_dig_num2) / 10;

        sum[i] = (char)(dig_sum + 48);
    }

    for (; i < num1_size; ++i)
    {
        curr_dig_num1 = num1[i] - 48;
        dig_sum = (carry + curr_dig_num1) % 10;
        carry = (carry + curr_dig_num1) / 10;

        sum[i] = (char)(dig_sum + 48);
    }

    if (carry != 0)
        sum[i] = (char)(carry + 48);

    for (i = 0; i < (num1_size + 1) / 2; ++i)
        std::swap(sum[i], sum[num1_size - i]);

    if (sum[0] == '0')
        sum = sum.substr(1, num1_size + 1);

    return sum;
}

int main()
{

    std::cout << "Sum of '11' and '123' is:" << std::endl;
    std::cout << addStrings("11", "123") << std::endl;

    std::cout << "Sum of '456' and '77' is:" << std::endl;
    std::cout << addStrings("456", "77") << std::endl;

    std::cout << "Sum of '0' and '0' is:" << std::endl;
    std::cout << addStrings("0", "0") << std::endl;

    std::cout << "Sum of '2' and '2' is:" << std::endl;
    std::cout << addStrings("2", "2") << std::endl;

    std::cout << "Sum of '1' and '1' is:" << std::endl;
    std::cout << addStrings("1", "1") << std::endl;

    std::cout << "Sum of '1' and '9' is:" << std::endl;
    std::cout << addStrings("1", "9") << std::endl;

    std::cout << std::endl;
    return 0;
}
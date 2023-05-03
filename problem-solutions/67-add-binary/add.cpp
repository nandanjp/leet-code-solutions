#include <iostream>
#include <iomanip>

using namespace std;

string addBinary(string a, string b)
{
    string temp;
    if (a.length() < b.length())
    {
        temp = a;
        a = b;
        b = temp;
    }

    bool carry = false;
    char a_curr, b_curr;
    size_t a_size = a.length(), b_size = b.length(), i = 0;
    string sum(a_size + 1, '0');

    char temp_c;
    for (; i < a_size / 2; ++i)
    {
        temp_c = a[a_size - i - 1];
        a[a_size - i - 1] = a[i];
        a[i] = temp_c;
    }

    for (i = 0; i < b_size / 2; ++i)
    {
        temp_c = b[b_size - i - 1];
        b[b_size - i - 1] = b[i];
        b[i] = temp_c;
    }

    std::cout << "a = " << a << ", b = " << b << std::endl
              << std::endl;

    for (i = 0; i < b_size; ++i)
    {
        a_curr = a[i];
        b_curr = b[i];

        if (a_curr == '0' && b_curr == '0')
            sum[i] = carry ? '1' : '0';
        else if (a_curr == '1' && b_curr == '1')
            sum[i] = carry ? '1' : '0';
        else
            sum[i] = carry ? '0' : '1';

        std::cout << std::boolalpha << "a_curr = " << a_curr << ", b_curr = " << b_curr << ", carry = " << carry << ", sum[i] = " << sum[i] << std::endl;

        if (a_curr == '1' && b_curr == '1')
            carry = true;
        else if (carry && (a_curr == '1' || b_curr == '1'))
            carry = true;
        else
            carry = false;
    }

    for (; i < a_size; ++i)
    {
        a_curr = a[i];

        if (a_curr == '0')
            sum[i] = carry ? '1' : '0';
        else
            sum[i] = carry ? '0' : '1';

        std::cout << std::boolalpha << "a_curr = " << a_curr << ", carry = " << carry << ", sum[i] = " << sum[i] << std::endl;

        if (a_curr == '1' && carry)
            carry = true;
        else
            carry = false;
    }

    if (carry)
        sum[a_size] = '1';

    std::cout << std::boolalpha << "carry = " << carry << ", sum[a_size] = " << sum[a_size] << std::endl;

    for (i = 0; i < (a_size + 1) / 2; ++i)
    {
        temp_c = sum[a_size - i];
        sum[a_size - i] = sum[i];
        sum[i] = temp_c;
    }

    i = 0;
    while (sum[i] == '0' && sum.length() > 1)
    {
        sum = sum.substr(1, a_size + 1);
    }

    return sum;
}

int main()
{
    std::cout << "Sum of '11' and '1' is: " << std::endl
              << addBinary("11", "1") << std::endl;
    std::cout << "Sum of '1010' and '1011' is: " << std::endl
              << addBinary("1010", "1011") << std::endl;

    std::cout << std::endl;
    return 0;
}
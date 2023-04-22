#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x)
{
  if (x < 0)
    return false;

  std::vector<int> digits;
  while (x)
  {
    digits.emplace_back(x % 10);
    std::cout << "x % 10 = " << x << " % 10 = " << x % 10 << std::endl;
    x /= 10;
  }
  int i = 0, j = digits.size() - 1;
  while (i < j)
  {
    if (digits[i] != digits[j])
      return false;
    ++i, --j;
  }
  return true;
}

bool isPalindrome2(int x)
{
  if (x < 0)
    return false;

  int rev = 0, x_cop = x;
  while (x)
  {
    rev += x % 10;
    x /= 10;
    rev *= 10;
    std::cout << "rev = " << rev << ", x = " << x << std::endl;
  }
  rev /= 10;
  std::cout << "rev = " << rev << ", x = " << x << std::endl;
  return rev == x_cop;
}

int main()
{
  std::cout << std::boolalpha;
  std::cout << "121 is palindrome: " << isPalindrome2(121) << std::endl;
  std::cout << "-121 is palindrome: " << isPalindrome2(-121) << std::endl;
  std::cout << "12121 is palindrome: " << isPalindrome2(12121) << std::endl;

  std::cout << std::endl;
  return 0;
}

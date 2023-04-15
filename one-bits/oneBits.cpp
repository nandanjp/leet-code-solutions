#include <iostream>
#include <stdint.h>

int hammingWeight(uint32_t n)
{
  int num_ones=0;

  while(n)
    {
      if(n&1) ++num_ones;
      n >>= 1;
    }
  return num_ones;
}

int main()
{
  int n{4};
  std::cout << "n = 4 >> 1 should be: " << "4 >> 1 = " << "2" << std::endl;
  std::cout << "4 >> 1 = " << (4 >> 1) << std::endl;

  std::cout << std::endl;
  return 0;
}

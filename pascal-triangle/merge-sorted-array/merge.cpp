#include <iostream>
#include <vector>

using namespace std;

void merge_naive(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  vector<int> merged;
  int i = 0, j = 0;
  while (i < m && j < n)
  {
    if (nums1[i] <= nums2[j])
      merged.push_back(nums1[i++]);
    else
      merged.push_back(nums2[j++]);
  }

  while (i < m)
    merged.push_back(nums1[i++]);
  while (j < n)
    merged.push_back(nums2[j++]);

  size_t size = merged.size();
  for (size_t i = 0; i < size; ++i)
    nums1[i] = merged[i];
}

void print_vec(const vector<int> &nums)
{
  std::cout << "[";
  for (vector<int>::const_iterator i = nums.begin(); i != nums.end(); ++i)
    std::cout << *i << (i + 1 != nums.end() ? ", " : "");

  std::cout << "]" << std::endl;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  int curr = m - 1;
  int i;
  int j = 0;

  std::cout << "Starting nums1: ";
  print_vec(nums1);
  std::cout << "Starting nums2: ";
  print_vec(nums2);

  while (curr < (m + n) && j < n)
  {
    i = curr;
    while (nums1[i] > nums2[j] && i > 0)
    {
      nums1[i + 1] = nums1[i];
      std::cout << "nums1: ";
      print_vec(nums1);
      std::cout << "i = " << i << ", j = " << j << std::endl;
      --i;
    }
    nums1[i] = nums2[j];

    std::cout << "nums1: ";
    print_vec(nums1);
    ++curr;
    ++j;
  }
}

int main()
{
  vector<int> nums1{1, 2, 3, 0, 0, 0};
  vector<int> nums2{2, 3, 5};
  merge(nums1, 3, nums2, 3);
  print_vec(nums1);

  std::cout << std::endl;
  return 0;
}

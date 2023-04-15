#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

// int singleNumber(vector<int> &nums)
// {
//     int size = nums.size();
//     if (size == 1)
//         return *(nums.begin());

//     int sum = 0;
//     int min = *(std::min_element(nums.begin(), nums.end()));
//     int max = *(std::max_element(nums.begin(), nums.end()));

//     std::accumulate(nums.begin(), nums.end(), sum);

//     // Bit manipulations:
//     // sum = 2 * (partial_sum) + x, where x is the single element only
//     // shifted_sum_right = sum >> 1 = (partial_sum) + x // 2
//     // shifted_sum_left = shifted_sum_right << 1 = 2 *(partial_sum) + 2 * (x // 2)
//     // thus, sum - shifted_sum_left = x - 2 * (x // 2) = 1
//     // thus, x - 2floor(x/2) = 1,
//     // if x is odd, we get = 1
//     // if x is even, we get = 0

//     int shifted_sum = (sum >> 1);
//     shifted_sum <<= 1;

//     int x = min;
//     if (min % 2) // odd
//     {
//         if (sum - shifted_sum == 0) // 0, thus x is even
//             x = min + 1;            // make x even
//         // otherwise, x is odd so start at min...
//     }
//     else
//     {                          // even
//         if (sum - shifted_sum) // 1, thus x is odd
//             x = min + 1;       // make x odd
//         // otherwise, x is even so start at min...
//     }

//     while (x <= max)
//     {
//         if (std::find(nums.begin(), nums.end(), x) != nums.end())
//         {
//             break;
//         }
//         x += 2;
//     }
//     return x;
// }

int singleNumber(vector<int> &nums)
{
    // eg. [1, 2, 1, 2, 3, 4, 3, 4, 5]
    // xor throughout the list:
    // xor = 0, xor ^ 1 = 1
    // xor ^ 2 = 2
    // xor ^ 1 = 1
    // xor ^ 2 = 2

    int x = 0;
    for (int i : nums)
        x ^= i;
    return x;
}

int main()
{
    // sum = 3 + 3 + 7 + 7 + 5 = 2 * (3 + 7) + 5 = 25
    // (25 - (25 >> 2))/2 = ?
    // sum = 2 * (partial_sum) + x, where x is the single element only
    // shifted_sum_right = sum >> 1 = (partial_sum) + x // 2
    // shifted_sum_left = shifted_sum_right << 1 = 2 *(partial_sum) + 2 * (x // 2)
    // thus, sum - shifted_sum_left = x - 2 * (x // 2) = 1
    // thus, x - 2floor(x/2) = 1,

    // std::cout << (2 * 22 + 9) << std::endl;
    // std::cout << ((2 * 22 + 9) >> 1) << std::endl;
    // std::cout << (((2 * 22 + 9) >> 1) << 1) << std::endl
    //           << std::endl;

    // when the number is odd, the difference between the two when shifting is 1

    // std::cout << (2 * 22 + 8) << std::endl;
    // std::cout << ((2 * 22 + 8) >> 1) << std::endl;
    // std::cout << (((2 * 22 + 8) >> 1) << 1) << std::endl;
    // when the number is even, the difference between the two when shifting is 0

    std::vector<int> nums{1, 2, 1, 2, 3, 4, 3, 4, 5};
    // sum = 3 * 10 + 5 = 25
    // sum >> 1 = 3 * 5 + 5 // 2
    // sum << 1 = 3 * 10 + 4
    // thus, sum - shifted = 1, x is odd
    // start at min, 1
    std::cout << "single number in nums: " << singleNumber(nums) << std::endl;

    std::cout << std::endl;
    return 0;
}
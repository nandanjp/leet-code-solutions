#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int maxArea(vector<int> &height)
{
	size_t size = height.size();
	size_t left = 0, right = size - 1;
	int area = -1, currArea;
	while (left < right)
	{
		currArea = std::min(height[left], height[right]) * (right - left);

		area = std::max(area, currArea);
		if (height[left] > height[right])
			--right;
		else
			++left;
	}
	return area;
}

int main()
{
	vector<int> heights{1, 8, 6, 2, 5, 4, 8, 3, 7};
	int maxA = maxArea(heights);

	std::cout << "Max Area of Water Possible is: " << maxA << std::endl;

	std::cout << std::endl;
	return 0;
}

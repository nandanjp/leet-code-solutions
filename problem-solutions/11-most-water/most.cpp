#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int maxArea(vector<int> &height)
{
	size_t size = height.size();
	if (size == 2)
		return height[0] > height[1] ? height[1] : height[0];

	size_t left = 0, right = size - 1;
	int area = -1, currArea, nextArea;

	while (left < right)
	{
		currArea = (right - left) * (height[left] > height[right] ? height[right] : height[left]);
		if (abs(currArea) > area)
			area = currArea;

		nextArea = (right - left - 1) * (height[left + 1] > height[right] ? height[right] : height[left + 1]);

		if (abs(nextArea) > area)
			++left, right = size - 1;
		else
			--right, left = 0;

		std::cout << "left = " << left << ", right = " << right << ", currArea = " << currArea << ", nextArea = " << nextArea << ", area = " << area << std::endl;
	}

	return area;
}

int main()
{
	vector<int> heights{2, 3, 4, 5, 18, 17, 6};
	int maxA = maxArea(heights);

	std::cout << "Max Area of Water Possible is: " << maxA << std::endl;

	std::cout << std::endl;
	return 0;
}

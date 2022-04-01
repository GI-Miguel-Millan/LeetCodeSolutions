// 0017-RotateArray.cpp : Source file for your target.
//

#include "0017-RotateArray.h"
#include "Utilities.h"

#include <vector>
#include <iostream>

void rotateInPlace(std::vector<int>& nums, int k)
{
	k = k % nums.size();
	std::reverse(nums.begin(), nums.end());
	std::reverse(nums.begin(), nums.begin() + k);
	std::reverse(nums.begin() + k, nums.end());
}

void rotateGuarenteed(std::vector<int>& nums, int k)
{
	if (k >= nums.size())
		k = k % nums.size();

	if (k == 0) return;

	std::vector<int> numsCopy(nums.begin(), nums.end());

	int target;
	for (int i = 0; i < nums.size(); i++)
	{
		target = i + k;
		if (target >= nums.size())
			target -= (int)nums.size();

		nums[target] = numsCopy[i];
	}

}

void testRotationValues(std::vector<int>& nums, int maxK)
{
	for (int i = 0; i < maxK; i++)
	{
		std::vector<int> expected(nums.begin(), nums.end());
		std::vector<int> actual(nums.begin(), nums.end());

		rotateInPlace(actual, i);
		rotateGuarenteed(expected, i);

		std::cout << "Test: " << Utilities::GetString(nums) << ", " << i << ": ";

		std::string result = Utilities::Equals(expected, actual) ? "Pass" : "Fail";
		std::cout << result << ": Expected: " << Utilities::GetString(expected) << ", Actual: " << Utilities::GetString(actual) << std::endl;
	}
}

int main()
{
	std::vector<int> nums1 = { 1, 2};
	std::vector<int> nums2 = {1, 2, 3};
	std::vector<int> nums3 = {1, 2, 3, 4};
	std::vector<int> nums4 = {1, 2, 3, 4, 5};
	std::vector<int> nums5 = {1, 2, 3, 4, 5, 6};

	testRotationValues(nums1, 2);
	testRotationValues(nums2, 3);
	testRotationValues(nums3, 5);
	testRotationValues(nums4, 8);
	testRotationValues(nums5, 8);
	return 0;
}

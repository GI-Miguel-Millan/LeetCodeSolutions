// 0017-RotateArray.cpp : Source file for your target.
//

#include "0017-RotateArray.h"
#include "Utilities.h"

#include <vector>
#include <iostream>

void xrotate(std::vector<int>& nums, int k)
{
	if (k >= nums.size())
		k = k % nums.size();

	if (k == 0) return;

	int bucket = nums[0];
	int targetIndex = 0;
	bool needsAdjustment = (nums.size() % k == 0);
	for (int i = 0; i < nums.size(); i++)
	{
		targetIndex += k;
		if (targetIndex >= nums.size())
		{ 
			targetIndex -= (int)nums.size();
			if (needsAdjustment)
			{
				nums[targetIndex] = bucket;
				targetIndex++;
				bucket = nums[targetIndex];
			}
			else
			{
				std::swap(bucket, nums[targetIndex]);
			}
			continue;
		}
			
		std::swap(bucket, nums[targetIndex]);
	}
}

void rotate(std::vector<int>& nums, int k)
{
	if (k >= nums.size())
		k = k % nums.size();

	if (k == 0) return;



	int startIndex = k;
	int targetIndex;
	int bucket = nums[startIndex];
	for (int i = 0; i < nums.size(); i++)
	{
		targetIndex = startIndex + 1;
		if (targetIndex >= nums.size())
			targetIndex -= nums.size();

		std::swap(bucket, nums[targetIndex]);

		startIndex++;
		if (startIndex >= nums.size())
			startIndex -= nums.size();
	}
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

		rotate(actual, i);
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

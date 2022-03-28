// 0012-Array-Partition1.cpp : Source file for your target.
//

#include "0012-Array-Partition1.h"
#include <algorithm>
#include <vector>

int arrayPairSum(std::vector<int>& nums)
{
	std::sort(nums.begin(), nums.end());

	int sum = 0;
	for (int i = 0; i < nums.size(); i += 2)
		sum += nums[i];

	return sum;
}

int main()
{
	
	return 0;
}

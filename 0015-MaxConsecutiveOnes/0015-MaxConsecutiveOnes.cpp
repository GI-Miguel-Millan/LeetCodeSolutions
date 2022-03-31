// 0015-MaxConsecutiveOnes.cpp : Source file for your target.
//

#include "0015-MaxConsecutiveOnes.h"
#include <vector>

int findMaxConsecutiveOnes(std::vector<int>& nums)
{
	if (nums.size() == 1 && nums[0] == 1) return 1;
	int j = -1;
	int i = 0;
	int maxCount = 0;
	while (i < nums.size())
	{
		if (nums[i] == 1 && j == -1)
		{
			j = i;
		}
		while (i < nums.size() && nums[i] == 1)
		{
			i++;
		}

		if (j > -1 && maxCount < i - j)
			maxCount = i - j;

		i++;
		j = -1;
	}

	return maxCount; 
}

int main()
{
	return 0;
}

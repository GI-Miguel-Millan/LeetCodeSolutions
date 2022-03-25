// 0004-LargestNumberTwiceOthers.cpp : Source file for your target.
//

#include "0004-LargestNumberTwiceOthers.h"
#include <vector>
#include <iostream>

int dominantIndex(std::vector<int>& nums)
{
    if (nums.size() == 1) return 0;

    int largestIndex = 0;
    int secondLargestIndex = 1;
    if (nums[0] < nums[1])
    {
        largestIndex = 1;
        secondLargestIndex = 0;
    }

    for (int i = 2; i < nums.size(); i++)
    {
        if (nums[i] > nums[largestIndex])
        {
            secondLargestIndex = largestIndex;
            largestIndex = i;
            continue;
        }

        if (nums[i] > nums[secondLargestIndex])
            secondLargestIndex = i;
    }

    return (nums[largestIndex] >= 2 * nums[secondLargestIndex]) ? largestIndex : -1;
}


int main()
{
    std::vector<int> test1 = { 3, 6, 1, 0 };
    std::vector<int> test2 = { 1, 2, 3, 4 };
    std::vector<int> test3 = { 1 };

    std::cout << "Expected: 1, Actual: " << dominantIndex(test1) << std::endl;
    std::cout << "Expected: -1, Actual: " << dominantIndex(test2) << std::endl;
    std::cout << "Expected: 0, Actual: " << dominantIndex(test3) << std::endl;
	return 0;
}

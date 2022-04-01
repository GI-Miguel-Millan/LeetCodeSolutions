// 0016-MinimumSizeSubArraySum.cpp : Source file for your target.
//

#include "0016-MinimumSizeSubArraySum.h"
#include <vector>
#include <limits>

int minSubArrayLen(int target, std::vector<int>& nums)
{
    if (nums.size() == 1) return nums[0] >= target ? 1 : 0;

    int i = -1;
    int j = 0;
    int minCount = INT_MAX;
    int sum = 0;
    int lastElementIndex = nums.size() - 1;
    while (true)
    {
        if (i < lastElementIndex)
        {
            i++;
            sum += nums[i];
        }
        else if (j < lastElementIndex)
        {
            sum -= nums[j];
            j++;
        }
        else
        {
            break;
        }

        while (sum >= target)
        {
            if (i - j + 1 < minCount)
                minCount = i - j + 1;
            sum -= nums[j];
            j++;
        }
    }

    return minCount == INT_MAX ? 0 : minCount;
}

int main()
{
    std::vector<int> nums = { 2, 3, 1, 2, 4,3 };
    std::vector<int> nums2 = { 1, 2, 3, 4, 5};

    bool test1 = -1 < nums.size(); // evaluates to false, because -1 gets converted to an unsigned integer (really large). 
    bool test2 = nums.size() > -1; //also evaluates to false, same reason
    bool test3 = -1 < (int)nums.size(); // evalutates to true, since we will not be performing a signed integer comparison

    int val = minSubArrayLen(7, nums);
    int val2 = minSubArrayLen(15, nums2);
	return 0;
}

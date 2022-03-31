// 0014-RemoveElement.cpp : Source file for your target.
//

#include "0014-RemoveElement.h"
#include <vector>

int removeElement(std::vector<int>& nums, int val)
{
    int j = nums.size() - 1;
    int i = 0;
    while (i <= j)
    {
        if (nums[i] == val)
        {
            std::swap(nums[i], nums[j]);
            j--;
            continue;
        }

        i++;
    }

    return j + 1;
}


int main()
{
	return 0;
}

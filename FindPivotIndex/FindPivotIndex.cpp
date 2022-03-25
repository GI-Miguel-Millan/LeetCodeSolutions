// FindPivotIndex.cpp : Source file for your target.
//

#include "FindPivotIndex.h"
#include <vector>
#include <iostream>

using namespace std;

int pivotIndex(vector<int>& nums)
{
    /*if (nums.size() == 1) return 0;

    int leftSum = 0;
    int rightSum = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        rightSum += nums[i];
    }

    int i = 0;
    while (true)
    {
        if (leftSum == rightSum) return i;

        i++;
        if (i == nums.size()) return -1;

        leftSum += nums[i - 1];
        rightSum -= nums[i];
    }*/

    if (nums.size() == 1) return 0;
    if (nums.size() == 2)
    {
        if (nums[1] == 0) return 0;
        if (nums[0] == 0) return 1;
        return -1;
    }

    int lastIndex = nums.size() - 1;
    for (int i = 1; i < nums.size()-1; i++)
    {
        nums[lastIndex] += nums[i];
    }

    if (nums[lastIndex] == 0) return 0;

    nums[lastIndex] -= nums[1];

    int i = 1;
    while (true)
    {
        if (nums[i - 1] == nums[lastIndex]) return i;

        i++;
        if (i == nums.size()) return -1;

        nums[i - 1] += nums[i - 2];
        nums[lastIndex] -= nums[i];
    }
}

int main()
{
    vector<int> test1 = { 1, 7, 3, 6, 5,6 };
    vector<int> test2 = { 1, 2, 3 };
    vector<int> test3 = { 2, 1, -1 };
    vector<int> test4 = { -1, -1, 0, 1, 1, 0 };

    cout << "Expected: 3, Actual: " << pivotIndex(test1) << endl;
    cout << "Expected: -1, Actual: " << pivotIndex(test2) << endl;
    cout << "Expected: 0, Actual: " << pivotIndex(test3) << endl;
    cout << "Expected: 5, Actual: " << pivotIndex(test4) << endl;
	return 0;
}

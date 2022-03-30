// 0013-Two-Sum-II-Input-Array-Sorted.cpp : Source file for your target.
//

#include "0013-Two-Sum-II-Input-Array-Sorted.h"
#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
    if (numbers.size() == 2)
    {
        numbers.clear();
        numbers.push_back(1);
        numbers.push_back(2);
        return numbers;
    }

    int high = numbers.size() - 1;
    int low = 0;

    bool sumFound = false;
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        high = numbers.size() - 1;
        low = i;

        if (numbers[high] + numbers[low] == target)
            break;

        int mid = (high - low) / 2 + low;
        while (mid > low && mid < high)
        {
            int sum = numbers[mid] + numbers[i];
            if (sum == target)
            {
                sumFound = true;
                break;
            }

            if (sum > target)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }

            mid = (high - low) / 2 + low;
        }

        if (sumFound)
        {
            low = i;
            high = mid;
            break;
        }
    }

    numbers.clear();
    numbers.push_back(low + 1);
    numbers.push_back(high + 1);
    return numbers;
}

int main()
{
    std::vector<int> numbers = { 3, 24, 50, 79, 88, 150, 345 };
    twoSum(numbers, 200);
	return 0;
}

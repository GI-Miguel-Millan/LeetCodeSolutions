// 0013-Two-Sum-II-Input-Array-Sorted.cpp : Source file for your target.
//

#include "0013-Two-Sum-II-Input-Array-Sorted.h"
#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target)
{

    int low = 0;
    int high = numbers.size() - 1;
    int sum = numbers[low] + numbers[high];

    while (sum != target)
    {
        if (sum > target)
        {
            high--;
        }
        else
        {
            low++;
        }

        sum = numbers[low] + numbers[high];
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

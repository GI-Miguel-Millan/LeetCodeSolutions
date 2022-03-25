// 0005-Plus-One.cpp : Source file for your target.
//

#include "0005-Plus-One.h"
#include <vector>
#include <iostream>

std::vector<int> plusOne(std::vector<int>& digits)
{
    int index = digits.size() - 1;
    digits[index]++;
    for (; index > 0; index--)
    {
        if (digits[index] == 10)
        {
            digits[index] -= 10;
            digits[index - 1]++;
            continue;
        }
        break;
    }

    if (digits[0] == 10)
    {
        digits[0] -= 10;
        digits.insert(digits.begin(), 1);
    }

    return digits;
}

void print(std::vector <int> const& a)
{
    std::cout << "[ ";

    for (int i = 0; i < a.size(); i++)
        std::cout << a.at(i) << ',';

    std::cout << " ]" << std::endl;
}

int main()
{
    std::vector<int> test1 = { 1, 2, 3 };
    std::vector<int> test2 = { 4, 3, 2, 1 };
    std::vector<int> test3 = { 9 };

    std::cout << "Expected: [1, 2, 4], Actual: "; print(plusOne(test1));
    std::cout << "Expected: [ 4, 3, 2, 2], Actual: "; print(plusOne(test2));
    std::cout << "Expected: [1, 0], Actual: "; print(plusOne(test3));
	return 0;
}

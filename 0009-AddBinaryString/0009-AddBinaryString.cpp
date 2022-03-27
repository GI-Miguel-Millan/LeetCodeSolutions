// 0009-AddBinaryString.cpp : Source file for your target.
//

#include "0009-AddBinaryString.h"
#include <string>
#include <math.h>
#include <limits>
#include <iostream>

std::string addBinary(std::string a, std::string b)
{
	std::string result;

	int aIndex = a.size() - 1;
	int bIndex = b.size() - 1;
	int carry = 0;

	while (aIndex >= 0 || bIndex >= 0 || carry > 0)
	{
		int aVal = 0, bVal = 0;

		if (aIndex >= 0)
		{
			aVal = a[aIndex] == '1' ? 1 : 0;
			aIndex--;
		}

		if (bIndex >= 0)
		{
			bVal = b[bIndex] == '1' ? 1 : 0;
			bIndex--;
		}

		int sum = aVal + bVal + carry;
		char digit = (sum % 2 == 0) ? '0' : '1';
		result = digit + result;
		carry = sum >> 1;
	}

	return result;
}

int main()
{
	std::cout << "1001 + 1111 = " << addBinary("1001", "1111") << std::endl;
	std::cout << "1 + 11 = " << addBinary("1", "11") << std::endl;
	std::cout << "1010 + 1011 = " << addBinary("1010", "1011") << std::endl;
	std::cout << "1 + 111 = " << addBinary("1", "111") << std::endl;
	std::cout << "100 + 110010 = " << addBinary("100", "110010") << std::endl;
	return 0;
}

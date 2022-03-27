// 0009-AddBinaryString.cpp : Source file for your target.
//

#include "0009-AddBinaryString.h"
#include <string>
#include <math.h>
#include <limits>
#include <iostream>

std::string addBinary(std::string a, std::string b)
{
	std::string longerString = a;
	std::string shorterString = b;
	std::string result;

	if (a.size() < b.size())
	{
		longerString = b;
		shorterString = a;
	}

	int carry = 0;
	int longerStringIndex = longerString.size() - 1;
	for (int i = shorterString.size() - 1; i >= 0; i--, longerStringIndex--)
	{
		int lVal = longerString[longerStringIndex] == '1' ? 1 : 0;
		int sVal = shorterString[i] == '1' ? 1 : 0;
		int digitSum = lVal + sVal + carry;

		result += (digitSum % 2 == 0) ? '0' : '1';
		carry = digitSum >> 1;
	}

	while (longerStringIndex >= -1)
	{
		if (longerStringIndex < 0)
		{
			if (carry == 1)
				result += "1";
			break;
		}

		int lVal = longerString[longerStringIndex] == '1' ? 1 : 0;
		int digitSum = lVal + carry;

		result += (digitSum % 2 == 0) ? '0' : '1';
		carry = digitSum >> 1;

		longerStringIndex--;
	}

	int halfPoint = result.size() / 2;
	for (int i = 0, j = result.size() - 1; i < halfPoint; i++, j--)
		std::swap(result[i], result[j]);

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

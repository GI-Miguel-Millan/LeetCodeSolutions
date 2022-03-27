// 0009-AddBinaryString.cpp : Source file for your target.
//

#include "0009-AddBinaryString.h"
#include <string>
#include <math.h>
#include <limits>
#include <iostream>

int parseBinary(std::string str)
{
	int decimalValue = 0;
	int power = 0;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] == '1')
			decimalValue += pow(2, power);
		power++;
	}
	return decimalValue;
}

std::string toBinaryString(int decimalValue)
{
	if (decimalValue == 0) return "0";
	std::string str;

	int numBits = std::numeric_limits<int>::digits;
	for (int i = 0; i < numBits; i++)
	{
		if (decimalValue & 1)
			str += "1";
		else
			str += "0";

		decimalValue = decimalValue >> 1;

		if (decimalValue == 0)
			break;
	}

	int halfPoint = str.size() / 2;
	for (int i = 0, j = str.size() - 1; i < halfPoint; i++, j--)
		std::swap(str[i], str[j]);

	return str;
}

std::string addBinary(std::string a, std::string b)
{
	int aVal = parseBinary(a);
	int bVal = parseBinary(b);
	return toBinaryString(aVal + bVal);
}

int main()
{
	std::cout << "1001 + 1111 = " << addBinary("1001", "1111") << std::endl;
	return 0;
}

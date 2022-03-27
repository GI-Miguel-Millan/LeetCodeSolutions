// 0010-Implement-strStr.cpp : Source file for your target.
//

#include "0010-Implement-strStr.h"
#include <string>

int strStr(std::string haystack, std::string needle)
{
	if (needle.size() == 0) return 0;
	if (haystack.size() < needle.size()) return -1;

	int i = 0;
	int j = 0;
	do
	{
		while (haystack[i + j] == needle[j])
		{
			if (j == needle.size() - 1)
				return i;

			j++;
		}

		i++;
		j = 0;
	} while (i < haystack.size() - needle.size());

	return -1;
}

int main()
{
	return 0;
}

// 0011-Longest-Common-Prefix.cpp : Source file for your target.
//

#include "0011-Longest-Common-Prefix.h"
#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
	if (strs.size() == 1) return strs[0];

	std::string shortestString = strs[0];
	for (auto str : strs)
	{
		if (str.size() < shortestString.size())
			shortestString = str;
	}

	std::string prefix = "";
	for (int i = 0; i < shortestString.size(); i++)
	{
		for (auto str : strs)
		{
			if (str[i] != shortestString[i])
				return prefix;
		}

		prefix += shortestString[i];
	}

	return prefix;
}

int main()
{
	return 0;
}

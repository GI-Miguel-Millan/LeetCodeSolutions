// 0011-Longest-Common-Prefix.cpp : Source file for your target.
//

#include "0011-Longest-Common-Prefix.h"
#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
	if (strs.size() == 1) return strs[0];

	std::string prefix = "";
	for (int i = 0; i < strs[0].size(); i++)
	{
		for (int j = 1; j < strs.size(); j++)
		{
			if (i == strs[j].size() || strs[j][i] != strs[0][i])
				return prefix;
		}

		prefix += strs[0][i];
	}

	return prefix;
}

int main()
{
	return 0;
}

// DisjointSet-Provinces.cpp : Source file for your target.
//

#include "DisjointSet-Provinces.h"
#include <iostream>

int main()
{
	std::vector<std::vector<int>> isConnected1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
	std::vector<std::vector<int>> isConnected2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	std::vector<std::vector<int>> isConnected3 = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};

	ProvinceUnionizer test1(isConnected1);
	ProvinceUnionizer test2(isConnected2);
	ProvinceUnionizer test3(isConnected3);

	std::cout << "Expected: 2, Actual: " << test1.GetProvinceCount() << std::endl;
	std::cout << "Expected: 3, Actual: " << test2.GetProvinceCount() << std::endl;
	std::cout << "Expected: 1, Actual: " << test3.GetProvinceCount() << std::endl;

	return 0;
}

ProvinceUnionizer::ProvinceUnionizer(std::vector<std::vector<int>>& isConnected)
{
	int size = isConnected.size();
	this->provinceCount = size;

	for (int i = 0; i < size; i++) 
	{
		this->parentNodes.push_back(i);
		this->ranks.push_back(1);
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (isConnected[i][j] == 1)
			{
				Union(i, j);
			}
		}
	}
}

void ProvinceUnionizer::Union(int i, int j)
{
	int iRoot = FindRootOf(i);
	int jRoot = FindRootOf(j);

	if (iRoot == jRoot) return;

	this->provinceCount--;

	if (ranks[iRoot] > ranks[jRoot])
	{
		this->parentNodes[jRoot] = iRoot;
		return;
	}

	if (ranks[iRoot] < ranks[jRoot])
	{
		this->parentNodes[iRoot] = jRoot;
		return;
	}

	this->parentNodes[jRoot] = iRoot;
	this->ranks[iRoot]++;
}

int ProvinceUnionizer::FindRootOf(int i)
{
	if (i == this->parentNodes[i])
		return i;
	this->parentNodes[i] = FindRootOf(this->parentNodes[i]);
	return this->parentNodes[i];
}


// 0008-Pascals-Triangle.cpp : Source file for your target.
//

#include "0008-Pascals-Triangle.h"

#include <vector>
#include <iostream>

std::vector<int> GenerateRow(int rowNum, std::vector<int> previousRow)
{
	std::vector<int> row = { 1 };
	for (int i = 1; i < rowNum - 1; i++)
	{
		row.push_back(previousRow[i] + previousRow[i - 1]);
	}
	row.push_back(1);

	return row;
}

std::vector<std::vector<int>> generate(int numRows)
{
	std::vector<std::vector<int>> pascalsTriangle = { {1} };
	if (numRows == 1) return pascalsTriangle;

	pascalsTriangle.push_back({ 1, 1 });

	for (int i = 2; i < numRows; i++)
		pascalsTriangle.push_back(GenerateRow(i + 1, pascalsTriangle.back()));

	return pascalsTriangle;
}

int main()
{
	return 0;
}

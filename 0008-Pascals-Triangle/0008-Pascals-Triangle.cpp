// 0008-Pascals-Triangle.cpp : Source file for your target.
//

#include "0008-Pascals-Triangle.h"

#include <vector>
#include <iostream>

std::vector<int> GenerateRow(int rowNum, std::vector<int> previousRow)
{
	std::vector<int> row = { 1 };

	int remainder = rowNum % 2 == 0 ? 0 : 1;

	int halfPoint = rowNum / 2 + remainder;
	for (int i = 1; i < halfPoint; i++)
	{
		row.push_back(previousRow[i] + previousRow[i - 1]);
	}

	for (int i = halfPoint - 1 - remainder; i >= 0; i--)
	{
		row.push_back(row[i]);
	}

	return row;
}

std::vector<std::vector<int>> generate(int numRows)
{
	std::vector<std::vector<int>> pascalsTriangle = { {1} };
	if (numRows == 1) return pascalsTriangle;

	pascalsTriangle.push_back({ 1, 1 });
	if (numRows == 2) return pascalsTriangle;

	pascalsTriangle.push_back({ 1, 2, 1 });

	for (int i = 3; i < numRows; i++)
		pascalsTriangle.push_back(GenerateRow(i + 1, pascalsTriangle.back()));

	return pascalsTriangle;
}

void print(std::vector<std::vector<int>> const& a)
{
	std::cout << "[ ";

	for (int i = 0; i < a.size(); i++)
	{
		std::cout << "[ ";
		for (int j = 0; j < a[i].size(); j++)
			std::cout << a[i][j] << ',';
		std::cout << " ]";
	}

	std::cout << " ]" << std::endl;
}

int main()
{
	print(generate(10));
	return 0;
}

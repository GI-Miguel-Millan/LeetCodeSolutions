// 0007-SpiralMatrix.cpp : Source file for your target.
//

#include "0007-SpiralMatrix.h"
#include <vector>
#include <iostream>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	int len = m * n;

	int row = 0, rowStart = 0, rowEnd = m - 1;
	int col = 0, colStart = 0, colEnd = n - 1;

	vector<int> spiral;

	enum class state
	{
		right, down, left, up
	};

	state direction = state::right;
	for (int i = 0; i < len; i++)
	{
		spiral.push_back(matrix[row][col]);

		switch (direction)
		{
		case state::right:
			if (col == colEnd)
			{
				row++;
				rowStart++;
				direction = state::down;
				continue;
			}

			col++;
			break;
		case state::down:
			if (row == rowEnd)
			{
				col--;
				colEnd--;
				direction = state::left;
				continue;
			}

			row++;
			break;
		case state::left:
			if (col == colStart)
			{
				row--;
				rowEnd--;
				direction = state::up;
				continue;
			}

			col--;
			break;
		case state::up:
			if (row == rowStart)
			{
				col++;
				colStart++;
				direction = state::right;
				continue;
			}

			row--;
			break;
		}
	}

	return spiral;
}

void print(std::vector<int> const& a)
{
	std::cout << "[ ";

	for (int i = 0; i < a.size(); i++)
		std::cout << a.at(i) << ',';

	std::cout << " ]" << std::endl;
}


int main()
{
	std::vector<std::vector<int>> test1 = { {1,2,3}, {4, 5, 6}, {7, 8, 9} };
	std::vector<std::vector<int>> test2 = { {1} };
	std::vector<std::vector<int>> test3 = { {1, 2} };
	std::vector<std::vector<int>> test4 = { {1}, {2} };

	std::vector<std::vector<int>> test5 = { {1, 2}, {3,4} };
	std::vector<std::vector<int>> test6 = { {1, 2, 3}, {4, 5, 6}, {7, 8 ,9}, {10, 11, 12} };
	std::vector<std::vector<int>> test7 = { {1, 2 , 3, 4, 5}, {6, 7, 8 ,9, 10}, {11, 12, 13, 14, 15 } };

	std::vector<std::vector<int>> test8 = { {1}, {2}, {3} };

	std::cout << "Expected [1, 2, 3, 6, 9, 8, 7, 4, 5], Actual: "; print(spiralOrder(test1));
	std::cout << "Expected [1], Actual: "; print(spiralOrder(test2));
	std::cout << "Expected [1, 2], Actual: "; print(spiralOrder(test3));
	std::cout << "Expected [1, 2], Actual: "; print(spiralOrder(test4));
	std::cout << "Expected [1, 2, 4, 3], Actual: "; print(spiralOrder(test5));
	std::cout << "Expected [1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8], Actual: "; print(spiralOrder(test6));
	std::cout << "Expected [1, 2, 3, 4, 5, 10, 15, 14, 13, 12, 11, 6, 7, 8, 9], Actual: "; print(spiralOrder(test7));
	std::cout << "Expected [1, 2, 3], Actual: "; print(spiralOrder(test8));

	return 0;
}

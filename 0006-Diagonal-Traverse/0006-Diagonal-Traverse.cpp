// 0006-Diagonal-Traverse.cpp : Source file for your target.
//

#include "0006-Diagonal-Traverse.h"
#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat)
{
    std::vector<int> diagonal;
    int m = mat.size();
    int n = mat[0].size();
    int len = m * n;

    int incrRow = -1;
    int incrCol = +1;
    int row = 0, col = 0;

    int maxDiagonal = std::min(m, n);

    // Ramp up to diagonal
    for (int i = 0; i < maxDiagonal; i++)
    {
        int currentDiagonalCount = i + 1;
        while (currentDiagonalCount > 0)
        {
            diagonal.push_back(mat[row][col]);
            currentDiagonalCount--;

            if (currentDiagonalCount == 0)
            {
                if (incrRow < 0)
                    col++;
                else
                    row++;

                std::swap(incrRow, incrCol);
                continue;
            }

            row += incrRow;
            col += incrCol;
        }
    }

    // Handle out of bounds
    if (row == m)
    {
        row = m - 1;
        col++;
    }
    else if (col == n)
    {
        col = n - 1;
        row++;
    }

    // add additional diagonals
    int remainingDiagonals = std::abs(m - n);
    for (int i = 0; i < remainingDiagonals; i++)
    {
        for (int j = 0; j < maxDiagonal; j++)
        {
            diagonal.push_back(mat[row][col]);

            if (j == maxDiagonal - 1)
            {
                if (incrRow < 0)
                    row++;
                else
                    col++;

                std::swap(incrRow, incrCol);
                continue;
            }

            row += incrRow;
            col += incrCol;
        }
    }

    // Ramp down from diagonal
    for (int i = maxDiagonal - 1; i > 0; i--)
    {
        int currentDiagonalCount = i;
        while (currentDiagonalCount > 0)
        {
            diagonal.push_back(mat[row][col]);
            currentDiagonalCount--;

            if (currentDiagonalCount == 0)
            {
                if (incrRow < 0)
                    row++;
                else
                    col++;

                std::swap(incrRow, incrCol);
                continue;
            }

            row += incrRow;
            col += incrCol;
        }
    }

    return diagonal;
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

    std::cout << "Expected [1, 2, 4, 7, 5, 3, 6, 8, 9], Actual: "; print(findDiagonalOrder(test1));
    std::cout << "Expected [1], Actual: "; print(findDiagonalOrder(test2));
    std::cout << "Expected [1, 2], Actual: "; print(findDiagonalOrder(test3));
    std::cout << "Expected [1, 2], Actual: "; print(findDiagonalOrder(test4));
    std::cout << "Expected [1, 2, 3, 4], Actual: "; print(findDiagonalOrder(test5));
    std::cout << "Expected [1, 2, 4, 7, 5, 3, 6, 8, 10, 11, 9, 12], Actual: "; print(findDiagonalOrder(test6));
    std::cout << "Expected [1, 2, 6, 11, 7, 3, 4, 8, 12, 13, 9, 5,10, 14, 15], Actual: "; print(findDiagonalOrder(test7));
    
	return 0;
}

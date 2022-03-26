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

    if (m == 1) return mat[0];
    if (n == 1)
    {
        for (int i = 0; i < mat.size(); i++)
            diagonal.push_back(mat[i][0]);
        return diagonal;
    }

    int len = m * n;
    
    diagonal.push_back(mat[0][0]); 

    int row = 0, col = 1;
    int incrRow = +1;
    int incrCol = -1;

    for (int i = 1; i < len - 1; i++)
    {
        diagonal.push_back(mat[row][col]);

        if (incrRow < 1)
        {
            if (row == 0 || col == n - 1)
            {
                if (col < n - 1)
                    col++;
                else
                    row++;

                std::swap(incrRow, incrCol);
            }
            else
            {
                row += incrRow;
                col += incrCol;
            }
        }
        else
        {
            if (row == m - 1 || col == 0)
            {
                if (row < m - 1)
                    row++;
                else
                    col++;

                std::swap(incrRow, incrCol);
            }
            else
            {
                row += incrRow;
                col += incrCol;
            }
        }
    }

    diagonal.push_back(mat[m - 1][n - 1]);

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

    std::vector<std::vector<int>> test8 = { {1}, {2}, {3} };
    std::vector<std::vector<int>> test9 = { {2,3,4}, {5, 6, 7 }, {8, 9, 10}, {11, 12, 13}, {14, 15, 16} };

    std::cout << "Expected [1, 2, 4, 7, 5, 3, 6, 8, 9], Actual: "; print(findDiagonalOrder(test1));
    std::cout << "Expected [1], Actual: "; print(findDiagonalOrder(test2));
    std::cout << "Expected [1, 2], Actual: "; print(findDiagonalOrder(test3));
    std::cout << "Expected [1, 2], Actual: "; print(findDiagonalOrder(test4));
    std::cout << "Expected [1, 2, 3, 4], Actual: "; print(findDiagonalOrder(test5));
    std::cout << "Expected [1, 2, 4, 7, 5, 3, 6, 8, 10, 11, 9, 12], Actual: "; print(findDiagonalOrder(test6));
    std::cout << "Expected [1, 2, 6, 11, 7, 3, 4, 8, 12, 13, 9, 5,10, 14, 15], Actual: "; print(findDiagonalOrder(test7));
    std::cout << "Expected [1, 2, 3], Actual: "; print(findDiagonalOrder(test8));
    std::cout << "Expected [2,3,5,8,6,4,7,9,11,14,12,10,13,15,16], Actual: "; print(findDiagonalOrder(test9));
    
	return 0;
}

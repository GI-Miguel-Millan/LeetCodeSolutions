// 002-SmallestStringWithSwaps.h : Header file for your target.

#pragma once
#include <string>
#include <vector>

class UnionFind
{
private:
    std::vector<int> root;
    std::vector<int> rank;
public:
    // Initialize the array root and rank
    // Each vertex is representative of itself with rank 1
    UnionFind(int sz) : root(sz), rank(sz)
    {
        for (int i = 0; i < sz; i++)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }

    // Get the root of a vertex
    int find(int x)
    {
        if (x == root[x])
        {
            return x;
        }
        return root[x] = find(root[x]);
    }

    // Perform the union of two components
    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] >= rank[rootY])
            {
                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            }
            else
            {
                root[rootX] = rootY;
                rank[rootY] += rank[rootX];
            }
        }
    }
};

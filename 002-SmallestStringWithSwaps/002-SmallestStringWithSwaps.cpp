// 002-SmallestStringWithSwaps.cpp : Source file for your target.
//

#include "002-SmallestStringWithSwaps.h"
#include <unordered_map>
#include <algorithm>

std::string smallestStringWithSwaps(std::string s, std::vector<std::vector<int>>& pairs)
{
	int size = s.size();
	UnionFind uf(size);

	// iterate over the edges
	for (auto edge : pairs)
	{
		int source = edge[0];
		int destination = edge[1];

		// perform the union of end points
		uf.unionSet(source, destination);
	}

	std::unordered_map<int, std::vector<int>> rootToComponent;

	// Group the vertices that are in the same component
	for (int vertex = 0; vertex < size; vertex++)
	{
		int root = uf.find(vertex);
		rootToComponent[root].push_back(vertex);
	}

	std::string smallestString(s.length(), ' ');
	for (auto component : rootToComponent)
	{
		std::vector<int> indices = component.second;
		std::vector<char> characters;
		for (int index : indices)
			characters.push_back(s[index]);

		std::sort(characters.begin(), characters.end());

		for (int index = 0; index < indices.size(); index++)
			smallestString[indices[index]] = characters[index];
	}

	return smallestString;
}


int main()
{
	std::string str1 = "dcab";
	std::vector<std::vector<int>> pairs1 = { {0, 3}, {1, 2}, {0, 2} };



	return 0;
}


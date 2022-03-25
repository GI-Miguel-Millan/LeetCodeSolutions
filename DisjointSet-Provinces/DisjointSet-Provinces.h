#pragma once

#include <vector>

class ProvinceUnionizer {
public:
	ProvinceUnionizer(std::vector<std::vector<int>>& isConnected);
	~ProvinceUnionizer() = default;

	inline int GetProvinceCount() { return provinceCount; }

private:
	std::vector<int> parentNodes;
	std::vector<int> ranks;
	int provinceCount;

	void Union(int i, int j);
	int FindRootOf(int i);
};

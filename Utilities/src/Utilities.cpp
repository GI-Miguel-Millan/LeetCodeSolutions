// Utilities.cpp : Source file for your target.
//

#include "Utilities.h"
#include <iostream>
#include <sstream>
#include <iterator>

namespace Utilities
{
	std::string GetString(std::vector<int> const& a)
	{
		if (a.size() == 0) return "[]";

		std::ostringstream oss;
		std::ostream_iterator<int> ossIterator(oss, ", ");
		oss << "[ ";

		std::copy(a.begin(), a.end() - 1, ossIterator);

		oss << a[a.size() - 1];
		oss << " ]";

		return oss.str();
	}

	std::string GetString(std::vector<std::vector<int>> const& a)
	{
		if (a.size() == 0) return "[]";

		std::string str = "[ ";

		for (int i = 0; i < a.size() - 1; i++)
		{
			str += GetString(a[i]);
			str += ", ";
		}

		str += GetString(a[a.size() - 1]);
		str += " ]";

		return str;
	}

	void print(std::vector<std::vector<int>> const& a)
	{
		std::cout << GetString(a) << std::endl;
	}

	void print(std::vector <int> const& a)
	{
		std::cout << GetString(a) << std::endl;
	}

	bool Equals(std::vector <int> const& a, std::vector <int> const& b)
	{
		if (a.size() != b.size()) return false;

		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i]) return false;
		}

		return true;
	}
};
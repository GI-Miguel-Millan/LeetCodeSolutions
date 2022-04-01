// Utilities.h : Header file for your target.

#pragma once
#include <vector>
#include <string>

namespace Utilities
{
    std::string GetString(std::vector<int> const& a);
    std::string GetString(std::vector<std::vector<int>> const& a);
    void print(std::vector<std::vector<int>> const& a);
    void print(std::vector<int> const& a);
    bool Equals(std::vector<int> const& a, std::vector<int> const& b);
};
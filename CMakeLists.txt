# CMakeList.txt : CMake project for LeetCodeSolutions, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("LeetCodeSolutions")

# Add source to this project's executable.
add_executable (0000-LeetCodeSolutions "LeetCodeSolutions.cpp" "LeetCodeSolutions.h")

# TODO: Add tests and install targets if needed.

add_subdirectory("DisjointSet-Provinces")

add_subdirectory("002-SmallestStringWithSwaps")

add_subdirectory("FindPivotIndex")

add_subdirectory("0004-LargestNumberTwiceOthers")

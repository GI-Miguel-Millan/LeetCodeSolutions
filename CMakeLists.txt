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

add_subdirectory("0005-Plus-One")

add_subdirectory("0006-Diagonal-Traverse")

add_subdirectory("0007-SpiralMatrix")

add_subdirectory("0008-Pascals-Triangle")

add_subdirectory("0009-AddBinaryString")

add_subdirectory("0010-Implement-strStr")

add_subdirectory("0011-Longest-Common-Prefix")

add_subdirectory("0012-Array-Partition1")

add_subdirectory("0013-Two-Sum-II-Input-Array-Sorted")

add_subdirectory("0014-RemoveElement")

add_subdirectory("0015-MaxConsecutiveOnes")

add_subdirectory("0016-MinimumSizeSubArraySum")

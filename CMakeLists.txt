cmake_minimum_required(VERSION 3.21)
project(DoA_Labb3_V1)

set(CMAKE_CXX_STANDARD 17)

add_executable(DoA_Labb3_V1 main.cpp linearSearch.h binarySearch.h interpolationSearch.h binaryTreeSearch.h hashTable.h timer.cpp timer.h testCases.h)

cmake_minimum_required(VERSION 3.1)

project(boj_algorithm
        VERSION 1.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

add_executable(BOJ.out union_find_disjoint_set/1976.cpp)
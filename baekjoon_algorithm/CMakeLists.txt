cmake_minimum_required(VERSION 3.1)

project(boj_algorithm
        VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE RelWithDebInfo)

#set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")

#set(CMAKE_CXX_FLAGS "-g -fsanitize=address")
#set(CMAKE_CXX_FLAGS "-fconcepts")

add_executable(BOJ.out recursion/simple_merge_sort.cpp)

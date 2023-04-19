cmake_minimum_required(VERSION 3.1)

project(boj_algorithm
        VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE RelWithDebInfo)

#set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")

#set(CMAKE_CXX_FLAGS "-g -fsanitize=address")

add_executable(BOJ.out simulation/15683_re.cpp)
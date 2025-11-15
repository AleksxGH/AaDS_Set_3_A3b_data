cmake_minimum_required(VERSION 3.28)
project(A3i)

set(CMAKE_CXX_STANDARD 20)

add_executable(A3i main.cpp
        ArrayGenerator.hpp
        Sorts.hpp
        SortTester.hpp)

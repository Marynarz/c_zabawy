message("--- set zeroes ---")
cmake_minimum_required(VERSION 3.22)

enable_testing()

project(longest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/tests")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(longest main.c)

add_executable(longest_test tests/slongest_test.cpp)
target_link_libraries(longest_test PUBLIC GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(longest_test)

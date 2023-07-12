message("--- set zeroes ---")
cmake_minimum_required(VERSION 3.22)

enable_testing()

project(longest)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/tests")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(subsets main.c)

add_executable(subsets_test tests/slongest_test.cpp)
target_link_libraries(subsets_test PUBLIC GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(subsets_test)

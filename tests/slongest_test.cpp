#include <gtest/gtest.h>
#include <array>
#include "../sem/longest.c"

TEST(LeetCodeSubsests, EmptyList)
{
    int *test_array = NULL;

    int result = longestSubarray(test_array, 0);

    ASSERT_EQ(result, 0);
}

TEST(LeetCodeSubsets, OneElementList)
{
    int *test_array = new int[1];
    test_array[0] = 0;

    int result = longestSubarray(test_array, 1);

    delete[] test_array;

    ASSERT_EQ(result, 0);
}

TEST(LeetCodeSubsets, TwoElementsListLastZero)
{
    std::array<int, 2> test_array{1, 0};

    int result = longestSubarray(test_array.data(), test_array.size());

    ASSERT_EQ(result, 1);
}

TEST(LeetCodeSubsets, TwoElementsListFirstZero)
{
    std::array<int, 2> test_array{0, 1};

    int result = longestSubarray(test_array.data(), test_array.size());

    ASSERT_EQ(result, 1);
}

TEST(LeetCodeSubsets, TwoElementsListOnlyOnes)
{
    std::array<int, 2> test_array{1, 1};

    int result = longestSubarray(test_array.data(), test_array.size());

    ASSERT_EQ(result, 1);
}

TEST(LeetCodeSubsets, TwoElementsListOnlyZeroes)
{
    std::array<int, 2> test_array{0, 0};

    int result = longestSubarray(test_array.data(), test_array.size());

    ASSERT_EQ(result, 0);
}

TEST(LeetCodeSubsets, LeetCodeTestCase1)
{
    std::array<int, 4> test_array{1,1,0,1};

    int result = longestSubarray(test_array.data(), test_array.size());

    ASSERT_EQ(result, 3);
}

TEST(LeetCodeSubsets, LeetCodeTestCase2)
{
    std::array<int, 9> test_array{0,1,1,1,0,1,1,0,1};

    int result = longestSubarray(test_array.data(), test_array.size());

    ASSERT_EQ(result, 5);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
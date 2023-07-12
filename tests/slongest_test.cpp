#include <gtest/gtest.h>
#include <array>
#include "../sem/longest.c"

TEST(LeetCodeSubsests, EmptyList)
{
    int * test_array = NULL;

    int result = longestSubarray(test_array ,0);

    ASSERT_EQ(result, 0);
}

TEST(LeetCodeSubsets, OneElementList)
{
    int * test_array = new int[1];
    test_array[0] = 0;

    int result = longestSubarray(test_array, 1);

    delete [] test_array;

    ASSERT_EQ(result, 0);
}

TEST(LeetCodeSubsets, TwoElementsList)
{
    std::array<int, 2> test_array{1,0};

    int result = longestSubarray(test_array.data(), test_array.size());

    ASSERT_EQ(result, 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
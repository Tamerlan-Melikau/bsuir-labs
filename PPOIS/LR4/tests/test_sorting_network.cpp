#include <gtest/gtest.h>
#include "sorting/sorting_network.h"
#include <vector>

TEST(SortingNetworkTest, SortsFourNumbers) {
    std::vector<int> numbers = {8, 2, 10, 1};
    sortingNetwork4(numbers, std::less<int>());
    
    std::vector<int> expected = {1, 2, 8, 10};
    EXPECT_EQ(numbers, expected);
}

TEST(SortingNetworkTest, SortsAlreadySorted) {
    std::vector<int> numbers = {1, 2, 3, 4};
    sortingNetwork4(numbers, std::less<int>());
    
    std::vector<int> expected = {1, 2, 3, 4};
    EXPECT_EQ(numbers, expected);
}

TEST(SortingNetworkTest, SortsReversed) {
    std::vector<int> numbers = {4, 3, 2, 1};
    sortingNetwork4(numbers, std::less<int>());
    
    std::vector<int> expected = {1, 2, 3, 4};
    EXPECT_EQ(numbers, expected);
}

TEST(SortingNetworkTest, IgnoresIfLessThanFour) {
    std::vector<int> numbers = {3, 1, 2};
    sortingNetwork4(numbers, std::less<int>());
    
    std::vector<int> expected = {3, 1, 2};
    EXPECT_EQ(numbers, expected);
}

TEST(SortingNetworkTest, EmptyArray) {
    std::vector<int> numbers;
    sortingNetwork4(numbers, std::less<int>());
    EXPECT_TRUE(numbers.empty());
}
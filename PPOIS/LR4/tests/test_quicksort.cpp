#include <gtest/gtest.h>
#include "sorting/quicksort.h"
#include <vector>

TEST(QuickSortTest, SortsNumbers) {
    std::vector<int> numbers = {10, 1, 5, 3, 8, 2};
    quickSort(numbers, std::less<int>());
    
    std::vector<int> expected = {1, 2, 3, 5, 8, 10};
    EXPECT_EQ(numbers, expected);
}

TEST(QuickSortTest, SortsAlreadySorted) {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    quickSort(numbers, std::less<int>());
    
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(numbers, expected);
}

TEST(QuickSortTest, SortsEmptyVector) {
    std::vector<int> numbers;
    quickSort(numbers, std::less<int>());
    EXPECT_TRUE(numbers.empty());
}

TEST(QuickSortTest, SortsSingleElement) {
    std::vector<int> numbers = {42};
    quickSort(numbers, std::less<int>());
    EXPECT_EQ(numbers[0], 42);
}

TEST(QuickSortTest, SortsWithDuplicates) {
    std::vector<int> numbers = {5, 2, 5, 1, 2};
    quickSort(numbers, std::less<int>());
    
    std::vector<int> expected = {1, 2, 2, 5, 5};
    EXPECT_EQ(numbers, expected);
}

TEST(QuickSortTest, SortsLargeArray) {
    std::vector<int> numbers = {9, 3, 7, 1, 8, 2, 6, 4, 5, 0, 11, 15, 13, 12, 10, 14};
    quickSort(numbers, std::less<int>());
    
    std::vector<int> expected = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    EXPECT_EQ(numbers, expected);
}
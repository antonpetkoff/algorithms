#include <gtest/gtest.h>
#include "Sorting.cpp"

TEST(InsertionSort, Sort) {
    int arr[] = {43, 19, 2, 10, 8};

    ASSERT_FALSE(isSorted(arr, 5));
    insertionSort(arr, 5);
    ASSERT_TRUE(isSorted(arr, 5));
}

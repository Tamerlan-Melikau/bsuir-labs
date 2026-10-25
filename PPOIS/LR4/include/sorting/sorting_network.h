#pragma once
#include <vector>
#include <utility>

template <typename T, typename Compare>
void compareAndSwap(std::vector<T>& arr, int i, int j, Compare comp) {
    if (comp(arr[j], arr[i])) {
        std::swap(arr[i], arr[j]);
    }
}

template <typename T, typename Compare>
void sortingNetwork4(std::vector<T>& arr, Compare comp) {
    if (arr.size() < 4) return;

    compareAndSwap(arr, 0, 1, comp);
    compareAndSwap(arr, 2, 3, comp);
    compareAndSwap(arr, 0, 2, comp);
    compareAndSwap(arr, 1, 3, comp);
    compareAndSwap(arr, 1, 2, comp);
}
#pragma once
#include <vector>
#include <utility>

template <typename T, typename Compare>
void quickSort(std::vector<T>& arr, int left, int right, Compare comp) {
    if (left >= right) return;

    int pivotIndex = left + (right - left) / 2;
    T pivot = arr[pivotIndex];
    
    int i = left;
    int j = right;

    while (i <= j) {
        while (comp(arr[i], pivot)) i++;
        while (comp(pivot, arr[j])) j--;

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j, comp);
    if (i < right) quickSort(arr, i, right, comp);
}

template <typename T, typename Compare>
void quickSort(std::vector<T>& arr, Compare comp) {
    if (!arr.empty()) {
        quickSort(arr, 0, static_cast<int>(arr.size()) - 1, comp);
    }
}
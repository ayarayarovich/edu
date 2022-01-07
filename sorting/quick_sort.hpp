#pragma once

#include <vector>
#include <utility>

template <class T>
int partition(std::vector<T>& arr, int lo, int hi) {
    T pivot = arr[hi];

    int i = lo;
    for (int j = lo; j < hi; ++j)
    {
        if (arr[j] <= pivot)
        {
            std::swap(arr[i], arr[j]);
            ++i;
        }
    }
    std::swap(arr[i], arr[hi]);

    return i;
}

template <class T>
void quick_sort_impl(std::vector<T>& arr, int lo, int hi) {
    if (lo < hi) {
        int pi = partition(arr, lo, hi);
        quick_sort_impl(arr, lo, pi - 1);
        quick_sort_impl(arr, pi + 1, hi);
    }
}

template <class T>
std::vector<T> quick_sort( std::vector<T> arr ) {
    quick_sort_impl(arr, 0, arr.size() - 1);
    return arr;
}

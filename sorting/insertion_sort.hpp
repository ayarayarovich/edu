#pragma once

#include <vector>
#include <utility>

template <class T>
std::vector<T> insertion_sort( std::vector<T> arr )
{
    size_t n = arr.size();
    for ( size_t i = 1; i < n; ++i )
    {
        for (size_t j = i; j > 0 && arr[j - 1] > arr[j]; --j)
            std::swap(arr[j - 1], arr[j]);
    }
    return arr;
}

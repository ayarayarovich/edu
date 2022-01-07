#pragma once

#include <vector>
#include <utility>

template <class T>
std::vector<T> shaker_sort( std::vector<T> arr )
{
    int n = arr.size();
    bool swapped = false;
    do
    {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;

        swapped = false;
        for (int i = n - 1; i > 0; --i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
    } while (swapped);

    return arr;
}

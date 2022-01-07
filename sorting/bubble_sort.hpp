#include <vector>
#include <utility>

template <class T>
std::vector<T> bubble_sort( std::vector<T> arr )
{
    size_t n = arr.size();
    for ( size_t i = 0; i < n; ++i )
    {
        for ( size_t j = i + 1; j < n; ++j )
        {
            if ( arr[i] > arr[j] )
                std::swap(arr[i], arr[j]);
        }
    }
    return arr;
}

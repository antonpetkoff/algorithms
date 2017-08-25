#include <cstdlib>
#include <algorithm>

template <class T>
bool isSorted(T * arr, std::size_t length) {
    for (int i = 1; i < length; ++i) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

void insertionSort(int * arr, std::size_t length) {
    for (int i = 1; i < length; ++i) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            std::swap(arr[j - 1], arr[j]);
            --j;
        }
    }
}

#include "dynamic_array.h"
//bubble sort
template <typename T, typename Comparator = std::less<T>>
void bubble_sort(DynamicArray<T> &array, Comparator comparator){
    for (int j = 1; j < array.Size(); j++) {
        bool isSorted = true;
        for (int i = 0; i < array.Size() - j; i++) {
            if (comparator(array[i], array[i + 1])) {
                int tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                isSorted = false;
            }
        }
        if (isSorted) {
            break;
        }
    }
}

//shaker sort
template <typename T, typename Comparator = std::less<T>>
void shacker_sort(DynamicArray<T>& arr, Comparator comparator) {
    bool swapped = true;
    int start = 0;
    int end = arr.Size() - 1;

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (comparator(arr[i], arr[i + 1])) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (comparator(arr[i], arr[i + 1])) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}


//Merge sort

template <typename T, typename Comparator = std::less<T>>
void merge_sort(DynamicArray<T> &array, Comparator comparator){
    DynamicArray<T> temp_array;
    merge_sort(array, temp_array, comparator);
}

template <typename T, typename Comparator = std::less<T>>
void merge_sort(DynamicArray<T> &array, DynamicArray<T> &temp_array, int left, int right, Comparator comparator){
    if(left < right){
        int mid = left - (right - left) / 2;
        merge_sort(array, temp_array, left, mid, comparator);
        merge_sort(array, temp_array, mid + 1, right, comparator);
        merging<T>();
    }
}

template <typename T, typename Comparator = std::less<T>>
void merging(){
    cout << 52;
}

//Quick sort

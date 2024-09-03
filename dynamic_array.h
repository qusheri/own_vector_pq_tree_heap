#pragma once
#include "Error_Handler.h"
#include "vector"
template<typename T>
class DynamicArray {
private:
    ErrorHandler errors;
    void throw_exception(int error){
        errors.handleError(error);
    }
    size_t size_;
    T *val;

    //sorting helpers

        //merge sort
    template<typename Comparator = std::less<T>>
    void merge_sort(int left, int right, Comparator comparator) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            merge_sort(left, mid, comparator);
            merge_sort(mid + 1, right, comparator);
            merging(comparator, left, mid + 1, mid, right);
        }
    }
    template<typename Comparator = std::less<T>>
    void merging(Comparator comparator, int ptr1, int ptr2, int wall1, int wall2) {
        int i = 0, ptr = ptr1;
        DynamicArray<T> Arr;
        while (ptr1 <= wall1 && ptr2 <= wall2) {
            Arr.Resize(i + 1);
            if (comparator(val[ptr1], val[ptr2])) {
                Arr[i++] = val[ptr1++];
            } else {
                Arr[i++] = val[ptr2++];
            }
        }
        while (ptr1 <= wall1) {
            Arr.Resize(i + 1);
            Arr[i++] = val[ptr1++];
        }
        while (ptr2 <= wall2) {
            Arr.Resize(i + 1);
            Arr[i++] = val[ptr2++];
        }
        for (int z = 0; z < i; ++z) {
            val[ptr++] = Arr[z];
        }
    }

    //quick sort //5, 2, 2, 4, 2, 9
    template<typename Comparator = std::less<T>>
    void quick_sort(DynamicArray<T>& arr, Comparator comparator){ //&&&&&
        DynamicArray<T> left, right;
        T pivot = arr[arr.Size()/2];
        for(int i = 0; i < arr.Size(); ++i) {
            if(i != arr.Size()/2) {
                if (comparator(arr[i], pivot)) {
                    left.Append(arr[i]);
                } else {
                    right.Append(arr[i]);
                }
            }
        }
        if(left.Size() > 1) quick_sort(left, comparator);
        if(right.Size() > 1) quick_sort(right, comparator);
        left.Append(pivot);
        arr = left + right;
    }
public:
    DynamicArray() : size_(0), val(new T[size_]) {}

    DynamicArray(const DynamicArray &array) : size_(array.size_), val(new T[size_]) {
        std::copy(array.val, array.val + size_, val);
    }

    DynamicArray(const std::vector<T>& array) : size_(array.size()), val(new T[array.size()]) {
        std::copy(array.begin(), array.end(), val);
    }

    DynamicArray(T* items, size_t count) : size_(count), val(new T[count]){
        for(size_t i = 0; i != count; ++i){
            T n = items[i];
            val[i] = items[i];
        }
    }
    ~DynamicArray() {
        delete[] val;
    }

    [[nodiscard]] size_t Size() const {
        return size_;
    }
    DynamicArray<T>& operator=(const DynamicArray<T>& other) {
        if (this == &other) {
            return *this;
        }
        delete[] val;
        size_ = other.size_;
        val = new T[size_];
        for (size_t i = 0; i < size_; ++i) {
            val[i] = other.val[i];
        }

        return *this;
    }
    DynamicArray<T> operator+(const DynamicArray<T>& other) const {
        DynamicArray<T> result;
        result.Resize(this->size_ + other.size_);
        for (size_t i = 0; i < this->size_; ++i) {
            result[i] = this->val[i];
        }
        for (size_t i = 0; i < other.size_; ++i) {
            result[this->size_ + i] = other.val[i];
        }
        return result;
    }
    void Resize(size_t newSize) {
        if (newSize == size_) return;
        if (newSize > size_) {
            T *tmp = new T[newSize];
            for(size_t i = 0; i != size_; ++i){
                tmp[i] = val[i];
            }
            val = tmp;
        }
        if (newSize < size_) {
            for (size_t i = newSize; i < size_; ++i) {
                val[i].~T();
            }
        }
        size_ = newSize;
    }

    void Append(T new_el){
        (*this).Resize(size_ + 1);
        val[size_ - 1] = new_el;
    }

    const T &operator[](const size_t i) const {
        return val[i];
    }

    T &operator[](const size_t i) {
        return val[i];
    }
    //SORTING
    //bubble sort
    template<typename Comparator = std::less<T>>
    void bubble_sort(Comparator comparator) {
        for (int j = 1; j < size_; j++) {
            bool isSorted = true;
            for (int i = 0; i < size_ - j; i++) {
                if (!comparator(val[i], val[i + 1])) {
                    int tmp = val[i];
                    val[i] = val[i + 1];
                    val[i + 1] = tmp;
                    isSorted = false;
                }
            }
            if (isSorted) {
                break;
            }
        }
    }

    //shaker sort
    template<typename Comparator = std::less<T>>
    void shacker_sort(Comparator comparator) {
        bool swapped = true;
        int start = 0;
        int end = size_ - 1;

        while (swapped) {
            swapped = false;
            for (int i = start; i < end; ++i) {
                if (!comparator(val[i], val[i + 1])) {
                    std::swap(val[i], val[i + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
            swapped = false;
            --end;
            for (int i = end - 1; i >= start; --i) {
                if (!comparator(val[i], val[i + 1])) {
                    std::swap(val[i], val[i + 1]);
                    swapped = true;
                }
            }
            ++start;
        }
    }


    //Merge sort

    template<typename Comparator = std::less<T>>
    void merge_sort(Comparator comparator) {
        merge_sort(0, size_ - 1, comparator);
    }

    //Quick sort
    template<typename Comparator = std::less<T>>
    void quick_sort(Comparator comparator){
        quick_sort(*this, comparator);
    }
};
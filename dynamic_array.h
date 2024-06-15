#pragma once
#include "Error_Handler.h"
template<typename T>
class DynamicArray {
private:
    ErrorHandler errors;
    void throw_exception(int error){
        errors.handleError(error);
    }
    size_t size_;
    T *val;
public:
    DynamicArray() : size_(0), val(new T[size_]) {}

    DynamicArray(const DynamicArray &array) : size_(array.size_), val(new T[size_]) {
        std::copy(array.val, array.val + size_, val);
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

    const T &operator[](const size_t i) const {
        return val[i];
    }

    T &operator[](const size_t i) {
        return val[i];
    }

};
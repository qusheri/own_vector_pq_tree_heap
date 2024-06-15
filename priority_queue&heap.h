#pragma once
#include <iostream>
#include <stdexcept>
#include "definitions.h"

template<typename T>
class PriorityQueue{
private:
    ArraySequence<T> array_;
    void sift(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < array_.GetLength() && array_[left] > array_[largest]) {
            largest = left;
        }

        if (right < array_.GetLength() && array_[right] > array_[largest]) {
            largest = right;
        }

        if (largest != i) {
            std::swap(array_[i], array_[largest]);
            sift(largest);
        }
    }
    void siftup(int i){
        while (i > 0 && array_[i] > array_[(i - 1) / 2]){
            std::swap(array_[i], array_[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
public:
    PriorityQueue() = default;
    PriorityQueue(const PriorityQueue<T>& other) : array_(other.array_) {}
    PriorityQueue(const ArraySequence<T>& other, int size){
        for (int i = 0; i < size; ++i) {
            array_.Append(other[i]);
            siftup(i);
        }
    }
    ~PriorityQueue() = default;
    size_t size() {
        return array_.GetLength();
    }
    T Max() const {
        return array_[0];
    }
    void Push(const T& key) {
        array_.Append(key);
        siftup(array_.GetLength() - 1);
    }
    void Pop(){
        array_[0] = array_[array_.GetLength() - 1];
        array_.pop();
        sift(0);
    }
    template<typename U>
    PriorityQueue<U> map(std::function<U(const T&)> func) {
        PriorityQueue<U> result;
        for (size_t i = 0; i < this->size(); ++i) {
            result.Push(func(array_[i]));
        }
        return result;
    }

    PriorityQueue<T> where(std::function<bool(const T&)> func) {
        PriorityQueue<T> result;
        for(size_t i = 0; i != this->size(); ++i){
            if(func(array_[i])){
                result.Push(array_[i]);
            }
        }
        return result;
    }

    template<typename u>
    u reduce(std::function<u(const T&, const T&)> func, u c) {
        u res = c;
        for(int i = 0; i != this->size(); ++i){
            res = func(array_[i], res);
        }
        return res;
    }

    void print(){
        PriorityQueue<T> other(*this);
        while (other.size() != 0){
            std::cout << other.Max() << ' ';
            other.Pop();
        }
        std::cout << std::endl;
    }
};

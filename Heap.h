#include <iostream>
#include <vector>
#include <functional>

template<typename T>
class Heap {
private:
    std::vector<T> heap;
    void siftUp(int index) {
        if (index <= 0) return;
        int parentIndex = (index - 1) / 2;
        if (heap[index] > heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            siftUp(parentIndex);
        }
    }

    void siftDown(int index) {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int largestIndex = index;

        if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[largestIndex]) {
            largestIndex = leftChildIndex;
        }

        if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[largestIndex]) {
            largestIndex = rightChildIndex;
        }

        if (largestIndex != index) {
            std::swap(heap[index], heap[largestIndex]);
            siftDown(largestIndex);
        }
    }

public:

    Heap() = default;

    Heap(const std::vector<T>& array) : heap(array) {
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            siftDown(i);
        }
    }
    Heap(std::vector<T>&& array) : heap(array) {
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            siftDown(i);
        }
    }

    Heap<T> extractSubsequence(const Heap<T>& heap, int i, int j) {
        if (i < 0 || j >= heap.size() || i > j) {
            throw std::invalid_argument("Invalid argument");
        }

        std::vector<T> subsequence(heap.size());
        std::copy(heap.heap.begin() + i, heap.heap.begin() + j + 1, subsequence.begin());

        return Heap<T>(subsequence);
    }

    Heap<T> mergeHeaps(const Heap<T>& heap1, const Heap<T>& heap2) {
        std::vector<T> merged(heap1.size() + heap2.size());
        std::merge(heap1.heap.begin(), heap1.heap.end(), heap2.heap.begin(), heap2.heap.end(), merged.begin());

        return Heap<T>(merged);
    }


    void insert(const T& value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    T extractMax() {
        if (heap.empty()) {
            throw std::out_of_range("Out of range");
        }

        T maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0);
        return maxValue;
    }

    T top() const {
        if (heap.empty()) {
            throw std::out_of_range("Out of range");
        }
        return heap[0];
    }

    size_t size() const {
        return heap.size();
    }

    bool empty() const {
        return heap.empty();
    }
};
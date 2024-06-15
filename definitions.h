#pragma once

#include <iostream>
#include "dynamic_array.h"
#include "list.h"
template<typename T>
class Sequence {
public:
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual int GetLength() = 0;
    virtual Sequence<T>* Append(T item) = 0;
    virtual Sequence<T>* Prepend(T item) = 0;
    virtual Sequence<T>* InsertAt(T item, int index) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;
    virtual ~Sequence() {}
    virtual T& operator[](const size_t i) = 0;
    virtual const T& operator[](const size_t i) const = 0;
    virtual void Clear() = 0;
};

template<typename T>
class ListSequence : public Sequence<T> {
private:
    List<T> list_;
public:
    ListSequence(T* items, int count) : list_(items, count) {}

    ListSequence() : list_() {}
    ListSequence(const ListSequence<T>& other) : list_(other.list_) {}
    T GetFirst() override {
        return list_.GetFirst();
    }

    T GetLast() override {
        return list_.GetLast();
    }

    T Get(int index) override {
        return list_.Get(index);
    }
    void pop_front(){
        list_.pop_front();
    }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override {
        ListSequence<T>* subsequence = new ListSequence<T>();
        List<T>* sublist = list_.GetSubList(startIndex, endIndex);
        for (int i = 0; i < sublist->GetLength(); ++i) {
            subsequence->Append((*sublist)[i]);
        }
        delete sublist;
        return subsequence;
    }

    int GetLength() override {
        return list_.GetLength();
    }

    Sequence<T>* Append(T item) override {
        list_.Append(item);
        return this;
    }

    Sequence<T>* Prepend(T item) override {
        list_.Prepend(item);
        return this;
    }

    Sequence<T>* InsertAt(T item, int index) override {
        list_.InsertAt(item, index);
        return this;
    }

    Sequence<T>* Concat(Sequence<T>* otherList) override {
        ListSequence<T>* concatenatedSequence = new ListSequence<T>();
        List<T>* otherListPtr = dynamic_cast<List<T>*>(otherList);
        if (otherListPtr) {
            List<T>* combinedList = list_.Concat(otherListPtr);
            for (int i = 0; i < combinedList->GetLength(); ++i) {
                concatenatedSequence->Append((*combinedList)[i]);
            }
            delete combinedList;
        }
        return concatenatedSequence;
    }
    void Clear(){
        list_.Clear();
    }
    T& operator[](const size_t i){
        return list_[i];
    }
    const T& operator[](const size_t i) const{
        return list_[i];
    }
};

template<typename T>
class ArraySequence : public Sequence<T> {
private:
    ErrorHandler errors;
    void throw_exception(int error){
        errors.handleError(error);
    }
    DynamicArray<T> array_;
    size_t capacity_;
    size_t size_;
public:
    ArraySequence() : array_(), capacity_(0), size_(0) {}

    ArraySequence(T* items, int count) : array_(items, count), capacity_(count), size_(count) {}

    ArraySequence(const ArraySequence<T>& other) : array_(other.array_), capacity_(other.capacity_), size_(other.size_) {}

    void Reserve(size_t new_capacity){
        if(new_capacity > capacity_){
            new_capacity = std::max(1, std::max((int)new_capacity, 2 * (int)capacity_));
            T* new_arr = new T[new_capacity];
            for(size_t i = 0; i != size_; ++i){
                T n = array_[i];
                new_arr[i] = array_[i];
            }
            DynamicArray<T> newData(new_arr, size_);
            for(size_t i = 0; i != size_; ++i){
                T n = newData[i];
                array_[i] = n;
            }
            capacity_ = new_capacity;
        }
    }

    T GetFirst() override {
        if (size_ == 0) {
            throw_exception(2);
        }
        return array_[0];
    }

    T GetLast() override {
        if (size_ == 0) {
            throw_exception(1);
        }
        return array_[size_ - 1];
    }

    T Get(int index) override {
        if (index < 0 || index >= size_) {
            throw_exception(1);
        }
        return array_[index];
    }

    void pop(){
        if(size_ > 0) {
            Reserve(size_ - 1);
            size_--;
        }
    }

    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override {
        if (startIndex < 0 || endIndex < 0 || startIndex >= size_ || endIndex >= size_ || startIndex > endIndex) {
            throw_exception(1);
        }
        T* items = new T[endIndex - startIndex + 1];
        for (int i = startIndex; i <= endIndex; ++i) {
            items[i - startIndex] = array_[i];
        }
        return new ArraySequence<T>(items, endIndex - startIndex + 1);
    }

    int GetLength() override {
        return size_;
    }

    Sequence<T>* Append(T item) override {
        Reserve(size_ + 1);
        array_.Resize(size_ + 1);
        size_++;
        array_[size_ - 1] = item;
        return this;
    }

    Sequence<T>* Prepend(T item) override {
        Reserve(size_ + 1);
        array_.Resize(size_ + 1);
        size_++;
        for (int i = size_ - 1; i > 0; --i) {
            array_[i] = array_[i - 1];
        }
        array_[0] = item;
        return this;
    }

    Sequence<T>* InsertAt(T item, int index) override {
        if (index < 0 || index > size_) {
            throw_exception(1);
        }
        Reserve(size_ + 1);
        array_.Resize(size_ + 1);
        ++size_;
        for (int i = size_ - 1; i > index; --i) {
            array_[i] = array_[i - 1];
        }
        array_[index] = item;
        return this;
    }

    Sequence<T>* Concat(Sequence<T>* list) override {
        ArraySequence<T>* concatenatedList = new ArraySequence<T>();
        for (int i = 0; i < size_; ++i) {
            concatenatedList->Append(array_[i]);
        }
        for (int i = 0; i < list->GetLength(); ++i) {
            concatenatedList->Append(list->Get(i));
        }
        return concatenatedList;
    }
    void Clear(){
        array_.Resize(0);
        capacity_ = 0;
        size_ = 0;
    }
    T& operator[](const size_t i){
        return array_[i];
    }
    const T& operator[](const size_t i) const{
        return array_[i];
    }
};

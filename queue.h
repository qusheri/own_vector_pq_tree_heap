#pragma once

#include "definitions.h"
#include "functional"
template<typename T>
class Queue {
private:
    ListSequence<T> list;
public:
    Queue() = default;

    ~Queue() = default;

    void push(const T &value) {
        list.Append(value);
    }

    void pop() {
        list.pop_front();
    }

    T front() {
        if (!isEmpty()) {
            return list[0];
        }
        throw std::runtime_error("Queue is empty");
    }

    [[nodiscard]] bool isEmpty() {
        return list.GetLength() == 0;
    }

    [[nodiscard]] size_t size() {
        return list.GetLength();
    }

    template<typename U>
    Queue<U> map(std::function<U(const T&)> func) {
        Queue<U> result;
        for (size_t i = 0; i < list.GetLength(); ++i) {
            result.push(func(list[i]));
        }
        return result;
    }

    Queue<T> where(std::function<bool(const T&)> func) {
        Queue<T> result;
        for(size_t i = 0; i != list.GetLength(); ++i){
            if(func(list[i])){
                result.push(list[i]);
            }
        }
        return result;
    }

    template<typename u>
    u reduce(std::function<u(const T&, const T&)> func, u c) {
        u res = c;
        for(int i = 0; i != list.GetLength(); ++i){
            res = func(list[i], res);
        }
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) {
        os << "Queue contents: ";
        for (size_t i = 0; i < queue.size(); ++i) {
            os << queue.list[i] << " ";
        }
        os << std::endl;
        return os;
    }
    void print(){
        for(int i = 0; i < this->size(); ++i){
            std::cout << list[i] << ' ';
        }
        std::cout << std::endl;
    }
};

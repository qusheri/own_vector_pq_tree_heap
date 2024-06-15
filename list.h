#pragma once
#include "Error_Handler.h"
template<typename T>
class List {
private:
    struct Node {
        T value;
        Node *next;

        explicit Node(const T &value) : value(value), next(nullptr) {}
    };

    Node *head;
    size_t size_;
    ErrorHandler errors;
    void throw_exception(int error){
        errors.handleError(error);
    }
public:
    List() : head(nullptr), size_(0) {}
    void pop_front(){
        if(size_ > 0) {
            this->head = this->head->next;
            size_--;
        }
    }
    List(T* items, int count) : head(nullptr), size_(0) {
        if (count > 0) {
            head = new Node(items[0]);
            Node* current = head;
            for (int i = 1; i < count; ++i) {
                current->next = new Node(items[i]);
                current = current->next;
            }
            size_ = count;
        }
    }

    List(const List<T>& list) : head(nullptr), size_(0) {
        if (list.head != nullptr) {
            head = new Node(list.head->value);
            Node* current = head;
            Node* listCurrent = list.head->next;
            while (listCurrent != nullptr) {
                current->next = new Node(listCurrent->value);
                current = current->next;
                listCurrent = listCurrent->next;
            }
            size_ = list.size_;
        }
    }

    ~List() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        size_ = 0;
    }

    T GetFirst() {
        if (head == nullptr) {
            errors.handleError(2);
        }
        return head->value;
    }

    T GetLast() {
        if (head == nullptr) {
            errors.handleError(1);
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        return current->value;
    }

    T Get(int index) {
        if (index < 0 || index >= size_) {
            errors.handleError(1);
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }

    List<T>* GetSubList(int startIndex, int endIndex) {
        if (startIndex < 0 || endIndex < 0 || startIndex >= size_ || endIndex >= size_ || startIndex > endIndex) {
            errors.handleError(1);
        }
        List<T>* sublist = new List<T>();
        Node* current = head;
        for (int i = 0; i <= endIndex; ++i) {
            if (i >= startIndex) {
                sublist->Append(current->value);
            }
            current = current->next;
        }
        return sublist;
    }

    int GetLength() {
        return size_;
    }

    void Append(T item) {
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        ++size_;
    }

    void Prepend(T item) {
        Node* newNode = new Node(item);
        newNode->next = head;
        head = newNode;
        ++size_;
    }

    void InsertAt(T item, int index) {
        if (index < 0 || index > size_) {
            errors.handleError(1);
        }
        if (index == 0) {
            Prepend(item);
            return;
        }
        Node* newNode = new Node(item);
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        ++size_;
    }

    List<T>* Concat(List<T> *list) {
        List<T>* concatenatedList = new List<T>(*this);
        Node* current = list->head;
        while (current != nullptr) {
            concatenatedList->Append(current->value);
            current = current->next;
        }
        return concatenatedList;
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    void Clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size_ = 0;
    }
    T &operator[](size_t index) {
        if (index >= size_) {
            errors.handleError(1);
        }
        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }
    const T &operator[](size_t index) const {
        Node *current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }
};

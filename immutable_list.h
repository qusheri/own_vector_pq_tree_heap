#include "Error_Handler.h"
template<typename T>
class ImmutableList{
private:
    struct Node {
        T value;
        Node* next;
        Node(const T& value) : value(value), next(nullptr) {}
    };
    Node* head;
    size_t size_;
public:
    ImmutableList() : head(nullptr), size_(0) {}

    ~ImmutableList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    ImmutableList(const ImmutableList& other) : head(nullptr), size_(0) {
        Node* other_current = other.head;
        Node* this_last = nullptr;
        while (other_current) {
            Node* new_node = new Node(other_current->value);
            if (!head) {
                head = new_node;
            } else {
                this_last->next = new_node;
            }
            this_last = new_node;
            other_current = other_current->next;
            ++size_;
        }
    }

    ImmutableList& operator=(const ImmutableList& other) {
        if (this == &other) return *this;

        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size_ = 0;

        Node* other_current = other.head;
        Node* this_last = nullptr;
        while (other_current) {
            Node* new_node = new Node(other_current->value);
            if (!head) {
                head = new_node;
            } else {
                this_last->next = new_node;
            }
            this_last = new_node;
            other_current = other_current->next;
            ++size_;
        }

        return *this;
    }

    ImmutableList InsertAt(const T& value, size_t pos) const {
        if (pos > size_) {
            throw std::out_of_range("Error 1: Index out of range");
        }
        ImmutableList result(*this);

        if (pos == 0) {
            Node* newNode = new Node(value);
            newNode->next = result.head;
            result.head = newNode;
            ++result.size_;
            return result;
        }

        Node* current = result.head;
        for (size_t i = 0; i < pos - 1; ++i) {
            current = current->next;
        }
        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
        ++result.size_;

        return result;
    }
    ImmutableList Append(const T& value){
        return this->InsertAt(value, 0);
    }
    ImmutableList Prepend(const T& value){
        return this->InsertAt(value, size_);
    }
    ImmutableList operator+(const ImmutableList& other){
        ImmutableList result(*this);
        for(size_t i = 0; i != other.GetLength(); ++i) {
            result = result.InsertAt(other[i], result.GetLength());
        }
        return result;
    }
    size_t GetLength() const {
        return size_;
    }

    const T& operator[](const size_t i) const {
        if (i >= size_) {
            throw std::out_of_range("Error 1: Index out of range");
        }
        Node* current = head;
        for (size_t j = 0; j < i; ++j) {
            current = current->next;
        }
        return current->value;
    }
};


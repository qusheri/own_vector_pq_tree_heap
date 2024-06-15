#pragma once
#include "stdexcept"
class ErrorHandler {
public:
    void handleError(int errorCode) {
        switch (errorCode) {
            case 1:
                throw std::out_of_range("Error 1: Index out of range");
            case 2:
                throw std::out_of_range("Error 2: Empty struct");
            case 3:
                throw std::logic_error("Immutable list cannot be cleared");
            case 4:
                throw std::invalid_argument("Argument must be of type ImmutableLinkedList");
        }
    }
};
#pragma once

#include <iostream>
#include "tests.h"

using namespace std;

void PrintMenu();

void PrintMenu() {
    cout << "Menu\n";
    cout << "1. Add element\n";
    cout << "2. Insert element at index\n";
    cout << "3. Print elements\n";
    cout << "4. Exit\n";
}

void LinkedListMenu() {
    ListSequence<int> sequence;
    int option;
    while (true) {
        PrintMenu();
        cin >> option;
        switch (option) {
            case 0:
                PrintMenu();
                break;
            case 1: {
                int value;
                cout << "Enter the element to add:\n";
                cin >> value;
                sequence.Append(value);
                cout << "Element added.\n";
                break;
            }
            case 2: {
                size_t index;
                int value;
                cout << "Enter the index to insert:\n";
                cin >> index;
                cout << "Enter the value to insert:\n";
                cin >> value;
                sequence.InsertAt(value, index);
                cout << "Element inserted.\n";
                break;
            }
            case 3: {
                if (sequence.GetLength() == 0) {
                    cout << "Sequence is empty.\n";
                    break;
                }
                cout << "Elements in the sequence:\n";
                for (size_t i = 0; i < sequence.GetLength(); ++i) {
                    cout << sequence[i] << " ";
                }
                cout << endl;
                break;
            }
            case 4: {
                cout << "Exiting...\n";
                return;
            }
            default:
                cout << "Invalid option. Exiting.\n";
                return;
        }
    }
}


void Array_SequenceMenu() {
    Sequence<int> *sequence = new ArraySequence<int>();

    int option;
    while (true) {
        PrintMenu();
        cout << "If you want to show menu again enter 0" << endl;
        cout << "Enter your choice:\n";
        cin >> option;
        switch (option) {
            case 0:
                PrintMenu();
                break;
            case 1: {
                int value;
                cout << "Enter the element to add:\n";
                cin >> value;
                sequence->Append(value);
                cout << "Element added.\n";
                break;
            }
            case 2: {
                size_t index;
                int value;
                cout << "Enter index to insert:\n";
                cin >> index;
                cout << "Enter value to insert:\n";
                cin >> value;
                sequence->InsertAt(value, index);
                cout << "Element inserted.\n";
                break;
            }
            case 3: {
                if (sequence->GetLength() == 0) {
                    cout << "Sequence is empty.\n";
                    break;
                }
                cout << "Elements in the sequence:\n";
                for (size_t i = 0; i < sequence->GetLength(); ++i) {
                    cout << (*sequence)[i] << " ";
                }
                cout << endl;
                break;
            }
            case 4: {
                cout << "Completion of the program\n";
                delete sequence;
                return;
            }
            default:
                cout << "Incorrect option. Exiting.\n";
                return;
        }
    }
}


void PrintMenu_dArray();

void PrintMenu_dArray() {
    cout << "Linked List Menu\n";
    cout << "1. Get element by index\n";
    cout << "2. Get array's size\n";
    cout << "3. Set element at index\n";
    cout << "4. Resize array\n";
    cout << "5. Print elements\n";
    cout << "6. Exit\n";
}


void dynamic_array_Menu() {
    DynamicArray<int> sequence;

    int option;
    while (true) {
        PrintMenu_dArray();
        cout << "If you want to show menu again enter 0" << endl;
        cout << "Enter your choice:\n";
        cin >> option;
        switch (option) {
            case 0:
                PrintMenu();
                break;
            case 1: {
                size_t index;
                cout << "Enter the index:\n";
                cin >> index;
                if (index >= sequence.Size()) {
                    throw std::out_of_range("Index out of range");
                }
                cout << sequence[index];
                break;
            }
            case 2: {
                cout << sequence.Size();
            }
            case 3: {
                size_t index;
                cout << "Enter index:\n";
                cin >> index;
                int value;
                cout << "Enter value:\n";
                cin >> value;
                sequence[index] = value;
                cout << "Element set.\n";
                break;
            }
            case 4: {
                size_t new_size;
                cout << "Enter new size:\n";
                cin >> new_size;
                sequence.Resize(new_size);
                break;
            }
            case 5: {
                cout << "Elements:\n";
                for (int i = 0; i < sequence.Size(); i++) {
                    cout << sequence[i] << ' ';
                }
                cout << '\n';
                break;
            }
            case 6: {
                cout << "Completion of the program\n";
                return;
            }
            default:
                cout << "Incorrect option. Exiting.\n";
                return;
        }
    }
}

void interface() {
    int choice_int;
    while(true) {
        cout << "Laboratory work 2" << endl;
        cout << "which type do you want to work with?\n";
        cout << "1. Linked list\n"
                "2. Array_Sequence\n"
                "3. Dynamic Array\n"
                "4. I want to start tests and complete the program\n"
                "0. Main menu\n";
        cin >> choice_int;
        if (choice_int == 1) {
            LinkedListMenu();
        } else if (choice_int == 2) {
            Array_SequenceMenu();
        } else if (choice_int == 3) {
            dynamic_array_Menu();
        } else if (choice_int == 4) {
            ListSequence<int> linkedList;
            TestSequence(&linkedList);
            ArraySequence<int> array;
            TestSequence(&array);
        }
        else if(choice_int == 0){
                return;
        }
        else {
            cout << "Incorrect choice" << endl;
        }
    }
}
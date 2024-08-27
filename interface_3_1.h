#include "test_4.h"
#include "test_3_1.h"
#include "dynamic_array.h"
struct Student {
    int id;
    double grade;
    bool operator < (const Student& other) const {
        return grade < other.grade;
    }
    bool operator > (const Student& other) const {
        return grade > other.grade;
    }
    bool operator == (const Student& other) const {
        return id == other.id;
    }
    bool operator >= (const Student& other) const {
        return grade >= other.grade;
    }
    bool operator <= (const Student& other) const {
        return grade <= other.grade;
    }
};

std::istream& operator>>(std::istream& is, Student& student) {
    cout << "Insert id and grade\n";
    is >> student.id >> student.grade;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "ID: " << student.id << ", Grade: " << student.grade;
    return os;
}
void Menu_out_sorting() {
    cout << "Choose type of elements:\n"
            "1. integer\n"
            "2. string\n"
            "3. student\n";
}
int sortType_choosing(){
    cout << "Choose type of sorting algorithm you want to use.\n"
            "1. Bubble sort\n"
            "2. Shaker sort\n"
            "3. Merge sort\n"
            "4. Quick sort\n";
    int choice;
    cin >> choice;
    return choice;
}
template <typename T>
void sort_menu(){
    DynamicArray<T> dynArr;
    int choice = sortType_choosing();
    switch (choice) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
    }
}

void interface_3_1() {
    int choice_int;
    while (true) {
        cout << "Laboratory work 1" << endl;
        Menu_out_sorting();
        cin >> choice_int;
        if (choice_int == 1) {
            sort_menu<int>();
        } else if (choice_int == 2) {
            sort_menu<string>();
        } else if(choice_int == 3) {
            sort_menu<Student>();
        } else {
            cout << "Incorrect choice" << endl;
            return;
        }
    }
}
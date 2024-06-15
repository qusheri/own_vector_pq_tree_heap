#include "test_4.h"
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

void Menu_out() {
    cout << "Select action:\n"
            "-1. Print kpl\n"
            "-2. Print lpk\n"
            "0. Go to \"4_lab\" menu\n"
            "1. Push element\n"
            "2. Delete element\n"
            "3. Get root val\n";
}

void Menu_out2() {
    cout << "4. Print result of function map: my queue with function { return queue[i] * 2 - 52; }\n"
            "5. Print result of function where: my queue with \"Get even\" function\n"
            "6. Print result of function reduce: reduce(f(x1,x2) = 2 * x1 + 3 * x2, queue, 4)\n";
}

template<typename T>
void Tree_menu() {
    bst<T> root;
    int action;
    while (true) {
        Menu_out();
        cin >> action;
        if (action == 1) {
            cout << "Insert element to push: \n";
            T elem_to_push;
            cin >> elem_to_push;
            try {
                root.insert(elem_to_push);
            }
            catch (std::out_of_range &e) {}
            catch (std::invalid_argument &e) {}
        } else if (action == 2) {
            cout << "Insert element to delete: \n";
            T elem_to_push;
            cin >> elem_to_push;
            try {
                root.delete_element(elem_to_push);
            }
            catch (std::out_of_range &e) {}
            catch (std::invalid_argument &e) {}
        } else if (action == 0) {
            return;
        } else if (action == 3) {
            cout << root.getroot();
        }
        else if(action == -1){
            vector<T> a = root.kpl();
            for(T elem : a){
                cout << elem << ' ';
            }
            cout << endl;
        }
        else if(action == -2){
            vector<T> a = root.lpk();
            for(T elem: a){
                cout << elem << ' ';
            }
            cout << endl;
        }
        else {
            cout << "INCORRECT CHOICE\n";
            return;
        }
    }
}

void interface_4() {
    int choice_int;
    while (true) {
        cout << "Laboratory work 4" << endl;
        cout << "which type do you want to work with?\n"
                "1. I want to start tests and complete the program\n"
                "2. bst_int\n"
                "3. bst_string\n"
                "4. bst_student\n"
                "0. Main menu\n";
        cin >> choice_int;
        if (choice_int == 1) {
            test_4();
        } else if (choice_int == 0) {
            return;
        } else if (choice_int == 2) {
            Tree_menu<int>();
        } else if(choice_int == 3) {
            Tree_menu<string>();
        } else if(choice_int == 4){
            Tree_menu<Student>();
        } else {
            cout << "Incorrect choice" << endl;
            return;
        }
    }
}
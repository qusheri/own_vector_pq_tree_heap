#include "3_tests.h"

void Pq_Q_Menu_out() {
    cout << "Select action:\n"
            "-1. Print\n"
            "0. Go to \"3_lab\" menu\n"
            "1. Push element\n"
            "2. Pop element\n"
            "3. Get front element\n"
            "4. Get struct's size\n";
}

void Q_Menu_out() {
    cout << "5. Print result of function map: my queue with function { return queue[i] * 2 - 52; }\n"
            "6. Print result of function where: my queue with \"Get even\" function\n"
            "7. Print result of function reduce: reduce(f(x1,x2) = 2 * x1 + 3 * x2, queue, 4)\n";
}

void QueueMenu() {
    Queue<int> q;
    int action;
    while (true) {
        Pq_Q_Menu_out();
        Q_Menu_out();
        cin >> action;
        if (action == 1) {
            cout << "Insert element to push: \n";
            string elem_to_push;
            cin >> elem_to_push;
            try {
                q.push(stoi(elem_to_push));
            }
            catch (std::out_of_range &e) {}
            catch (std::invalid_argument &e) {}
        } else if (action == 2) {
            q.pop();
        } else if (action == 3) {
            cout << "Front elem: " << q.front() << endl;
        } else if (action == 4) {
            cout << "Size: " << q.size() << endl;
        } else if (action == 5) {
            q.map<int>([](int x) { return 2 * x - 52; }).print();
        } else if (action == 6) {
            q.where([](int x) { return x % 2 == 0; }).print();
        } else if (action == 7) {
            std::cout << q.reduce<int>([](int x1, int x2) { return 2 * x1 + 3 * x2; }, 4) << endl;
        } else if (action == -1) {
            q.print();
        } else if (action == 0) {
            return;
        } else {
            cout << "INCORRECT CHOICE\n";
            return;
        }
    }
}

void PQ_menu(){
    PriorityQueue<int> pq;
    int action;
    while (true) {
        Pq_Q_Menu_out();
        cin >> action;
        if (action == 1) {
            cout << "Insert element to push: \n";
            string elem_to_push;
            cin >> elem_to_push;
            try {
                pq.Push(stoi(elem_to_push));
            }
            catch (std::out_of_range &e) {}
            catch (std::invalid_argument &e) {}
        } else if (action == 2) {
            pq.Pop();
        } else if (action == 3) {
            cout << "Front elem: " << pq.Max() << endl;
        } else if (action == 4) {
            cout << "Size: " << pq.size() << endl;
        } else if (action == -1) {
            pq.print();
        } else if (action == 0) {
            return;
        } else {
            cout << "INCORRECT CHOICE\n";
            return;
        }
    }
}

void interface_3() {
    int choice_int;
    while (true) {
        cout << "Laboratory work 3" << endl;
        cout << "which type do you want to work with?\n";
        cout << "1. Queue\n"
                "2. Priority queue\n"
                "3. I want to start tests and complete the program\n"
                "0. Main menu\n";
        cin >> choice_int;
        if (choice_int == 1) {
            QueueMenu();
        } else if (choice_int == 2) {
            PQ_menu();
        } else if (choice_int == 3) {
            test_3();
        } else if (choice_int == 0) {
            return;
        } else {
            cout << "Incorrect choice" << endl;
            return;
        }
    }
}

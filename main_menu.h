#include "iostream"
#include "interface_3_1.h"
using namespace std;
void menu(){
    int act;
    while(true) {
        cout << "Select action:\n"
                "1. Start Sequnce<T> tests\n"
                "2. Start Sorting algorithms tests\n"
                "3. Input source data\n"
                "0. Exit.\n";
        cin >> act;
        switch (act) {
            case 0:
                cout << "Exiting..\n";
                return;
            case 1:
                test_4();
                break;
            case 2:
                test_3_1();
                break;
            case 3:
                interface_3_1();
                break;
            default:
                cout << "Invalid choice..\n"
                        "Exiting..\n";
                return;
        }
    }
}

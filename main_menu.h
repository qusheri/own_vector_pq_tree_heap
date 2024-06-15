#include "iostream"
#include "interface.h"
#include "3_lab_interface.h"
#include "interface_4.h"
using namespace std;
void menu(){
    int lab_num;
    while(true) {
        cout << "Insert lab's num(2, 3 or 4):\n"
                "Insert 0 to exit\n";
        cin >> lab_num;
        switch (lab_num) {
            case 0:
                cout << "Exiting..\n";
                return;
            case 2:
                interface();
                break;
            case 3:
                interface_3();
                break;
            case 4:
                interface_4();
            default:
                cout << "Invalid choice..\n"
                        "Exiting..\n";
                return;
        }
    }
}

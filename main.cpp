#include <iostream>
#include <string>
#include <fstream>
#include "Classes.h"
using namespace std;

int main()
{
    string app_state = "executing";
    Teacher teacher;
    Student student;

    while (app_state == "executing")
    {
        int role;
        cout << "Choose a role:\n1. Teacher.\n2. Student.\n3. Exit\n>";
        cin >> role;
        switch (role) {
        case 1:
            int teacherAction;
            cout << "Choose an action: \n1. Sign up.\n2. Login.\n3. Back\n>";
            cin >> teacherAction;
            switch (teacherAction) {
            case 1:
                teacher.signup();
                break;
            case 2:
                teacher.login();
                break;
            case 3:
                break;
            default:
                cout << "Invalid credentials!\n";
                break;
            }
        case 2:
            int studentAction;
            cout << "Choose an action: \n1. Sign up.\n2. Login.\n3. Back\n>";
            cin >> studentAction;
            switch (studentAction) {
            case 1:
                student.signup();
                break;
            case 2:
                student.login();
                break;
            case 3:
                break;
            default:
                cout << "Invalid credentials!\n";
                break;
            }
        case 3:
            app_state = "exit";
            break;
        default:
            cout << "Invalid credentials!\n";
            break;
        }
    }

    return 0;
}
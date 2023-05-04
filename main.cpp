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
        cout << "Choose a role: \n1. Teacher.\n2. Student.\n3. Exit\n>";
        cin >> role;
        switch (role)
        {
        case 1:
            int teacher_action;
            cout << "Choose an action: \n1. Sign up.\n2. Login.\n3. Back\n>";
            cin >> teacher_action;
            switch (teacher_action)
            {
            case 1:
                teacher.signup();
                break;
            case 2:
                if (teacher.login() == 1)
                {
                    int option;
                    cout << "Choose option: \n1. Create multiple choice questions test.\n>";
                    cin >> option;
                    switch (option)
                    {
                    case 1:
                        teacher.create_test();
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 3:
                break;
            default:
                cout << "Invalid credentials!\n";
                break;
            }
            break;
        case 2:
            int student_action;
            cout << "Choose an action: \n1. Sign up.\n2. Login.\n3. Back\n>";
            cin >> student_action;
            switch (student_action)
            {
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
            break;
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
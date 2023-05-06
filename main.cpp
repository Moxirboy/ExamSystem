#include <iostream>
#include <string>
#include <fstream>
#include<exam_class.h>
using namespace std;

int main()
{
    string app_state = "executing";
    exam_system exam;

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
                exam.signup();
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
                exam.signup();
                break;
            case 2:
                if (student.login())
                {
                    int option;
                    cout << "Choose option:\n1. Go to tests.\n2. Logout\n>";
                    cin >> option;
                    switch (option)
                    {
                    case 1:
                        student.showTests();
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
        case 3:
            app_state = "exit";
            break;
        default:
            cout << "Invalid credentials!\n";
            break;
        }
    }

    // string test_name = "Test name: ";
    // string line = "Test name: tname";
    // int test_name_start_index = line.find(test_name);
    // test_name = line.substr(test_name_start_index + test_name.size());
    // cout << test_name;

    return 0;
}
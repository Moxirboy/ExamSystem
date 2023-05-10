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
                    cout << "Choose option: \n1. Create multiple choice test.\n2. Create essay test.\n3. Create subjective question.\n4. Show essay answers.\n5. Show subjective questions answers.\n6. Show test answers.\n>";
                    cin >> option;
                    switch (option)
                    {
                    case 1:
                        teacher.create_test();
                        break;
                    case 2:
                        teacher.create_essay();
                        break;
                    case 3:
                        teacher.create_subjective();
                        break;
                    case 4:
                        teacher.show_essay_answers();
                        break;
                    case 5:
                        teacher.show_subjective_answers();
                        break;
                    case 6:
                        teacher.show_test_answers();
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
            {
                bool isLoggedIn = student.login();
                if (isLoggedIn)
                {
                    int option;
                    cout << "Choose option:\n1. Go to tests.\n2. Go to essays.\n3. Go to subjective questions.\n4.  Logout.\n>";
                    cin >> option;

                    switch (option)
                    {
                    case 1:
                        student.showTests();
                        break;
                    case 2:
                        student.showEssays();
                        break;
                    case 3:
                        student.showSubjective();
                        break;
                    default:
                        break;
                    }
                }
                break;
            }
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
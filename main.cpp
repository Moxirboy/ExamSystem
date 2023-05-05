#include <iostream>
#include <string>
#include <fstream>
#include <C:\Users\User\Documents\GitHub\ExamSystem\class.h>
using namespace std;
int main()
{
    string app_state = "executing";
    student student;
    teacher teacher;
    do
    {
        string role_state = "executing";
        int role;
        string name, password;

        do
        {
            cout << "1. Student.\n2. Teacher.\n3. Out.\n>";
            cin >> role;
            switch (role)
            {
            case 1:
                int option;
                cout << "1. Sign up.\n2. Login.\n3. Out\n>";
                cin >> option;
                switch (option)
                {
                case 1:
                    cout << "Enter your name: ";
                    cin >> name;
                    cout << "Enter your password: ";
                    cin >> password;
                    student.filesaver(name, password);
                    break;
                case 2:
                    cout << "Enter your name: ";
                    cin >> name;
                    cout << "Enter your password: ";
                    cin >> password;

                    student.filereader(name, password);
                    break;
                case 0:
                    exit(0);
                    break;
                default:
                    cout << "Invalid credentials!";
                    break;
                }
                break;
            case 2:
                cout << "Enter your name: ";
                cin >> name;
                cout << "Enter your password: ";
                cin >> password;

                teacher.filereader(name, password);
                break;

            case 3:
                app_state = "exit";
                break;
            default:
                cout << "Invalid credentials!";
                break;
            }
        } while (role_state == "executing");

    } while (app_state == "executing");
    return 0;
}
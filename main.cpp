#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <Classes.h>
#define Clear system("cls");
using namespace std;
int main()
{
    int a = 5;
    student person1;
    teacher techone;
    string name, password;
    do
    {
        int l;
        int f;
        cout << "1- student or 2-teacher or 0-out " << endl;
        cin >> l;
        Clear switch (l)
        {
        case 1:
            cout << "1-sign or 2-Login or 0-out " << endl;
            cin >> f;
            switch (f)
            {
            case 1:
                cout << "enter name ";
                cin >> name;
                cout << "enter password ";
                cin >> password;
                person1.filesaver(name, password);
                Clear break;
            case 2:
                cout << "name:";
                cin >> name;
                cout << "Password:";
                cin >> password;
                Clear
                    person1.filereader(name, password);
                break;
            case 0:
                exit(0);
                break;
            default:
                cout << "invalid";
                break;
            }
            break;
        case 2:
            cout << "name:";
            cin >> name;
            cout << "Password:";
            cin >> password;
            Clear
                techone.filereader(name, password);
            break;

        case 0:
            exit(0);
            break;
        default:
            cout << "invalid";
            break;
        }
    } while (a);
    Clear
        essay s;
    s.writer();
    essay c;
    c.showStudentsNames();

    return 0;
}
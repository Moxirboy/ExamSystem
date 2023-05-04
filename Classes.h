#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Person
{
private:
    string name;
    string password;
};

class Teacher : Person
{
public:
    void filesaver(string name, string password)
    {
        ofstream file("teachers.txt", ios::app);
        if (!file.is_open())
        {
            cout << "Error opening a file teachers.txt";
            exit(0);
        }

        file << name << "-" << password << endl;

        file.close();
    }

    void filereader(string name, string password)
    {
        ifstream file("teachers.txt", ios::in);

        if (!file.is_open())
        {
            cout << "Error opening a file teachers.txt";
            exit(0);
        }

        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }

    bool userValidator(string requestedName, string requestedPassword)
    {
        ifstream file("teachers.txt", ios::in);
        if (!file.is_open())
        {
            cout << "Error opening a file teachers.txt";
            exit(0);
        }

        string line;
        bool isUserValid = false;
        while (getline(file, line))
        {
            string username = "";
            string password = "";
            bool isDashFound = false;
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == '-')
                {
                    isDashFound = true;
                    continue;
                }

                if (isDashFound)
                {
                    password += line[i];
                }
                else
                {
                    username += line[i];
                }
            }
            cout << username << endl;
            cout << password << endl;

            if (requestedName.compare(username) == 0 && requestedPassword.compare(password) == 0)
            {
                isUserValid = true;
                break;
            }
        }

        return isUserValid;
    }

    void signup()
    {
        string name;
        string password;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> password;

        filesaver(name, password);

        cout << "Teacher successfully created!" << endl;
    }

    void login()
    {
        string name;
        string password;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> password;

        bool isUserValid = userValidator(name, password); // returns true or false

        if (isUserValid)
        {
            cout << "User found!" << endl;
        }
        else
        {
            cout << "Invalid Credentials!" << endl;
        }
    }
};

class Student : Person
{
    public:

    void filesaver(string name, string password)
    {
        ofstream file("students.txt", ios::app);
        if (!file.is_open())
        {
            cout << "Error opening a file students.txt";
            return;
        }

        file << name << "-" << password << endl;

        file.close();
    }

    void filereader(string name, string password)
    {
        ifstream file("students.txt", ios::in);

        if (!file.is_open())
        {
            cout << "Error opening a file students.txt";
            return;
        }

        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }
    
    bool userValidator(string requestedName, string requestedPassword)
    {
        ifstream file("students.txt", ios::in);
        if (!file.is_open())
        {
            cout << "Error opening a file teachers.txt";
            exit(0);
        }

        string line;
        bool isUserValid = false;
        while (getline(file, line))
        {
            string username = "";
            string password = "";
            bool isDashFound = false;
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == '-')
                {
                    isDashFound = true;
                    continue;
                }

                if (isDashFound)
                {
                    password += line[i];
                }
                else
                {
                    username += line[i];
                }
            }
            cout << username << endl;
            cout << password << endl;

            if (requestedName.compare(username) == 0 && requestedPassword.compare(password) == 0)
            {
                isUserValid = true;
                break;
            }
        }

        return isUserValid;
    }


    void signup()
    {
        string name;
        string password;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> password;

        filesaver(name, password);

        cout << "Student successfully created!" << endl;
    }

    void login()
    {
        string name;
        string password;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> password;

        bool isUserValid = userValidator(name, password); // returns true or false

        if (isUserValid)
        {
            cout << "Student found!" << endl;
        }
        else
        {
            cout << "Invalid Credentials!" << endl;
        }
    }
};
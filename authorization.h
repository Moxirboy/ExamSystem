#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool is_digit_only(string input)
{
    bool return_value = true;
    for (int i = 0; i < input.size(); i++)
    {
        if (!isdigit(input[i]))
        { // if not digit
            return_value = false;
        }
    }
    return return_value;
}

class Person
{
private:
    string name;
    string password;

public:
    bool userValidator(string requestedName, string requestedPassword, string filename)
    {
        ifstream file(filename, ios::in);

        if (!file.is_open())
        {
            cout << "Error opening a file " << filename;
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
    void filesaver(string name, string password, string filename)
    {
        ofstream file(filename, ios::app);
        if (!file.is_open())
        {
            cout << "Error opening a file " << filename;
            exit(0);
        }

        file << name << "-" << password << endl;

        file.close();
    }
    bool namefinder(string requestedString, string filename)
    {
        ifstream file(filename, ios::in);

        if (!file.is_open())
        {
            cout << "Error opening a file " << filename;
            exit(0);
        }

        string line;
        bool is_string_found = false;
        while (getline(file, line))
        {
            int dash_index = line.find('-');
            string name = line.substr(0, dash_index);
            if (name.compare(requestedString) == 0)
            {
                is_string_found = true;
                break;
            }
        }

        file.close();
        return is_string_found;
    }
};

class Teacher : public Person
{
public:
    void signup()
    {
        string name;
        string password;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> password;

        bool user_exists = namefinder(name, "teachers.txt");
        if (user_exists)
        {
            cout << "Sorry, user with this name already exists!" << endl;
        }
        else
        {
            filesaver(name, password, "teachers.txt");
            cout << "Teacher successfully created!" << endl;
        }
    }

    bool login()
    {
        string name;
        string password;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> password;

        bool isUserValid = userValidator(name, password, "teachers.txt"); // returns true or false

        if (isUserValid)
        {
            cout << "Successfully logged in!" << endl;
        }
        else
        {
            cout << "Invalid Credentials!" << endl;
        }

        return isUserValid;
    }

    void create_test()
    {
        ofstream file("test.txt");

        if (!file.is_open())
        {
            cout << "Error opening a file test.txt";
            exit(0);
        }

        string test_name;
        int questions_number;
        cout << "Test name: ";
        cin >> test_name;
        cout << "Test questions number: ";
        cin >> questions_number;

        file << "Test name: " << test_name << endl;
        for (int i = 1; i <= questions_number; i++)
        {
            string question_name;
            string variant_a, variant_b, variant_c;
            string correct_variant;
            cout << "Question #" << i << ": ";
            cin >> question_name;

            cout << " a. ";
            cin >> variant_a;

            cout << " b. ";
            cin >> variant_b;

            cout << " c. ";
            cin >> variant_c;
        start:
            cout << "Correct answer (write variant): ";
            cin >> correct_variant;
            if (correct_variant != "a" && correct_variant != "b" && correct_variant != "c")
            {
                cout << "You should write a, b or c! \n";
                goto start;
            }
            file << "Question" << i << ": " << question_name << endl
                 << "a) " << variant_a << endl
                 << "b) " << variant_b << endl
                 << "c) " << variant_c << endl;
            << "Correct Answer: " << correct_variant << endl;
        }

        file << "---" << endl;

        cout << "Test successfully created!\n";

        file.close();
    }
};

class Student : public Person
{
public:
    void signup()
    {
        string name;
        string password;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> password;

        bool student_exists = namefinder(name, "students.txt");
        if (student_exists)
        {
            cout << "Sorry, student with this name already exists!";
        }
        else
        {
            filesaver(name, password, "students.txt");
            cout << "Student successfully created!" << endl;
        }
    }

    bool login()
    {
        string name;
        string password;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> password;

        bool isUserValid = userValidator(name, password, "students.txt"); // returns true or false

        if (isUserValid)
        {
            cout << "Student found!" << endl;
        }
        else
        {
            cout << "Invalid Credentials!" << endl;
        }

        return isUserValid;
    }


};
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
    bool check_user(string name, string password, string filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "Error opening a file " << filename;
            exit(0);
        }

        string line;
        string name_query = "Name: ";
        string password_query = "Password: ";
        bool is_user_valid = false;
        while (getline(file, line))
        {
            if (line.find(name_query) != string::npos)
            {
                string found_name = line.substr(name_query.size());
                if (found_name == name)
                {
                    is_user_valid = true;
                }
            }
            else if (line.find(password_query) != string::npos && is_user_valid)
            {
                string found_password = line.substr(password_query.size());
                if (found_password == password)
                {
                    is_user_valid = true;
                    break;
                }
                else
                {
                    is_user_valid = false;
                }
            }
        }

        file.close();

        return is_user_valid;
    }

    void save_user(string name, string password, string filename)
    {
        ofstream file(filename, ios::app);
        if (!file.is_open())
        {
            cout << "Error opening a file " << filename;
            exit(0);
        }

        file << "Name: " << name << endl;
        file << "Password: " << password << endl
             << "---" << endl;
    }

    string get_name()
    {
        return name;
    }
    string get_password()
    {
        return password;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_password(string password)
    {
        this->password = password;
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

        bool user_exists = check_user(name, password, "teachers.txt");
        if (user_exists)
        {
            cout << "Sorry, user with this name already exists!" << endl;
        }
        else
        {
            save_user(name, password, "teachers.txt");
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

        bool is_user_valid = check_user(name, password, "teachers.txt");

        if (is_user_valid)
        {
            set_name(name);
            set_password(password);
            cout << "Successfully logged in!" << endl;
        }
        else
        {
            cout << "Invalid Credentials!" << endl;
        }

        return is_user_valid;
    }

    void create_test()
    {
        ofstream file("test.txt", ios::app);

        if (!file.is_open())
        {
            cout << "Error opening a file test.txt";
            exit(0);
        }

        string test_name;
        int questions_number;
        cout << "Test name: ";
        cin.ignore();
        getline(cin, test_name, '\n');
        cout << "Questions number: ";
        cin >> questions_number;

        file << "Test name: " << test_name << endl;
        for (int i = 1; i <= questions_number; i++)
        {
            string question_name;
            string variant_a, variant_b, variant_c;
            string correct_variant;
            cout << "Question #" << i << ": ";
            cin.ignore();
            getline(cin, question_name);

            cout << " a. ";
            getline(cin, variant_a);

            cout << " b. ";
            getline(cin, variant_b);

            cout << " c. ";
            getline(cin, variant_c);

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
                 << "c) " << variant_c << endl
                 << "Correct Answer: " << correct_variant << endl;
        }

        file << "---" << endl;

        cout << "Test successfully created!\n";

        file.close();
    }

    void create_essay()
    {
        ofstream file("essay.txt", ios::app);

        if (!file.is_open())
        {
            cout << "Error opening a file essay.txt";
            exit(0);
        }

        string essay_question;
        int min_size = 0;
        cout << "Write essay question: ";
        cin.ignore();
        getline(cin, essay_question);
        cout << "Write minimum size of essay: ";
        cin >> min_size;

        file << "Essay question: " << essay_question << endl;
        file << "Minimum size: " << min_size << endl
             << "---" << endl;

        cout << "Essay successfully created!\n";
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

        bool student_exists = check_user(name, password, "students.txt");
        if (student_exists)
        {
            cout << "Sorry, such student already exists!";
        }
        else
        {
            save_user(name, password, "students.txt");
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

        bool is_user_valid = check_user(name, password, "students.txt");

        if (is_user_valid)
        {
            set_name(name);
            set_password(password);
            cout << "Successfully logged in!" << endl;
        }
        else
        {
            cout << "Invalid Credentials!" << endl;
        }

        return is_user_valid;
    }

    void showTests()
    {
        ifstream file("test.txt");

        if (!file.is_open())
        {
            cout << "Error opening file test.txt";
            exit(0);
        }

        string line;
        string tests_found[10] = {};
        int tests_found_num = 0;
        while (getline(file, line))
        {
            string query = "Test name: ";
            if (line.find(query) != string::npos)
            {
                string test_name = line.substr(query.size());
                tests_found[tests_found_num] = test_name;
                tests_found_num += 1;
            }
        }

        file.clear();
        file.seekg(0);

        cout << "Choose a test: " << endl;
        int choosen_test_num;
        for (int i = 0; i < tests_found_num; i++)
        {
            cout << " " << i << ". " << tests_found[i] << endl;
        }
        cout << ">";
        cin >> choosen_test_num;
        string choosen_test_name = tests_found[choosen_test_num];

        int points = 0;

        while (getline(file, line))
        {
            string query = "Test name: ";
            if (line.find(query) != string::npos)
            {
                string test_name = line.substr(query.size());
                if (test_name == choosen_test_name)
                {
                    string in_line;
                    string correct_answer;
                    string answer;
                    int answer_num = 0;
                    while (getline(file, in_line))
                    {
                        string correct_answer_query = "Correct Answer: ";
                        if (in_line.find(correct_answer_query) != string::npos)
                        {
                            correct_answer = in_line.substr(correct_answer_query.size());
                            cout << "Write your answer: ";
                            cin >> answer;
                            if (answer == correct_answer)
                            {
                                points += 1;
                            }
                        }
                        else
                        {
                            cout << in_line << endl;
                        }
                    }
                }
            }
        }

        cout << "\nCorrect Answers: " << points << endl;

        file.close();
    }

    void showEssays()
    {
        ifstream essay_file("essay.txt");
        ofstream essay_answers_file("essayAnswers.txt", ios::app);

        if (!essay_file.is_open())
        {
            cout << "Error opening file essay.txt";
            exit(0);
        }

        string line;

        essay_file.clear();
        essay_file.seekg(0);

        string essays_found[3][3] = {};
        int essays_found_num = 0;

        while (getline(essay_file, line))
        {
            string question_query = "Essay question: ";
            string size_query = "Minimum size: ";

            if (line.find(question_query) != string::npos)
            {
                string question = line.substr(question_query.size());
                essays_found[essays_found_num][0] = question;
                essays_found_num += 1;
            }
            else if (line.find(size_query) != string::npos)
            {
                string size = line.substr(size_query.size());
                essays_found[essays_found_num - 1][1] = size;
            }
        }

        essay_file.clear();
        essay_file.seekg(0);

        cout << "Choose an essay: " << endl;
        int choosen_essay_num;
        for (int i = 0; i < sizeof(essays_found) / sizeof(essays_found[0]); i++)
        {
            cout << " " << i << ". " << essays_found[i][0] << endl;
        }
        cout << ">";
        cin >> choosen_essay_num;
        string choosen_essay[2];
        choosen_essay[0] = essays_found[choosen_essay_num][0];
        choosen_essay[1] = essays_found[choosen_essay_num][1];

    essay_start:
        string essay_text;
        cout << "Write an essay (At least " << stoi(choosen_essay[1]) << " characters): " << endl;
        cin.ignore();
        getline(cin, essay_text);
        if (essay_text.size() < stoi(choosen_essay[1]))
        {
            cout << "Essay myst be at least " << choosen_essay[1] << " characters!" << endl;
            goto essay_start;
        }
        else
        {
            essay_answers_file << "Name: " << Person::get_name() << endl;
            essay_answers_file << "Answer: " << essay_text << endl
                               << "---" << endl;

            cout << "Answer recorded!" << endl;
        }
    }
};
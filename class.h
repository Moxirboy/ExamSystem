#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#define Clear system("cls");
using namespace std;
class person
{
protected:
    string name;
    string password;
};
class teacher : person
{
public:
    void filesaver(string name, string password)
    {
        ofstream outfile("Teacher", ios::app);
        if (!outfile.is_open())
        {
            cout << "Failed to open file." << endl;
        }

        outfile << name << endl
                << password << endl;
        outfile.close();
    }
    void filereader(string name, string password)
    {
        ifstream infile("Teacher", ios::in);
        string line;
        bool found = false;
        bool gound = false;
        while (getline(infile, line))
        {
            if (line.find(name) != string::npos)
            {
                found = true;
                break;
            }
        }
        while (getline(infile, line))
        {
            if (line.find(password) != string::npos)
            {
                gound = true;
                break;
            }
        }
        if (found)
        {
            cout << "Found the word '" << name << "' in the file." << endl;
        }
        else
        {
            cout << "Did not find the word '" << name << "' in the file." << endl;
        }

        if (gound)
        {
            cout << "Found the word '" << password << "' in the file." << endl;
        }
        else
        {
            cout << "Did not find the word '" << password << "' in the file." << endl;
        }
    }
};

class student : person
{
public:
    void filesaver(string name, string password)
    {
        ofstream outfile("person", ios::app);
        if (!outfile.is_open())
        {
            cout << "Failed to open file." << endl;
        }

        outfile << name << endl
                << password << endl;
        outfile.close();
    }
    void filereader(string name, string password)
    {
        ifstream infile("person", ios::in);
        string line;
        bool found = false;
        bool gound = false;
        while (getline(infile, line))
        {
            if (line.find(name) != string::npos)
            {
                found = true;
                break;
            }
        }
        while (getline(infile, line))
        {
            if (line.find(password) != string::npos)
            {
                gound = true;
                break;
            }
        }
        if (found)
        {
            cout << "Found the word '" << name << "' in the file." << endl;
        }
        else
        {
            cout << "Did not find the word '" << name << "' in the file." << endl;
        }

        if (gound)
        {
            cout << "Found the word '" << password << "' in the file." << endl;
        }
        else
        {
            cout << "Did not find the word '" << password << "' in the file." << endl;
        }
    }
};
class essay
{
public:
    void writer()
    {
        char ch;
        ofstream outfile("test.txt", ios::app);
        if (!outfile.is_open())
        {
            cout << "Failed to open file." << endl;
        }
        string c;
        outfile << "#";
        cout << "name of question \ntype '#' when it is done" << endl;
        do
        {
            ch = cin.get();
            if (ch == '\n')
            {
                ch = ' ';
            }
            outfile.put(ch);

        } while (ch != '#');

        cout << "Enter question" << endl;
        cout << "type '$' when it is done" << endl;
        outfile << "$";
        do
        {
            ch = cin.get();
            if (ch == '\n')
            {
                ch = ' ';
            }
            outfile.put(ch);

        } while (ch != '$');
        outfile << endl;
        outfile.close();
    }
    void Question_Name()
    {
        ifstream outfile("test.txt");
        string line;
        cout << "Questions:" << endl;
        int a = 1;
        while (getline(outfile, line))
        {
            bool found = false;
            char symbol = '#';
            cout << a << ".";
            for (char c : line)
            { // iterate over characters in line
                if (c == symbol)
                {
                    found = true;
                    continue;
                }
                if (c == '$')
                {
                    break;
                }
                if (found)
                {
                    cout << c;
                }
            }
            cout << "  ";
            a++;
        }
        outfile.close();
    }
    void Question(int a)
    {
        ifstream outfile("test.txt", ios::app);
        string line;
        int g = 0;
        cout << "Question:";
        while (getline(outfile, line))
        { // read file line by line
            bool found = false;
            char symbol = '$';
            g++;
            if (g == a)
            {
                for (char c : line)
                { // iterate over characters in line
                    if (c == symbol)
                    {
                        found = true;
                        continue;
                    }
                    if (found)
                    {
                        cout << c;
                    }
                }
            }
        }
        cout << endl;
        outfile.close();
    }
    void Write_Answer(string name, int a)
    {

        ofstream outfile("answer.txt", ios::app);
        if (!outfile.is_open())
        {
            cout << "Failed to open file." << endl;
        }
        ifstream file("test.txt", ios::app);
        string line;
        int g = 0;
        outfile << "~";
        while (getline(file, line))
        { // read file line by line
            bool found = false;
            char symbol = '#';
            g++;
            if (g == a)
            {
                for (char c : line)
                { // iterate over characters in line
                    if (c == symbol)
                    {
                        found = true;
                        continue;
                    }
                    if (c == '$')
                    {
                        break;
                    }
                    if (found)
                    {
                        outfile << c;
                    }
                }
            }
        }
        outfile << "~";
        cout << endl;
        outfile << "#" << name << "#";
        char ch;
        cout << "Enter Answer" << endl;
        cout << "type '$' when it is done" << endl;
        outfile << "$";
        do
        {
            ch = cin.get();
            if (ch == '\n')
            {
                ch = ' ';
            }
            outfile.put(ch);

        } while (ch != '$');
        outfile << endl;
        outfile.close();
        file.close();
    }
    void show_Students_Names()
    {
        ifstream outfile("answer.txt");
        string line;
        cout << "Students names:" << endl;
        int a = 1;
        while (getline(outfile, line))
        {
            bool found = false;
            char symbol = '#';
            cout << a << ".";
            for (char c : line)
            { // iterate over characters in line
                if (c == symbol)
                {
                    found = true;
                    continue;
                }
                if (c == '$')
                {
                    break;
                }
                if (found)
                {
                    cout << c;
                }
            }
            cout << "  ";
            a++;
        }
        outfile.close();
    }
    void show_answer(int a)
    {
        ifstream file("answer.txt", ios::app);
        string line;
        int f = 0;
        cout << "Name:";
        while (getline(file, line))
        { // read file line by line
            bool found = false;
            char symbol = '#';
            f++;
            if (f == a)
            {
                for (char c : line)
                { // iterate over characters in line
                    if (c == symbol)
                    {
                        found = true;
                        continue;
                    }
                    if (c == '$')
                    {
                        break;
                    }
                    if (found)
                    {
                        cout << c;
                    }
                }
            }
        }
        cout << endl;
        file.close();
        ifstream file("answer.txt", ios::app);
        string line2;
        int line_of_question = 0;
        int helper = 0;
        cout << "answered these quetions";
        while (getline(file, line2))
        { // read file line by line
            bool found = false;
            char symbol = '~';
            line_of_question++;
            for (char c : line2)
            { // iterate over characters in line
                if (c == symbol)
                {
                    found = true;
                    helper++;
                    continue;
                }
                if (c == '#')
                {
                    helper = 0;
                    cout << endl;
                    break;
                }

                if (found)
                {
                    if (helper == 1)
                    {
                        cout << line_of_question << ".";
                        helper++;
                    }
                    cout << c;
                }
            }
        }
        ifstream ile("answer.txt", ios::app);
        string sine;
        int x = 0;
        cout << "Question:";
        while (getline(ile, sine))
        { // read file line by line
            bool found = false;
            char symbol = '~';
            x++;
            if (x == a)
            {
                for (char c : sine)
                { // iterate over characters in line
                    if (c == symbol)
                    {
                        found = true;
                        continue;
                    }
                    if (c == '#')
                    {
                        break;
                    }
                    if (found)
                    {
                        cout << c;
                    }
                }
            }
        }
        cout << endl;
        ile.close();
        ifstream outfile("answer.txt");
        string kine;
        int g = 0;
        cout << endl;
        cout << "Answer:" << endl;
        while (getline(outfile, kine))
        { // read file line by line
            bool found = false;
            char symbol = '$';
            g++;
            if (g == a)
            {
                for (char c : kine)
                { // iterate over characters in line
                    if (c == symbol)
                    {
                        found = true;
                        continue;
                    }

                    if (found)
                    {
                        cout << c;
                    }
                }
            }
        }
        cout << endl;
        cout << "***************************************************************************" << endl;

        outfile.close();
        ofstream outile("marks.txt", ios::app);
        char l;
        cout << "do you want to evaluate (Y/N)" << endl;
        cin >> l;
        if (l == 'y' || l == 'Y')
        {

            ifstream fil("answer.txt", ios::app);
            string line;
            int f = 0;
            // cout << "Id:";
            outile << "^";
            while (getline(fil, line))
            { // read file line by line
                bool found = false;
                char symbol = '#';
                f++;
                if (f == a)
                {
                    for (char c : line)
                    { // iterate over characters in line
                        if (c == symbol)
                        {
                            found = true;
                            continue;
                        }
                        if (c == '$')
                        {
                            break;
                        }
                        if (found)
                        {
                            outile << c;
                        }
                    }
                }
            }
            outile << "^";
            fil.close();
            ifstream fle("answer.txt", ios::app);
            string sine;
            int x = 0;
            // cout << "Question:";
            outile << "@";
            while (getline(fle, sine))
            { // read file line by line
                bool found = false;
                char symbol = '~';
                x++;
                if (x == a)
                {
                    for (char c : sine)
                    { // iterate over characters in line
                        if (c == symbol)
                        {
                            found = true;
                            continue;
                        }
                        if (c == '#')
                        {
                            break;
                        }
                        if (found)
                        {
                            outile << c;
                        }
                    }
                }
            }
            outile << "@";
            fle.close();
            char ch;
            if (!outile.is_open())
            {
                cout << "Failed to open file." << endl;
            }
            string c;
            outile << "#";
            cout << "Enter grades \ntype '#' when it is done" << endl;
            do
            {
                ch = cin.get();
                if (ch == '\n')
                {
                    ch = ' ';
                }
                outile.put(ch);

            } while (ch != '#');

            cout << "do u want to leave comment Y/N" << endl;
            char s;
            cin >> s;
            if (s == 'y' || s == 'Y')
            {
                cout << "Enter qcomment" << endl;
                cout << "type '$' when it is done" << endl;
                outile << "$";
                do
                {
                    ch = cin.get();
                    if (ch == '\n')
                    {
                        ch = ' ';
                    }
                    outile.put(ch);

                } while (ch != '$');
            }
            else
            {
                cout << "Happy for you!!";
            }
            outile << endl;
            outile.close();
            file.close();
        }
        else
        {
            cout << "Happy for you!!";
        }
    }
    void get_mark(string name)
    {
        ifstream outfile("marks.txt", ios::app);
        string line2;
        string line;
        int choice;
        bool found = false;
        while (getline(outfile, line2))
        {
            if (line2.find(name) != string::npos)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            outfile.seekg(0);
            int choice;
            ifstream file("marks.txt", ios::app);
            string sine;
            int line_of_question = 0;
            int helper = 0;
            cout << "YOU answered to this questions";

            while (getline(file, sine))
            { // read file line by line
                bool found = false;
                char symbol = '@';
                line_of_question++;
                for (char c : sine)
                { // iterate over characters in line
                    if (c == symbol)
                    {
                        found = true;
                        helper++;
                        continue;
                    }
                    if (c == '#')
                    {
                        helper = 0;
                        cout << endl;
                        break;
                    }

                    if (found)
                    {
                        if (helper == 1)
                        {
                            cout << line_of_question << ".";
                            helper++;
                        }
                        cout << c;
                    }
                }
            }
            file.close();
            cout << "Enter which answer of question do you want to see?" << endl;
            cin >> choice;
            int helper1;
            cout << "Your mark is ";
            while (getline(file, line))
            { // read file line by line
                bool found = false;
                char symbol = '#';
                helper1++;
                if (helper1 == choice)
                {
                    for (char c : line)
                    { // iterate over characters in line
                        if (c == symbol)
                        {
                            found = true;
                            continue;
                        }
                        if (c == '$')
                        {

                            break;
                        }

                        if (found)
                        {

                            cout << c;
                        }
                    }
                }
            }
            string line1;
            cout << "comment from teacher\n";
            while (getline(file, line1))
            { // read file line by line
                bool found = false;
                char symbol = '$';
                helper1++;
                if (helper1 == choice)
                {
                    for (char c : line1)
                    { // iterate over characters in line
                        if (c == symbol)
                        {
                            found = true;
                            continue;
                        }
                        if (c == '$')
                        {

                            break;
                        }

                        if (found)
                        {

                            cout << c;
                        }
                    }
                }
            }
        }
        else
        {
            cout << "You havent answered yet!!" << endl;
        }
    }
};
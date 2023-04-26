#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#define Clear system("cls");
using namespace std;
class essay
{
public:
    void writer()
    {
        ofstream outfile("test.txt", ios::app);
        if (!outfile.is_open())
        {
            cout << "Failed to open file." << endl;
        }
        string c;
        cout << "name of question" << endl;
        cin >> c;
        outfile << "#" << c << "#";
        char ch;
        cout << "type '$' when it is done" << endl;
        outfile << "$";
        do
        {
            cin >> ch;
            outfile.put(ch);

        } while (ch != '$');

        outfile.close();
    }

public:
    void QuestionName()
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
                        cout << c << " ";
                    }
                }
            }
        }
        cout << endl;
        outfile.close();
    }
    void WriteAnswer(string name)
    {
        ofstream outfile("answer.txt", ios::app);
        if (!outfile.is_open())
        {
            cout << "Failed to open file." << endl;
        }
        outfile << "#" << name << "#";
        char ch;
        cout << "type '$' when it is done" << endl;
        outfile << "$";
        do
        {
            cin >> ch;
            outfile.put(ch);

        } while (ch != '$');
        outfile << endl;
        outfile.close();
    }
    void showStudentsNames()
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
    void showAnswer(int a)
    {
        ifstream outfile("answer.txt");
        string line;
        int b[5];
        int g = 0;
        cout << endl;
        cout << "Question:" << endl;
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
                        cout << c << " ";
                    }
                }
            }
        }
        cout << endl;
        outfile.close();
        char l;
        cout << "do you want to evaluate (Y/N)" << endl;
        cin >> l;
        string korishga;
        if (l == 'Y' || l == 'y')
        {
            ofstream outfile("Marks.txt", ios::app);
            ifstream file("answers.txt", ios::app);
            if (!outfile.is_open())
            {
                cout << "Failed to open file." << endl;
            }
            string line;
            char c;
            char d = '#';
            outfile << d;
            int g = 0;
            while (getline(file, line))
            {
                g++;
                bool found = false;
                char symbol = '#';
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
            outfile << d;
            char h = '%';
            outfile << h;
            while (getline(file, line))
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
                            outfile << c;
                        }
                    }
                }
            }
            outfile << h;
            char ch;
            cout << "type '$' when it is done" << endl;
            outfile << "$";
            do
            {
                cin >> ch;
                outfile.put(ch);

            } while (ch != '$');
            file.close();
            outfile.close();
        }
    }
};

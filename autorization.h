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
    void filereader(string name, string password, int *checker, int *checker1)
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
            *checker = 1;
        }
        else
        {
            cout << "Did not find the word '" << name << "' in the file." << endl;
        }

        if (gound)
        {
            *checker1 = 1;
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
    void filereader(string name, string password, int *checker, int *checker1)
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
            *checker = 1;
        }
        else
        {
            cout << "Did not find the word '" << name << "' in the file." << endl;
        }

        if (gound)
        {
            *checker1 = 1;
        }
        else
        {
            cout << "Did not find the word '" << password << "' in the file." << endl;
        }
    }
};
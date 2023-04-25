#include<iostream>
#include<string>
#include<fstream>
#include <cstdlib>
#include "hozircha.h"
#define Clear system("cls");
using namespace std;
class person {
protected:
    string name;
    string password;

};
class teacher :person
{
public:
    void filesaver(string name, string password) {
        ofstream outfile("Teacher", ios::app);
        if (!outfile.is_open()) {
            cout << "Failed to open file." << endl;
        }

        outfile << name << endl << password << endl;
        outfile.close();
    }
    void filereader(string name, string password) {
        ifstream infile("Teacher", ios::in);
        string line;
        bool found = false;
        bool gound = false;
        while (getline(infile, line)) {
            if (line.find(name) != string::npos) {
                found = true;
                break;
            }
        }
        while (getline(infile, line)) {
            if (line.find(password) != string::npos) {
                gound = true;
                break;
            }
        }
        if (found) {
            cout << "Found the word '" << name << "' in the file." << endl;
        }
        else {
            cout << "Did not find the word '" << name << "' in the file." << endl;
        }

        if (gound) {
            cout << "Found the word '" << password << "' in the file." << endl;
        }
        else {
            cout << "Did not find the word '" << password << "' in the file." << endl;
        }
    }

};

class student :person
{
public:
    void filesaver(string name, string password) {
        ofstream outfile("person", ios::app);
        if (!outfile.is_open()) {
            cout << "Failed to open file." << endl;
        }

        outfile << name << endl << password << endl;
        outfile.close();
    }
    void filereader(string name, string password) {
        ifstream infile("person", ios::in);
        string line;
        bool found = false;
        bool gound = false;
        while (getline(infile, line)) {
            if (line.find(name) != string::npos) {
                found = true;
                break;
            }
        }
        while (getline(infile, line)) {
            if (line.find(password) != string::npos) {
                gound = true;
                break;
            }
        }
        if (found) {
            cout << "Found the word '" << name << "' in the file." << endl;
        }
        else {
            cout << "Did not find the word '" << name << "' in the file." << endl;
        }

        if (gound) {
            cout << "Found the word '" << password << "' in the file." << endl;
        }
        else {
            cout << "Did not find the word '" << password << "' in the file." << endl;
        }
    }
};
int main() {
    // int a=5;
    // student person1;
    // teacher techone;
    // string name,password;
    // do{
    //     int l;
    //     int f;
    //     cout<<"1- student or 2-teacher or 0-out "<<endl;
    //     cin>>l;
    //     Clear
    //     switch (l)
    //     {
    //     case 1:
    //     cout<<"1-sign or 2-Login or 0-out " <<endl;
    //     cin>>f;
    // switch (f){
    // case 1:
    // cout<<"enter name ";
    // cin>>name;
    // cout<<"enter password ";
    // cin>>password;
    // person1.filesaver(name,password);
    // Clear
    //  break;
    // case 2:
    // cout<<"name:";
    // cin>>name;
    // cout<<"Password:";
    // cin>>password;
    // Clear
    // person1.filereader(name,password);
    // break;
    // case 0: exit(0);break;    
    // default:cout<<"invalid";break;} break;
    // case 2: 
    // cout<<"name:";
    // cin>>name;
    // cout<<"Password:";
    // cin>>password;
    // Clear
    // techone.filereader(name,password); break;

    // case 0: exit(0);break;
    // default: cout<<"invalid";break; }}while(a);
    // Clear
    // essay s;
    // s.writer();
    essay c;
  
    c.seek();
    c.seek();
    c.seekName();
    c.seekName();

    c.seekName();
    return 0;
}
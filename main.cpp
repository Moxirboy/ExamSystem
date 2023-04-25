#include<iostream>
#include<string>
#include<fstream>
#include <cstdlib>

#define Clear system("cls");
using namespace std;
class essay {
public: void writer() {
    ofstream outfile("test.txt", ios::app);
    if (!outfile.is_open()) {
        cout << "Failed to open file." << endl;
    }
    string c;
    cout << "name of question" << endl;
    cin >> c;
    outfile <<"!!" << c <<"!!" << endl;
    char ch;
    cout << "type '$' when it is done" << endl;
    outfile << "$";
    do {
        ch = std::cin.get();
        outfile.put(ch);
        
    } while (ch != '$');
    outfile.close();
}
};
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
    string filename = "myfile.txt";
    string word_to_find = "hello";
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        int line_number = 0;
        int word_position = -1;
        int cumulative_length = 0;

        while (getline(file, line)) {
            line_number++;
            word_position = line.find(word_to_find);
            if (word_position != -1) {
                cout << "Word found on line " << line_number << " at position " << word_position << endl;
                cout << "Position in file: " << cumulative_length + word_position << endl;
                break;
            }
            cumulative_length += line.length() + 1; // add 1 for the newline character
        }

        if (word_position == -1) {
            cout << "Word not found in file." << endl;
        }

        file.close();
    }
    else {
        cout << "Error opening file." << endl;
    }
    return 0;
}
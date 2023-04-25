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
    outfile <<"#" << c <<"#" << endl;
    char ch;
    cout << "type '$' when it is done" << endl;
    outfile << "$";
    do {
        ch = std::cin.get();
        outfile.put(ch);
        
    } while (ch != '$');
    outfile<<endl;
    outfile.close();
}
public: 
void seekName(){
    ifstream outfile("test.txt", ios::app);
    string line;
     while (getline(outfile, line)) {
        bool found = false;
        char symbol='#';
        for (char c : line) { // iterate over characters in line
            if(c==symbol){
                found=true;
                continue;
            }
            if(c=='$'){
               break;
            }
            if(found){
                cout<<c;
            }
        }
        


     }
    outfile.close();
}





void seek(){
    ifstream outfile("test.txt", ios::app);
    string line;
    cout<<"Question:";
    while (getline(outfile, line)) { // read file line by line
        bool found = false;
        char symbol='$';

        for (char c : line) { // iterate over characters in line
            if(c==symbol){
                found=true;
                continue;
            }
            if(found){
                cout<<c;
            }
        }

    }
    cout<<endl;
    outfile.close();
}
};
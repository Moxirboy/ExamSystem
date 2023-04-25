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
void seek(){
    
}
};
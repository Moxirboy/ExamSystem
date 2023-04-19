#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Person{
private:
    string name;
    string password;
public:
Person(){}
Person(string id,string password){
    name=id;
    this->password=password;   
}
void filesaver(string name,string password){
   ofstream outfile("person", ios::app);
    if (!outfile.is_open()) {
        cout << "Failed to open file." << endl;
    }
    
    outfile << name<<endl<<password<<endl;
    outfile.close();}
    void filereader(string name,string password){
        ifstream infile("person",ios::in);
        string line;
        bool found=false;
        bool gound=false;
        while(getline(infile,line)){
            if(line.find(name)!=string::npos){
                found=true;
                break;
            }
        }
        while(getline(infile,line)){
            if(line.find(password)!=string::npos){
                gound=true;
                break;
            }
        }
        if (found) {
        cout << "Found the word '" << name << "' in the file." << endl;
    } else {
        cout << "Did not find the word '" << name<< "' in the file." << endl;
    }
    
    if (gound) {
        cout << "Found the word '" << password << "' in the file." << endl;
    } else {
        cout << "Did not find the word '" << password<< "' in the file." << endl;
    }
    }
};
int main(){
    int a=5;
    Person person1;
    string name,password;
    do{
        int l=0;
        cout<<"Login or Password " <<endl;
        cin>>l;
    switch (l){
        case 1:
    cout<<"enter name ";
    cin>>name;
    cout<<"enter pasword";
    cin>>password;
    person1.filesaver(name,password);
            break;
    case 2:
    cout<<"name:";
    cin>>name;
    cout<<"Password:";
    cin>>password;
    person1.filereader(name,password);
        default:
            break;
    case 3: exit(0);break;    }
    } while(a);
    system("pause");
    return 0;
}
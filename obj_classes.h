#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class objective
{
protected:
    void writer_obj() {
        char character;
        char character1;
        char character2;
        string line;
        int choice;
        ofstream infile("question_names.txt", ios::app);
        if (!infile.is_open())
        {
            cout << "Failed to open file." << endl;
        }
        cout << "Do you want 1.checker or 2.check for yourself\n";
        cin >> choice;
        if (choice == 1) {
            infile << "$";
        }
        cout << "name of question \ninput enter 2 times \n:";
        do
        {
            character = cin.get();
            if (character == '\n')
            {
                character1 = cin.get();
                if (character1 == '\n') { break; }
                character = ' ';

            }
            line = line + character;
            infile.put(character);
        } while (character != '|');
        infile << endl;
        infile.close();
        line = line + ".txt";
        ofstream file(line, ios::app);
        int number_of_questions;
        
        int blocker = 0;
        char block;
        cout << "How many objective questions do you want? \n:";
        cin >> number_of_questions;
        file << choice;
        file << endl;
        cout << "input enter 2 times \n";
        cout << "**************************************************\n";
        for (int i = 1; i <= number_of_questions; i++) {
            cout << "Question \nenter\n:" << " " << i << ".";
            do
            {
                if (blocker == 0) { block = cin.get(); blocker++; }
                character2 = cin.get();
                if (character2 == '\n')
                {
                    character1 = cin.get();
                    if (character1 == '\n') { break; }
                    file << " ";
                }
                else {
                    file.put(character2);
                }

            } while (character2 != '|');
            if (choice == 1) {



                file << "$";
                cout << "Answer \nenter\n:" << " " << i << ".";

                do
                {
                    character = cin.get();
                    if (character == '\n')
                    {
                        character1 = cin.get();
                        if (character1 == '\n') { break; }
                        continue;
                    }
                    character = tolower(character);
                    file.put(character);

                } while (character != '|');
                file << "$";
            }


            file << endl;
        }
        cout << "Over go to sleep";
        file.close();
    }
    void possible_questions() {
        string line;
        int increment = 0;
        int a;
        int* choice = &a;
        cout << "possible questions\n>";
        ifstream outfile("question_names.txt");
        while (getline(outfile, line)) {
            increment++;

            cout << increment << "." << line << "\t";
        }
        outfile.close();
        cout << "\n";
        cout << "which do you want to answer\n:";
        cin >> a;

    }
    void show_question(int a, string name) {
        ofstream answered("answered.txt", ios::app);
        ifstream outfile("question_names.txt");
        string line;
        string question_name;
        int g = 0;
        char input;
        string answer;
        string answer1;
        while (getline(outfile, line)) {
            g++;
            if (g == a) {
                for (char c : line) {
                    question_name = question_name + c;
                }
            }
        }
        outfile.close();
        answered << question_name << endl;
        string answer_name = question_name + "_ans.txt";
        question_name = question_name + ".txt";
        ifstream checker(question_name);
        getline(checker, line);
        int score = 0;
        if (line == "1") {
            while (getline(checker, line)) {
                for (char c : line) {
                    if (c == '$') {
                        break;
                    }
                    else {
                        cout << c;
                    }
                }
                do {
                    input = cin.get();
                    if (input == '\n') {
                        if (input == '\n') {
                            break;
                        }
                    }if (input == ' ') {

                    }
                    else {
                        input = tolower(input);
                        answer = answer + input;
                    }
                } while (true);
            }
            int i = 0;
            for (char c : line) {
                if (c == '$') {
                    i++;
                }
                if (i == 1) {
                    answer1 = answer1 + c;
                }
            }
            if (answer == answer1) {
                score++;
            }

        }
        else {
            ifstream not_checker(question_name, ios::app);
            ofstream answers(answer_name, ios::app);
            getline(checker, line);
            answers << "$" << name << "|";
            int i = 0;
            while (getline(checker, line)) {
                for (char c : line) {
                    if (c == '$') {
                        break;
                    }
                    else {
                        cout << c;
                    }

                    string ans="";
                    do {
                        input = cin.get();
                        if (input == '\n') {
                            char c;
                            c = cin.get();
                            if (c == '\n') {
                                break;
                                input == ' ';
                            }
                        }
                        else {

                            ans = ans + input;
                        }
                    } while (true);
                    i++;
                    answers << i << "." << ans << "-";
                }
                answers << endl;
            }
            if (line == "1") {
                cout << endl;
                answers << name << "|" << score << "|" << endl;
                cout << "your score is:" << score;
            }
            else { cout << "your score will be published soon!!"; }
        }
    }
    void marking(){
        ifstream file("answered.txt");
        string line;
        int i=0;
           while (getline(file, line)) {
               i++;
               cout << i << ".";
               for (char c : line) {
                   if (c == '$') {

                   }else{
                   cout << c;}
               }cout << "\t";
            }
           int a;
           cout << "which do you want to see\n>";
           cin >> a;
           i = 0;
           int j;
           file.seekg(0, ios::beg);
           string question_name;
           int checker_of_checker = 0;
           while (getline(file, line)) {
               i++;
               if (i == a) {
                   for (char c : line) {
                       j++;
                       if (c == '$' && j == 1) {
                           checker_of_checker++;
                           break;
                       }
                   }
               }
               if (checker_of_checker == 1) {
                   break;
               }
               
           }
           while (getline(file, line)) {
               i++;
               if (i == a) {
                   for (char c : line) {
                       question_name = question_name + c;
                   }
               }
           }
           file.close();
           if(checker_of_checker==1){
           cout << "This Students answered to that question and their scores:\n";
           question_name= question_name+ "_ans.txt";
           ifstream answer_showing(question_name);
           while (getline(answer_showing, line)) {
               i = 0;
               int k = 0;
                   for (char c : line) {
                       if (c == '$') {
                           i++;
                           continue;
                       }if (c == '|') {
                           i++;
                           k++;
                           continue;
                       }if (i == 1) {
                           cout << c;
                       }
                       if (i == 2) {
                           if (k == 1) {
                               cout << "Score:";
                               k++;
                           }
                           cout << c;
                       }
                   }
                   cout << endl;
               }
               //cout<<"do you want to check"
           answer_showing.close();
           }
           else {
               cout << "This Students answered to that question:\n";
               question_name = question_name + "_ans.txt";
               ifstream answer_showing(question_name);
               i = 0;
               while (getline(answer_showing, line)) {
                   int k = 0;
                   i++;
                   for (char c : line) {
                       if (c == '$') {
                           break;
                       }if (c == '|') {
                           break;
                       }
                       else {
                           if (k == 0) {
                               cout << i << ".";
                           }
                           cout << c;
                       }
                   }
                   cout << endl;
               }
               cout << "Which do you want to check\n:";
               int choice;
               cin >> choice;
               answer_showing.seekg(0, ios::beg);
               int seeker = 0;
               ofstream infile("checked.txt", ios::app);
               infile << a << "|";
               while (getline(answer_showing, line)) {
                   seeker++;
                   if (choice == seeker) {
                       for (char c : line) {
                           if (c == '|') {
                               break;
                           }
                           infile << c;
                       }
                   }
               }
               answer_showing.seekg(0, ios::beg);
               i = 0;
               while (getline(answer_showing, line)) {
                   int k = 0;
                   i++;
                   if (choice == i) {
                       for (char c : line) {
                           if (c == '|') {
                               i++;
                               if (i == 2) {
                                   char booler;
                                   cout << "is it correct? y/n \n";
                                   cin >> booler;
                                   if (booler == 'y' || booler == 'Y') {
                                       infile << "|" << "1";
                                   }
                                   else {
                                       string answer;
                                       cout << "enter true answer\n";
                                       cin >> answer;
                                       infile << "|" << answer;
                                   }
                               }
                               continue;
                           }
                           if (i == 1) {
                               cout << c;
                           }
                       }
                       
                   }
                   cout << endl;
               }
               infile.close();
               answer_showing.close();
           }
           }
           void answer() {

           }
        };
    


#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string filename = "example.txt";
    ofstream outfile(filename);  // create a new file named "example.txt"

    if (!outfile) {   // check if the file was successfully created
        cerr << "Error creating file." << endl;
        return 1;
    }

    string input_string = "This is an example string.";
    outfile << input_string << endl;  // write the string to the file
    outfile.close();  // close the file

    ifstream infile(filename);  // open the file for reading
    if (!infile) {   // check if the file was successfully opened
        cerr << "Error opening file." << endl;
        return 1;
    }

    // find the pointers in the file
    string line;
    while (getline(infile, line)) {
        const char* cstr = line.c_str();  // convert the line to a C string
        const char* start_ptr = strstr(cstr, "example");  // find the start pointer
        const char* end_ptr = start_ptr + strlen("example");  // find the end pointer
        cout << "Start pointer: " << start_ptr << endl;
        cout << "End pointer: " << end_ptr << endl;
    }
    infile.close();  // close the file
    return 0;
}

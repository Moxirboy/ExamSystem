#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main()
{
    int count = 2;
    while (count >= 0)
    {
        cout << "\r\t\t\t\t--------  " << count << " seconds remaining" << "  --------";
        this_thread::sleep_for(chrono::seconds(1));
        count--;
    }
    cout << "\033[2K\r";
    cout << "\r\t\t\t\t-------------  "<< "Time's up!" << "  -------------" << endl;
    system("pause");
    return 0;
}
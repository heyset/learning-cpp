#include <iostream>
#include <string>

using namespace std;

/*
    Receives from stdin an input that has something to be counted and the things to count from
    The first line is the input to be counted
    The following lines are the objects to be counted
*/

int main() {
    string x;
    getline(cin, x);

    string arg;
    int count { 0 };
    while (getline(cin, arg))
        if (arg.compare(x) == 0)
            count++;
    
    cout << count << '\n';
}

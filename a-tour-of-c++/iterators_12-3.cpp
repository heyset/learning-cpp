#include <vector>
#include <iostream>
using std::vector;

int main(void)
{
    vector<int> myvec { 1, 2, 3, 4, 5 };
    auto p = myvec.begin();

    std::cout << *p;
}
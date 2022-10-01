#include <string>
#include <iostream>

using namespace std;

class Vector {
    public:
        Vector(int s): ptr{ new double[s] }, sz { s } {};
        double& operator[](int i) { return ptr[i]; };
        int size() { return sz; };
        ~Vector() { delete ptr; }; // ? Added to prevent memory leaks
    private:
        double* ptr;
        int sz;
};

int main(int argc, char **argv) {
    int size { stoi(argv[1]) };

    Vector vector(size);

    for (int i = 0; i < size; i++)
        cin >> vector[i];
}

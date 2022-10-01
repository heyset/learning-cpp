#include <string>
#include <iostream>
#include <utility>

using namespace std;

class Vector
{
    public:
        Vector(int s): ptr{ new double[s] }, sz { s } {};
        double& operator[](int i) { return ptr[i]; };
        int size() { return sz; };

        Vector operator+(Vector v2)
        {
            int newSize = v2.size() + sz;
            Vector newVector(newSize);
            for (int i = 0; i < sz; i++)
                newVector[i] = ptr[i];
            for (int i = 0; i < v2.size(); i++) {
                newVector[i + sz] = v2[i];
            }
            return newVector;
        };

        Vector (Vector&& tar):
            ptr { exchange(tar.ptr, nullptr) },
            sz { exchange(tar.sz, 0) }
        { };

        Vector (const Vector& tar):
            ptr { new double[tar.sz] },
            sz { tar.sz }
        {
            for (int i = 0; i < sz; i++)
                ptr[i] = tar.ptr[i];
        }

        ~Vector() { delete[] ptr; };
    private:
        double* ptr;
        int sz;
};

int main(void)
{
    int size;
    cout << "Size for first vector: ";
    cin >> size;
    Vector v1(size);

    cout << "Elements for first vector:\n";
    for (int i = 0; i < size; i++)
        cin >> v1[i];

    cout << "Size for second vector: ";
    cin >> size;
    Vector v2(size);

    cout << "Elements for second vector:\n";
    for (int i = 0; i < size; i++)
        cin >> v2[i];

    Vector vr { v1 + v2 };
    cout << "\nResulting vector: size " << vr.size() << "\n";

    for (int i = 0; i < vr.size(); i++)
        cout << vr[i] << "\n";
}

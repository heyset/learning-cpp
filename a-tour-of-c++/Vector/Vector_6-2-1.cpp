#include <string>
#include <iostream>
#include <utility>

using namespace std;

template<typename T>
class Vector
{
    public:
        Vector(int s): ptr{ new T[s] }, sz { s } {};
        T& operator[](int i) { return ptr[i]; };
        int size() { return sz; };

        int size() const { return sz; }
        T& operator[](int i) const { return ptr[i]; };


        Vector operator+(const Vector& other)
        {
            int newSize = other.size() + sz;
            Vector newVector(newSize);

            for (int i = 0; i < sz; i++)
                newVector[i] = ptr[i];

            for (int i = 0; i < other.size(); i++) {
                newVector[i + sz] = other[i];
            }

            return newVector;
        };

        Vector(Vector&& tar):
            ptr { exchange(tar.ptr, nullptr) },
            sz { exchange(tar.sz, 0) }
        { };

        Vector& operator=(Vector&& tar)
        {
            if (&tar == this)
                return *this;
            delete[] ptr;
            ptr = exchange(tar.ptr, nullptr);
            sz = exchange(tar.sz, 0);
            return *this;
        }

        Vector(const Vector& tar):
            ptr { new T[tar.sz] },
            sz { tar.sz }
        {
            for (int i = 0; i < sz; i++)
                ptr[i] = tar.ptr[i];
        }

        Vector& operator=(const Vector& tar)
        {
            if (&tar == this)
                return *this;

            T* tmp = new T[tar.sz];
            for (int i=0; i < tar.sz; i++)
                tmp[i] = tar.ptr[i];
            
            delete[] ptr;
            ptr = tmp;
            sz = tar.sz;
            return *this;
        }

        ~Vector() { delete[] ptr; };

        T* begin() {
            return sz ? &ptr[0] : nullptr;
        }

        T* end() {
            return sz ? &ptr[0 + sz] : nullptr;
        }

    private:
        T* ptr;
        int sz;
};

int main(void)
{
    int size;
    cout << "Size for first vector: ";
    cin >> size;
    Vector<double> v1(size);

    cout << "Elements for first vector:\n";
    for (int i = 0; i < size; i++)
        cin >> v1[i];

    cout << "Size for second vector: ";
    cin >> size;
    Vector<double> v2(size);

    cout << "Elements for second vector:\n";
    for (int i = 0; i < size; i++)
        cin >> v2[i];

    Vector vr { v1 + v2 };
    cout << "\nResulting vector: size " << vr.size() << "\n";

    for (auto el : vr)
        cout << el << "\n";
}

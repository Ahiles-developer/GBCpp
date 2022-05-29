#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void mySwap(T& a, T& b) { 
    std::cout << "swap(" << a << ", " << b << ")\n";
    T t;
    t = a;
    a = b;
    b = t;
}

template<typename T>
void sortPointers(vector<T*> &v) {
    std::sort(v.begin(), v.end(), [](T* left, T* right) {
        return *left < *right;
        });
}

int main()
{
    int a = 10, b = 5;
    std::cout << a << " " << b << '\n';
    mySwap(a, b);
    std::cout << a << " " << b << '\n';


    return 0;
}


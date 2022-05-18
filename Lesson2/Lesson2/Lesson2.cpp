#include <iostream>
using namespace std;

/*
Здесь создаются глобальные переменные
int a{ 125 }; // -2.000.000.000 .. +2.000.000.000
int b{ 0b11110000 }; // универсальная инициализация
int c{ 0xAABB'CCDD };
long d{ 0 }; // C++11
*/

int a = 100;

std::size_t Var = 0; // 0 .. 64bit

using CarSpeed = double; // позволяет создавать псеводонимы для типов(using новый_тип = старый_тип)

typedef long long PlaneSpeed; // typedef старый_тип новый_тип

int main()
{
    CarSpeed car1{ 300.0 };

    PlaneSpeed plane{ 800 };

    // Здесь создаются локальные переменные

    char const a = 'S';  // Константы изменять нельзя
   
    cout << a << " - " << ::a; // делаем вот так(два двоеточия), если локальная переменная заслоняет глобальную

    double d1{ 77.88 };

    auto d2{ 88U };

    return 0;

    int arr[10] = { 0 }; // записать 0 в 10 элементов массива

    const size_t MYSIZE{ 10 }; // размер массива - константа
    int arr2[MYSIZE] = { 1, 2, 3, 5, 9, 10 };

    bool arr3[10] = { true, true, false, false, true };

    char str[]{ "Some very cool string in C++" }; // 0

    str[0] = 'X';
    str[4] = '+';

    const int size = 5;
    int arg[size][size];

    cout << arg[0][0] << " " << arg[2][1];

    //cout << str << endl;

    /*
    bool flag = true;

    flag = false;

    char ch = 'A'; // -127 .. 127
    unsigned char ch2 = 255; // 0 .. 255

    short sh = 60'000; // -32.000 ... 32.000

    long long d64 = 1;

    float ff = 1.23f; // 4 байта
    double dd = 3.14; // 8 байт
    long double ddd; // long double и double имеют одинаковый размер

    std::cout << sizeof(double) << " - " << sizeof(long double);
    */
}

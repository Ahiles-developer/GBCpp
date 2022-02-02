#include <iostream>
using namespace std;
#include "MyLib.h"
#define NUMBER(a, b) (a >= 0 && a < b) ? cout << "true" : cout << "false";
#define ARRAY_SIZE 10


inline void task3() {
    int* arr = new (nothrow) int[ARRAY_SIZE];

    if (arr != nullptr) {
        cout << "Enter " << ARRAY_SIZE << " numbers: " << endl;
        for (size_t i = 0; i < ARRAY_SIZE; i++) {
            cin >> arr[i];
        }

        MyLib::sortArr(arr, ARRAY_SIZE);
        MyLib::printArray(arr, ARRAY_SIZE);

        delete[] arr;
    }
}

int main()
{
    // 1. Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: 
    // для инициализации массива (типа float), печати его на экран и подсчета количества отрицательных и положительных элементов. 
    // Вызывайте эти 3-и функции из main для работы с массивом.

    const int size = 14;
    const float* arr = MyLib::initArray(size);
    MyLib::printArray(arr, size);
    MyLib::printPositiveAndNegative(arr, size);
    cout << "\n" << endl;
    
    //======================================================================================================================================

    // 2. Описать макрокоманду(через директиву define), проверяющую, входит ли переданное ей число(введенное с клавиатуры) в диапазон 
    // от нуля(включительно) до переданного ей второго аргумента(исключительно) и возвращает true или false, 
    // вывести на экран «true» или «false».

    NUMBER(5, 20);
    cout << "\n" << endl;

    //======================================================================================================================================

    


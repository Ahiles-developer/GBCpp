#include <iostream>

/*
    ДЗ по 2 уроку.
    1. Создать и инициализировать переменные пройденных типов данных(short int, int, long long, char, float, double).
    2. Создать перечисление(enum) с возможными вариантами символов для игры в крестики-нолики.
    3. Создать массив, способный содержать значения такого перечисления и инициализировать его.
*/
int main()
{
    // 1.
    short int a = 20;
    int b = 10;
    long long c = 343;
    char ch = 'X';
    bool isTrue = true;
    float t = 3.14f;
    double d = 3.14;

    // 2.
    enum Simb { X, O };

    // 3.
    Simb battleField[3][3] = { { X, X, X },
                               { X, X, X },
                               { X, X, X } };
}


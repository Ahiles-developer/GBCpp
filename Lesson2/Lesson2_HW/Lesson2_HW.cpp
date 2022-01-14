#include <iostream>

// ДЗ по 2 уроку.

// 1. Создать и инициализировать переменные пройденных типов данных(short int, int, long long, char, float, double).

short int a = 20;
int b = 10'000;
long long c = 2'000'000;
char ch = 'X';
bool isTrue = true;
float t = 3.14f;
double d = 3.14;


// 2. Создать перечисление(enum) с возможными вариантами символов для игры в крестики-нолики.

enum TicTacToeCell : char {
    TC_EMPTY = '_',
    TC_CROSS = 'X',
    TC_ZERO = '0'
};

// 3. Создать массив, способный содержать значения такого перечисления и инициализировать его.

TicTacToeCell battleField[3][3] = { { TC_EMPTY, TC_EMPTY, TC_EMPTY },  // поле для игры 3 х 3
                                    { TC_EMPTY, TC_EMPTY, TC_EMPTY },
                                    { TC_EMPTY, TC_EMPTY, TC_EMPTY } };

// 4. *Создать структуру(struct) данных <<Поле для игры в крестики - нолики>> и снабдить его всеми свойствами (подумайте что может понадобиться).

struct TicTacToe
{
    const unsigned int nFieldSize = 3;
    TicTacToeCell battleField[3][3]; // Как минимум структура должна содержать массив клеток игры
    bool isGameFinished;
    bool isFirstPlayerWon;
    unsigned long long Player1ID, Player2ID;
    TicTacToeCell ePlayer1, ePlayer2; // Чем ходит первый и второй игрок
};

// 5. **Создать структуру(struct MyVariant) объединяющую: union MyData(int, float, char) и 3 - и битовых поля(флага) 
// указывающими какого типа значение в данный момент содержится в объединении(isInt, isFloat, isChar).Продемонстрировать пример использования в коде этой структуры.

union MyVariantData {
    int MyInt;
    float MyFloat;
    char MyChar;
};

struct MyVariant {
    MyVariantData data;

    unsigned int isInt : 1;
    unsigned int isChar : 1;
    unsigned int isFloat : 1;
};

int main()
{
    MyVariant var;

    var.data.MyFloat = 77.7777f;
    var.isChar = 0;
    var.isFloat = 1; // Мы храним float
    var.isInt = 0;

    std::cout << var.data.MyFloat << std::endl;

    var.data.MyChar = 'G';
    var.isChar = 1; // Мы храним символ
    var.isFloat = 0;
    var.isInt = 0;

    std::cout << var.data.MyChar << std::endl;
    return 0;
}


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

//#include <stdio.h> /*<csdtio*/

int main()
{
    // Старая и новая системы ввода-вывода Потоки в С++
    // puts(); gets();
    // char arr[255];
    // sprintf(arr, "hello, %s, %05d, %.2f, %c. %x", "world", 12, 32.0f, 'f', 65432);
    // printf("%s\n", arr);
    // int a;
    // int b;
    // scanf("%d %d", &a, &b);
    // C++20 libfmt Python style string formatting
    
    
    // Потоковые классы и строки
    std::cout << "hello \n";
    // std::stringstream st;
    std::string str1;
    // st << 123 << ", " << "hello";
    // st >> str1;
    // std::cout << str1 << std::endl;
    // st >> str1;
    // std::cout << str1 << std::endl;

    // Потоковые классы
    // std::cin.getline(); // >> //cin.operator>>()
    // std::cin.gcount();
    // std::cin.peek(); // позволяет подсмотреть в стек, если там есть что читать, то можно прочитать, если нет, то нет.

    // Функциональность класса istream
    // std::ifstream fileIn("file.txt");
    // fileIn >> str1;
    // std::cout << str1 << std::endl;
    // 
    // Функциональность класса ostream
    std::ofstream fileOut("file.bin", std::ofstream::binary); // append
    fileOut << "Hello";
    std::cout << std::boolalpha << true << std::endl;

    // Перегрузка оператора вывода
    // << const Animal& a
    // Перегрузка оператора ввода
    // >> Animal& a


    return 0;
}


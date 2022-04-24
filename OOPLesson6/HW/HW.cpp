#include <iostream>
using namespace std;

class manipulyator {
public:
    friend std::ostream& operator<< (std::ostream& out, const manipulyator& manip);
};
std::ostream& operator<< (std::ostream& out, const manipulyator& manip) {
    out << std::endl << std::endl;
    return out;
}


int main()
{
    // 1. Создать программу, которая считывает целое число типа int.
    // И поставить «защиту от дурака» : если пользователь вводит что - то кроме одного целочисленного значения, 
    // нужно вывести сообщение об ошибке и предложить ввести число еще раз.
    // Пример неправильных введенных строк :
    //    rbtrb
    //    nj34njkn
    //    1n  
    int a;
    std::cout << "Enter integer number: " << std::endl;
    do {
        if (std::cin >> a) break;
        std::cout << "Error! Try again...\n";
        std::cin.clear(); // сбрасывает биты потока
        std::cin.sync();  // удаляет данные из буфера
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // недает уйти программе в бесконечный цикл
    } while (true);
    std::cout << "Number: " << a << std::endl;

    // 2. Создать собственный манипулятор endll для стандартного потока вывода, 
    // который выводит два перевода строки и сбрасывает буфер.
    manipulyator endll;
    std::cout << "mani " << endll << "pulyator";
       
    return 0;
}


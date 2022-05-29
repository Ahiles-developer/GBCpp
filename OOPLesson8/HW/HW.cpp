#include <iostream>
#include <exception>

// 1. Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и 
// запускать исключение DivisionByZero, если второй параметр равен 0. 
// В функции main выводить результат вызова функции div в консоль, а также ловить исключения.
template <typename T>
const T& div_0(const T& a,const T& b) {
    if (b == 0)
        throw std::runtime_error("division by zero"); // работает и с типом double
    
    return a / b;
}

class Ex {
    int x;
public:
    Ex(int _x) : x(_x) {}
};

class Bar {
    int y;
public:
    Bar(int _y = 0) : y(_y) {}
    void setY(int a) {}
};

int main()
{
    try {
        int i = div_0(10, 0);
        std::cout << i << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Division by zero" << std::endl;
    }


    return 0;
}


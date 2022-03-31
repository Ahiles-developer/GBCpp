#include <iostream>
#include <cstdint>

class Power {
    int a = 5;
    int b = 10;

public:
    void setNumbers(int numberOne, int numberTwo) {
        a = numberOne;
        b = numberTwo;
    }

    void calculate() {
        int c = a * b;
        std::cout << c << std::endl;
    }
};

class RGBA {
    std::uint8_t 
        m_red   = 0, 
        m_green = 0, 
        m_blue  = 0, 
        m_alpha = 255;

public:
    RGBA() {}; // Добавил т.к. конструктор по умолчанию отсутствовал, в связи с чем была ошибка в главном методе
    RGBA(std::uint8_t m_red, std::uint8_t m_green, std::uint8_t m_blue, std::uint8_t m_alpha) {
        this->m_red = m_red;
        this->m_green = m_green;
        this->m_blue = m_blue;
        this->m_alpha = m_alpha;
    }

    void print() {
        printf("%d %d %d %d", m_red, m_green, m_blue, m_alpha);
    }
};

class Stack {
    // код...

public:
    void reset(){}
    void push(){}
    void pop(){}
    void print(){}
};

int main()
{
    Power p;
    // p.setNumbers(5, 10);
    p.calculate();

    RGBA r;
    r.print();

    return 0;
}


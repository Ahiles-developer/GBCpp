#include <iostream>
#include <cstdint>

/* 1. Создать класс Power, который содержит два вещественных числа.Этот класс должен иметь две переменные - члена для хранения
   этих вещественных чисел.Еще создать два метода : один с именем set, который позволит присваивать значения объявленным 
   в классе переменным, второй — calculate, который будет выводить результат возведения первого числа в степень второго числа.
   Задать значения этих двух чисел по умолчанию. */
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

/* 2. Написать класс с именем RGBA, который содержит 4 переменные - члена типа std::uint8_t: 
   m_red, m_green, m_blue и m_alpha(#include cstdint для доступа к этому типу).
   Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
   Создать конструктор со списком инициализации членов, который позволит пользователю передавать 
   значения для m_red, m_blue, m_green и m_alpha.Написать функцию print(), которая будет выводить значения переменных - членов. */
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

/* 3. Написать класс, который реализует функциональность стека.Класс Stack должен иметь :
• private - массив целых чисел длиной 10;
• private целочисленное значение для отслеживания длины стека;
• public - метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
• public - метод с именем push(), который будет добавлять значение в стек.push() должен возвращать значение false, 
  если массив уже заполнен, и true в противном случае;
• public - метод с именем pop() для вытягивания и возврата значения из стека.Если в стеке нет значений, 
  то должно выводиться предупреждение;
• public - метод с именем print(), который будет выводить все значения стека. */
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


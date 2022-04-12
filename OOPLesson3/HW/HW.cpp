#include <iostream>

// 1. Создать абстрактный класс Figure(фигура). Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
// Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).
// Для всех классов создать конструкторы.Для класса Figure добавить чисто виртуальную функцию area() (площадь).
// Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
class Figure {
public:
    Figure() {};
    virtual void area() const = 0; // чисто виртуальная функция
};

class Parallelogram : public Figure {
    std::uint8_t a;  // основание 
    std::uint8_t h;  // высота
public:
    Parallelogram() {};
    Parallelogram(std::uint8_t _a, std::uint8_t _h) : a(_a), h(_h) {};
    void area() const override {
        std::uint8_t s = a * h;
        printf("Площадь параллелограмма равна: %d\n", s);
    }
};

// Круг
class Circle : public Figure{};

// Прямоугольник
class Rectangle : public Parallelogram {
    std::uint8_t a; // длина
    std::uint8_t b; // ширина
public:
    Rectangle(std::uint8_t _a, std::uint8_t _b) : a(_a), b(_b) { };

    void area() const override {
        std::uint8_t s = a * b;
        printf("Площадь прямоугольника равна: %d\n", s);
    };
};

// Квадрат
class Square : public Parallelogram {
    std::uint8_t a;
public:
    Square(std::uint8_t _a) : a(_a) {};

    void area() const override {
        std::uint8_t s = a * a;
        printf("Площадь квадрата равна: %d\n", s);
    };
};

// Ромб
class Rhombus : Parallelogram { };

//2. Создать класс Car(автомобиль) с полями company(компания) и model(модель). 
//Классы - наследники: PassengerCar(легковой автомобиль) и Bus(автобус).От этих классов наследует класс Minivan(минивэн).
//Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.Создать объекты для каждого из классов и 
//посмотреть, в какой последовательности выполняются конструкторы.Обратить внимание на проблему «алмаз смерти».
class Car {
    std::string company;
    std::string model;
public:
    Car() {}
    Car(std::string _company, std::string _model) : company(_company), model(_model) {}

    void info() {
        std::cout << "Компания: " << company << ". Модель: " << model << std::endl;
    };
};

// Легковой автомобиль
class PassengerCar : virtual public Car {
public:
    PassengerCar() {}
    PassengerCar(std::string company, std::string model) : Car(company, model) {}
};

// Автобус
class Bus : virtual public Car {
public:
    Bus() {}
    Bus(std::string company, std::string model) : Car(company, model) {}
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan(std::string _company, std::string _model) : PassengerCar(_company, _model) {}
};

//3. Создать класс : Fraction(дробь).Дробь имеет числитель и знаменатель(например, 3 / 7 или 9 / 2).
//Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить :
class Fraction {

};

int main()
{
    setlocale(LC_ALL, "Russian");

    Parallelogram p(5, 15);
    p.area();
    Rectangle r(2, 10);
    r.area();
    Square s(10);
    s.area();

    Car c1("Car", "Model");
    c1.info();
    PassengerCar p1("Passenger Car", "Q");
    p1.info();
    Bus b1("Bus", "Bogdan");
    b1.info();
    Minivan m1("Minivan", "Bolshoi");
    m1.info();
    
    

    return 0;
}


#include <iostream>
#include <cassert>

// 1. Создать абстрактный класс Figure(фигура). Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
// Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).
// Для всех классов создать конструкторы.Для класса Figure добавить чисто виртуальную функцию area() (площадь).
// Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
class Figure {
protected:
    double width;
    double height;
public:
    Figure(double _width, double _height) : width(_width), height(_height) {};
    virtual double area() = 0; // чисто виртуальная функция
};

class Parallelogram : public Figure {
public:
    Parallelogram(double width, double height) : Figure(width, height) {};
    double area() override { return width * height; }
};

// Круг
class Circle : public Figure{
public:
    Circle(double radius) : Figure(radius, radius) { }
    double area() override { return 3.1415926 * width * height; }
};

// Прямоугольник
class Rectangle : public Parallelogram {
public:
    Rectangle(double width, double height) : Parallelogram(width, height) {};
    double area() override { return width * height; };
};

// Квадрат
class Square : public Parallelogram {
public:
    Square(double width, double height) : Parallelogram(width, height) {};
};

// Ромб
class Rhombus : public Parallelogram {
public:
    Rhombus(double width, double height) : Parallelogram(width, height) {}
    double area() override { return 0.5 * width * height; }
};

//2. Создать класс Car(автомобиль) с полями company(компания) и model(модель). 
//Классы - наследники: PassengerCar(легковой автомобиль) и Bus(автобус).От этих классов наследует класс Minivan(минивэн).
//Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.Создать объекты для каждого из классов и 
//посмотреть, в какой последовательности выполняются конструкторы.Обратить внимание на проблему «алмаз смерти».
class Car {
    std::string company;
    std::string model;
public:
    Car(std::string company, std::string model) : company(std::move(company)), model(std::move(model)) {}
    virtual ~Car() {}
    void info() {
        std::cout << "Компания: " << company << ". Модель: " << model << std::endl;
    };
};

// Легковой автомобиль
class PassengerCar : virtual public Car {
public:
    PassengerCar(const std::string &company, const std::string &model) : Car(company, model) {}
};

// Автобус
class Bus : virtual public Car {
public:
    Bus(const std::string company, const std::string model) : Car(company, model) {}
};

class Minivan : public Bus, public PassengerCar {
public:
    Minivan(const std::string &company, const std::string &model) : 
        Car(company, model), Bus(company, model), PassengerCar(company, model) {}
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
    Square s(10, 12);
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


#include <iostream>

// 1. Создать класс Person(человек) с полями : имя, возраст, пол и вес. 
// Определить методы переназначения имени, изменения возраста и веса.
// Создать производный класс Student(студент), имеющий поле года обучения.
// Определить методы переназначения и увеличения этого значения.Создать счетчик количества созданных студентов.
// В функции main() создать несколько(не больше трёх) студентов.Вывести информацию о них.
class Person {
protected:
    std::string name;
    int age;
    std::string gender;
    int weight;

public:
    Person(std::string name, int age, int weight) {
        this->name = name;
        this->age = age;
        this->weight = weight;
    }

    void setName(std::string n) { name = n; }
    void setAge(int a) { age = a; }
    void setHeight(int h) { weight = h; }
    /*std::string getName(std::string name) { return name; }
    int getAge(int age) { return age; }
    int getHeight(int height) { return height; }*/

    
};

class Student : public Person {
private:
    int yearOfStudy;
    static int counter;
public:
    Student(std::string name, int age, int yearOfStudy) : Person(name, age, yearOfStudy) {
        this->yearOfStudy = yearOfStudy;
        counter++;
    }
    void setStudy(int s) { yearOfStudy = s; }
    int getCount() { return counter; }

    void TotalCount() { printf("Total students: %d", getCount()); }
    void info() {
        printf("Name: %s. %d years of age. Years of study: %d.\n", name.c_str(), age, yearOfStudy);
    }
};
int Student::counter = 0;

// 2. Создать классы Apple(яблоко) и Banana(банан), которые наследуют класс Fruit(фрукт).
// У Fruit есть две переменные - члена: name(имя) и color(цвет).
// Добавить новый класс GrannySmith, который наследует класс Apple.
class Fruit {
    std::string name;
    std::string color;
public:
    Fruit(std::string _name, std::string _color) : name(_name), color(_color) {}
    std::string getName() const { return name; }
    std::string getColor() const { return color; }
};

class Apple : public Fruit {
public:
    Apple(std::string _color = "red", std::string _name = "Apple") : Fruit(_name, _color) {}
};

class Banana : public Fruit {
public:
    Banana(std::string _name = "Banana", std::string _color = "yellow") : Fruit(_name, _color) {}
};

class GrannySmith : public Apple {
public:
    GrannySmith() : Apple("green", "") {}
};

int main()
{
    Student s0("Vasili", 25, 3);
    Student s1("Genadi", 42, 5);
    Student s2("Aleksey", 33, 10);

   /* Student* s[] = { &s0, &s1, &s2 }; // найти как правильно сделать вывод счетчика после цикла
    
    for (int i = 0; i < 4 ; i++)
    {
        s[i]->info();
    }*/
    
    s0.info();
    s1.info();
    s2.info();
    s0.TotalCount(); // работает, но такой подход мне не нравится
    std::cout << "\n" << std::endl;

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}


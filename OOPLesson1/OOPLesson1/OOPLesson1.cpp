#include <iostream>

class Cat {
private:
	// private-public 
	int yearOfBirth;
	std::string name;
	// mutable - позволяет изменять значение там, где запрещено(const например)
	mutable std::string color; // позволяет изменять константное значение

public:
	// initialization lists(спеисок инициализации - то что после двоеточия написано)
	Cat() : yearOfBirth(2022) { // КОНСТРУКТОР ПО УМОЛЧАНИЮ(Если напишем другой конструктор, то конст. по умолчанию перестанет существовать)
		color = "Peachy"; // here can be color randomizer
		std::cout << "MEOW!" << std::endl;
	}

	Cat(std::string name, std::string color, int yearOfBirth=2021) { // в скобках можно устанавливать дефолтные параметры
		this->name = name;
		this->color = color;
		this->yearOfBirth = yearOfBirth;
	}
	// copy constructor
	Cat(Cat& c)
		: name(c.name), color(c.color), yearOfBirth(c.yearOfBirth) {}


	// destructors
	~Cat() {
		std::cout << "cat..." << std::endl;
	}

	// functions constructors
	void voice() {
		std::cout << name << " meow" << std::endl;
	}

	void move() {
		std::cout << name << " walks on paws" << std::endl;
	}

	void setName(std::string n) { name = n; }

	// const metods
	int getAge() const { return 2022 - yearOfBirth; } // Константные функции изменять нельзя
	std::string getName() const { return name; }
	std::string getColor() const { return color; }
	void info() {
		printf("%s is %s and %d years of age\n", getName().c_str(), color.c_str(), getAge());
	}
};

// links vs pointers
void makeCatMove(Cat* c) {
	(*c).move();
	// c->move();
}

void makeCatMove(Cat& c) {
	c.move();
}


int main(int argc, const char** argv) {
	// classes vs objects, fields
	Cat c0("Barsik", "White", 2017);
//	c0.setAge(5);
//	c0.setName("Barsik");
//	c0.setColor("White");
	c0.info();

	Cat c1("Murzik", "Black", 2020);
	c1.info();

	Cat c2;
	c2.setName("Kotik");
	c2.info();
	c2.info();
	c2.info();

	// Cat.voice(); // compile error
	c0.voice();
	c1.voice();
	c0.move();
	c1.move();
	
	// pointer to object
	Cat* c2p = &c2;
	c2p->setName("pointer"); // сокращенный синтаксис разыменования
	c2.info();

	Cat c4(c1); // клон кота c4 от c1
	c4.setName("Clone");
	c4.info();
	c1.info();
	
	// this

	return 0;
}

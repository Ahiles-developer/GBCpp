#include <iostream>

class Animal {
	// protected
protected:
	Animal() {}
	int age;
	std::string name;
	std::string color;

public:
	Animal (std::string name, std::string color, int age) {
		this->name = name;
		this->color = color;
		this->age = age;
	}
	~Animal() { std::cout << "animal..." << std::endl; }
	void setName(std::string n) { name = n; }
	int getAge() const { return age; } // Константные функции изменять нельзя
	std::string getName() const { return name; }
	std::string getColor() const { return color; }
	void move() { std::cout << name << " walks on paws" << std::endl; }
	void info() {
		printf("%s is %s and %d years of age\n",
			getName().c_str(), color.c_str(), getAge());
	}
};

class Cat : public Animal {  // public class Cat extends Animal {...}
private:
public:
	Cat(std::string name, std::string color, int age) : Animal(name, color, age) { }
	
	virtual ~Cat() { std::cout << "cat..." << std::endl; }
	// polymorphism
	void voice() { std::cout << name << " meow" << std::endl; }
};

// public-private
class Dog : public Animal {
private:
public:
	// constructor invokation
    Dog(std::string name, std::string color, int age) {
		this->name = name;
		this->color = color;
		this->age = age;
	}

	virtual ~Dog() { std::cout << "dog..." << std::endl; }
	// polymorphism
	void voice() { std::cout << name << " woof" << std::endl; }
};
// cascade
class Bird : public Animal {
protected:
	int flyHeight;
public:
	Bird(std::string name, std::string color, int age, int flyHeight) : Animal(name, color, age) { 
		this->flyHeight = flyHeight;
	}
	virtual ~Bird() { std::cout << "bird..." << std::endl; }
	// polymorphism
	void voice() { std::cout << name << " tweet" << std::endl; }
};
class Parrot : public Bird { //, public Cat { - diamond иерархия, множественное наследование
public:
//	Parrot(std::string name, std::string color, int age, int height) : Animal(name, color, age), flyHeight(height) { }
	Parrot(std::string name, std::string color, int age, int height) : Bird (name, color, age, height) { } // выше такая же запись
	virtual ~Parrot() { std::cout << "parrot..." << std::endl; }							// но с ошибкой непрямого наследования	
	void speak() { std::cout << "polly wanna cracker" << std::endl; }
};


int main()
{
	// derived classes
	Animal a0("amoeba", "white", 0);
    Cat c0("Barsik", "Black", 2);
	Cat c1("Murzik", "Peachy", 3);
	Dog d0("Sharik", "White", 5);
	Dog d1("Tuzik", "Grey", 4);
	Bird b0("Chijik", "Yellow", 1, 5);
	Parrot p1("Polly", "Rainbow", 2, 7);
	// pointers to base and derived objects

	Animal* zoo[] = { &c0, &c1, &d0, &d1, &b0, &p1 };

	for (int i = 0; i < 6; i++) {
		zoo[i]->info();
	}
	// multiple base classes, diamond of death
	// don't do it

	// typecast
	// Parrot* pp = (Parrot*)zoo[5]; // C-style
	Parrot* pp = static_cast<Parrot *>(zoo[5]); // recommended orthodox cpp way
	//pp->speak(); можно так

	static_cast<Parrot*>(zoo[5])->speak(); // можно так, это без указателя и в одну строку

	((Parrot*)zoo[5])->speak(); 

	p1.speak();
	// frend-functions/classes

	return 0;
}

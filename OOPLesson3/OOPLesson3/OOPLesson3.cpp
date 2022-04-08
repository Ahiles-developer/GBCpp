#include <iostream>

class Animal {
protected:
	int age;
	std::string name;
	std::string color;

public:
	Animal(std::string name, std::string color, int age) {
		this->name = name;
		this->color = color;
		this->age = age;
	}
	~Animal() { std::cout << "animal..." << std::endl; }
	void move() { std::cout << name << " walks on paws" << std::endl; }
	void info() {
		printf("%s is %s and %d years of age\n",
			name.c_str(), color.c_str(), age);
	}
	virtual void voice() {} // virtual говорит что нужно поискать в наследниках(позднее связывание)
};

class Cat : public Animal {  // public class Cat extends Animal {...}
public:
	Cat(std::string name, std::string color, int age) : Animal(name, color, age) {}

	virtual ~Cat() { std::cout << "cat..." << std::endl; }
	void voice() { std::cout << name << " meow" << std::endl; }
};

class Dog : public Animal {
public:
	Dog(std::string name, std::string color, int age) : Animal(name, color, age) {}

	virtual ~Dog() { std::cout << "dog..." << std::endl; }
	void voice() { std::cout << name << " woof" << std::endl; }
};

class Bird : public Animal {
protected:
	int flyHeight;
public:
	Bird(std::string name, std::string color, int age, int flyHeight) : Animal(name, color, age) {
		this->flyHeight = flyHeight;
	}
	virtual ~Bird() { std::cout << "bird..." << std::endl; }
	void voice() { std::cout << name << " tweet" << std::endl; }
};

class Parrot : public Bird { //, public Cat { - diamond иерархия, множественное наследование
public:
	Parrot(std::string name, std::string color, int age, int height) : Bird(name, color, age, height) { } 
	virtual ~Parrot() { std::cout << "parrot..." << std::endl; }								
	void speak() { std::cout << "polly wanna cracker" << std::endl; }
};


int main() {
    // static fields/methods
    // virtual functions + polymorphysm
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
		zoo[i]->voice();
	}
	 
    // abstract class
    // interface
    // operator overloading
    // friend functions
    return 0;
}


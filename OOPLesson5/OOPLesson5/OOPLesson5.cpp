#include <iostream>

class Animal {
protected:
    std::string name;
    int age;
public:
    Animal(int _age, std::string _name) : age(_age), name(_name) {}
    virtual ~Animal() {}
    Animal& operator++();
    Animal operator++(int);
};
Animal& Animal::operator++() {
    ++age;
    return *this;
}
Animal Animal::operator++(int) {
    Animal a(this->age, this->name);
    ++(*this);
    return a;
}

template <typename T1, typename T2>
double sum(const T1& a, const T2& b) {
    return a + b;
}

template <typename T>
T& abs(T& a) {
    return (a < 0) ? -a : a;
}

template <typename T1, typename T2>
bool isEqual(const T1& a, const T2& b) {
    return abs(a - b) < 0.00001;
}

// class templates
template<class T, int size>
class Container {
    T* data[size];
};

// class templates partial specification
template<int size>
class Container<bool, size> {

};

template<class T>
class Box {
    int size;
    T entities;
public:
    Box(int _size) : size(_size) {
        entities = new T[_size];
    }
    Box() : size(0), entities(nullptr) {}
    ~Box() {
        delete[] entities;
        entities = nullptr;
    }
    virtual int getSize();
};
template <typename T>
int Box<T>::getSize() {
    return sizeof(T) * this->size;
}

// class templates specification
template<> class Box<bool> {
    unsigned entities;
public:
    Box(): entities(0) {}
    void set(int idx, bool value) {
        unsigned mask = 1 << idx;
        if (value)
            entities |= mask;
        else
            entities &= ~mask;
    }
    int get(int idx) {
        unsigned mask = 1 << idx;
        return (entities & mask) != 0;
    }
    int getSize() {
        return 32;
    }

};

int main() {
    Container<int, 5> iC;
    Container<Animal, 7> cC;
    Container<float, 10> fC;

    // function templates
    std::cout << sum(1, 1) << " ";
    std::cout << sum(1.0, 1.0) << " ";
    std::cout << sum(1.0f, 1.0f) << " ";
    std::cout << ((int)sum('a', 'b')) << " ";
    std::cout << sum(1.0, 1.0f) << " ";
    std::cout << sum(1, 1.0f) << " ";

    // overloading increment
    std::cout << std::endl;

    int i = 10;
    std::cout << ++i << std::endl;
    std::cout << i++ << std::endl;
    std::cout << i << std::endl;

    
    
    

    return 0;
}




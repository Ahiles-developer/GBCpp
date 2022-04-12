#include <iostream>
#include <vector>
#include <cassert>

class Orange {
    class Juice {
    public:
        std::string spill() {
            return " leak";
        }
    };
    Juice juice;
public:
    void squeeze() {
        std::cout << "orange my juice" << juice.spill() << std::endl;
    }
};

class Box {
    Orange orange;
public:
    void hasOranges() {
        std::cout << "box: ";
        orange.squeeze();
    }
};

class Merchant {
    Box* box;
public:
    Box* showBox() const {
        return box;
    }
    void eat(Orange o) {
        std::cout << "merchant prepares a glass: ";
        o.squeeze();
    }
};

// operator[]
// pop_back()
// pop_front()
// sort()
// print()
class Container {
    int* data;
    int size;
    int capacity;
    int& operator[](int idx) {}

public:
    Container() : size(0), data(nullptr), capacity(0) {}
    Container(int _size) : size(_size) {
        if (_size == 0) {
            Container();
        } else if (_size < 0) {
            std::cout << "Bad thing happened" << std::endl;
            Container();
        } else {
            this->data = new int[_size];
            this->capacity = 0;
        }
    }
    virtual ~Container() {
        delete[] data;
    }
    void setData(int idx, int value) {
        assert(idx >= 0 && idx < size);
        // capacity++; // ?
        this->data[idx] = value;
    }
    int getData(int idx) {
        assert(idx >= 0 && idx < size);
        // capacity--; // ?
        return this->data[idx];
    }
    int capacity() {
        return this->capacity;
    }
    void resize(int newLength) {
//        data = (int*)realloc(data, sizeof(int) * newLength);
        if (newLength == size) return;
        if (newLength <= 0) {
            //erase();
            return;
        }
        int* newData = new int[newLength];
        if (size > 0) {
            int elemToCopy = (newLength > size) ? size : newLength;
            for (int idx = 0; idx < capacity; idx++) {
//              memcpy(data, 0, newData, 0, elemToCopy);
                newData[idx] = data[idx];
            }
        }
        delete[] data;
        data = newData;
        size = newLength;
    }
    void erase() {
        capacity = 0;
        for (int idx = 0; idx < size; idx++) {
            data[idx] = 0;
        }
    }
};

int main() {
    // composition
    Orange o;
//    o.squeeze();

    // aggregation
    Box b;
//    b.hasOranges();

    // assotiation
    Merchant m;
//    std::cout << m.showBox() << std::endl;

    // dependency
//    m.eat(o);
    
    // STL - vector
    int* arr0 = new int[5];
    int arr1[] = {1, 2, 3, 4, 5};

    std::vector<int> arr2; // хз какой размер
    arr2.resize(5);
    std::vector<int> arr3 = { 1, 2, 3, 4, 5 };

    // done by proffesionals
    std::vector<bool> b0 = { true, false, true, true, false }; // char data = b'00010110
    //std::cout << &b0[0] << std::endl;  ошибка компиляции(булево значение вектор не выводит)

    //std::cout << &arr3[0] << std::endl;
    //std::cout << b0[0] << std::endl;
    //std::cout << arr3[0] << std::endl; 
    arr3[0] = 10;
    //std::cout << arr3[0] << std::endl;
    //std::cout << arr3.size() << std::endl;
    arr3.push_back(11);
    std::cout << arr3.size() << " " << arr3[arr3.size() - 1] << std::endl;
    arr3.pop_back();
    std::cout << arr3.size() << std::endl;

    // STL - iterators
    arr3.begin();
    arr3.end();
    arr3.cbegin();
    arr3.cend();
    std::vector<int>::iterator iter;
    iter = arr3.begin();
    while (iter != arr3.end()) {
        std::cout << *iter << " ";
        ++iter;
    }
    
    // own container class
    

    return 0;
}


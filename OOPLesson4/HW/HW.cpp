#include <iostream>
#include <vector>
#include <cassert>

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
        }
        else if (_size < 0) {
            std::cout << "Bad thing happened" << std::endl;
            Container();
        }
        else {
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
    void popBack() {
        
    }
    void popFront() {

    }

    void sortArr() {

    }

    void print() {

    }
};

int main() {



    return 0;
}


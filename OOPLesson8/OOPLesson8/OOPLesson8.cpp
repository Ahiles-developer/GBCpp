#include <iostream>
#include <exception>

// exceptions
int div0(int a, int b) {
    if (b == 0)
        // throw
        throw 100;

    return a / b;
}

int div1(int a, int b) {
    int x;
    try {
        x = div0(a, b);
    } catch (int e) {
        throw "we caught ... and context ... and parameters ...";
    }
    return x;
}

// std::
class MyExc : public std::exception {
    const char* msg;
public:
    MyExc(const char* _msg) : msg(_msg) {}
    const char* what() const noexcept override {
        return msg;
    }
};


int div2(int a, int b) try {
    if (b == 0)
        throw std::runtime_error("division by zero!");

    return a / b;
} catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    throw std::runtime_error(dynamic_cast<std::runtime_error &>(e));
    //return 0;
}

int main() {

    int x = 10;
    int y = 0;

    // try
    try {
        std::cout << div2(x, y) << std::endl;
        //std::cout << div1(x, y) << "\n";
        // a lot of code
        //throw std::exception("this is std'arta!!!");
        //throw MyExc("wait, what?");
    } catch (int a) {
        std::cerr << "An exception is thrown: " << a << "\n";
    } catch (const char* a) { // дает информативность
        std::cout << a << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        // catch-all
    } catch (...) { 
        std::cout << "somthing went wrong" << std::endl;
    }


    // functional
    


    // побитный сдвиг
    // n << k = n * 2^k
    // n >> k = n / 2^k

    // n * 10 = n << 3 + n << 1

    return 0;
}


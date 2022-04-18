#include <iostream>

template <class T>  // шаблон класса
class Pair1 {
private:
    T a;
    T b;
public:
    Pair1(const T& _a, const T& _b) : a(_a), b(_b) {}

    T first(){
        return a;
    }

    T second() {
        return b;
    }
    
};

class Pair {
private:
    std::string a;
    int b;
public:
    Pair(std::string _a, int _b) : a(_a), b(_b) {}
};

template<class T>
class StringValuePair {
private:
    std::string str;
    int b;
public:
    StringValuePair(std::string _str, const T _b) : str(_str), b(_b) {}

    std::string first() {
        return str;
    }

    T second() {
        return b;
    }
};


int main()
{
    Pair1<int> p1(6, 7.9);
    std::cout << "Pair: " << p1.first() << " " << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    // std::cout << "Pair: " << p2.first() << " " << p2.second() << '\n'; // не работает

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}


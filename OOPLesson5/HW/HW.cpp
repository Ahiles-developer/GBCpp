#include <iostream>
#include <string>

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

template <class T1, class T2>
class Pair {
private:
    T1 a;
    T2 b;
public:
    Pair(const T1& first, const T2& second) : a(first), b(second) {}

    T1 first() {
        return a;
    }

    T2 second() {
        return b;
    }
};

template<class T>
class StringValuePair : public Pair<std::string, T> {
private:
    std::string str;
    int b;
public:
    StringValuePair(const string& _str, const T& _b) : Pair<T>(first, second) {}

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

    Pair<int, double> p1(6, 7.8);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}


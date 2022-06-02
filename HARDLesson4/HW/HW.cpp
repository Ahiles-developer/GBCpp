#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

void insert_sorted(std::vector<int> &v, int val) {
    v.push_back(val);
    std::sort(v.begin(), v.end());
}

template<typename T>
T insert_sorted_any(T& v, int val) {
    v.push_back(val);
    std::sort(v.begin(), v.end());
}

int main()
{
    std::vector<int> v = { 1, 4, 7, 8, 2, 9 };
    std::cout << "Don't sorted: ";
    for (auto a : v) {
        std::cout << a << " ";
    }
    std::cout << "\n";

    insert_sorted(v, 3);
    std::cout << "Add and sorted: ";
    for (auto a : v) {
        std::cout << a << " ";
    }

    std::list<int> l{1, 4, 7, 9,};
    insert_sorted_any(l, 10);
    for (auto a : l) {
        std::cout << a << " ";
    }
    return 0;
}

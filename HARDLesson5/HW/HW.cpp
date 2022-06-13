#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

// 1. Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов, 
// и выводящую в консоль список уникальных слов(если слово повторяется больше 1 раза, то вывести его надо один раз).
// Продемонстрировать работу функции, передав итераторы различных типов.
template <typename T, typename Iterator>
void uniqElements(const Iterator& begin, const Iterator& end) {
	set<T> elements;
	copy(begin, end, inserter(elements, elements.end()));
	copy(elements.begin(), elements.end(), ostream_iterator<T>(cout, ", "));
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "RU");

	vector<string> str = { "one", "two", "three", "four", "one", "five", "five", "one" };
	cout << "Список уникальных слов: ";
	uniqElements<string>(str.begin(), str.end());
	
	vector<int> num = { 1, 2, 3, 4, 1, 5, 5, 1 };
	cout << "Список уникальных цифр: ";
	uniqElements<int>(num.begin(), num.end());

    return 0;
}

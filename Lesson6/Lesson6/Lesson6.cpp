#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	size_t n;
	cin >> n;

	if (n > 0) {
		int** ppArr = new (nothrow) int* [n]; // 1. выделяем массив указателей на строки
		for (size_t i = 0; i < n; i++) { // выделяем строки
			ppArr[i] = new int[n];
		}
		// 2. using
		ppArr[0][0] = 100;
		ppArr[n - 1][n - 1] = 999;

		// 3. free
		for (size_t i = 0; i < n; i++) { // удаляем строки нашей матрицы
			delete[] ppArr[i]; 
		}
		delete[] ppArr; // удаляем массив указателей
	}

	return 0;
}


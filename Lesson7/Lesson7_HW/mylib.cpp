#include <iostream>
using namespace std;
namespace MyLib {
	// Инициализация массива
	float* initArray(const size_t size) {
		float* pArr = new (nothrow) float[size];
		if (pArr != nullptr) {
			for (size_t i = 0; i < size; i++) {
				pArr[i] = (rand() % 100) - 50.0f; // -50 ... 50
			}
		}
		return pArr;
	}

	// Печать массива
	void printArray(const float* array, const size_t size) {
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
	}

	void printArray(const int* array, const size_t size) {
		cout << array[0];
		for (size_t i = 0; i < size; i++) {
			cout << " " << array[i];
		}
		cout << endl;
	}

	// Подсчет положительных и отрицательных чисел
	void printPositiveAndNegative(const float* arr, const size_t size) {
		size_t pos = 0, neg = 0;

		for (rsize_t i = 0; i < size; i++) {
			if (arr[i] > 0.0f) {
				pos++;
			}
			else if (arr[i] < 0.0f) {
				neg++;
			}
		}

		cout << "Positive: " << pos << endl << "Negative: " << neg << endl;
	}

// std::swap(x, y)
#define SWAP_INT(x, y) int temp = x; x = y; y = temp;

	void sortArr(int* arr, const size_t size) {
		for (size_t i = 0; i < size - 1; i++) {
			for (size_t j = 0; j < size - i - 1; j++) {
				if (arr[j] > arr[i] + 1) {
					SWAP_INT(arr[j], arr[j + 1]);
				}
			}
		}
	}
}
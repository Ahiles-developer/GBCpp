#include <iostream>
using namespace std;

// 1. По значению
// 2. По ссылке
// 3. По указателю

int D{ 4000 };

void tryToChange(int a, int & rB, int * pC) {
	a = 10;
	rB = 20;
	*pC = 30;
	D = 40;
}

bool printArray(const int* arr, const size_t SIZE) {
	if (arr == nullptr || SIZE == 0)
		return false; // FAILED

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}

	return true; // SUCCESS 
}

int main()
{
	int A{ 1000 }, B{ 2000 }, C{ 3000 };
	tryToChange(A, B, &C);

	cout << A << " " << B << " " << C << " " << D;


	/*
	const size_t SIZE = 8;
	int arr[SIZE] = { 1, 2, 3, 4, 6, 7, 8, 9 };

	if (printArray(arr, SIZE)) {
		cout << "Success!" << endl;
	}
	else {
		cerr << "Array printing failed!" << endl;
	}

	cout << endl;

	const size_t SIZE2 = 7;
	int arr2[SIZE2] = { 10, 20, 30, 44, 666, 777, 888 };

	printArray(arr2, SIZE2);
	*/
	return 0;
}


#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

int listAdd(std::list<int> l) {
    int sum = 0;
    for (auto number : l) {
        sum += number;
    }
    return sum / l.size();
}

class Matrix {
private:
    std::vector<std::vector<int>> matrix;
public:
    Matrix() {}

    int detOfMatrix_3x3(std::vector<std::vector<int>> matrix) {
        int dmatrix = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
                      matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
                      matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
        return printf("Determinant: %d", dmatrix);
    };
};

int main()
{
    /*std::list<int> l{4, 3, 6, 7, 9, 11};
    std::cout << "List before: ";
    for (auto number : l) {
        std::cout << number << " ";
    }
    
    std::cout << std::endl;
    std::cout << "List after: ";
    l.push_back(listAdd(l));
    for (auto number : l) {
        std::cout << number << " ";
    }*/

    std::vector<std::vector<int>> matrix = { { 6, 1, 1 },
                                             { 4, -2, 5 },
                                             { 2, 8, 7 } };
    Matrix m;
    m.detOfMatrix_3x3(matrix);

    
    
    return 0;
}


#include <iostream>
#include "matrixOperations.hpp"
#include "locale.h"

int main() {
    setlocale(LC_ALL,"Russian");
    int n;

    std::cout << "Введите размер матрицы n: ";
    std::cin >> n;

    int** matrix = createMatrix(n);
    readMatrix(matrix, n);

    if (!isSymmetric(matrix, n)) {
        std::cout << "Матрица не симметрична!\n";
        freeMatrix(matrix, n);
        return 1;
    }

    int** newMatrix = transformMatrix(matrix, n);

    std::cout << "\nИзначальная матрица:\n";
    printMatrix(matrix, n);

    std::cout << "\nНовая матрца:\n";
    printMatrix(newMatrix, n);

    freeMatrix(matrix, n);
    freeMatrix(newMatrix, n);

    return 0;
}

// для сборки проекта  воспользуйтесь команндой   g++ main.cpp matrixOperations.cpp -o main


#include "matrixOperations.hpp"
#include <iostream>

int** createMatrix(int n) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    return matrix;
}

void readMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

int** transformMatrix(int** matrix, int n) {
    int** newMatrix = createMatrix(n);
    for (int i = 0; i < n; i++) {
        int minindex = 0;
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] < matrix[i][minindex]) {
                minindex = j;
            }
        }
        for (int j = minindex; j < n; j++) {
            newMatrix[i][j - minindex] = matrix[i][j];
        }
        for (int j = n - minindex; j < n; j++) {
            newMatrix[i][j] = 0;
        }
    }
    return newMatrix;
}

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool isSymmetric(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

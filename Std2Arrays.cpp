#include <iostream>
#include "\Users\Baþak\source\repos\Task1FillArray\Std2Arrays.h"
void fillArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }

    int startValue = 1;

    // Traverse diagonals from NE to SW
    for (int diag = 0; diag < rows + columns - 1; diag++) {
        int startRow = diag < columns ? 0 : diag - columns + 1;
        int startCol = diag < columns ? columns - diag - 1 : 0;

        while (startRow < rows && startCol < columns) {
            arr[startRow][startCol] = startValue;
            startValue++;
            startRow++;
            startCol++;
        }
    }
}

void printArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


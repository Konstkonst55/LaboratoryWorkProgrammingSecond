#include "Lab5.h"

void fillKMatrixFromVector(int m, int k) {
    int* srcArr = (int*)malloc(m * sizeof(int));
    int rows = m / k;
    if (m % k != 0) rows++;

    fillRandIntVector(srcArr, m, 1, 9);
    printVector(srcArr, m); printf("\n");

    int** matrix = allocateMemIntMatrix(rows, k);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < k; j++) {
            if (i * k + j < m) matrix[i][j] = srcArr[i * k + j];
            else matrix[i][j] = 0; 
        }
    }

    printIntMatrix(matrix, rows, k);

    freeMemIntMatrix(matrix, rows);
    free(srcArr);
}

void printMultTable(int rows) {
    int i, j;
    int** table = (int**)malloc(rows * sizeof(int*));

    for (i = 0; i < rows; i++) table[i] = (int*)malloc((i + 1) * sizeof(int));

    for (i = 0; i < rows; i++) {
        for (j = 0; j <= i; j++) {
            table[i][j] = (i + 1) * (j + 1);
        }
    }

    printf("\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j <= i; j++) printf("[%d] ", table[i][j]);
        printf("\n");
    }

    freeMemIntMatrix(table, rows);
}
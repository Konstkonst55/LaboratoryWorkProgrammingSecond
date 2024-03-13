#include "Lab4.h"
#include <stdio.h>
#include <stdlib.h>
#include "ArrayUtils.h"
#include <stdbool.h>

void fillMatrixAndDeleteMax(const int m, const int n)
{
    int** srcArr = allocateMemIntMatrix(m, n);

    fillRandIntMatrix(srcArr, m, n, 10, 99);

    int maxI = 0, maxJ = 0;

    getMaxMatrixPosition(srcArr, m, n, &maxI, &maxJ);

    printIntMatrixWithSelectedElement(srcArr, m, n, maxI, maxJ);

    int** withoutMaxArr = allocateMemIntMatrix(m - 1, n - 1);

    for (int i = 0, k = 0; i < m; i++) {
        if (i == maxI) continue;

        for (int j = 0, l = 0; j < n; j++) {
            if (j == maxJ) continue;

            withoutMaxArr[k][l++] = srcArr[i][j];
        }

        k++;
    }

    printIntMatrix(withoutMaxArr, m - 1, n - 1);

    freeMemIntMatrix(srcArr, m);
    freeMemIntMatrix(withoutMaxArr, m - 1);
}

void printSumRowsColsMatrix(const int m, const int n) {
    int** srcArr = allocateMemIntMatrix(m, n), sum = 0;

    fillRandIntMatrix(srcArr, m, n, 10, 99);

    int** withSumArr = allocateMemIntMatrix(m + 1, n + 1);

    for (int i = 0; i <= m; i++) withSumArr[i][n] = 0;
    for (int j = 0; j <= n; j++) withSumArr[m][j] = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            withSumArr[i][j] = srcArr[i][j];
            withSumArr[m][j] += srcArr[i][j];
            withSumArr[i][n] += srcArr[i][j];
            sum += srcArr[i][j];
        }
    }

    withSumArr[m][n] = sum;

    printIntMatrixWithSelectedRowCol(withSumArr, m + 1, n + 1, m, n);

    freeMemIntMatrix(srcArr, m);
    freeMemIntMatrix(withSumArr, m + 1);
}
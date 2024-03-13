#include <stdio.h>
#include <stdlib.h>
#include "Lab7.h"
#include "ArrayUtils.h"
#include "MathUtils.h"

void zeroBetweenMinimums(int arr[], int len) {
    int min1 = arr[0], min2 = arr[0];
    int min1Id = 0, min2Id = 0;

    for (int i = 1; i < len; i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min2Id = min1Id;
            min1 = arr[i];
            min1Id = i;
        }
        else if (arr[i] < min2) {
            min2 = arr[i];
            min2Id = i;
        }
    }

    if (min1Id < min2Id) {
        for (int i = min1Id + 1; i < min2Id; i++) arr[i] = 0;
    }
    else {
        for (int i = min2Id + 1; i < min1Id; i++) arr[i] = 0;
    }
}

void printSumRowsMatrix(int rows) {
    int** arr = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        int length = getRandomInt(2, 10);

        arr[i] = malloc((length + 1) * sizeof(int));
        arr[i][0] = length;

        for (int j = 1; j <= length; j++) {
            arr[i][j] = getRandomInt(0, 10);
            printf("[%d] ", arr[i][j]);
        }

        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        int length = arr[i][0];
        int sum = 0;
        for (int j = 1; j <= length; j++) sum += arr[i][j];
        printf("\nSum of row %d: %d", i + 1, sum);
    }

    freeMemIntMatrix(arr, rows);
}

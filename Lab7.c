#include "Lab7.h"

void getTwoMinVector(int arr[], int len, int *min1, int *min2) {
    if (len < 2) return;

    *min1 = 0;
    *min2 = 1;

    if (arr[*min1] > arr[*min2]) {
        *min1 = 1;
        *min2 = 0;
    }

    for (int i = 2; i < len; i++) {
        if (arr[i] < arr[*min1]) {
            *min2 = *min1;
            *min1 = i;
        }
        else if (arr[i] < arr[*min2]) {
            *min2 = i;
        }
    }
}

void zeroBetweenMinimums(int arr[], int len) {
    int min1Id = 0, min2Id = 0;

    getTwoMinVector(arr, len, &min1Id, &min2Id);

    if (min1Id < min2Id) {
        for (int i = min1Id + 1; i < min2Id; i++) arr[i] = 0;
    }
    else {
        for (int i = min2Id + 1; i < min1Id; i++) arr[i] = 0;
    }
}

void printSumRowsMatrix(int rows) {
    int** arr = (int**)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        int length = getRandomInt(2, 10);

        arr[i] = (int*)malloc((length + 1) * sizeof(int));
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

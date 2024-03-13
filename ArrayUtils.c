#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ArrayUtils.h"
#include "MathUtils.h"
#include <time.h>

void fillRandIntVector(int arr[], int len, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < len; i++) arr[i] = getRandomInt(min, max);
}

void printVector(int arr[], int len) {
	printf("\n");
	for (int i = 0; i < len; i++) printf("[%d] ", arr[i]);
	printf("\n");
}

void printIntMatrixWithSelectedElement(int** arr, int rows, int cols, const int sRow, const int sCol) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == sRow && j == sCol) printf("\033[32m[%d]\t", arr[i][j]);
			else printf("\033[0m[%d]\t", arr[i][j]);
		}

		printf("\033[0m\n");
	}

	printf("\033[0m\n");
}

void printIntMatrixWithSelectedRowCol(int** arr, int rows, int cols, const int sRow, const int sCol) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (j == sCol || i == sRow) printf("\033[32m[%d]\t", arr[i][j]);
			else printf("\033[0m[%d]\t", arr[i][j]);
		}

		printf("\033[0m\n");
	}

	printf("\033[0m\n");
}

int getPosCountVector(int arr[], int len) {
	int n = 0;

	for (int i = 0; i < len; i++) if (arr[i] >= 0) n++;

	return n;
}

int getNegCountVector(int arr[], int len) {
	int n = 0;

	for (int i = 0; i < len; i++) if (arr[i] < 0) n++;

	return n;
}

void bubbleSortPP(int** arr, int len)
{
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (*arr[j] > *arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int binarySearch(int arr[], int len, int key, int* c) {
	int l = 0, r = len - 1;

	while (l <= r) {
		int m = l + (r - l) / 2;

		(*c)++;
		if (arr[m] == key) return m;

		(*c)++;
		if (arr[m] < key) l = m + 1;
		else r = m - 1;
	}

	return -1;
}

int enumSearch(int arr[], int len, int key, int* c) {
	for (int i = 0; i < len; i++) {
		(*c)++;
		if (arr[i] == key) return i;
	}
	
	return -1;
}

void shellSortKnutDec(int arr[], int len, int* m, int* c) {
	int max = (log2(len)) - 1;
	int* hArr = malloc(max * sizeof(int));
	hArr[0] = 1;
	for (int i = 1; i < max; i++) hArr[i] = 2 * hArr[i - 1] + 1;

	int temp, k, j, l = max - 1;
	for (k = hArr[l]; l >= 0; l--, k = hArr[l]) {
		for (int i = k; i < len; i++) {
			temp = arr[i]; (*m)++;
			j = i - k;

			while (j >= 0 && temp < arr[j]) {
				(*c)++;
				arr[j + k] = arr[j];
				j -= k;
				(*m)++;
			}

			if (j < 0) (*c)--;

			arr[j + k] = temp; (*m)++;
		}
	}
}

void printIntMatrix(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("[%d] ", arr[i][j]);
		}

		printf("\033[0m\n");
	}

	printf("\033[0m\n");
}

void fillRandIntMatrix(int** arr, int rows, int cols, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = getRandomInt(min, max);
		}
	}
}

int** allocateMemIntMatrix(int rows, int cols)
{
	int** arr = (int**)malloc(rows * sizeof(int*));

	for (int i = 0; i < rows; i++) arr[i] = (int*)malloc(cols * sizeof(int));

	return arr;
}

void freeMemIntMatrix(int** arr, int rows) {
	for (int i = 0; i < rows; i++) free(arr[i]);
	free(arr);
}

void getMaxMatrixPosition(int** arr, int rows, int cols, int* x, int* y) {
	int max = arr[0][0];

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
				*x = i; *y = j;
			}
		}
	}
}

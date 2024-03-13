
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayUtils.h"

#include "Lab1.h" // ✔
#include "Lab2.h" // ✔
#include "Lab3.h" // ✔
#include "Lab4.h" // ✔
#include "Lab5.h" // ✔
#include "Lab6.h" // ✔
#include "Lab7.h" // 

#define N 20
#define N100 100
#define N1000 1000

void main() {
	int arr[N];
	fillRandIntVector(arr, N, 0, N * 2);
	printVector(arr, N);
	zeroBetweenMinimums(arr, N);
	printVector(arr, N);

	printf("\n\n");

	printSumRowsMatrix(7);

	printf("\n\n");

	int arrSearch[N100], m = 0, c = 0, key = 5, res = -1;
	fillRandIntVector(arrSearch, N100, 0, N * 2);
	shellSortKnutDec(arrSearch, N100, &m, &c);

	res = binarySearch(arrSearch, N100, key, &c, c = 0);
	if (res != -1) printf("BS Key %d was found on index %d!", key, res);
	else printf("BS Key %d was not found!", key);
	printf("\nC: %d\n\n", c);

	res = enumSearch(arrSearch, N100, key, &c, c = 0);
	if (res != -1) printf("ES Key %d was found on index %d!", key, res);
	else printf("ES Key %d was not found!", key);
	printf("\nC: %d\n\n", c);

	int arrEnumSearch[N1000];
	fillRandIntVector(arrEnumSearch, N1000, 0, 40);
	shellSortKnutDec(arrEnumSearch, N1000, &m, &c);

	res = binarySearch(arrEnumSearch, N1000, key, &c, c = 0);
	if (res != -1) printf("BS Key %d was found on index %d!", key, res);
	else printf("BS Key %d was not found!", key);
	printf("\nC: %d\n\n", c);

	res = enumSearch(arrEnumSearch, N1000, key, &c, c = 0);
	if (res != -1) printf("ES Key %d was found on index %d!", key, res);
	else printf("ES Key %d was not found!", key);
	printf("\nC: %d", c);
}
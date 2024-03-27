
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
#include "Lab8.h" // 

#define N 20
#define N100 100
#define N1000 1000

void lab7();
void lab8();

void main() {
	lab8();
}

void lab7() {
	int arr[N];
	fillRandIntVector(arr, N, 0, N * 2);
	printVector(arr, N);
	zeroBetweenMinimums(arr, N);
	printVector(arr, N);

	printf("\n\n");

	printSumRowsMatrix(7);

	printf("\n\n\n");

	int arrSearch[N100], m = 0, c = 0, key = 5, res = -1;
	fillRandIntVector(arrSearch, N100, 0, N * 2);
	shellSortKnutDec(arrSearch, N100, &m, &c); c = 0;

	res = binarySearch(arrSearch, N100, key, &c);
	if (res != -1) printf("BS Key %d was found on index %d!", key, res);
	else printf("BS Key %d was not found!", key);
	printf("\nC: %d\n\n", c); c = 0;

	res = enumSearch(arrSearch, N100, key, &c);
	if (res != -1) printf("ES Key %d was found on index %d!", key, res);
	else printf("ES Key %d was not found!", key);
	printf("\nC: %d\n\n", c);

	int arrEnumSearch[N1000];
	fillRandIntVector(arrEnumSearch, N1000, 0, 40);
	shellSortKnutDec(arrEnumSearch, N1000, &m, &c); c = 0;

	res = binarySearch(arrEnumSearch, N1000, key, &c);
	if (res != -1) printf("BS Key %d was found on index %d!", key, res);
	else printf("BS Key %d was not found!", key);
	printf("\nC: %d\n\n", c); c = 0;

	res = enumSearch(arrEnumSearch, N1000, key, &c);
	if (res != -1) printf("ES Key %d was found on index %d!", key, res);
	else printf("ES Key %d was not found!", key);
	printf("\nC: %d", c);
}

void lab8() {
	
}
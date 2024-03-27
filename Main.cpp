
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <locale>
#include <cstdlib>

#include "ArrayUtils.h"

#include "Lab1.h"	// ✔
#include "Lab2.h"	// ✔
#include "Lab3.h"	// ✔
#include "Lab4.h"	// ✔
#include "Lab5.h"	// ✔
#include "Lab6.h"	// ✔
#include "Lab7.h"	// 
#include "Lab8.h"	// 

#include "Lab10.h"	// 

using namespace std;

#define N 20
#define N100 100
#define N1000 1000

void lab7();
void lab8();
void lab10();

int main() {
	setlocale(LC_ALL, "Rus");
	lab10();
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
	School schools[] = {
		{1, 100, 1},
		{2, 85, 80},
		{3, 30, 4},
		{4, 70, 10},
		{5, 150, 30},
		{6, 150, 30},
		{7, 200, 40}
	};

	Room rooms[] = {
		{1, 21.3, "Факультет 1", 2},
		{2, 20.2, "Факультет 2", 3},
		{3, 21.5, "Факультет 2", 4},
		{4, 20.3, "Факультет 3", 2},
		{5, 31.0, "Факультет 1", 3},
		{6, 21.4, "Факультет 3", 2},
		{7, 22.0, "Факультет 1", 3},
		{8, 21.6, "Факультет 4", 2},
	};

	int sn = sizeof(schools) / sizeof(schools[0]);
	int rn = sizeof(rooms) / sizeof(rooms[0]);

	printSchoolData(schools, sn);
	cout << "-----------" << endl << endl;
	printRoomData(rooms, rn);
}

void lab10() {
	sortWordFile();
}
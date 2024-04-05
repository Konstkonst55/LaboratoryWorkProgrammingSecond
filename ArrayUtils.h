#pragma once

#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include "MathUtils.h"
#include <stdio.h>

void fillRandIntVector(int arr[], int len, int min, int max);
void fillRandFloatVector(float arr[], int len, float min, float max);
void printVector(int arr[], int len);
void printFloatVector(float arr[], int len);
void printIntMatrixWithSelectedElement(int** arr, int rows, int cols, const int sRow, const int sCol);
void printIntMatrixWithSelectedRowCol(int** arr, int rows, int cols, const int sRow, const int sCol);

int getPosCountVector(int arr[], int len);
int getNegCountVector(int arr[], int len);

void bubbleSortPP(int **arr, int len);
void swap(int *a, int *b);
int binarySearch(int arr[], int len, int key, int* c);
int enumSearch(int arr[], int len, int key, int* c);
void shellSortKnutDec(int arr[], int len, int* m, int* c);

void printIntMatrix(int** arr, int rows, int cols);
void fillRandIntMatrix(int** arr, int rows, int cols, int min, int max);

int** allocateMemIntMatrix(int rows, int cols);
void freeMemIntMatrix(int** arr, int rows);
void getMaxMatrixPosition(int** arr, int rows, int cols, int* x, int* y);

#endif // !ARRAY_UTILS_H
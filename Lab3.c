#include "Lab3.h"

void fillDynamicArray(int n) {
	int* arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        free(arr);
        return;
    }

	fillRandIntVector(arr, n, -50, 50);

	int posN = getPosCountVector(arr, n), negN = getNegCountVector(arr, n);

	int* posArr = (int*)malloc(posN * sizeof(int));
	int* negArr = (int*)malloc(negN * sizeof(int));

	if (posArr == NULL || negArr == NULL) {
		free(arr);
		if (posArr != NULL) free(posArr);
		if (negArr != NULL) free(negArr);
		return;
	}

	int pId = 0, nId = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] >= 0) posArr[pId++] = arr[i];
		else negArr[nId++] = arr[i];
	}

	printVector(arr, n);
	printVector(posArr, posN);
	printVector(negArr, negN);

	free(arr), free(posArr), free(negArr);
}

void sortPPArray(int n) {
    int* a = (int*)malloc(n * sizeof(int));
    int** b = (int**)malloc(n * sizeof(int*));

    if (a == NULL || b == NULL) {
        if (a != NULL) free(a);
        if (b != NULL) free(b);
        return;
    }

	fillRandIntVector(a, n, -10, 10);

	for (int i = 0; i < n; i++) b[i] = &a[i];

	printVector(a, n);

    bubbleSortPP(b, n);

    printf("\n");
    for (int i = 0; i < n; i++) 
        printf("[%d] ", *b[i]);

    free(a);
	free(b);
}

void printPrimeNumbers(int n) {
    bool* prime = (bool*)malloc(n * sizeof(bool));

    if (prime == NULL) {
        free(prime);
        return;
    }

    for (int i = 0; i < n; i++) prime[i] = true;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i < n; i += p) {
                prime[i] = false;
            } 
        }
    }

    for (int p = 2; p < n; p++) if (prime[p]) printf("%d ", p);

    free(prime);
}
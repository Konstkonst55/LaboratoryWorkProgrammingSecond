
#include <stdio.h>
#include <stdlib.h>

/// <summary>
/// �������� ������������� ����� �� �������� ������������������
/// </summary>
void scanPrintPositiveNumbers() {
    int number;
    scanf_s("%d", &number);

    if (number == 0){
        printf("0 ");
    } 
    else {
        scanPrintPositiveNumbers();
        if (number > 0 && number % 10 == 0) printf("%d ", number);
    }
}

/// <summary>
/// �������� ������� ��� ������������� ����� � �������, ����� �������������
/// </summary>
/// <param name="arr"> - �������� ������</param>
/// <param name="len"> - ����� �������</param>
/// <param name="start"> - ������ ������ ������</param>
/// <param name="posAreOver"> - 0 -> �������� ��� ������������� �����; 1 -> �������� ��� ������������� �����</param>
void printPosNegNumbers(int arr[], int len, int start, int posAreOver) {
    if (start < len) {
        if (posAreOver && arr[start] >= 0) printf("[%d] ", arr[start]);

        if (!posAreOver && arr[start] < 0) printf("[%d] ", arr[start]);
        
        printPosNegNumbers(arr, len, start + 1, posAreOver);
    }
    else if (!posAreOver) printPosNegNumbers(arr, len, 0, 1);
}

/// <summary>
/// ���������� �������� ������������� ����������� �����
/// </summary>
/// <param name="num"></param>
/// <returns></returns>
char* convertToBinary(int num) {
    static char binary[33];
    
    if (num == 0 || num == 1) {
        binary[0] = '0' + num;
        return binary;
    }

    char* temp = convertToBinary(num / 2);
    strcpy(binary, temp);
    strcat(binary, (num % 2 == 0 ? "0" : "1"));

    return binary;
}
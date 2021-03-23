/*
 * Created by Petrov.S
 *
 * Homework for lesson 6
 */

#include <stdio.h>
#include <math.h>
#include "func.h"


// Task 1
void bubbleSort(char ** arr2d, int row, int col) {
    int len = row * col;
    for (int t = 1; t < len; ++t) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col - 1; ++j) {
                if (arr2d[i][j] > arr2d[i][j + 1])
                    swap(&arr2d[i][j], &arr2d[i][j + 1]);
            }
        }
        for (int i = 0; i < row - 1; ++i) {
            if (arr2d[i][col - 1] > arr2d[i + 1][0])
                swap(&arr2d[i][col-1], &arr2d[i+1][0]);
        }
    }
}


// Task 2

double tpk(int t) {

    return sqrt(fabs(t)) + 5 * pow(t, 3);
}


int main() {

    const int row = 5;
    const int col = 5;
    char** arr2d= init2dArr(arr2d, row, col);
    fillRandom(arr2d,row,col, 100);
    printArr(arr2d,row,col);
    bubbleSort(arr2d, row, col);
    printArr(arr2d,row,col);

// Task 2
const int SZ = 11;
double arr[SZ];
double tmp = 0;
    printf("Write number, than press ENTER: ");
    for (int i = 0; i < SZ; ++i) {
        scanf("%lf", &arr[i]);
    }
    printf("Original sequence: \n");
    for (int i = 0; i < SZ; ++i) {
        printf("%.2lf ", *(arr + i));
    }
    printf("\n");
    printf("\nReversed and calculated by TPK: \n");
    for (int i = 10; i >= 0; i--) {
        tmp = tpk(arr[i]);
        if (tmp > 400)
            printf("%d: TOO LARGE\n", i);
        else
            printf("%d: %.2lf\n", i, tmp);
    }

    printf("\n");
    return 0;
}

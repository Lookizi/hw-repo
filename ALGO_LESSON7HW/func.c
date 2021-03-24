//
// Created by Serj Petrov on 24.03.2021.
//

#include "func.h"

int qs(int* arr, int first, int last) {
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }

    } while (i <= j);

    if (i < last) qs(arr,i,last);
    if (first < j) qs(arr,first,j);

}

void sortInserts(int* array, int size) {
    int temp, pos;
    for (int i = 1; i < size; ++i) {
        temp = array[i];
        pos = i - 1;
        while (pos >= 0 && array[pos] > temp) {
            array[pos + 1] = array[pos];
            pos--;
        }
        array[pos + 1] = temp;
    }
}


void swapInt(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printIntArray(int* array, int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}

void fillIntRandom(int* array, int size, int border) {
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}
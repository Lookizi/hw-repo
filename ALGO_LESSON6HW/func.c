/*
 * Created by Petrov.S
 *
 * Homework for lesson 6
 */

#include "func.h"
#include <stdio.h>
#include <stdlib.h>

void swap(char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}

char** init2dArr(char** arr2d, int row, int col) {
    arr2d = (char**) calloc(sizeof(char*), row);
    for (int i = 0; i < row; ++i) {
        *(arr2d + i) = (char*) calloc(sizeof(char), col);
    }
    return arr2d;
}

void fillRandom(char** arr2d, int row, int col, int border) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *((*(arr2d + i)) + j) = rand() % border;
        }
    }
}

void printArr(char ** arr2d, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%3d", *((*(arr2d + i)) + j));
        }
        printf("\n");
    }
    printf("\n");
}

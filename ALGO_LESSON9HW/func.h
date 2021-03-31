//
// Created by Serj Petrov on 23.03.2021.
//

#ifndef ALGO_LESSON7_FUNC_H
#define ALGO_LESSON7_FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>


#define true 1 == 1
#define false 1 != 1
typedef int boolean;
typedef int T;

void swapInt(int *a, int *b);
void qs(int* arr, int first, int last);
void qsl(int* arr, int first, int last);
void thickSplit(int* arr, int l, int r);
void mergeSort(int* arr, int first, int last);
void countingSort(int* arr,int len, int max);
void sortCount(int* arr, int len);
void bucketSort(int* arr, int len);
void sortShells(int* arr, int len);

#endif //ALGO_LESSON7_FUNC_H

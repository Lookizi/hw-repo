//
// Created by Serj Petrov on 23.03.2021.
//
#include <stdio.h>
//#include "geek.h"
#include "func.h"

void swapInt(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


//разбиение(алгоритм) Хоара (быстрая сортировка)
void qs(int* arr, int first, int last) {
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];//опорный элемент

    do {
        while (arr[i] < x) i++;
        while(arr[j] > x) j--;

        if (i <= j) {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }

    } while (i <= j);

    if(i < last) qs(arr,i,last);
    if (first < j) qs(arr, first, j);
}

// Разбиение Ломуто
void qsl(int* arr, int first, int last) {
    if (first < last) {
        int x = arr[last];
        int i = first;
        int j;
        for (j = first; j <= last - 1 ; j++) {
            if (arr[j] <= x) {
                swapInt(&arr[i],&arr[j]);
                i++;
            }
        }
        swapInt(&arr[i],&arr[last]);
        qsl(arr,first,i - 1);
        qsl(arr,i + 1, last);
    }
}

void thickSplit(int* arr, int l, int r) { //Толстое разбиение
    int x = arr[r];
    if (r <= l) return;

    int i = l;
    int j = r - 1;
    int p = l - 1;
    int q = r;

    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i >= j) break;
        swapInt(&arr[i], &arr[j]);

        if (arr[i] == x) {
            p++;
            swapInt(&arr[p], &arr[i]);
            i++;
        }
        if (arr[j] == x) {
            swapInt(&arr[--q], &arr[j--]);
        }
    }
    swapInt(&arr[i], &arr[r]);
    j = i - 1;
    i++;

    for (int k = l; k <= p ; ++k, --j) {
        swapInt(&arr[k], &arr[j]);
    }
    for (int k = r - 1; k >= q ; --k, ++i) {
        swapInt(&arr[k], &arr[i]);
    }
    thickSplit(arr,l,j);
    thickSplit(arr,i,r);
}

//нисходящее слияние
void merge(int* arr, int first, int mid, int last) {
    int l = first;
    int r = mid + 1;
    int* tmp = (int*) malloc(last * sizeof(int));
    int step = 0;

    while (l <= mid && r <= last) {
        if (arr[l] < arr[r]){
            tmp[step++] = arr[l++];
        } else {
            tmp[step++] = arr[r++];
        }
    }
    while (r <= last) {
        tmp[step++] = arr[r++];
    }
    while (l <= mid) {
        tmp[step++] = arr[l++];
    }
    for (int i = 0; i < last - first +1; ++i) {
        arr[first + i] = tmp[i];
    }
}

void mergeSort(int* arr, int first, int last) {
    int split;
    if (first < last) {
        split = (first + last) / 2;
        mergeSort(arr,first, split);
        mergeSort(arr, split + 1, last);
        merge(arr,first,split,last);
    }
}

//сортировка подсчетом (целесообразно при небольших значениях данных, например оценки учеников)
void countingSort(int* arr,int len, int max) {
    int counts[max];
    for (int i = 0; i < max; ++i) {
        counts[i] = 0;
    }
    for (int i = 0; i < len; ++i) {
        counts[arr[i]]++;
    }
    int indx = 0;
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < counts[i]; ++j) {
            arr[indx] = i;
            indx++;
        }
    }
}

//сортировка алгоритмом со списком
int findMin(int* arr, int len) {
    int min = arr[0];
    for (int i = 0; i < len; ++i) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int findMax(int* arr, int len) {
    int max = arr[0];
    for (int i = 0; i < len; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}


void sortCount(int* arr, int len) {
    int min = findMin(arr, len);
    int max = findMax(arr, len);
    const int spread = abs(min) + abs(max) + 1;
    int support[spread];
    for (int i = 0; i < spread; ++i) {
        support[i] = 0;
    }
    for (int i = 0; i < len; ++i) {
        support[arr[i] - min]++;
    }
    int count = 0;
    for (int i = 0; i < spread; ++i) {
        while (support[i] > 0) {
            arr[count++] = i + min;
            support[i]--;
        }
    }
}

//блочная сортировка O(n),
// но сильно деградирует при большом количестве близких по значению элементов

void bucketSort(int* arr, int len) {
    const int max = len;
    const int b = 10;

    int buckets[b][max+1];
    for (int i = 0; i < b; ++i) {
        buckets[i][max] = 0;
    }

    for (int digit = 1; digit < 1000000000 ; digit*=10) {
        for (int i = 0; i < max; ++i) {
            int d = (arr[i] / digit) % b;

//            int counter = buckets[d][max];
//            buckets[d][counter] = arr[i];
//            counter++;
//            buckets[d][max] = counter;

            buckets[d][buckets[d][max]++] = arr[i]; //то же самое что и верхние 4е строки
        }
        int idx = 0;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < buckets[i][max]; ++j) {
                arr[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }

    }
}


//сортировка Шелла (улучшенная сортировка вставками)
// (хорошо подходит для массивов среднего размера до несколько тысяч)
//0(n * log n)
void sortShells(int* arr, int len) {
    int i, j, step, temp;

    for (step = len / 2; step > 0; step /= 2) {
        for (i = step; i < len; ++i) {
            temp = arr[i];
            for (j = i; j >= step ; j -= step) {
                if (temp < arr[j - step]){
                    arr[j] = arr[j - step];
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}

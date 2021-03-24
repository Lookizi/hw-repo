/*
 * Created by Petrov S.
 *
 * Homework for lesson 7
 */

#include <stdio.h>
#include "func.h"

//1st task
int med(int* arr, int first, int last) {
    int m;
    int mid = arr[(first+last) / 2];
    if(last < mid && last < first) m = first < mid ? first : mid;
    else m = first > mid ? first : mid;
    return m;
}

void qsFast(int* arr,int len, int first, int last) {

    int x = arr[(first + last) / 2];

    if (len <= 10){
        sortInserts(arr,len);
    } else {
        int m = med(arr,first,last);
        arr[m] = arr[x];
        qs(arr,first,last);
    }
}

// 2nd task - к сожалению так и не успел с этим разобраться в условленный срок

int main() {

    // 1st task
    const int SZ = 30;
    int arr[SZ];
    fillIntRandom(arr,SZ,100);
    printIntArray(arr,SZ,3);
//
//    //if array > 10 elements
    printf("median is : %d\n", med(arr,0,SZ));
    qsFast(arr,SZ,0,SZ - 1);
    printIntArray(arr,SZ,3);
    printf("\n");

    //if array <= 10 elements
    const int SZ10 = 9;
    fillIntRandom(arr,SZ10,100);
    printIntArray(arr,SZ10,3);
    printf("median is : %d\n", med(arr,0,SZ10));
    qsFast(arr,SZ,0,SZ10 - 1);
    printIntArray(arr,SZ10,3);

    return 0;
}

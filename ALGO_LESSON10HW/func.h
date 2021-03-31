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
typedef char T;

//односвязные списки
typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;
typedef struct {
    OneLinkNode *head;
    int size;
} OneLinkList;
void OneLinkInit(OneLinkList* lst);
void OneLinkIns(OneLinkList *lst, int data);
OneLinkNode* rm(OneLinkList* lst, int data);
void printOneLinkNode(OneLinkNode* n);
void printOneLinkList(OneLinkList* lst);

//2связные списки
typedef struct TwoLinkNode {
    int dat;
    struct TwoLinkNode *next;
    struct TwoLinkNode *prev;
} TwoLinkNode;
typedef struct {
    TwoLinkNode *head;
    TwoLinkNode *tail;
    int size;
} TwoLinkList;
void initTwoLinkList(TwoLinkList *lst);
void pushFront(TwoLinkList *lst, int data);
void pushBack(TwoLinkList *lst, int data);
TwoLinkNode* remFront(TwoLinkList *lst);
TwoLinkNode* remBack(TwoLinkList *lst);
void printTwoLinkNode(TwoLinkNode* n);
void printTwoLinkList(TwoLinkList* lst);

//циклические списки

//Односвязный циклический список

void insertCyclic(OneLinkList *lst, int data);
OneLinkNode *rmCyclic(OneLinkList *lst, int data);
void printCyclicIntList(OneLinkList* lst);

//стек на основе односвязного списка
typedef struct {
    OneLinkNode *head;
    int size;
} OneLinkStack;
void initOneLinkStack(OneLinkStack *stack);
boolean pushOneLinkStack(OneLinkStack *stack, T value);
T popOneLinkStack(OneLinkStack *stack);
void printOneLinkCharNode(OneLinkNode* n);
void printOneLinkCharStack(OneLinkStack * stack);

//очередь на основе 2хсвязного списка
boolean enqueueTwoLinkList(TwoLinkList *queue, T value);
T dequeueTwoLinkList(TwoLinkList *queue);
void printTwoLinkCharNode(TwoLinkNode* n);
void printTwoLinkCharList(TwoLinkList* lst);



//сортировки массивов
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

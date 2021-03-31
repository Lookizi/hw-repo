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


//односвязные списки
void OneLinkInit(OneLinkList* lst) {
    lst->head = NULL;
    lst->size = 0;
}
void OneLinkIns(OneLinkList *lst, int data) {
    OneLinkNode *new = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    new->dat = data;
    new->next = NULL;

    OneLinkNode *current = lst->head;
    if (current == NULL) {
        lst->head = new;
        lst->size++;
        return;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        lst->size++;
    }
}
OneLinkNode* rm(OneLinkList* lst, int data) {
    OneLinkNode* current = lst->head;
    OneLinkNode* parent = NULL;
    if (current == NULL)
        return NULL;

    while (current->next != NULL && current->dat != data) {
        parent = current;
        current = current->next;
    }
    if (current->dat != data) {
        return NULL;
    }
    if (current == lst->head) {
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent->next = current->next;
    lst->size--;
    return current;
}
void printOneLinkNode(OneLinkNode* n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}
void printOneLinkList(OneLinkList* lst) {
    OneLinkNode* current = lst->head;
    if (current == NULL) {
        printOneLinkNode(current);
    } else {
        do {
            printOneLinkNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", lst->size);
}

//2связные списки
void initTwoLinkList(TwoLinkList *lst) {
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}
void pushFront(TwoLinkList *lst, int data) {
    TwoLinkNode *new = (TwoLinkNode *) malloc(sizeof(TwoLinkNode));
    new->dat = data;
    new->prev = NULL;
    new->next = lst->head;
    if (lst->head != NULL) {
        lst->head->prev = new;
    }
    if (lst->tail == NULL) {
        lst->tail = new;
    }
    lst->head = new;
    lst->size++;
}
void pushBack(TwoLinkList *lst, int data) {
    TwoLinkNode *new = (TwoLinkNode*) malloc(sizeof(TwoLinkNode));
    new->dat = data;
    new->next = NULL;
    new->prev = lst->tail;
    if (lst->tail != NULL) {
        lst->tail->next = new;
    }
    if (lst->head == NULL) {
        lst->head = new;
    }
    lst->tail = new;
    lst->size++;
}
TwoLinkNode* remFront(TwoLinkList *lst) {
    if (lst->head == NULL) {
        return NULL;
    }
    TwoLinkNode *tmp = lst->head;
    lst->head = lst->head->next;
    if (lst->head != NULL) {
        lst->head->prev = NULL;
    }
    if (tmp == lst->tail){
        lst->tail = NULL;
    }
    lst->size--;
    return tmp;
}
TwoLinkNode* remBack(TwoLinkList *lst) {
    if (lst->tail == NULL) {
        return NULL;
    }
    TwoLinkNode *tmp = lst->tail;
    lst->tail = lst->tail->prev ;
    if (lst->tail != NULL) {
        lst->tail->next = NULL;
    }
    if (tmp == lst->head){
        lst->head = NULL;
    }
    lst->size--;
    return tmp;
}
void printTwoLinkNode(TwoLinkNode* n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}
void printTwoLinkList(TwoLinkList* lst) {
    TwoLinkNode *current = lst->head;
    if (current == NULL) {
        printTwoLinkNode(current);
    } else {
        do {
            printTwoLinkNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", lst->size);
}

//Односвязный циклический список

void insertCyclic(OneLinkList *lst, int data) {
    OneLinkNode *new = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    new->dat = data;
    new->next = lst->head;

    OneLinkNode *current = lst->head;
    if (current == NULL){
        lst->head = new;
        new->next = lst->head;
        lst->size++;
        return;
    } else {
        while (current->next != lst->head) {
            current = current->next;
        }
        current->next = new;
        lst->size++;
    }
}
OneLinkNode *rmCyclic(OneLinkList *lst, int data) {
    OneLinkNode *current = lst->head;
    OneLinkNode *parent = NULL;

    if (current == NULL) {
        return NULL;
    }
    while (current->next != lst->head && current->dat != data) {
        parent = current;
        current = current->next;
    }
    if (current->dat != data) {
        return NULL;
    }
    if (current == lst->head) {
        if (current->next == lst->head) {
            lst->head = NULL;
            lst->size--;
            return current;
        } else {
            OneLinkNode *tmp = current;
            while (current->next != lst->head) {
                current = current->next;
            }
            lst->head = tmp->next;
            current->next = lst->head;
            lst->size--;
            return tmp;
        }
    }
    parent->next = current->next;
    lst->size--;
    return current;
}
void printCyclicIntList(OneLinkList* lst) {
    OneLinkNode* current = lst->head;
    if (current == NULL) {
        printOneLinkNode(current);
    } else {
        do {
            printOneLinkNode(current);
            current = current->next;
        } while (current != lst->head);
    }
    printf(" Size: %d \n", lst->size);
}

//Стек на основе односвязного списка
void initOneLinkStack(OneLinkStack *stack) {
    stack->head = NULL;
    stack->size = 0;
}
boolean pushOneLinkStack(OneLinkStack *stack, T value) {
    OneLinkNode *tmp = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (tmp == NULL) {
        printf("OneLinkStack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}
T popOneLinkStack(OneLinkStack *stack) {
    if (stack->size == 0) {
        printf("OneLinkStack is empty \n");
        return -1;
    }
    OneLinkNode *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}
void printOneLinkCharNode(OneLinkNode* n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%c]", n->dat);
}
void printOneLinkCharStack(OneLinkStack * stack) {
    OneLinkNode * current = stack->head;
    if (current == NULL) {
        printOneLinkCharNode(current);
    } else {
        do {
            printOneLinkCharNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", stack->size);
}

//Очередб на основе 2хсвязного списка
boolean enqueueTwoLinkList(TwoLinkList *queue, T value) {
    TwoLinkNode *tmp = (TwoLinkNode*) malloc(sizeof(TwoLinkNode));
    if (tmp == NULL) {
        printf("Out of Memory! \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = NULL;
    tmp->prev = queue->tail;

    if (queue->tail != NULL) {
        queue->tail->next = tmp;
    }
    if (queue->head == NULL) {
        queue->head = tmp;
    }

    queue->tail = tmp;
    queue->size++;
    return true;
}
T dequeueTwoLinkList(TwoLinkList *queue) {
    if (queue->size == 0) {
        printf("Queue is empty! \n");
        return -1;
    }
    TwoLinkNode *tmp = queue->head;
    T data = queue->head->dat;

    queue->head = queue->head->next;

    if (queue->head != NULL) {
        queue->head->prev = NULL;
    }
    if (tmp == queue->tail) {
        queue->tail = NULL;
    }

    free(tmp);
    queue->size--;
    return data;
}
void printTwoLinkCharNode(TwoLinkNode* n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%c]", n->dat);
}
void printTwoLinkCharList(TwoLinkList* lst) {
    TwoLinkNode *current = lst->head;
    if (current == NULL) {
        printTwoLinkCharNode(current);
    } else {
        do {
            printTwoLinkCharNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", lst->size);
}

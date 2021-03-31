/*
 * Created by Petrov S.
 *
 * Homework for lesson 9
 */

#include "func.h"
#define SIZE 10
#define SZ 100

typedef struct {
    int pr;
    int dat;
} Node;

Node* arr[SIZE];
int head;
int tail;
int items;

void init() {
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = NULL;
    }
    head = 0;
    tail = -1;
    items = 0;
}

boolean insert(int pr,int dat) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;

    if (items == SIZE) {
        printf("%s \n", "Queue is full");
        return false;
    }
    if (tail == SIZE - 1)
        tail = -1;
    arr[++tail] = node;
    items++;
    return true;
}

//к сожалению с основным заданием так и не успел разобраться,
// добавление ок - удаление не реализовано
Node* rem() {

    Node* node = (Node*) malloc(sizeof(Node));
    int flag;
    if (items == 0) {
        return NULL;
    } else {
        int i = 0;
        int idx = 0;
        Node *tmp;
        for ( i = head; i < tail; ++i) {
            idx = i % SIZE;
            if (arr[idx]->pr < node->pr)
                break;
            else
                idx++;
        }
        flag = idx % SIZE;
        i++;
        while (i <= tail) {
            idx = i % SIZE;
            tmp = arr[idx];
            arr[idx] = arr[flag];
            arr[flag] = tmp;
            i++;
        }
        arr[flag] = NULL;
        items++;
        tail--;
}

}

void printQueue() {
    printf("[ ");
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

// Task 2

T Stack[SZ];
int cursor = -1;

boolean push(T data) {
    int bin = 0;
    int i = 1;

    if (cursor < SZ) {
        while (data){
            bin += (data % 2) * i;
            i *= 10;
            data /= 2;
        }
        Stack[++cursor] = bin;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T pop() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

void lesson9_1() {
    init();
    insert(1,11);
    insert(3,22);
    printQueue();
    insert(5,66);
    insert(8,33);
    printQueue();
    insert(7,19);
    insert(10,123);
    insert(2,15);
    insert(4,90);
    insert(6,86);
    insert(9,47);
    printQueue();
    rem();
    rem();
    rem();
    rem();
    printQueue();
printf("\n");
}

void lesson9_2() {
    push(25);
    while (cursor != -1) {
        printf("25 in binary: %d", pop());
    }
    push(15);
    printf("\n");
    while (cursor != -1) {
        printf("15 in binary: %d", pop());
    }

}

int main() {
    printf("--------9.1------- \n");
    lesson9_1();
    printf("--------9.2------- \n");
    lesson9_2();
    return 0;
}

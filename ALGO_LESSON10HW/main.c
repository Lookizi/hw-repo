/*
 * Created by Petrov S.
 *
 * Homework for lesson 10
 */

#include <stdio.h>
#include "func.h"

//Task 10.1 - не успел

//Task 10.2
void OneLinkCopy(OneLinkList* from, OneLinkList* to) {
        OneLinkNode* current = from->head;
        OneLinkNode* end = NULL;
    while (current) {
        OneLinkNode* n = (OneLinkNode*) malloc(sizeof(OneLinkNode));
        n->dat = current->dat;

        if (!to->head) {
            to->head = n;
            end = to->head;
        } else {
            end->next = n;
            end = n;
        }
        current = current->next;
        to->size++;
    }
}

void lesson10_2() {
    OneLinkList * from = (OneLinkList*) malloc(sizeof(OneLinkList));
    OneLinkInit(from);
    OneLinkList* to = (OneLinkList*) malloc(sizeof(OneLinkList));
    OneLinkInit(from);
    OneLinkIns(from,1);
    OneLinkIns(from,10);
    OneLinkIns(from,76);
    printf("It's an original list: ");
    printOneLinkList(from);
    OneLinkCopy(from,to);
    printf("It's a copied list: ");
    printOneLinkList(to);
    rm(from,76);
    printOneLinkList(from);
    OneLinkInit(to);
    OneLinkCopy(from,to);
    printOneLinkList(to);
}

//Task 10.3
boolean isSort(OneLinkList* lst){
    OneLinkNode *new = (OneLinkNode*) malloc(sizeof(OneLinkNode));
        OneLinkNode* current = lst->head;
        OneLinkNode* next = new->next;

    if (!current){
        return true;
    }
    int tmp = current->dat;
    current = current->next;
    while (current) {
        if (tmp > current->dat) {
            return false;
        }
        tmp = current->dat;
        current = current->next;
    }
    return true;

}

void lesson10_3() {
    OneLinkList * lst = (OneLinkList*) malloc(sizeof(OneLinkList));
    OneLinkInit(lst);
    OneLinkIns(lst,4);
    OneLinkIns(lst,12);
    OneLinkIns(lst,10);
    OneLinkIns(lst,15);
    printOneLinkList(lst);
    printf("List sorted: %d \n", isSort(lst));
    OneLinkList * lst2 = (OneLinkList*) malloc(sizeof(OneLinkList));
    OneLinkInit(lst2);
    OneLinkIns(lst2,4);
    OneLinkIns(lst2,8);
    OneLinkIns(lst2,10);
    OneLinkIns(lst2,15);
    printOneLinkList(lst2);
    printf("List sorted: %d \n", isSort(lst2));
}
int main() {

    printf("--------10.2------- \n");
    lesson10_2();
    printf("--------10.3------- \n");
    lesson10_3();

    return 0;
}

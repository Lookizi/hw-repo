

#ifndef LESSON12_HW_FUNC_H
#define LESSON12_HW_FUNC_H

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef unsigned int bool;



typedef struct Node {
    int key;
    struct Node *left;
    struct Node* right;
} BinTreeIntNode;


BinTreeIntNode* treeInsert(BinTreeIntNode *t, int data);
void printBinTree(BinTreeIntNode *root);
void printBinTreeSearch(BinTreeIntNode *root);
BinTreeIntNode* getSuccessor(BinTreeIntNode *node);
bool deleteBinTree(BinTreeIntNode *root, int key);

void preOrderTravers(BinTreeIntNode *root);
void inOrderTravers(BinTreeIntNode *root);
void postOrderTravers(BinTreeIntNode *root);

BinTreeIntNode* balancedTree(int n);

bool binTreeSearch(BinTreeIntNode *root, int value);

void buildTree(int* arr, int new, int size);

void heapSort(int* arr, int size);

#endif //LESSON12_HW_FUNC_H

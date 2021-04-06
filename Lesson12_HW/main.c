/*
 * Created by Petrov S.
 *
 * Homework for lesson 12 (Trees)
 */

#include <stdio.h>
#include "func.h"
#include <time.h>
#define SZ 50
#define NODES 10000

//-------------------- Exercise1 --------------------

//get height of each subtree by recursive algo
int treeHeight(BinTreeIntNode *root) {

    if (root == NULL)
        return 0;
    else {
        int left = treeHeight(root->left);
        int right = treeHeight(root->right);
        return (left > right) ? left : right + 1;
    }
}

//check is tree balanced or not
bool isBalancedIntTree(BinTreeIntNode *root) {
    if (root == NULL){
        return true;
    } else {
        int heightL = treeHeight(root->left);
        int heightR = treeHeight(root->right);
        if (heightL - heightR > 1 || heightR - heightL > 1)
            return false;
        else return true;
    }

}

void Ex1() {
    BinTreeIntNode *treeUnBal = NULL;
    treeUnBal = treeInsert(treeUnBal, 10);
    treeInsert(treeUnBal, 8);
    treeInsert(treeUnBal, 19);
    treeInsert(treeUnBal, 5);
    treeInsert(treeUnBal, 9);
    treeInsert(treeUnBal, 16);
    treeInsert(treeUnBal, 21);
    treeInsert(treeUnBal, 77);
    treeInsert(treeUnBal, 80);
    printBinTree(treeUnBal);
    printf("\n");
    printf("tree is %s balanced \n", isBalancedIntTree(treeUnBal) ? "" : "not" );
    free(treeUnBal);

    printf("-------------------\n");

    BinTreeIntNode *treeBal = NULL;
    treeBal = treeInsert(treeBal, 10);
    treeInsert(treeBal, 8);
    treeInsert(treeBal, 19);
    treeInsert(treeBal, 5);
    treeInsert(treeBal,9 );
    treeInsert(treeBal, 16);
    treeInsert(treeBal, 21);
    printBinTree(treeBal);
    printf("\n");
    printf("tree is%s balanced \n", isBalancedIntTree(treeBal) ? "" : "not" );
    free(treeBal);

    printf("-------------------\n");
}

//-------------------- Exercise2 --------------------
                       /*Part1*/

void treeGenerator(BinTreeIntNode* arr[SZ]) {

    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
        for (int j = 0; j < NODES; ++j) {
            arr[i] = treeInsert(arr[i], rand() % NODES);
        }
    }

}

void printArrOfTrees(BinTreeIntNode* arr[SZ]) {
        for (int i = 0; i < SZ; ++i) {
        printf("[%d] tree is: ", i+1);
        printBinTree(arr[i]);
        printf("\n");
    }
}

void Ex2a(){
    srand(time(NULL));
    BinTreeIntNode *arrayOfTrees[SZ];
    treeGenerator(arrayOfTrees);
//    printArrOfTrees(arrayOfTrees);
    printf("\n");
//    free(arrayOfTrees);
}


//-------------------- Exercise2 --------------------
                       /*Part2*/
double howManyBalanced(BinTreeIntNode* arr[SZ]){
    double size = SZ;
    double balanced = 0;
    for (int i = 0; i < SZ; ++i) {
        if (isBalancedIntTree(arr[i]))
            balanced++;
    }
    return  size - size/ 100 * balanced;
}

void Ex2b(){
    srand(time(NULL));
    BinTreeIntNode *arrayOfTrees[SZ];
    treeGenerator(arrayOfTrees);
    printf("%.2f%% is balanced \n",howManyBalanced(arrayOfTrees));
}

//-------------------- Exercise3 --------------------
BinTreeIntNode* searchNode(BinTreeIntNode* root, int value) {
    if (root == NULL) {
        printf("Value not found! \n");
        return NULL;
    }
    if (root->key == value)
        return root;

    if (value < root->key)
        return searchNode(root->left,value);
    else
        return searchNode(root->right,value);

}

void Ex3() {
    BinTreeIntNode *tree = NULL;
    tree = treeInsert(tree, 10);
    treeInsert(tree, 8);
    treeInsert(tree, 19);
    treeInsert(tree, 5);
    treeInsert(tree, 9);
    treeInsert(tree, 16);
    treeInsert(tree, 21);
    printf("Current tree: ");
    printBinTree(tree);
    printf("\n");
    BinTreeIntNode *data = NULL;
    data = searchNode(tree,19);
    printf("value 19 is found in node: ");
    printBinTree(data);
    printf("\n");
    data = searchNode(tree,5);
    printf("value 5 is found in node: ");
    printBinTree(data);
    printf("\n");
    printf("value 11 is found in node: ");
    data = searchNode(tree,11);
    printBinTree(data);
}

int main() {
    char key = '\0';
    printf("*** please choose an exercise from 1 to 4: \n");
    while (key != 'n') {
        scanf("%c", &key);
        switch (key) {
            case '1':
                Ex1();
                break;
            case '2':
                Ex2a();
                Ex2b();
                break;
            case '3':
                Ex3();
                break;
            default:
                printf("*** please choose an exercise from 1 to 4 or press 'n' for exit: \n");
        }
    }
   return 0;
}

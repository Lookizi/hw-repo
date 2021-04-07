/*
 * Created by Petrov S.
 *
 * Homework for lesson 13 (graphs)
 */

#include <stdio.h>
#include "geek.h"
#define SZ 7



//-------------------- Exercise1 --------------------

void depthTraversStack(int** matrix,int start, int size) {
    OneLinkList* stack = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(stack);

    int visited[size];
    clearIntArray(visited,size);

    pushOneLinkStack(stack,start);

    while (stack->size > 0) {
        int index = popOneLinkStack(stack);
        if (visited[index] == 1) continue;
        visited[index] = 1;
        printf("%d ", index);
        for (int i = size - 1; i >= 0; --i) {
            if (matrix[index][i] == 1 && !visited[i]){
                pushOneLinkStack(stack,i);
            }
        }
    }
}

void Ex1() {
    int** adjacency = init2dIntArray(adjacency,SZ,SZ);

    set2dInt(adjacency,0,1,1);
    set2dInt(adjacency,0,2,1);
    set2dInt(adjacency,1,3,1);
    set2dInt(adjacency,1,4,1);
    set2dInt(adjacency,1,5,1);
    set2dInt(adjacency,2,5,1);
    set2dInt(adjacency,3,0,1);
    set2dInt(adjacency,5,4,1);
    printf("---------- adjacency matrix for Exercise 1 ----------\n");
    print2dIntArray(adjacency,SZ,SZ,3);
    printf("\n");

    printf("---------- Depth travers realized by stack ----------\n");
    for (int i = 0; i < SZ; ++i) {
        printf("if graph vertex is %d, than travers is: ", i);
        depthTraversStack(adjacency,i,SZ);
        printf("\n");
    }
    printf("\n");

}

//-------------------- Exercise2 --------------------



void adjacencyCount(int** matrix, const int size) {
    int indegree = 0;
    int vertex = 0;
    int sum = 0;
    printf("---------- Indegree of each vertex ----------\n");
    while (vertex < size) {
        for (int i = 0; i < size; ++i) {
            if (get2dInt(matrix, vertex, i) == 1) {
                indegree++;
            }
        }
        printf("vertex is: %d, indegree of vertex: %d \n",vertex, indegree);
        vertex++;
        sum += indegree;
        indegree = 0;
    }
    printf("\nsum of edges: %d\n",sum);
}

void traversalCount(int** matrix, int start, const int size) {
    TwoLinkList* queue = (TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(queue);
    int visited[size];
    clearIntArray(visited,size);
    int indegree = 0;
    TwoLinkEnqueue(queue,start);
    while (queue->size > 0) {
        int index = TwoLinkDequeue(queue);
        if (visited[index] == 1) continue;
            for (int i = 0; i < size; ++i) {
                if (get2dInt(matrix,index,i) == 1 && visited[i] == 0) {
                    TwoLinkEnqueue(queue, i);
                    indegree++;
                }
        }
        visited[index] = 1;
    }
    printf("vertex is: %d, indegree of adjacent vertices: %d ",start, indegree);
}

void Ex2() {
    int **adjacency = init2dIntArray(adjacency, SZ, SZ);

    set2dInt(adjacency, 0, 1, 1);
    set2dInt(adjacency, 1, 0, 1);
    set2dInt(adjacency, 2, 3, 1);
    set2dInt(adjacency, 2, 4, 1);
    set2dInt(adjacency, 3, 2, 1);
    set2dInt(adjacency, 3, 4, 1);
    set2dInt(adjacency, 3, 5, 1);
    set2dInt(adjacency, 4, 2, 1);
    set2dInt(adjacency, 4, 3, 1);
    set2dInt(adjacency, 4, 5, 1);
    set2dInt(adjacency, 5, 3, 1);
    set2dInt(adjacency, 5, 4, 1);
    set2dInt(adjacency, 6, 6, 1);
    printf("---------- adjacency matrix for Exercise 2 ----------\n");
    print2dIntArray(adjacency, SZ, SZ, 3);
    printf("\n");

    adjacencyCount(adjacency,SZ);
    printf("\n");
    printf("---------- Indegree of adjacent vertices ----------\n");
    for (int i = 0; i < SZ; ++i) {
        traversalCount(adjacency, i, SZ);
        printf("\n");
    }

}

int main() {

    Ex1();
    Ex2();

    return 0;
}

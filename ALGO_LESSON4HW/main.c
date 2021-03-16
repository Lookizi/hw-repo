/*
 * Created by Petrov S.
 *
 * Homework for lesson 4
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define sizeY 5
#define sizeX 5

int board[sizeY][sizeX];

//function for task 1
int dec_to_bin(int);

//function for task 2
int recPower(int, int);

//function for task 3
int recPropertyPower(int, int);

//functions for task 4
void barriers();
int kingsRoute(int, int);
void printRoute();


int main() {
//Task 1
    int n;
    printf("Enter decimal number: ");
    scanf("%d", &n);
    printf("\nYour decimal number in binary: 0x");
    printf("%d",dec_to_bin(n));
    printf("\n");

//Task 2 & 3

    int num, pow;
    printf("\nEnter number and power: ");
    scanf("%d %d", &num, &pow);
    printf("\nIn 1st case your powered number: %d\n", recPower(num,pow));
    printf("\nIn 2nd case your powered number: %d\n", recPropertyPower(num,pow));

//Task 4

    srand(time(NULL));

    printf("\n-----Board with barriers-----\n");
    barriers();
    printf("\n");
    printf("-----Board with King's routes-----\n");
    printRoute();

    return 0;
}

//Task 1

int dec_to_bin(int n) {
    if (n == 0)
        return 0;
    else
        return n % 2 + 10 * (dec_to_bin(n / 2));
}

//Task 2

int recPower(int num, int pow) {
    if (num == 0)
        return 0;
    else if (pow == 0 || num == 1)
        return 1;
    else if (pow > 0)
        return num * recPower(num,pow-1);
}

//Task 3

int recPropertyPower(int num, int pow) {
    if (num == 0)
        return 0;
    if (pow == 0 || num == 1)
        return 1;

    if (pow % 2 == 0 && pow > 0){
        pow/=2;
        return recPropertyPower(num,pow) * recPropertyPower(num,pow);
    }
    else
        return num * recPropertyPower(num, pow - 1);
}

//Task4

//I'm not really sure about this task, but how could :)



//Here we fill the array of ones with random zeros (barriers) and print it
void barriers() {
    for (int i = 0; i < sizeY; ++i) {
        for (int j = 0; j < sizeX; ++j) {
            board[i][j] = 1;
        }
    }
    for (int i = rand()%5; i < sizeY; ++i) {
        for (int j = rand()%5; j < sizeX; ++j) {
            board[i][j] = 0;

        }
    }
    for (int i = 0; i < sizeY; ++i) {
        for (int j = 0; j < sizeX; ++j) {
            printf("%5d",board[i][j]);
        }
        printf("\n");
    }

}
//main algorithm (added diagonals)
int kingsRoute(int x, int y) {
    if (x == 0 && y == 0)
        return 1;
    else if (x == 0 ^ y == 0)
        return 1;
    else if (board[y][x])
        return kingsRoute(x, y -1) + kingsRoute(x - 1, y) + kingsRoute(x - 1, y - 1);
    else
        return 0;
}
//print routes of our king
void printRoute() {

    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            printf("%5d", kingsRoute(x,y));
        }
        printf("\n");
    }
}


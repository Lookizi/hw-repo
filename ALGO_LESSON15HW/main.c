/*
 *Created by Petrov S.
 *
 *Homework for lesson 15
 */

#include "geek.h"
#define SZ 250
//-------------------- EX1 --------------------

int simpleHashSum(char* in) {
    int key = 0;
    for (int i = 0; i < SZ; ++i) {
        key += in[i];
    }
    return key;
}

void EX1() {
    printf("---------- EX1 ----------\n");
    char str[SZ] = "~";
    printf("Hash for the string '~' is: %d",simpleHashSum(str));
    printf("\n");
    char str2[SZ] = "AB\0";
    printf("Hash for the string 'AB' is: %d",simpleHashSum(str2));
    printf("\n");
    char str3[SZ] = "Hello world!";
    printf("Hash for the string 'Hello world!' is: %d",simpleHashSum(str3));
    printf("\n");
}

//-------------------- EX2 --------------------

int* exchange(int* money, int size, int sum) {
    printf("Minimum number of coins for the amount %d is:", sum);
    for (int i = 0; i < size; ++i) {
        while ((sum % money[i] != sum) && sum > 0) {
            sum -= money[i];
            printf("%3d,",money[i]);
        }
    }
    printf("\n");
}

void EX2() {
    printf("---------- EX2 ----------\n");

    const int size = 5;
    int money[size] =   {50, 10, 5, 2, 1};
    int sum = 98;
    exchange(money,size,sum);
}

int main() {
    EX1();
    EX2();

    return 0;
}

/*
 * Created by Petrov S.
 *
 * Homework for lesson 3
 */

#include <stdio.h>
#include <math.h>

int main() {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    int flag = 0;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0){
            flag = 1;
        }
    }
    if (num == 1 || flag != 0)
        printf("Number is not prime\n");
    else
        printf("Number is prime\n");
    return 0;
}

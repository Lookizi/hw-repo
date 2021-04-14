/*
 * Created by Petrov S.
 *
 * Homework for lesson 16
 */

#include <stdio.h>
#include <stdlib.h>
#include "geek.h"


//-------------------- EX1 --------------------

char* caesar(char* in, int key, bool encrypt) {
    for (int i = 0; i < strlen(in); ++i) {
        if (encrypt) {
            in[i] = (char)((int) in[i] + key);
        }else{
            in[i] = (char)((int) in[i] - key);
        }
    }
   return in;
}

void EX1() {
    //    char* message = (char*)malloc(sizeof(char));
//    scanf("%s",message);

    printf("-------------------- EX1 --------------------\n");
    char message[] = "CDEF\0";
    char message2[] = "it's a caesar algo\0";
    int key = -2;
    int key2 = 3;
//---------- Test 1 ----------
    printf("Encrypt message \"%s\" by key = %d is: ",message,key);
    printf("%s\n",caesar(message,key,true));
    printf("Decrypt message is: %s\n",caesar(message,key,false));
    printf("\n");

//---------- Test 2 ----------
    printf("Encrypt message \"%s\" by key = %d is: ",message2,key2);
    printf("%s\n",caesar(message2,key2,true));
    printf("Decrypt message is: %s\n",caesar(message2,key2,false));
}



//-------------------- EX2 --------------------
//doesn't working :(

char* shuffle(char* in, int key, bool encrypt) {
//    int row;
//    int col = key;
//    for (int i = 0; i < strlen(in); ++i) {
//        row = (int)(strlen(in)) % key;
//    }
        for (int i = 0; i < strlen(in); ++i) {
            char temp = in[i];
            in[i] = in[i + key];
            in[i + key] = temp;

    }
    return in;
}

void EX2() {
char message[] ="this is a secret message\0";
//printf("%s",shuffle(message,5,true));
shuffle(message,5,true);
}


int main() {
    EX1();
//    EX2();
    return 0;
}

//
// Created by Petrov S.
//


#include <iostream>
#include "lesson5_hw.h"
#include <cstdarg>

//Func for 5th task


    void reverseVa(int revArr2[], ...) {

        va_list ap;

        va_start(ap, revArr2);

        int SIZE = va_arg(ap, int);

        for (int i = 0; i < SIZE; i++) {
            revArr2[i] ^= 1;

            std::cout << revArr2[i] << " ";
        }
        std::cout << std::endl;
        va_end(ap);
    }

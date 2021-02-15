//
// Created by Petrov S.
//


#include <iostream>
#include "lesson5_hw.h"

//Func for 1st task


    void reverse(int *revArr) {

        for (int i = 0; i < 10; i++) {
            if (revArr[i] == 0) {
                revArr[i] = 1;
            } else revArr[i] = 0;

            std::cout << revArr[i] << " ";
        }
        std::cout << std::endl;
    }

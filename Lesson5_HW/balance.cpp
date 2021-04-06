//
// Created by Petrov S.
//


#include <iostream>
#include "lesson5_hw.h"

//Func for 3d task


    void balance(int *b_arr) {

        int sum_l = 0, sum_r = 0, sum_a = 0;

        for (int i = 0; i < 5; i++) {
            sum_a += b_arr[i];

        }


        for (int i = 0; i < 5; i++) {

            sum_l += b_arr[i - 1];
            sum_r = sum_a - sum_l;
            if (sum_r == sum_l) {
                std::cout << "true" << std::endl;
                break;
            }

        }
        if (sum_r != sum_l) {
            std::cout << "false" << std::endl;

        }
    }

//
// Created by Petrov S.
//
#include <iostream>
#include "lesson5_hw.h"

// Func for 4th task


    void shift(int *array4, int &n) {

        int temp;

        if (n > 0) {

            for (int j = 0; j < n; j++) {
                temp = array4[4];
                for (int i = 4; i > 0; i--) {
                    array4[i] = array4[i - 1];
                }
                array4[0] = temp;
            }
        } else if (n < 0) {
            n *= -1;
            for (int j = 0; j < n; j++) {
                temp = array4[0];
                for (int i = 0; i < 5; i++) {
                    array4[i] = array4[i + 1];
                }
                array4[4] = temp;
            }
        }

    }

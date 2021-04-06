//
// Created by Petrov S.
//


#include <iostream>
#include "lesson5_hw.h"

//Func for 2nd task


    void threeStep(int stepArr[8]) {

        int step = 1;
        for (int i = 0; i < 8; i++) {

            stepArr[i] = step;
            step += 3;

            std::cout << stepArr[i] << " ";
        }
        std::cout << std::endl;
    }

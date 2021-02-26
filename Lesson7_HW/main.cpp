/*
 * Created by Petrov S.
 *
 * Homework for lesson 7
 */

#include <iostream>
// 1st task
#define RANGE(X,Y) ((X)>=0 && (X)<(Y)) ? (std::cout << "true\n" << std::endl) : (std::cout << "false\n")

//2nd task
#define DIM1 4
#define DIM2 4
#define ARR_ELEMENT(ARRAY,X,Y) (*(*(ARRAY + X) + Y))

//3d task
#define AMOUNT_OF_ELEMENTS(ARR,TYPE) (sizeof((*(&(ARR))))) / ((sizeof(TYPE)))

int **array_creator(unsigned int, unsigned int);

void array_destroyer(int**, unsigned int);


int main(){

    // 1st task
    std::cout << "1st task\n";

    RANGE(0,15);

    // 2nd task
    std::cout << "2nd task\n";

    int **dynamic_arr;
    int x = 3, y = 3;
    dynamic_arr = array_creator(DIM1,DIM2);

    std::cout << "This is your array: \n";

    for (int i = 0; i < DIM1; i++) {
        for (int j = 0; j < DIM2; j++) {
            std::cout << dynamic_arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Element of dinamic_arr[" << x << "][" << y << "] = "<< ARR_ELEMENT(dynamic_arr,x,y) << std::endl;
    std::cout << std::endl;

    array_destroyer(dynamic_arr,DIM1);

    //3d task
    std::cout << "3d task\n";
    int local_arr[256];
    std::cout << "Amount of elements of array = " << AMOUNT_OF_ELEMENTS(local_arr,int) << std::endl;



    return 0;

}

int **array_creator(unsigned int dim1, unsigned int dim2){
    int **pt_arr = new int*[dim1];
    for (int i = 0; i < dim1; i++) {
        pt_arr[i] = new int[dim2];
    }

    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            pt_arr[i][j] = j;
        }
    }
    return pt_arr;

}

void array_destroyer(int **arr, unsigned int dim1){
    for (int i = 0; i < dim1; i++) {
        delete [] arr[i];
    }
    delete [] arr;
}




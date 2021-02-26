#include <iostream>
#include "lesson5_hw.h"
using namespace std;
using namespace func;
//using namespace Lesson5_HW;




int main() {

    // 1st task
   cout << "1st task:" << endl;
   cout << endl;

   int arr[] = {1,0,1,1,0,0,0,1,0,1};

    void reverse(int *);
    void (*Reverse)(int *);
    Reverse = reverse;
    (*Reverse)(arr);

    cout << endl;

    //2nd task
    cout << "2nd task:" << endl;
    cout << endl;

    int arr2[8];
    void threeStep(int *);
    void (*ThreeStep)(int *);
    ThreeStep = threeStep;
    (*ThreeStep)(arr2);
    cout << endl;

    //3d task
    cout << "3d task:" << endl;
    cout << endl;

    int arr3[5] = {4,1,2,2,1};
    void balance(int *);
    void (*Balance)(int *);
    Balance = balance;
    (*Balance)(arr3);
    cout << endl;

    //4th task

    cout << "4d task:" << endl;
    cout << endl;

    int arr4[5] = {5,1,0,2,1};
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << endl;

    void shift(int *array4, int &n);

    void (*Shift)(int*, int &n);
    Shift = shift;
    (*Shift)(arr4,n);
    for (int i = 0; i < 5; i++){
        cout <<arr4[i] <<" ";
    }
    cout << endl;
    cout << endl;

    //5th task
    cout << "5th task:" << endl;
    cout << endl;

    int arr_d[] = {1,0,1,1,0,0,0,1,0,1};
    void reverseVa(int *, ...);
    void (*ReverseVa)(int *, ...);
    ReverseVa = reverseVa;
    (*ReverseVa)(arr_d, 10);

    return 0;

}









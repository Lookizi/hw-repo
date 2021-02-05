#include <iostream>
#include "program.h"
#include "Global.h"
using namespace std;
int main(){

// 1st task

 int a = 11;
 int b = 6;
 int c = 134;
 int d = 13;

float result = (a * ( b + ((float)c / d)));

cout << "First task " << endl;
cout << " " << endl;
cout << " a * ( b + (c / d) ) = " << result << endl;
cout << " " << endl;

//2nd task

int n;
cout << "Second task " << endl;
cout << " " << endl;
cout << "n = ";
cin >> n;

int difference = (n > 21) ? ((n - 21) * 2) : (n - 21);

cout << " " << endl;
cout << difference << endl;
cout << " " << endl;

//3d task

cout << "Third task " << endl;
cout << " " << endl;
 extern int a1;
 extern int b1;
 extern int c1;
 extern int d1;

float result1 = (a1 * ( b1 + ((float)c1 / d1)));

cout << " a * ( b + (c / d) ) = " << result1 << endl;
cout << " " << endl;

//4th task
cout << "4th task " << endl;
cout << " " << endl;

int array[3][3][3] = {
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    },
    {
        {10,11,12},
        {13,14,15},
        {16,17,18}
    },
    {
        {19,20,21},
        {22,23,24},
        {25,26,27}
    }
}, *parray;

parray = &array[1][1][1];

cout << " array[1][1][1] = " << *parray << endl;

return SUCCESS;
}

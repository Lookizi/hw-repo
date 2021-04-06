/*
 * Created by Petrov S.
 *
 * Homework for 4th lesson
 */

#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    // 1st task

    int a,b,sum=0;

    cout << "1st task:" << endl;
    cout << " " << endl;
    cout << "Enter a = ";
    cin >> a;
    cout << " " << endl;
    cout << "Enter b = ";
    cin >> b;
    cout << " " << endl;
    sum = a+b;
    if (sum>=10 && sum <=20){
        cout << "true" <<endl;
      }
    else{
        cout << "false" <<endl;
    }

    cout << " " << endl;


    // 2nd task

    cout << "2nd task:" << endl;
    cout << " " << endl;

    int n,count=0;
    cout << "Enter n = ";
      cin>>n;

    for(int i=2;i<sqrt(n);i++)
    {
        if(n%i==0){
        count++;
        }
    }

    if(n==1||count!=0)
        cout<<"n is not prime" << endl;
    else{
        cout<<"n is prime" << endl;
    }

        cout << " " << endl;


    // 3d task

      cout << "3d task:" << endl;
      cout << " " << endl;

            int d = 4,e = 6,sum2;
            sum2 = d + e;
            if((d == 10 && e == 10) || (sum2 == 10))
                cout << "true" << endl;
            else{
                cout << "false" << endl;
            }

                cout << " " << endl;

    // 4th task

       cout << "4th task:" << endl;
       cout << " " << endl;

       int year = 0;

       cout << "Enter year: ";
       cin >> year;
       cout << " " << endl;

           if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
               cout << year << " is leap year" << endl;
           }
           else{
               cout << year << " is not leap year" << endl;
           }

    return 0;
}

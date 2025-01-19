/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: WAP to show swapping using template function (Generic).
Date: 00-11-2024
*/

#include <iostream>
using namespace std;

template <class T>
void swap_num(T &a, T &b){
   a = a + b;
   b = a - b;
   a = a - b;
}

int main(){
   int a=25, b=52;
   cout << "-------------------------"<<endl;
   cout << "Before swap:\n\ta = " << a << " b = " << b << endl;
   swap_num(a, b);
   cout << "After swap:\n\ta = " << a << " b = " << b << endl;

   cout << "-------------------------"<<endl;
   
   float x=2.5, y=5.2;
   cout << "Before swap:\n\tx = " << x << " y = " << y << endl;
   swap_num(x, y);
   cout << "After swap:\n\tx = " << x << " y = " << y << endl;
   cout << "-------------------------"<<endl;
}

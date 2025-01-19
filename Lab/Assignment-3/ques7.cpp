/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: WAP to demonstrate the concept of rethrowing an exception.
Date: 00-11-2024
*/

#include <iostream>
using namespace std;

void divide(int a, int b){
   try{
      if (b<=0)
         throw a;
      else
         cout << a << "/" << b << " = " << a / b<<endl;
   }
   catch(int){
      cout << "I caught an exception but \nmom said i'm not allowed to deal with it. "
              "\nTT \n*wipes tears on sleeve *"<<endl;
      throw;
   }
}

int main(){
   try{
      divide(24, 2);
      divide(24, 0);
   }
   catch(int){
      cout << "Caught Re-Thrown Integer Exception"<<endl;
   }
   return 1;
}
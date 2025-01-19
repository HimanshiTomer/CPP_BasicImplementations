/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: Define a class Counter which contains an int variable count defined 
         as static and a static function Display () to display the value of count. 
         Whenever an object of this class is created count is incremented by 1. 
         Use this class in main to create multiple objects of this class 
         and display value of count each time
Date: 04-09-2024
*/

#include <iostream>
#include<string.h>
using namespace std;

class Counter{
   public:
      static int count;
      Counter(){
         count+=1;
         cout<<"Object created."<<endl;
      }
      static void Display(){
         cout<<"Counter: "<<count<<endl;
      }
};
int Counter::count=0;
int main(){
   
   Counter c1, c2;
   Counter::Display();
   Counter c3, c4, c5;
   Counter::Display();
   Counter c6, c7, c8;
   Counter::Display();
   Counter c9, c10;
   Counter::Display();
   return 0;
}

/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: WAP to implement 'Exception Handling'.
Date: 29-10-2024
*/

#include <iostream>
using namespace std;

void sum(int a, int b){
   if (a>0 && b>0){
      cout<<"Sum: "<<a + b<<endl;
      return;
   }
   throw 1;
}

int main(){
   int result = 0;
   try{
      sum(32, 23);
      sum(32, 0);
   }
   catch(int){
      cout << "Caught Excedption";
   }
}


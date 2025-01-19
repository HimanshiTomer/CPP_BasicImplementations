/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: WAP to illustrate use of multiple catch statements.
Date: 00-11-2024
*/

#include <iostream>
using namespace std;

void num_check(int a){
   try{
      if (a==1) 
         throw a;
      else if (a==0) 
         throw '0';
      else if (a==-1) 
         throw float(1.0);
      else 
         cout << "No Exception Was Found"<<endl;
   }
   catch(int i){
      cout << "Caught Integer Exception"<<endl;
   }
   catch(char i){
      cout << "Caught Char Exception"<<endl;
   }
   catch(float i){
      cout << "Caught Float Exception"<<endl;
   }
}

int main(){
   num_check(1);
   num_check(0);
   num_check(-1);
   num_check(34);
   return 1;
}
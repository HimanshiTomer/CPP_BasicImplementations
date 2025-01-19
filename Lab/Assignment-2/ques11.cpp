/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: Write program to overload Binary + to add two similar types of objects. (Both with 
and without using friend functions)
Date: 01-10-2024
*/

#include <iostream>

using namespace std;

class num{
public:
   int n;
   num(){ 
      n = 0; 
   }
   num(int v){
      n = v;
   }
   num operator+(num &n1){
      num n2;
      n2.n = this->n + n1.n;
      return n2;
   }
   num operator=(num &n1){
      n = n1.n;
      return *this;
   }
   friend num operator+(num &n1, num &n2);
   void output(){
      cout << "Number: " << n << endl;
   }
};

num operator+(num &n1, num &n2) {
   num n3;
   n3.n = n1.n + n2.n;
   return n3;
}

int main() {
   num n1(2), n2(6);

   num sum;
   sum = n1 + n2; 
   sum.output();
   
   num sum_f = operator+(sum, n1);
   sum_f.output();

   return 0;
}
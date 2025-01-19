/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: WAP to convert meter to centimeter and vice versa, 
         using data conversions and operator overloading.
Date: 01-10-2024
*/

#include <iostream>
using namespace std;

class centimeter;

class meter{
public:
   float m;
   meter(){
      m = 0;
   }
   meter(float val){
      m = val;
   }
   meter(centimeter &c1);
   operator centimeter();
   void output(){
      cout << "Meters: " << m << endl;
   }
};

class centimeter{
public:
   float cm;
   centimeter(){
      cm = 0;
   }
   centimeter(float val){
      cm = val;
   }
   centimeter(meter &m1){
      cm = m1.m * 100;
   }
   operator meter(){
      meter m1(cm / 100);
      return m1;
   }
   void output(){
      cout << "Centimeters: " << cm << endl;
   }
};

meter::meter(centimeter &c1){
   m = c1.cm / 100;
}

meter::operator centimeter(){
   centimeter c1(m * 100);
   return c1;
}


int main(){
   meter m1(1.50); centimeter c1 (150);
   m1.output(); c1.output();

   meter m2 = c1;
   centimeter c2 = m1;
   m2.output(); c2.output();
   
   return 1;
}
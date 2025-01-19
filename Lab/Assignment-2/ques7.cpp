/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: Create two classes and square and rectangle with side and length and
         breadth as data members respectively. WAP to convert one object type
         to another using overloaded assignment op & parameterized constructor.
Date: 01-10-2024
*/

#include <iostream>
#include <cstring>
using namespace std;

class rectangle;

class square
{
public:
   int size;
   square(){
      size=0;
      sqdisplay();
   }
   square(int s){
      size=s;
      sqdisplay();
   }
   square(square &s){
      size=s.size;
      sqdisplay();
   }
   square(rectangle &r);
   square operator=(rectangle &r);
   void sqdisplay(){
      cout<<"Side of Square: "<<size<<endl;
   }
};

class rectangle
{
public:
   int length, breadth;
   rectangle(){
      length=breadth=0;
      recdisplay();
   }
   rectangle(int l, int b){
      length=l; breadth=b;
      recdisplay();
   }
   rectangle(square &s){
      length=s.size;
      breadth=s.size;
      recdisplay();
   }
   rectangle operator= (square &s){
      rectangle r1;
      r1.length = r1.breadth = s.size;
      return r1;
   }
   void recdisplay(){
      cout<<"Length of Rectangle: "<<length<<endl;
      cout<<"Breadth of Rectangle: "<<breadth<<endl;
   }
};

square::square(rectangle &r){
   //size=r.length;
   size=r.breadth;
   sqdisplay();
}
square square::operator= (rectangle &r){
   square s;
   //s.size=r.length;
   s.size=r.breadth;
   return s;
}

int main(){
   square s1(4); 
   rectangle r1(4, 8);
   square s2 = r1;
   rectangle r2 = s1;
   return 0;
}

//works on online comp
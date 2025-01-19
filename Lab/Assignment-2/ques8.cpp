/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: Write a string class which contains a string and its size. 
         Write following for the class: 
            a. Write input and output functions. 
            b. Create proper constructors and destructors. 
         Overloaded +, = and > operators for concatenation, assignment and 
         comparison of string.
Date: 01-10-2024
*/

#include <iostream>
#include <cstring>
using namespace std;

class String
{
   char *str;
   int size;

public:
   String() {
      size = 0;
   };
   String(char s[]){
      size = strlen(s);
      str = new char[size];
      strcpy(str, s);
   }
   String(int s){
      size=s;
      str=new char[size];
   }
   void input(){
      cout<<"\nEnter size: "; cin>>size;
      str=new char[size];
      cout<<"Enter string: "; cin>>str;
   }
   void output(){
      cout << "String: " << str << endl;
   }
   // Con-meow-enation +
   String operator+(String &s){
      String s1(size+s.size+1);
      strcpy(s1.str, str);
      strcat(s1.str, s.str);
      return s1;
   }
   // Assignment =
   String operator= (String &s){
      size=s.size;
      str = new char[size];
      strcpy(str, s.str);
      return *this;
   }
   // Comparison >
   bool operator>(String &s){
      if (strcmp(str, s.str)>0)
         return true;
      return false;
   }
   ~String(){
      delete[] str;
   }
};

int main(){
   char fname[9]="Himanshi", lname[6]="Tomer";
   String s1(fname);
   String s2 = lname;
   s1.output(); s2.output();
   String s3 = s1 + s2;
   s3.output();
   if (s1 > s2)
      cout << "s1 is greater.";
   else
      cout << "s2 is greater.";
}

//run on programiz
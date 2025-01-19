/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: WAP to implement += and = operator.
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
      str = nullptr;
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
   String operator+=(String &s){
      char *strn = new char[size + s.size];
      strcpy(strn, str);
      strcat(strn, s.str);
      delete[] str;
      str=strn;
      size += s.size;
      return *this;
   }
   // Assignment =
   String operator= (String &s){
      delete[] str;
      size=s.size;
      str = new char[size];
      strcpy(str, s.str);
      return *this;
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
   s1 += s2;
   s1.output();
   return 0;
}
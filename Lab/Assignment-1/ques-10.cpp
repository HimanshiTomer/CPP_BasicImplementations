/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: Write a class String. It must have constructors which
         allow definition of objects in the following form:
            1.  String name1;
            2.  String name2="Lowe";
            3.  String name3=name2;
Date: 05-09-2024
*/

#include <iostream>
#include <string.h>
using namespace std;

class String
{
   char name[30];

public:
   String() {}
   String(char n[30])
   {
      strcpy(name, n);
   }
   String(String &s1)
   {
      strcpy(name, s1.name);
   }
   void input()
   {
      cout << "Enter name: ";
      cin >> name;
   }
   void display()
   {
      cout << "Name: " << name << endl;
   }
};

int main()
{
   char name[30] = "Rakesh";
   String name1, name2(name), name3(name2);
   name1.input();
   name1.display();
   name2.display();
   name3.display();
   return 0;
}

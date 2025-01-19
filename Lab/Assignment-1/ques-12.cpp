/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: Write a program for adding two vectors (which are
         objects of a class Vector). Use dynamic data members
         instead of arrays to store a vector. Write a
         function which adds two vectors passed as parameters.
         Declare this function as friend to the vector class.
Date: 05-09-2024
*/
#include <iostream>
using namespace std;

class Vector
{
   int *arr, size;

public:
   Vector(int a)
   {
      size = a;
      arr = new int[size];
      for (int i = 0; i < 10; i++)
      {
         arr[i] = 1;
      }
   }
   Vector(Vector &v1, Vector &v2)
   {
      if (v1.size > v2.size)
         size = v1.size;
      else
         size = v2.size;
      arr = new int[size];
      for (int i = 0; i < size; i++)
      {
         arr[i] = 0;
      }
   }
   void input()
   {
      for (int i = 0; i < size; i++)
      {
         cout << "Enter number(" << i + 1 << "/5): ";
         cin >> arr[i];
      }
   }
   void output()
   {
      cout << "\n";
      for (int i = 0; i < size; i++)
      {
         cout << arr[i] << " ";
      }
   }

   friend void add(Vector &v1, Vector &v2, Vector &v3);

   ~Vector()
   {
      delete arr;
   }
};

// dost lol
void add(Vector &v1, Vector &v2, Vector &v3)
{
   for (int i = 0; i < v1.size; i++)
   {
      v3.arr[i] = v1.arr[i];
   }
   for (int i = 0; i < v2.size; i++)
   {
      v3.arr[i] += v2.arr[i];
   }
}

int main()
{
   Vector v1(5), v2(5), v3(v1, v2);
   v1.input();
   v2.input();
   cout << "\nVectors 1 and 2: ";
   v1.output();
   v2.output();
   cout << "\nBefore addition: ";
   v3.output();
   cout << "\nAfter addition: ";
   add(v1, v2, v3);
   v3.output();
}

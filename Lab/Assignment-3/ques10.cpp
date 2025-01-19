/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: Write a generic class to represent generic vector and perform following: 
         a. Create vector 
         b. Modify value of vector 
         c. Multiply scalar value to vector 
         d. Display vector
Date: 00-11-2024
*/

#include <iostream>
using namespace std;

template <class T>
class Vector{
   T *v;
   int size = 0;
public:
   //creating
   Vector(){
      size = 3;
      v = new T[size];
      for (int i = 0; i<size; i++)
         v[i] = 0;
   }
   Vector(int sz){
      size = sz;
      v = new T[size];
      for (int i = 0; i<size; i++)
         v[i] = 0;
   }
   Vector(T arr[]){
      size = sizeof(arr)/sizeof(arr[0]);
      v = new T[size];
      for (int i = 0; i<size; i++){
         v[i] = arr[i];
      }
   }
   Vector(Vector &v1){
      size = v1.size;
      v = new T[size];
      for (int i = 0; i<size; i++)
         v[i] = v1.v[i];
   }
   //input
   void input(){
      cout << "Enter size of vector: ";
      cin >> size;
      cout << "Enter elements:" << endl;
      for (int i = 0; i < size; i++){
         cin >> v[i];
      }
      cout << endl;
   }
   //modify
   int modify(){
      int x, ind;
      cout << "Enter index to replace at: ";
      cin >> ind;
      if (ind<size){
         cout << "Enter new element: ";
         cin >> v[ind];
         cout << "Updated Vector:-" << endl;
         output();
      }
      else
         cout << "Index beyond range.";
   }
   //display
   void output(){
      cout << "Elements:" << endl;
      for (int i = 0; i < size; i++){
         cout << v[i] << " ";
      }
      cout << endl;
   }
   //scalar multiplication
   Vector operator*(int scalar){
      //if (typeof(v)!=char){
         for (int i = 0; i<size; i++)
            v[i] *= scalar;
         return *this;
      //}
      //throw 1;
      //this was better in my head
   }
   //destructor
   ~Vector(){
      delete[] v;
   }
};

int main(){

   Vector<int> v1;
   v1.input(); v1.output();
   v1.modify();
   v1 * 2;
   v1.output();

   Vector<char> v2;
   v2.input(); v2.output();
   v2.modify(); 

}
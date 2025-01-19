/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: Write a function template to sort an array passed as parameter.
Date: 00-11-2024
*/

#include <iostream>
using namespace std;

template <class T>
void array_sort(T arr[], int size){
   T temp;
   //int size = sizeof(arr) / sizeof(arr[0]);
   for (int i = 0; i < size; i++){
      for (int j = 0; j < size-i-1; j++){
         if (arr[j]>arr[j+1]){
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}

int main(){
   int size = 5;

   int a[5] = {84, 56, 32, 67, 213};
   
   cout << "Array before swap: " << endl;
   for (int i = 0; i < size; i++)
      cout << a[i] << " ";
   cout << endl;

   cout << "Array after swap: " << endl;
   array_sort(a, size);
   for (int i = 0; i < size; i++)
      cout << a[i] << " ";
   cout << endl << endl;

   char b[] = {'o','i','e','u', 'a'};
   cout << "Array before swap: " << endl;
   for (int i = 0; i < size; i++)
      cout << b[i] << " ";
   cout << endl;

   cout << "Array after swap: " << endl;
   array_sort(b, size);
   for (int i = 0; i < size; i++)
      cout << b[i] << " ";
}
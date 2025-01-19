#include<iostream>
using namespace std;

class Vector
{
   int *arr, size;
   public:
      Vector(int a){
         size=a;
         arr = new int[size];
         for (int i=0; i<10; i++){
            arr[i]=1;
         }
      }
      Vector(Vector &v1, Vector &v2){
         if (v1.size>v2.size)
            size=v1.size;
         else
            size=v2.size;
         arr = new int[size];
         for (int i=0; i<10; i++){
            arr[i]=0;
         }
      }
      void input(){
         for (int i=0; i<size; i++){
            cout<<"\nEnter number: ";
            cin>>arr[i];
         }
      }
      void output(){
         cout<<"\n";
         for (int i=0; i<size; i++){
            cout<<arr[i]<<" ";
         }
      }
      void add(Vector &v1, Vector &v2){
         for (int i=0; i<v1.size; i++){
            arr[i] = v1.arr[i];
         }
         for (int i=0; i<v2.size; i++){
            arr[i] += v2.arr[i];
         }
      }
      ~Vector(){
         delete arr;
      }
};

int main(){
   Vector v1(5), v2(7), v3(v1, v2);
   v1.output(); v2.output(); v3.output();
   v3.add(v1, v2);
   v3.output();
}
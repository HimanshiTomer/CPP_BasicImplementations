#include<iostream>
using namespace std;

class Vector
{
   int arr[10];
   public:
      Vector(){
         for (int i=0; i<10; i++){
            arr[i]=0;
         }
      }
      void input(){
         for (int i=0; i<10; i++){
            cout<<"\nEnter number: ";
            cin>>arr[i];
         }
      }
      void output(){
         cout<<"\n";
         for (int i=0; i<10; i++){
            cout<<arr[i]<<" ";
         }
      }
      void add(Vector &v1, Vector &v2){
         for (int i=0; i<10; i++){
            arr[i] = v1.arr[i] + v2.arr[i];
         }
      }
};

int main(){
   Vector v1, v2, v3;
   v1.output(); v2.output(); v3.output();
   v3.add(v1, v2);
   v3.output();
}
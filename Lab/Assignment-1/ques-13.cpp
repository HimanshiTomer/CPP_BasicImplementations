/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: Create a class which keep track of number of instances. 
         Use static data members, constructors and destructors 
         to maintain updated information about active objects
Date: 05-09-2024
*/
#include<iostream>
using namespace std;

class Tracker{
   public:
      static int num_instances;
      Tracker(){
         num_instances+=1;
      }
      ~Tracker(){
         num_instances-=1;
      }
      void active_obj_count(){
         cout<<"Number of active objects: "<<num_instances<<endl;
      }
};
int Tracker::num_instances=0;

int main(){
   Tracker t1, t2;
   t1.active_obj_count();
   {
      Tracker tt1;
      tt1.active_obj_count();
   }
   t1.active_obj_count();
}
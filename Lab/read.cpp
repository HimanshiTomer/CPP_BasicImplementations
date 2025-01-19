#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Person
{
   char name[20];
   int age;
public:
   Person(){ }
   void input(char n[], int a){
      strcpy(name, n);
      age = a;
   }
   void output(){
      cout<<name<<" "<<age<<endl;
   }
   int returnage(){
      return age;
   }
};

int main(){
   fstream f("persondata.dat", ios::binary | ios::in);
   f.seekg(0);
   Person p1;

   while(f.read((char *)&p1, sizeof(Person))){
      p1.output();
   }
   return 0;
}
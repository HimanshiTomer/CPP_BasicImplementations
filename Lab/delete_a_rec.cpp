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
   Person p1;
   int search = 14, flag = 0;
   cout << "Age to search: "<<search;
   f.seekg(0);
   while(f.read((char *)&p1, sizeof(Person)))
      if (search==p1.returnage()){
         flag = 1;
         break;
      }

   if (!flag){
      f.close();
      cout << "Rec not found.";
      return 1;
   }
   
   f.seekg(0);
   fstream newf("newdata.dat", ios::binary | ios::out);
   newf.seekp(0);
   while(f.read((char *)&p1, sizeof(Person))){
      if (search!=p1.returnage())
      
         newf.write((char *)&p1, sizeof(Person));
   }
   newf.close();
   f.close();

   remove("persondata.dat");
   rename("newdata.dat", "persondata.dat");
   
   return 0;
}
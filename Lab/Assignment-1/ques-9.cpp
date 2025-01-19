/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: Write a class student with rollno, name and age as data members. 
         Include following in the class: 
            a. Input and output functions 
            b. Default constructor which initializes rollno and age to 
               zero and name to “NA”. 
            c. A parameterized constructor. 
            d. A copy constructor 
            e. A Destructor
Date: 04-09-2024
*/

#include <iostream>
#include<string.h>
using namespace std;

class Student{
   int rollno, age;
   char name[30];
   public:
      Student(){
         rollno=age=0;
         strcpy(name, "NA");
      }
      Student(int a, int b, char c[]){
         rollno=a; age=b; strcpy(name, c);
      }
      Student(Student &obj){
         rollno=obj.rollno; age=obj.age; 
         strcpy(name, obj.name);
      }
		void input(){
			cout<<"Enter name: "; cin>>name;
			cout<<"Enter rollno: "; cin>>rollno;
			cout<<"Enter age: "; cin>>age;
		}
		void output(){
			cout<<"\nName: "<<name;
         cout<<"\nRollno: "<<rollno;
			cout<<"\nAge: "<<age<<endl;
		}
      ~Student(){
         cout<<"\nDestructor Envoked.";
      }
};
int main(){
   char a[30]="Ram Kumar";
   Student s1, s2(34, 16, a), s3(s2);
   s1.output(); s2.output(); s3.output();
   s1.input(); s1.output();
   return 0;
}

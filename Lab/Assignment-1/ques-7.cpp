/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: WAP to implement Parameterized Constructor, 
		 Copy Constructor and Destructor
Date: 04-09-2024
*/

#include <iostream>
#include<string.h>
using namespace std;

class Student{
	char name[30];
	int rollno;
	public:
      Student(char a[], int b){
         strcpy(name, a); rollno=b;
      }
      Student(Student &s1){
         strcpy(name,s1.name);
         rollno=s1.rollno;
      }
		void display(){
			cout<<"\nName: "<<name;
			cout<<"\nRollNo.: "<<rollno<<endl;
		}
      ~Student(){
         cout<<"\nDestructor called.";
      }
};

int main(){
   char a[30]="Ram Kumar";
	Student s1(a, 34);   s1.display();
   Student s2(s1);   s2.display();
   return 0;
}

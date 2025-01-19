/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: Create a class employee which have name, age and address 
         of employee, include functions getdata() and showdata(), 
		 getdata() takes the input from the user, showdata() 
		 display the data in following format:
			Name:
			Age:
			Address:
Date: 04-09-2024
*/

#include <iostream>
using namespace std;

class Employee{
	char name[30], address[50];
	int age;
	public:
		void getdata(){
			cout<<"Enter name: "; cin>>name;
			cout<<"Enter age: "; cin>>age;
			cout<<"Enter address: "; cin>>address;
		}
		void showdata(){
			cout<<"\nName:"<<name;
			cout<<"\nAge:"<<age;
			cout<<"\nAddress:"<<address;
		}
};

int main(){
	Employee e1;
	e1.getdata(); e1.showdata();
}

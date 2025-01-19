/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: WAP to show the usage of constructor in 
		 base and derived classes, in multiple inheritance
Date: 17-09-2024
*/

#include <iostream>
using namespace std;

class Student
{
	public:
		int sid;
		Student() {
			sid=0;
			cout<<"Student Object Created."<<endl;
		}
		Student(int a) {
			sid=a;
			cout<<"Student Object Created."<<endl;
		}
		~Student(){
			cout<<"Student Object Destroyed."<<endl;
		}
};

class Teacher
{
	public:
		int tid;
		Teacher(){
			tid=0;;
			cout<<"Teacher Object Created."<<endl;
		}
		Teacher(int a) {
			tid=a;
			cout<<"Teacher Object Created."<<endl;
		}
		~Teacher(){
			cout<<"Teacher Object Destroyed."<<endl;
		}
};

class Researcher : public Student, public Teacher
{
	public:
		int rid;
		Researcher(){
			rid=0;
			cout<<"Researcher Object Created."<<endl;
		}
		Researcher(int a){
			rid=a;
			cout<<"Researcher Object Created."<<endl;
		}
		Researcher(int a, int b):Teacher(b){
			rid=a;
			cout<<"Researcher Object Created."<<endl;
		}
		~Researcher(){
			cout<<"Researcher Object Destroyed."<<endl;
		}
};

int main(){
	Researcher r1;
}

/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: WAP to read and write values through object using file handling
Date: 15-10-2024
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Person{
	char name[30]; int age;
public:
	Person(){
		strcpy(name,"NA");
		age=0;
	}
	Person(char n[], int a){
		strcpy(name,n);
		age=a;
	}
	void output(){
		cout<<"Name: "<<name<<"\nAge: "<<age<<endl;
	}	
};

int main(){
	char n[9]="Himanshi";
	Person p1(n, 18);
	fstream fout("ques3.txt", ios::out);
	fout.write((char *)&p1, sizeof(p1));
	fout.close();
	fstream fin ("ques3.txt", ios::in);
	fin.read((char *)&p1, sizeof(Person));
	p1.output();
	fin.close();
}

/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: WAP to read objects of a structure emp from a file 
			'emp.dat' and search for a particular empno in it.
Date: 15-10-2024
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class emp{
	int empno; char name[30];
public:
	emp(){
		empno=0;
		strcpy(name,"NA");
	}
	emp(int e, char n[]){
		empno=e;
		strcpy(name,n);
	}
	void input(){
		cout<<"Emp ID: "; cin>>empno;
		cout<<"Name: "; cin>>name;
	}
	void output(){
		cout<<"Emp ID: "<<empno<<"\nName: "<<name<<endl;
	}
};

int main(){
	emp e1;
	
	fstream fout("emp.dat", ios::out);
	for(int i=0; i<5; i++){
		e1.input();
		fout.write((char *)&e1, sizeof(e1));
	}
	fout.close();
	
	fstream fin ("emp.dat", ios::in);
	cout << "Displaying: " << endl;
	for(int i=0; i<5; i++){
		fin.read((char *)&e1, sizeof(emp));
		e1.output();
	}
	e1.output();
	fin.close();
}

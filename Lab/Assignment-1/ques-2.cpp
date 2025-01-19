/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: WAP and demonstrate call to overloaded functions
Date: 04-09-2024
*/

#include <iostream>
using namespace std;

int sum(int a, int b){
	return a+b;
}
int sum(int a, int b, int c){
	return a+b+c;
}

int main(){
	int n1=2, n2=4, n3=6;
	cout<<"Sum fucntion with 2 parameters: "<<sum(n1, n2)<<endl;
	cout<<"Sum fucntion with 3 parameters: "<<sum(n1, n2, n3);
}

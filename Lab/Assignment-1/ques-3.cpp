/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: WAP to implement �Inline function�
Date: 04-09-2024
*/

#include <iostream>
using namespace std;

int inline sum(int a, int b, int c){
	return a+b+c;
}

int main(){
	int n1=2, n2=4, n3=6;
	cout<<"Sum using inline function sum: "<<sum(n1, n2, n3);
}

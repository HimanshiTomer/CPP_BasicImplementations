/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: WAP and demonstrate the use of reference 
         variable in calling by function by reference
Date: 04-09-2024
*/

#include <iostream>
using namespace std;

int increment(int &a){
	a+=2;
	return a;
}

int main(){
	int num=2;
	cout<<"Number before increment: "<<num<<endl;
	increment(num);
	cout<<"Number post increment: "<<num;
}

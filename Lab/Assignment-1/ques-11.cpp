/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: WAP to add and subtract two complex numbers using classes.
Date: 05-09-2024
*/
//incomplete
#include <iostream>
#include<string.h>
using namespace std;

class ComplexNumber{
	int a, b;
	public:
		ComplexNumber(){
			a=b=0;
		}
		void add(ComplexNumber &c2){
			int real, imag;
			real = a + c2.a;
			imag = b + c2.b;
			cout<<"Sum of "<<a<<" + "<<b<<"i and "<<c2.a;
			cout<<" + "<<c2.b<<"i = "<<real<<" + "<<imag<<"i"<<endl;
		}
		void diff(ComplexNumber &c2){
			int real, imag;
			real = a - c2.a;
			imag = b - c2.b;
			cout<<"Difference "<<a<<" + "<<b<<"i and "<<c2.a;
			cout<<" + "<<c2.b<<"i = "<<real<<" + "<<imag<<"i"<<endl;
		}
		void display(){
			cout<<"\nComplex Number: "<<a<<"+"<<b<<"i"<<endl;
		}
		void input(){
			cout<<"\nReal part: "; cin>>a;
			cout<<"\nImaginary part: "; cin>>b;
		}
};

int main(){
	ComplexNumber n1, n2;
	n1.input(); n2.input();
	n1.display(); n2.display();
	n1.add(n2); n1.diff(n2);
	return 0;
}
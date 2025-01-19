/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: WAP to read a series of numbers from a text file and divide
		 them in two separate files having even and odd numbers. Take
		 file names from user through command line.
Date: 15-10-2024
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
	if (argc<3){
		cout<<"Required arguments not received.";
		return 1;
	}
	
	ifstream file(argv[1], ios::in);
	int *numbers = new int[argc];
	int i=0; char ch[5];
	while (!file.eof()){
		file>>ch;
		numbers[i]=int(ch);
		i++;
	}
	int size=file.tellg();
	file.close();
	
	ofstream evenfile(argv[2], ios::out);
	ofstream oddfile(argv[3], ios::out);
	for (int i=0; i<size; i++){
		if (numbers[i]%2==0)
			evenfile<<numbers[i]<<" ";
		else
			oddfile<<numbers[i]<<" ";
	}
	
   	evenfile.close();
   	oddfile.close();
   	delete[] numbers;
}

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
	ofstream evenfile(argv[2], ios::out);
	ofstream oddfile(argv[3], ios::out);
	int size = file.tellg();
	int i=0; int num;
	while (!file.eof()){
		file>>num;
		if (int(num)%2==0){
			evenfile<<num;
			evenfile << "\n";
		}
		else{
			oddfile<<num;
			oddfile << "\n";
		}
		i++;
	}
	file.close();
   evenfile.close();
   oddfile.close();
}

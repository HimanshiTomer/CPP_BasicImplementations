/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: WAP to count digits, alphabets and spaces, stored in a text file, using streams
Date: 15-10-2024
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream file("ques1.txt", ios::in); //file open in read mode
   	int digit, alpha, space; //counter variables to count digits, alphabets and spaces each
	char ch; //will read character from file, one at a time
	digit = alpha = space = 0; //to avoid garbage values, setting to 0
	while(!file.eof()){ //loop till we reach end of file
      	file.get(ch); //reading one character at a time
      	if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) //checking for alphabets
      		alpha++; //increementing by one if alphabet
    	else if (ch>='0' && ch<='9') //checking for digits
    		digit++; //increementing by 1 if digit
    	else if (ch==' ') //checking for space
    		space++; //increementing by 1 if space
    	else 
    		continue; //if none of the above conditions are truye, move on
	}
	cout<<"Number of digits: "<<digit<<endl;
	cout<<"Number of alphabets: "<<alpha<<endl;
	cout<<"Number of spaces: "<<space<<endl;
	file.close(); //closing the file
}

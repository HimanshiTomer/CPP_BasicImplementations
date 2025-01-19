/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: Write a class called CAccount which contains two private data 
		 elements, an integer accountNumber and a floating point 
		 accountBalance, and three member functions: 
		 	> A constructor that allows the user to set initial values
			  for accountNumber and accountBalance and a default constructor that
			  prompts for the input of the values for the above data numbers.
			> A function called inputTransaction, which reads a character value 
			  for transactionType(�D� for deposit and �W� for withdrawal), and 
			  a floating point value for transactionAmount, which updates 
			  accountBalance. 
			> A function called printBalance, which prints on the screen the 
			  accountNumber and accountBalance.
Date: 04-09-2024
*/

#include <iostream>
using namespace std;

class CAccount{
	int accountNumber;
	float accountBalance;
	public:
		CAccount(){
			cout<<"Enter account number: "; cin>>accountNumber;
			cout<<"Enter account balamce: "; cin>>accountBalance;
		}
		CAccount(int initial){
			accountNumber=accountBalance=initial;
		}
		void inputTransaction(char value, int transactionAmount){
			if (value=='D')
				accountBalance+=transactionAmount;
			else if (value=='W')
				accountBalance-=transactionAmount;
			else
				cout<<"Error"<<endl;					
		}
		void printBalance(){
			cout<<"\nAccount Number: "<<accountNumber;
			cout<<"\nAccount Balance: "<<accountBalance;
		}
};

int main(){
	CAccount acc1;
	acc1.printBalance();
	acc1.inputTransaction('D', 10000);
	acc1.printBalance();
	acc1.inputTransaction('W', 10000);
	acc1.printBalance();
}

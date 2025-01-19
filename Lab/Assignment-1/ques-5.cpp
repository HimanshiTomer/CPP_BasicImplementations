/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: WAP to store student roll_no, name, marks in 5 subjects,
			total marks and percentage for 5 students.
			 a. Include a function to take roll_no, name and marks
				from user using input function.
			b. Include a function to display all details of a student.
			c. Include a calculate() function in private area to
				calculate total_marks and percentage. Let the input
				function invoke this function.
Date: 04-09-2024
*/

#include <iostream>
using namespace std;

class Student
{
	char name[30];
	int roll_no, marks[5], total, percent;
	void calculate(int sub[], int &total, int &percent)
	{
		total = percent = 0;
		for (int i = 0; i < 5; i++)
		{
			total += sub[i];
		}
		percent = (total / 5);
	}

public:
	void input()
	{
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter rollno: ";
		cin >> roll_no;
		cout << "Enter marks for 5 subjects: ";
		for (int i = 0; i < 5; i++)
		{
			cin >> marks[i];
		}
		calculate(marks, total, percent);
	}
	void output()
	{
		cout << "Name: " << name << ", Rollno: " << roll_no << endl;
		cout << "Marks for 5 subjects: ";
		for (int i = 0; i < 5; i++)
		{
			cout << marks[i] << ", ";
		}
		cout << "\nTotal: " << total << ", Percent: " << percent << "%\n"
			  << endl;
	}
};

int main()
{
	Student s[5];
	for (int i = 0; i < 5; i++)
	{
		s[i].input();
	}
	for (int i = 0; i < 5; i++)
	{
		s[i].output();
	}
}

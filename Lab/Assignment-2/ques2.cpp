/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: Implement the following class hierarchy considering appropriate data members and
member functions. A class Student acting as a base class with some data members. Two
classes Test and Score deriving from Student, both with appropriate data members. A class
Performance deriving from both Test and Score.
Date: 17-09-2024
*/

#include <iostream>
#include <cstring>

using namespace std;

class Student
{
	int roll;
	char name[20];

public:
	int sid;
	Student()
	{
		roll = 0;
		strcpy(name, "NA");
	}
	Student(int r, char n[]){
		roll = r;
		strcpy(name, n);
	}
	void display(){
		cout << "Roll no: " << roll << "\nName: " << name<<endl;
	}
};

class Test : virtual public Student
{
public:
	int marks[5];
	Test()
	{
		for (int i = 0; i < 5; i++)
			marks[i] = 0;
	}

};

class Score : virtual public Student
{
public:
	
	Score()
	{
		
	}
};

class Performance : public Test, public Score
{
};

int main()
{
	Student r1;
}

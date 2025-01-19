/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: In previous question, add a new class Research_Scholar which inherits from both
			student and teacher, and has new data member �research title�. Make sure that no
			data is duplicated in this process.
Date: 24-09-2024
*/

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
public:
	int age;
	char name[20], address[40];
	Person()
	{
		age = 0;
		strcpy(name, "NA");
		strcpy(address, "NA");
	}
	void input(int a, char b[], char c[])
	{
		age = a;
		strcpy(name, b);
		strcpy(address, c);
	}
	void output()
	{
		cout << "Age: " << age << ", Name: " << name << ", Address: " << address << endl;
	}
};

class Student : virtual public Person
{
	int enrollment;
	char batch;

public:
	Student()
	{
		enrollment = 0;
		batch = '-';
	}
	void input(int a, char b)
	{
		enrollment = a;
		batch = b;
	}
	Student(Student &sc)
	{
		batch = sc.batch;
		enrollment = sc.enrollment;
	}
	void output()
	{
		cout << "Enrollment: " << enrollment << ", Batch: " << batch << endl;
	}
};

class Teacher : virtual public Person
{
	int salary, exp;

public:
	Teacher()
	{
		salary = exp = 0;
	}
	void input(int a, int b)
	{
		salary = a;
		exp = b;
	}
	Teacher(Teacher &t) : Person(t)
	{
		salary = t.salary;
		exp = t.exp;
	}
	void output()
	{
		cout << "Salary: " << salary << ", Experience: " << exp << "yrs" << endl;
	}
};

class Research_Scholar : public Student, public Teacher
{
public:
	char research_title[30];
	Research_Scholar()
	{
		strcpy(research_title, "NA");
	}
	void input(int enroll, char batc, int sal, int e, int age, char name[], char add[], char title[])
	{
		Student::input(enroll, batc);
		Teacher::input(sal, e);
		Student::Person::input(age, name, add);
		strcpy(research_title, title);
		output();
	}
	void output()
	{
		cout << "Person Details: \n";
		Student::Person::output();
		cout << "\nStudent Details:\n";
		Student::output();
		cout << "\nTeacher Details:\n";
		Teacher::output();
		cout << "\nResearch_Scholar Details:\n";
		cout << "Research Title:" << research_title;
	}
};

int main()
{
	Research_Scholar r1;
	char a[20] = "Himanshi";
	char b[20] = "Rohini, Sector-5";
	char c[20] = "Assistant Prof.";
	r1.input(101, 'A', 230000, 3, 23, a, b, c);
}

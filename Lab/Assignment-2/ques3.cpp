/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: Write a program to store details of a school.
			A class �person� shows name, age, address. A
			class �student� has enrolment_no & batch, and also
			has all details of person. A class �teacher� has
			salary and experience along with all details of a person.
			Implement this using inherited classes, with default,
			parameterized and copy constructors.
Date: 17-09-2024
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
	Person(int a, char b[], char c[])
	{
		age = a;
		strcpy(name, b);
		strcpy(address, c);
	}
	void output()
	{
		cout << "Age= " << age << ", Name= " << name << ", Address= " << address << endl;
	}
};

class Student : public Person
{
	int enrollment;
	char batch;

public:
	Student()
	{
		enrollment = 0;
		batch = '-';
	}
	Student(int a, char b)
	{
		enrollment = a;
		batch = b;
	}
	Student(int a1, char a2, int b, char c[], char d[]) : Person(b, c, d)
	{
		enrollment = a1;
		batch = a2;
	}
	Student(Student &sc)
	{
		batch = sc.batch;
		enrollment = sc.enrollment;
	}
	void output()
	{
		Person::output();
		cout << "Enrollment= " << enrollment << ", Batch= " << batch << endl;
	}
};

class Teacher : public Person
{
	int salary, exp;

public:
	Teacher()
	{
		salary = exp = 0;
	}
	Teacher(int a, int b)
	{
		salary = a;
		exp = b;
	}
	Teacher(int a1, int a2, int b, char c[], char d[]) : Person(b, c, d)
	{
		salary = a1;
		exp = a2;
	}
	Teacher(Teacher &t) : Person(t)
	{
		salary = t.salary;
		exp = t.exp;
	}
	void output()
	{
		Person::output();
		cout << "Salary= " << salary << ", Experience= " << exp << "yrs" << endl;
	}
};

int main()
{
	char a[10] = "Himanshi";
	char b[10] = "Delhi";
	Student r1;
	r1.output();
	Student r2(05214002023, 'A');
	r2.output();
	Student r3(05214002023, 'A', 111, a, b);
	r3.output();
	Student r4(r3);
	r4.output();
	Teacher t1;
	t1.output();
	Teacher t2(1000, 3);
	t2.output();
	Teacher t3(10000, 2, 111, a, b);
	t3.output();
	Teacher t4(t3);
	t4.output();
}

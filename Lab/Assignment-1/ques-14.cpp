/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: WAP to show the implementation of �containership�.
Date: 10-09-2024
*/
#include <iostream>
using namespace std;

class door
{
	int lenght, width;

public:
	door()
	{
		lenght = width = 0;
	}
	void input()
	{
		cout << "Enter length and width";
		cin >> lenght >> width;
	}
	void output()
	{
		cout << "Length: " << lenght << " Width: " << width << endl;
	}
};
class room
{
	int walls;
	door d1;

public:
	room()
	{
		walls = 0;
	}
	void input()
	{
		cout << "Enter number of walls: ";
		cin >> walls;
	}
	void output()
	{
		cout << "Number of walls: " << walls << endl;
		d1.output();
	}
};

int main()
{
	room r1;
	r1.output();
}

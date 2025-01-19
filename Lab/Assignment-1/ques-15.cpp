/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: Declare two classes named �window� and �door� having attributes
			like height and width. Show a �has-a� relationship while creating
			a new class called �house� which may contain some doors and
			windows depending upon users choice. Also specify desired number
			of constructors and destructors, static members and friend members.
Date: 10-09-2024
*/
#include <iostream>
using namespace std;

class window
{
	int height, width;

public:
	static int no_wind;
	window(){
		height = width = 0;
		no_wind += 1;
	}
	window(int a, int b){
		height = a;
		width = b;
	}
	void input(){
		cout << "Enter height and width: ";
		cin >> height >> width;
	}
	void output(){
		cout << "Height: " << height << ", Width: " << width << endl;
	}
	int return_count_w(){
		return no_wind;
	}
	~window() { }
};
int window::no_wind = 0;

class door{
	int height, width;

public:
	static int no_door;
	door(){
		height = width = 0;
		no_door += 1;
	}
	door(int a, int b){
		height = a;
		width = b;
	}
	void input(){
		cout << "Enter height and width: ";
		cin >> height >> width;
	}
	void output(){
		cout << "Height: " << height << ", Width: " << width << endl;
	}
	int return_count_d(){
		return no_door;
	}
	~door() { }
};
int door::no_door = 0;

class house
{
	int house_no;
	char block;
	door front, back;
	window w1;

public:
	house(){
		house_no = 38;
		block = 'N';
	}
	void input(){
		cout << "Enter house no.: ";
		cin >> house_no;
		cout << "Enter block letter: ";
		cin >> block;
	}
	void output(){
		cout << "Block-" << block << "House no.: " << house_no << endl;
		cout << "Door details: "<<endl;
		cout << "Front Door: "; front.output();
		cout << "Back Door: "; back.output();
		cout << "Windows details: "<<endl;
		w1.output();
	}
	friend void return_count(house &h1);
	~house() { }
};

int main()
{
	house h1;
	h1.output();
}

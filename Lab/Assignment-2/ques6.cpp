/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: WAP with student as an abstract class and create many derived classes such as
         engineering, medical and science etc from student class. Student class must have
         pure virtual functions for data input and output which are implemented in all derived
         classes. At user screen at run-time, dynamic objects of different classes are created
         and referred by a common pointer of student class
Date: 24-09-2024
*/

#include <iostream>
#include <cstring>
using namespace std;

class Student{
public:
   int id;
   char name[30];
   virtual void input() {};
   virtual void output() {};
   //void input() {};
   //void output() {};
};

class engineering : public Student
{
   char branch[3];
public:
   engineering() {};
   void input(){
      cout << "\nEnter Student ID: "; cin >> id;
      cout << "Enter Name: "; cin >> name;
      cout << "Branch (CSE/ECE/EEE): "; cin >> branch;
   }
   void output(){
      cout << "\nStudent ID: " << id;
      cout << "\nName: " << name;
      cout << "\nBranch: " << branch<<endl;
   }
   ~engineering(){ }
};

class medical : public Student
{
   char prof_type[15];
public:
   medical() {};
   void input(){
      cout << "\nEnter Student ID: "; cin >> id;
      cout << "Enter Name: "; cin >> name;
      cout << "Profession (Doctor/Nurse/Technician): "; cin >> prof_type;
   }
   void output(){
      cout << "\nStudent ID: " << id;
      cout << "\nName: " << name;
      cout << "\nProfession:" << prof_type<<endl;
   }
};

class science : public Student
{
   char domain[10];
public:
   science() {};
   void input(){
      cout << "\nEnter Student ID: "; cin >> id;
      cout << "Enter Name: "; cin >> name;
      cout << "Domain (Biology/Physics/Chemistry): "; cin >> domain;
   }
   void output(){
      cout << "\nStudent ID: " << id;
      cout << "\nName: " << name;
      cout << "\nDomain: " << domain<<endl;
   }
};

int main(){
   Student *s;
   engineering e1; medical m1; science s1; 
   //uscore
   s = new engineering();
   s->input();  s->output();
   cout << "---------------------------------------"<<endl;
   //medicos
   s = new medical();
   s->input();  s->output();
   cout << "---------------------------------------"<<endl;
   //sci
   s = new science();
   s->input();  s->output();
}
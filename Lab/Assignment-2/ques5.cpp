/*
Programmer Name: Himanshi Tomer
Enrollment No.: 05214002023
Problem: WAP to run stack class with push() and pop() functions and following details-
         a. Derive 3 classes arraystack, linkedstack and multistack from base class stack
         b. Make it compulsary for every derive class to override push() , pop() and
            display methods of base class stack.
         c. Every derived class can have its own data members as follows:
                 i. Arraystack has a dynamic array
                ii. Linkedstack will have a structure object for linkedlist
               iii. Multistack will hav a 2D array
         d. Implement this program using dynamic binding.
Date: 24-09-2024
*/

#include <iostream>
#include <cstring>
using namespace std;

class stack{
public:
   virtual void push() = 0;
   virtual void pop() = 0;
   virtual void display() = 0;
};

class arraystack : public stack{
public:
   int size, *arr, top;
   arraystack(int s){
      size = s;
      arr = new int[size];
      top = -1;
   }
   void push(){
      if (top == size - 1){
         cout << "Stack Overflow." << endl;
         return;
      }
      else{
         top++;
         cout << "Enter new element: " << endl;
         cin >> arr[top];
      }
   }
   void pop(){
      if (top == -1){
         cout << "Stack Underflow." << endl;
         return;
      }
      else
         top--;
   }
   void display(){
      if (top == -1)
         cout << "Stack underflow." << endl;
      else{
         for (int i = top; i >= 0; i--)
            cout << "Element= " << arr[i] << endl;
      }
   }
};

// b. linkedlist array
// structure
struct linkedl{
   int data;
   struct linkedl *next;
};

class linkedstack : public stack{
public:
   struct linkedl *temp, *top;
   void push(){
      temp = new linkedl;
      cout << "Enter value = ";
      cin >> temp->data;
      temp->next = NULL;
      if (top != NULL)
         temp->next = top;
      top = temp;
   }
   void pop(){
      if (top == NULL)
         cout << "Stack Underflow" << endl;
      else{
         temp = top;
         top = top->next;
         delete temp;
      }
   }
   void display(){
      temp = top;
      if (top == NULL){
         cout << "Stack Underflow" << endl;
         return;
      }
      while (temp){
         cout << " Element = " << temp->data << endl;
         temp = temp->next;
      }
   }
};

int main()
{
   arraystack a1(5);
   cout << "For Array Implementation:" << endl;
   a1.push();
   a1.push();
   a1.push();
   a1.display();
   cout << "Pop:" << endl;
   a1.pop();
   a1.display();
   linkedstack l1;
   cout << "For Linked List Implementation:" << endl;
   l1.top = NULL;
   l1.push();
   l1.push();
   l1.push();
   l1.display();
   cout << "Pop:" << endl;
   l1.pop();
   l1.display();
}
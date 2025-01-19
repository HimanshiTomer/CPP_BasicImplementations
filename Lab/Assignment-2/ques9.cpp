/*
Programmer Name: Himanshi Tomer
Enrollment No. : 05214002023
Problem: WAP to implement addition, subtraction and multiplication of 
         matrices using overloaded operators
Date: 01-10-2024
*/

#include <iostream>
#include <cstring>
using namespace std;

class matrix{
public:
   int row, col, **arr; //uhm dynamic 2d array?
   matrix(){
      row = col = 0;
   }
   matrix(int r, int c){
      row = r; col = c;
      arr = new int*[row];
      for (int i = 0; i < row; i++){
         arr[i] = new int[col];
         for (int j = 0; j < col; j++)
            arr[i][j] = 0;
      }
   }
   matrix(matrix &m){
      row = m.row; col = m.col;
      arr = new int*[row];
      for (int i = 0; i < row; i++){
         arr[i] = new int[col];
         for (int j = 0; j < col; j++)
            arr[i][j] = m.arr[i][j];
      }
   }
   void input(){
      if (row==0 && col==0){
         cout << "\nEnter number of rows: "; cin >> row;
         cout << "Enter number of columns: "; cin >> col;
         arr = new int*[row];
         for (int i = 0; i < row; i++)
            arr[i] = new int[col];
      }
      for (int i = 0; i < row; i++){
         cout << "Elements for Row "<< i+1 <<endl;
         for (int j = 0; j<col; j++)
            cin >> arr[i][j];
      }
   }
   void output(){
      cout << "\n------------";
      for (int i = 0; i < row; i++){
         cout << endl;
         for (int j = 0; j<col; j++)
            cout << arr[i][j] << "\t";
      }
      cout << "\n------------"<<endl;
   }
   matrix operator=(matrix &m){
      row = m.row; col = m.col;
      arr = new int*[row];
      for (int i = 0; i < row; i++){
         arr[i] = new int[col];
         for (int j = 0; j < col; j++)
            arr[i][j] = m.arr[i][j];
      }
      return *this;
   }
   matrix operator+(matrix &m){
      if (row!=m.row || col!=m.col){
         cout << "Addition not possible."<<endl;
         matrix md;
         return md;
      }
      matrix sum(row, col);
      for (int i = 0; i < row; i++){
         for (int j = 0; j < col; j++)
            sum.arr[i][j] = arr[i][j] + m.arr[i][j];
      }
      return sum;
   }
   matrix operator-(matrix &m){
      if (row!=m.row || col!=m.col){
         cout << "Subtraction not possible."<<endl;
         matrix md;
         return md;
      }
      matrix sub(row, col);
      for (int i = 0; i < row; i++){
         for (int j = 0; j < col; j++)
            sub.arr[i][j] = arr[i][j] - m.arr[i][j];
      }
      return sub;
   }
   matrix operator*(matrix &m){
      if (col!=m.row){
         cout << "Multiplication not possible."<<endl;
         matrix md;
         return md;
      }
      matrix prod(row, col);
      for (int i = 0; i < row; i++){
         for (int j = 0; j < col; j++)
            for (int k = 0; k<col; k++)
               prod.arr[i][j] += arr[i][k] * m.arr[k][j];
      }
      return prod;
   }
   ~matrix(){
      for (int i = 0; i<row; i++)
         delete[] arr[i];
      delete[] arr;
   }
};

int main(){
   matrix m1, m2, m3;
   m1.input(); m1.output();
   m2.input(); m2.output();
   m3.input(); m3.output();

   cout << "Sum: ";
   matrix sum = m1 + m2;
   sum.output();
   
   cout << "Difference: ";
   matrix sub = m1 - m2;
   sub.output();
   
   cout << "Product: ";
   matrix prod = m1 * m3;
   prod.output();
}

// works on online comp;
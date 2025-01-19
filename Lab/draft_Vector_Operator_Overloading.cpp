#include <iostream>
using namespace std;

class vector
{
   int *v, v_size;

public:
   vector() {};
   void output(){
      for (int i = 0; i<v_size; i++)
         cout << v[i];
   }
   vector(vector obj){
      v_size=obj.size;
      v = new int[v_size];
      for (int i = 0; i < v_size; i++)
      {
         v[i] = a[i];
      }
   }

   vector(int a[])
   {
      v_size = 3;
      v = new int[v_size];
      for (int i = 0; i < v_size; i++)
      {
         v[i] = a[i];
      }
   }
   
   friend ostream &operator<<(ostream &print, vector &vec)
   {
      print << "{ ";
      for (int i = 0; i < vec.v_size; i++)
         print << vec.v[i] << " ";
      print << "}";
      return print;
   }

   friend istream &operator>>(istream &scan, vector &vec)
   {
      scan >> vec.v_size;
      vec.v = new int[vec.v_size];

      for (int i = 0; i < vec.v_size; i++)
         scan >> vec.v[i];
      return scan;
   }

   friend vector operator*(int num, const vector &vec)
   {
      vector vecy;
      vecy.v_size = vec.v_size;
      vecy.v = new int[vecy.v_size];
      for (int i = 0; i < vecy.v_size; i++)
         vecy.v[i] = num * vec.v[i];
      return vecy;
   }

   vector operator*(int num)
   {
      vector vecy;
      vecy.v_size = v_size;
      vecy.v = new int[vecy.v_size];
      for (int i = 0; i < vecy.v_size; i++){
         vecy.v[i] = num * v[i];
      cout << vecy.v[i];
      }
       for (int i = 0; i<v_size; i++)
         cout << vecy.v[i];
      return vecy;
   }

/*
   vector operator=(vector v1){
      v_size=v1.v_size;
      for (int i = 0; i < v_size; i++){
         v[i] = v1.v[i];
      }
   }
*/
   ~vector()
   {
      delete[] v;
   }
};

const int size = 3;
int x[size] = {2, 3, 4};

int main()
{
   vector m;
   //vector n = x;

   cout << "Enter number of elements of vector m: " << "\n";
   cin >> m;

   cout << "\n m = " << m << "\n";
   //cout << "\n n = " << n << "\n";

   vector p, q;
   p = 2 * m;
   q = m * 2;
   p.output();
   q.output();
   cout << "\n p=" << p << "\n";
   cout << "\n q=" << q << "\n";
   
   return 0;
}
#include <iostream>
using namespace std;

const int size = 3;
int x[size] = {2, 3, 4};

class vector
{
   int *v, v_size;

public:
   vector()
   {
      v_size = 3;
      v = new int[size];
   }

   vector(vector &obj)
   {
      v_size = obj.v_size;
      v = new int[size];
      for (int i = 0; i < v_size; i++)
      {
         v[i] = obj.v[i];
      }
   }
   vector(int *a)
   {
      v_size = 3;
      v = new int[size];
      for (int i = 0; i < size; i++)
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
      for (int i = 0; i < vecy.v_size; i++)
         vecy.v[i] = num * v[i];
      return vecy;
   }

   /*
   vector operator=(int arr[])
   {
      v_size = size;
      v = new int[v_size];
      for (int i = 0; i < v_size; i++)
         v[i] = arr[i];
      return *this;
   }
   */

   ~vector()
   {
      delete[] v;
   }
};

int main()
{
   vector m;
   vector n(x);

   cout << "Enter number of elements of vector m: " << "\n";
   cin >> m;

   cout << "\n m = " << m << "\n";
   cout << "\n n = " << n << "\n";

   vector p, q;
   p = 2 * m;
   q = n * 2;

   cout << "\n p=" << p << "\n";
   cout << "\n q=" << q << "\n";

   return 0;
}
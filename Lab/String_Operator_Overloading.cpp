#include <iostream>
#include <cstring>
using namespace std;

class String
{
   char *str;
   int size;

public:
   String() {};
   String(char s[])
   {
      size = strlen(s);
      str = new char[size];
      strcpy(str, s);
   }
   void output()
   {
      cout << "String: " << str << endl;
   }

   String operator+(String &s1)
   {
      String s;
      // in case of segmentation error, define size
      // s.size = size + s1.size;
      // s.str = new char[s.size];
      strcat(str, s1.str);
      strcpy(s.str, str);
      return s;
   }

   int operator<=(String &s1)
   {
      return strcmp(str, s1.str);
   }

   friend ostream &operator<<(ostream &print, String &s)
   {
      print << s.str;
      return print;
   }

   ~String()
   {
      delete[] str;
   }
};

int main()
{
   char a[10] = "Himanshi";
   char b[10] = "Tomer";
   String s1(b);
   cout << "String: " << a << endl;

   String s2(a);
   s2.output();

   String s3;
   s3 = s1 + s2;
   s3.output();

   String ss = ((s1 <= s2) == 0) ? s1 : s2;
   ss.output();

   return 0;
}
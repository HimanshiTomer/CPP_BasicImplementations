#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

// it's giving ravana
void corrupt(char ogdata[], char corrupted[]){
   char ch;
   int i=0;
   while(ogdata[i]!='\0'){
      ch = ogdata[i];
      if (ch>='A' && ch<='Z'){
         if (ch < 'Z')
            corrupted[i] = ch+1;
         else
            corrupted[i] = 'A';
      }
      else if (ch>='a' && ch<='z'){
         if (ch < 'z')
            corrupted[i] = ch+1;
         else
            corrupted[i] = 'a';
      }
      else if (ch>='0' && ch<='9'){
         if (ch < '9')
            corrupted[i] = ch+1;
         else
            corrupted[i] = '0';
      }
      else
         corrupted[i] = ch;
      i++;
      cout << ogdata[i];
   }
   corrupted[i] = '\0';
}

int main(){
   ifstream fin("workahfile.txt");
   fin.seekg(0);
   int count=1; char ch;
   while (!fin.eof()){
      fin.get(ch);
      count++;
   }
   count = fin.tellg();
   fin.seekg(0);
   char *ogdata = new char[count];
   char *corrupted = new char[count];
   
   fin.seekg(0);
   fin.read(ogdata, count);
   ogdata[count] = '\0';
   fin.close();
   
   corrupt(ogdata, corrupted);

   ofstream file("workahfile.txt");
   file << corrupted;
   file.close();

   delete[] ogdata;
   delete[] corrupted;
   return 0;
}
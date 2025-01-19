#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

int main()
{
   fstream fin("sample.txt", ios::in);

   ofstream special_file("Special.txt");
   ofstream word_file("Word.txt");
   ofstream capital_file("Capital.txt");
   ofstream number_file("Number.txt");
   ofstream mixed_file("Mixed.txt");

   int special_count, word_count, capital_count, number_count, mixed_count;
   special_count = word_count = capital_count = number_count = mixed_count = 0;

   word_file << "Total numbers of words:-   " << word_count << endl;
   number_file << "Total numbers of numbers:- " << number_count << endl;
   capital_file << "Total numbers of capital characters:-  " << capital_count << endl;
   special_file << "Total numbers of special characters:- " << special_count << endl;
   mixed_file << "Total numbers of mixed characters:-  " << mixed_count << endl;

   char ch, str[1024];

   while(!fin.eof())
   {
      fin >> str;

      bool capital, number, mixed_alpha, mixed_num, mixed_special;
      number = true;
      mixed_alpha = capital = mixed_num = mixed_special = false;

      word_count++;
      word_file << str << endl;
      
      char clean_n[1024], clean_cap[1024];
      int ind_n ,ind_cap;
      ind_n = ind_cap = 0;

      for (int i = 0; i < strlen(str); i++){

         if(str[i]>='a'&&str[i]<='z')
            capital=false;
         else if(str[i]>='A'&&str[i]<='Z'){
            capital=true;
            clean_cap[ind_cap++] = str[i];
         }
            
         if ((str[i] >= '0' && str[i] <= '9'))
            clean_n[ind_n++] = str[i];
         else
            number = false;

         if(str[i] >='A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
            mixed_alpha = true;

         if(str[i] >= '0' && str[i] <= '9')
            mixed_num = true;
            
         if(!((str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
            mixed_special = true;
      }

      clean_cap[ind_cap] = '\0';
      clean_n[ind_n] = '\0';

      if (capital){
         capital_count++;
         capital_file << clean_cap << endl;
      }
      if(ind_n>0){
         number_count++;
         number_file << clean_n << endl;
      }
      if((mixed_alpha && mixed_num)||(mixed_alpha && mixed_special)||(mixed_num && mixed_special)){
         mixed_count++;
         mixed_file << str << endl;
      }
   }

   fin.seekg(0);
   while(!fin.eof()){
      fin.get(ch);
      if (!(ch>='A'&& ch<='Z'||ch>='a' && ch<='z'||ch>='0' && ch<='9')){
         special_count++;
         special_file << ch;
      }
   }

   word_file.seekp(0);
   word_file << "Total numbers of words:- " << word_count << endl;

   special_file.seekp(0, ios::beg);
   special_file << "Total numbers of special characters:- " << special_count << endl;

   number_file.seekp(0, ios::beg);
   number_file << "Total numbers of numbers:- " << number_count << endl;

   capital_file.seekp(0);
   capital_file << "Total numbers of capital characters:- " << capital_count << endl;

   mixed_file.seekp(0);
   mixed_file << "Total numbers of mixed characters:- " << mixed_count << endl;

   number_file.close(); special_file.close(); word_file.close(); capital_file.close();
   fin.close();

   return 0;
}
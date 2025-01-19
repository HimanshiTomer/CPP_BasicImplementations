#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

int main(int argc, char *agrv[])
{
   if (argc<7){
      cout << "Minimum requirement of arguments was not met.";
      return 1;
   }

   fstream fin(agrv[1], ios::in);

   ofstream special_file(agrv[2]);
   ofstream word_file(agrv[3]);
   ofstream capital_file(agrv[4]);
   ofstream number_file(agrv[5]);
   ofstream mixed_file(agrv[6]);

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

      bool special,capital ,capital_flag, number, mixed_alpha, mixed_num, mixed_special;
      capital_flag=number = true;
      special=mixed_alpha = mixed_num = mixed_special=capital = false;

      word_count++;
      word_file << str << endl;
      
      char clean_n[1024], clean_cap[1024],clean_spc[1024];
      int ind_n ,ind_cap,ind_spc;
      ind_n = ind_cap = ind_spc=0;

      for (int i = 0; i < strlen(str); i++)
      {
         if ((str[i] >= '0' && str[i] <= '9'))
            clean_n[ind_n++] = str[i];

         if(str[i] >='A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
            mixed_alpha = true;

         if(str[i] >= '0' && str[i] <= '9')
            mixed_num = true;
            
         if(!((str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
            mixed_special = true;
         
         if((str[i]>='a'&&str[i]<='z'))
            capital_flag=false;
         else if((str[i]>='A'&&str[i]<='Z'))
            capital=true;    

         if(!(str[i]>='A'&& str[i]<='Z'||str[i]>='a' && str[i]<='z'||str[i]>='0' && str[i]<='9')) 
            clean_spc[ind_spc++]=str[i];
      }

      clean_cap[ind_cap] = '\0';
      clean_n[ind_n] = '\0';
      clean_spc[ind_spc] = '\0';

      if (capital&&capital_flag){
         capital_count++;
         capital_file << str << endl;
      }
      if(ind_n>0){
         number_count++;
         number_file << clean_n << endl;
      }
      if((mixed_alpha && mixed_num)||(mixed_alpha && mixed_special)||(mixed_num && mixed_special)){
         mixed_count++;
         mixed_file << str << endl;
      }
      if(ind_spc>0){
         special_count++;
         special_file<<clean_spc<<endl;
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
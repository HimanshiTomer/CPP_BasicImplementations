#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

int main(int argc, char *agrv[])
{
      //chcecking if all required number of parmeters are received
      //7 arguments should be a.exe file, the read-from file and 5 write-to files
      if (argc<7){
            cout << "Minimum requirement of arguments was not met.";
            return 1;
      }

      //opening file to read from
      fstream fin(agrv[1], ios::in); 
      //read-from is first parameter after exe file, then followed by write-to files

      //opening files to write to
      ofstream special_file(agrv[2]);
      ofstream word_file(agrv[3]);
      ofstream capital_file(agrv[4]);
      ofstream number_file(agrv[5]);
      ofstream mixed_file(agrv[6]);

      //initializing count variables
      int special_count, word_count, capital_count, number_count, mixed_count;
      special_count = word_count = capital_count = number_count = mixed_count = 0;

      //writing count to file
      word_file << "Total numbers of words:-   " << word_count << endl;
      number_file << "Total numbers of numbers:- " << number_count << endl;
      capital_file << "Total numbers of capital characters:-  " << capital_count << endl;
      special_file << "Total numbers of special characters:- " << special_count << endl;
      mixed_file << "Total numbers of mixed characters:-  " << mixed_count << endl;

      //initializing variables to read in
      char ch, str[1024]; //1024 kyuki unknown size, so as default

      while(!fin.eof())
      {
            //reading a word
            fin >> str;

            //initializing boolean variables that will be used to check what data goes where
            bool special,capital ,capital_flag, number, mixed_alpha, mixed_num, mixed_special;
            capital_flag=number = true;
            special=mixed_alpha = mixed_num = mixed_special=capital = false;

            //word counter
            word_count++;
            //writing to word file
            word_file << str << endl;
            
            //initlizing variables that will be used to store clean version of certain data, without the symbols strung to them
            char clean_n[1024], clean_cap[1024],clean_spc[1024];
            int ind_n ,ind_cap,ind_spc;
            ind_n = ind_cap = ind_spc=0;

            //traversing char by char
            for (int i = 0; i < strlen(str); i++)
            {
            //for clean numbers, without symbols
            if ((str[i] >= '0' && str[i] <= '9'))
                  clean_n[ind_n++] = str[i];

            //for char capital and non capital
            if(str[i] >='A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
                  mixed_alpha = true;
                  
            //for numbers
            if(str[i] >= '0' && str[i] <= '9')
                  mixed_num = true;
                  
            //for special 
            if(!((str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
                  mixed_special = true;
            
            //for capital char
            if((str[i]>='a'&&str[i]<='z'))
                  capital_flag=false;
            else if((str[i]>='A'&&str[i]<='Z'))
                  capital=true;    

            //for clean special char, without symbols
            if(!(str[i]>='A'&& str[i]<='Z'||str[i]>='a' && str[i]<='z'||str[i]>='0' && str[i]<='9')) 
                  clean_spc[ind_spc++]=str[i];
            }

            //ending clean strings with terminator so any grabage value isn't read
            clean_cap[ind_cap] = '\0';
            clean_n[ind_n] = '\0';
            clean_spc[ind_spc] = '\0';

            //writing to Capital text file
            if (capital&&capital_flag){
            capital_count++;
            capital_file << str << endl;
            }
            //writing to Number text file
            if(ind_n>0){
            number_count++;
            number_file << clean_n << endl;
            }
            //writing to Mixed text file
            if((mixed_alpha && mixed_num)||(mixed_alpha && mixed_special)||(mixed_num && mixed_special)){
            mixed_count++;
            mixed_file << str << endl;
            }
            //writing to Special text file
            if(ind_spc>0){
            special_count++;
            special_file<<clean_spc<<endl;
            }
      }

      //writing the word count for each file

      //setting the pointer/marker/bookmark to 0
      word_file.seekp(0);
      word_file << "Total numbers of words:- " << word_count << endl;

      //setting the pointer/marker/bookmark to 0 and setting direction to beginning of file
      special_file.seekp(0, ios::beg);
      special_file << "Total numbers of special characters:- " << special_count << endl;

      //setting the pointer/marker/bookmark to 0 and setting direction to beginning of file
      number_file.seekp(0, ios::beg);
      number_file << "Total numbers of numbers:- " << number_count << endl;

      //setting the pointer/marker/bookmark to 0
      capital_file.seekp(0);
      capital_file << "Total numbers of capital characters:- " << capital_count << endl;

      //setting the pointer/marker/bookmark to 0
      mixed_file.seekp(0);
      mixed_file << "Total numbers of mixed characters:- " << mixed_count << endl;

      //closing all files open in write mode
      number_file.close(); special_file.close(); word_file.close(); capital_file.close();
      //closing file open in read mode
      fin.close();

      //end, yay.
      return 0;
}
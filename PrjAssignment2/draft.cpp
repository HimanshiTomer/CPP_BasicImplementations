#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main(){
    fstream fin("sample.txt", ios::in);
    ofstream special_file("Special.txt");
    ofstream word_file("Word.txt");
    ofstream capital_file("Capital.txt");
    ofstream number_file("Number.txt");
    ofstream number_file("Mixed.txt");
    int special_count = 0;
    int word_count = 0;
    int capital_count = 0;
    int number_count = 0;
    int mixed_count = 0;
    word_file << "Total numbers of words:-   " << word_count << endl;
    number_file << "Total numbers of numbers:- " << number_count << endl;
    capital_file << "Total numbers of capital characters:- " << capital_count << endl;
    special_file << "Total numbers of special characters:- " << special_count << endl;
    special_file << "Total numbers of mixed characters:- " << mixed_count << endl;
    char ch, str[1024];
    while(!fin.eof()){
        fin >> str;
        bool capital, number;
        capital = number = true;
        word_count++;
        word_file<<str<<endl;
        for (int i=0;i<strlen(str);i++){
            if (!(str[i]>='A'&&str[i]<='Z'))
                 capital=false;
            if (!(str[i]>='0'&&str[i]<='9'))
                 number=false;    
        }
        if(capital){
            capital_count++;
            capital_file<<str<<endl;
        }
        if(number){
            number_count++;
            number_file<<str<<endl;
        }
    }
    fin.seekg(0);
    while(!fin.eof()){
        fin.get(ch);
        if (!(ch>='A'&& ch<='Z'||ch>='a' && ch<='z'||ch>='0' && ch<='9')){
            special_count++;
            special_file<<ch;
        }
    }
    word_file.seekp(0);
    word_file<<"Total numbers of words:- "<<word_count<<endl;
    special_file.seekp(0, ios::beg);
    special_file<<"Total numbers of special characters:- "<<special_count<<endl;
    number_file.seekp(0, ios::beg);
    number_file<<"Total numbers of numbers:- "<<number_count<<endl;
    capital_file.seekp(0);
    capital_file<<"Total numbers of capital characters:- "<<capital_count<<endl;
    number_file.close();
    special_file.close();
    word_file.close();
    capital_file.close();
    fin.close();
    return 0;
}
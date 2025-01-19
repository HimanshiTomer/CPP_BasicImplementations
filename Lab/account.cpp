#include<iostream>
#include<cstring>

using namespace std;

class Account
{
   int ano, balance;
   char name[30];
public:
   void input(){
      cout<<"\nEnter account number: "; cin>>ano;
      cout<<"\nEnter account holder name: "; cin>>name;
      cout<<"\nEnter account balance: "; cin>>balance;
   }
   void display(){
      cout<<"Account Number | Account Holder Name | Account Balance\n";
      cout<<ano<<"\t\t"<<name<<"\t\t\t"<<balance<<endl;
   }
   void deposit(int amt){
      balance+=amt;
   }
   void withdrawl(int amt){
      if (amt<balance)
         balance-=amt;
      else
         cout<<"Insufficient Balance.";
   }
   //by objects as parameter, by account numbers
   void transfer(Account &a1, Account &a2, int amt){
      a1.balance-=amt;
      a2.balance+=amt;
      cout<<"Remaining balance for account number "<<a1.ano<<" is "<<a1.balance;
   }
   //by the object that called and one object as parameter, by the object that called and one account number
   void transfer(Account &a1, int amt){
      balance-=amt;
      a1.balance+=amt;
      cout<<"Remaining balance for account number "<<ano<<" is "<<balance;
   }
   int get_accno(){
      return ano;
   }
   int get_bal(){
      return balance;
   }
   bool get_name(char n2[]){
      if (strcmp(n2,name)==0)
         return true;
      return false;
   }
   void initialize(int acc, int bal, char namee[]){
      ano=acc; balance=bal; strcpy(name, namee);
   }
};

int main(){
   //add for loop construct, regular function to find the object of the account number 
   Account a[10]; char n2[30];
   int amt, i=0, ch=0, internal_ch, ano; 
   a[0].initialize(1111, 10000, "Ram");
   a[1].initialize(2222, 20000, "Ravi");
   a[2].initialize(3333, 30000, "Shyam");
   i=3; 
   /*huh, what am i doing, 
     --> change up i so it's something that syncs for each individual task 
     --> and keeps record of last time it was called, accurate posiition bbg
   */
   while (true){
      cout<<"Menu: \n1. Create an Account \n2. View all Accounts"
      "\n3. Withdrawal \n4. Deposit \n5. Transfer \n6. Find account? \n7. Exit";
      cin>>ch;
      if (ch==1){
         a[i].input();
         i++;
      }
      else if (ch==2){
         for (i=0; i<3; i++)
            a[i].display();
      }
      else if (ch==3){
         a[i].withdrawl(amt);
      }
      else if (ch==4){
         a[i].deposit(amt);
      }
      else if (ch==5){
         a[i].transfer(a[i], amt);
      }
      else if (ch==6){
         cout<<"\n i. By account holder name\nii. By account number";
         cin>>internal_ch;
         if (internal_ch==1){
            cout<<"\nEnter name to search by: "; cin>>n2;
            for (int j=0; j<10; j++)
               if (a[j].get_name(n2)){
                  cout<<"\nAccount Number: "<<a[j].get_accno();
                  cout<<"\nAccount Balance: "<<a[j].get_bal();
               }
         }
         else if (internal_ch==2){
            cout<<"\nEnter account no. to search by: "; cin>>ano;
            for (int j=0; j<10; j++)
               if (ano==a[j].get_accno())
                  cout<<"\nAccount Balance: "<<a[j].get_bal();
         }
         else{
            cout<<"\nInvalid choice. Redirecting to main menu.";
            cout<<"\n-----------------------------------------";
         }
      }
      else if (ch==7)
         break;
      else{
         cout<<"\nInvalid choice"<<endl;
      }
   }
}
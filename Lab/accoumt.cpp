#include <iostream>
using namespace std;

class Account
{
    int ano, balance;
    char name[20];
public:
    void input(){
        cout<<"\n\nEnter account no."; cin>>ano;
        cout<<"\nEnter name"; cin>>name;
        cout<<"\nEnter balance:"; cin>>balance;
    }
    void output(){
        cout<<"\nAccount Number | Account Name | Balance\n";
        cout<<ano<<name<<balance;
    }
    void deposit(){
        int dep;
        cout<<"Enter amt to deposit="; cin>>dep;
        balance+=dep;
        cout<<"Updated Balance: "<<balance;
    }
    void withdraw(){
        int withd;
        cout<<"Enter amt to withdraw="; cin>>withd;
        balance-=withd;
        cout<<"Updated Balance: "<<balance;
    }
    int check_balance(){
        return balance;
    }
    int return_ano(){
    	return ano;
	}
    void transfer(Account a1, Account a2){
		int amt;
		cout<<"\nInitiating transfer: \nEnter amount to transfer:"; cin>>amt;
		a1.balance-=amt;
		a2.balance+=amt;
		cout<<"\nRemaining balance for "<<a1.ano<<"is"<<a1.balance;
    }
};

int main(){
    Account a[3]; int a1, a2;
    for (int i=0; i<3; i++){
        a[i].input();
    }
    for (int i=0; i<3; i++){
        a[i].output();
    }
    cout<<"\nEnter self account no.="; cin>>a1;
    cout<<"\nEnter account no. to transfer="; cin>>a2;
    for (int i=0; i<10; i++){
    	if (a[i].return_ano()==a1) 
			a1=i;
    	if (a[i].return_ano()==a2) 
			a2=i;
	}
	a[0].transfer(a[a1], a[a2]);
}

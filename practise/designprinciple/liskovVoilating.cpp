#include<bits/stdc++.h>
using namespace std;

class Account {  //superclass
    public : 
    virtual  void deposite() = 0;
    virtual  void withdrawl() = 0;
};


class SavingAccount : public Account  { //subclass
    public : 
    void deposite(){
        cout<<"saving account deposite "<<endl;
    }
    void withdrawl() {
        cout<<"saving account withdrawl"<<endl;
    }
};
class CurrentAccount : public Account  {
    public : 
    void deposite(){
        cout<<"Current account deposite "<<endl;
    }
    void withdrawl() {
        cout<<"Current  account withdrawl"<<endl;
    }
};
class FixedAccount : public Account  {
    public : 
    void deposite(){
        cout<<"saving account deposite "<<endl;
    }
    void withdrawl() {
        cout<<"Dont not implement this function"<<endl; // we are chaning the behaviour of fixedAccount , we cannot withdraw throw exceptional
    }
};
class BankClient {
    vector<Account *>AccountList;
    public : 
    BankClient(vector<Account*> accounts ){
        this->AccountList = accounts ;

    }
    void processing(){
        for(int i=0;i<AccountList.size() ; i++){
            AccountList[i]->deposite();
            AccountList[i]->withdrawl();

        }
    }

};
int main(){

    Account * fixed = new FixedAccount();
   Account * current  = new SavingAccount();
   Account * saving  = new  CurrentAccount();

   vector<Account *>accountsList = { current , saving , fixed};
   BankClient * bank = new BankClient(accountsList);
   bank->processing();


}
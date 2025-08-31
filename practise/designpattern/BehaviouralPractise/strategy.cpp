#include<bits/stdc++.h>
using namespace std;

class PaymentMode{
    public : 
    virtual int Payment(int money) = 0;

};

class UPI : public PaymentMode
 {
    public : 
    int Payment(int money ) override {
        cout<<"UPI  ";
        return money * 2;
    }

 };

 class CreditCard : public PaymentMode {
    public : 
     int Payment(int money ) override {
        cout<<"Credit  ";
        return money * 3;
    }
 };
 class Banking : public PaymentMode {
     public : 
     int Payment(int money ) override {
        cout<<"Banking  ";
        return money * 4;
    }
 };

 class PaymentStratergy {
    private : 
    PaymentMode * startegy ; 
    public:
    PaymentStratergy(PaymentMode * st){
        this->startegy = st;

    }
    int PaymentProcessing(int money){
        startegy->Payment(money);

    }

 };
 
int main(){ 
    cout<<"----Stratergy pattern implementation ---"<<endl;
   PaymentMode * upi = new UPI();
   PaymentMode * credit = new CreditCard();
   PaymentMode * bank = new Banking();

   PaymentStratergy* st1 = new PaymentStratergy(upi);
   cout<<st1->PaymentProcessing(20)<<endl;

     PaymentStratergy* st2 = new PaymentStratergy(bank);
   cout<<st2->PaymentProcessing(20)<<endl;
}
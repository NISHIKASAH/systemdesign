#include<bits/stdc++.h>
#include"Ipayment.h"
using namespace std;

class creditCardPayment : public Payment {
    string cardNumber;
    public : 
    creditCardPayment(string card){
        cardNumber = card;
    };
    void doPayment(int amount){
        cout << "Paid ₹" << amount << " using Credit Card (" << cardNumber << ")" << endl;

    }

};
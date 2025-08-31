#include<bits/stdc++.h>
#include"Ipayment.h"
using namespace std;

class UpiPayment : public Payment {
    string mobileNumber;
    public : 
    UpiPayment(string number){
        mobileNumber = number;
    };
    void doPayment(int amount){
        cout << "Paid ₹" << amount << " using Upi (" << mobileNumber << ")" << endl;

    }

};

#ifndef UPI_PAYMENT_H
#define UPI_PAYMENT_H

#include<iostream>
#include "../payment/paymentStrategy.h"
using namespace std;


class UpiPayment : public PaymentStrategy {
    private : 
    string upiNumber ;
    public :
    UpiPayment(string number){
        upiNumber = number; 
    }
       void doPayment(int total ) override {
        cout << "Paid ₹" << total << " using Credit Card (" <<upiNumber<< ")" << endl;
    }
}

#endif;
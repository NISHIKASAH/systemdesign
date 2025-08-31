#ifndef CREDIT_CARD_PAYMENT_H
#define CREDIT_CARD_PAYMENT_H


#include<iostream>
#include "../payment/paymentStrategy.h"
using namespace std;


class CreditCardPayment  : public PaymentStrategy {
    private : 
    string creditCardNumber
    public :
    CreditCardPayment(string numbers){
        CreditCardPayment = number ; 
    }
       void doPayment(int total ) override {
        cout << "Paid ₹" << total << " using Credit Card (" <<creditCardNumber << ")" << endl;
    }
}
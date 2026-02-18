#pragma once
#include<iostream>
#include "../payment/paymentgateway.hpp"
using namespace std;

class PaymentgateManager {

   static PaymentgateManager * paymentmanagerinstance;
    PaymentGateWay * paymentgateway;
    PaymentgateManager(){
        paymentgateway =nullptr;
    };
   ~ PaymentgateManager(){
       delete paymentgateway;
    };
    PaymentgateManager(PaymentgateManager * manager) = delete ; 
    PaymentgateManager * operator = (const PaymentgateManager*) = delete;
    public : 
    
   static PaymentgateManager* getManagerInstance(){
        if(paymentmanagerinstance == nullptr){
            paymentmanagerinstance = new PaymentgateManager();
        }
        return paymentmanagerinstance;
    }
    void setPaymentgateway(PaymentGateWay * gateway){
        if(paymentgateway) delete paymentgateway;
        paymentgateway  = gateway;
    }

    PaymentGateWay*getPaymentgateway(){
        return paymentgateway;
    }
    bool paymentHandler(PaymentRequest*req){
        if( !paymentgateway){
            cout<<"\n choose a payment method \n";
            return false;
        }
        paymentgateway->processPayment(req);
    }
};
PaymentgateManager * PaymentgateManager ::paymentmanagerinstance = nullptr;